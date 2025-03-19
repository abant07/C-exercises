// Amogh Bantwal
// amoghb07@uw.edu

#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        perror("Invalid number of args: <./ex12> <filename>");
        return EXIT_FAILURE;
    }

    std::map<std::string,int> counts;
    
    std::ifstream file(argv[1]);

    if (!file.is_open()) {
        std::cerr << "Error opening file";
        return EXIT_FAILURE;
    }
    
    std::string s;
    while (file >> s) {
        if (counts.find(s) != counts.end()) {
            counts[s] = counts[s] + 1;
        }
        else {
            counts[s] = 1;
        }   
    }

    file.close();
    for (std::map<std::string, int>::iterator it = counts.begin(); it != counts.end(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }

    return EXIT_SUCCESS;
}