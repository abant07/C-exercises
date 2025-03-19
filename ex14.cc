#include <iostream>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        return EXIT_FAILURE;
    }

    char* hostname = argv[1];
    char* port = argv[2];
    char* filename = argv[3];

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        std::cerr << strerror(errno) << std::endl;
        return EXIT_FAILURE;
    }

    struct addrinfo hints{}, *server_info;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, port, &hints, &server_info) != 0) {
        close(socket_fd);
        std::cerr << strerror(errno) << std::endl;
        return EXIT_FAILURE;
    }

    int res = connect(socket_fd, server_info->ai_addr, server_info->ai_addrlen);
    if (res == -1) {
        close(socket_fd);
        std::cerr << strerror(errno) << std::endl;
        freeaddrinfo(server_info);
        return EXIT_FAILURE;
    }
    freeaddrinfo(server_info);

    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        close(socket_fd);
        std::cerr << strerror(errno) << std::endl;
        return EXIT_FAILURE;
    }


    // find size of the filke
    size_t size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    size_t bytesLeft = size;
    int result;
    char* buf = (char*) malloc(size + 1);
    // read entire file into buffer
    while (bytesLeft > 0) {
        result = read(fd, buf + (size - bytesLeft), bytesLeft);
        if (result == -1) {
            if (errno != EINTR) {
                // real error happened, so return and error result
                close(socket_fd);
                close(fd);
                std::cerr << strerror(errno) << std::endl;
                return EXIT_FAILURE;
            }
            // EINTR happened, do nothing
            continue;
        }
        else if (result == 0) {
            break;
        }
        bytesLeft -= result;
    }

    // write the file to the socket. meaning transfer the data over to the server
    while(1) {
        int wres = write(socket_fd, buf, size);
        if (wres == 0) {
            std::cerr << "socket closed prematurely" << std::endl;
            close(fd);
            close(socket_fd);
            return EXIT_FAILURE;
        }
        if (wres == -1) {
            if (errno == EINTR) {
                continue;
            }
            std::cerr << "socket write failed: " << strerror(errno) << std::endl;
            close(fd);
            close(socket_fd);
            return EXIT_FAILURE;
        }
        break;
    }


    close(fd);
    close(socket_fd);

    return EXIT_SUCCESS;
}
