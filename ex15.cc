#include <iostream>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>
#include <dirent.h>


int main(int argc, char* argv[]) {
    if (argc != 2) {
        return EXIT_FAILURE;
    }
    // grab the port
    char* port = argv[1];
    // ipv4 specific address structure
    struct sockaddr_in address;
    socklen_t address_len = sizeof(address); // size of struct

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0); // connect the server socket
    if (socket_fd == -1) {
        std::cerr << strerror(errno) << std::endl;
        return EXIT_FAILURE;
    }
    
    address.sin_family = AF_INET; // address family - ipv4
    address.sin_addr.s_addr = INADDR_ANY; // the actual ipv4 address
    address.sin_port = htons(atoi((port))); // port in network byte order

    if (bind(socket_fd, reinterpret_cast<struct sockaddr*>(&address), sizeof(address)) == -1) {
        close(socket_fd);
        std::cerr << strerror(errno) << std::endl;
        return EXIT_FAILURE;
    }

    if (listen(socket_fd, 10) == -1) {
        close(socket_fd);
        std::cerr << strerror(errno) << std::endl;
        return EXIT_FAILURE;
    }


    char buffer[1000]; // have a buffer for reading the file from client
    while(1) {
        // repeatly accept waiting clients
        int client_fd = accept(socket_fd, reinterpret_cast<struct sockaddr*>(&address), &address_len);
        // check if failed, and retry if os interrupt
        if (client_fd < 0) {
            if ((errno == EINTR) || (errno == EAGAIN) || (errno == EWOULDBLOCK)) {
                continue;
            }
            std::cerr << "Failure on accept: " << strerror(errno) << std::endl;
            close(socket_fd);
            std::cerr << strerror(errno) << std::endl;
            return EXIT_FAILURE;
        }

        // read the file the user gave into the buffer.
        ssize_t bytes_read;
        while ((bytes_read = read(client_fd, buffer, 1000)) > 0) {
            // write to standard output
            write(STDOUT_FILENO, buffer, bytes_read);
        }
        
        // if no bytes read, close the client, and break out
        if (bytes_read < 0) {
            close(client_fd);
            break;
        }
    }

    // close the socket.
    close(socket_fd);
    return EXIT_SUCCESS;
}