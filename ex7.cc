// Amogh Bantwal
// amoghb07@uw.edu

#include <iostream>


int main(int argc, char* argv[]) {
    int number = 0;

    while (number <= 0) {
        std::cout << "Which positive integer would you like me to factorize? ";
        std::cin >> number;
    }

    for (int i = 1; i <= number; i++) {
        if (number % i == 0) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
}


