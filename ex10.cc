// Amogh Bantwal
// amoghb07@uw.edu

#include <iostream>
#include <istream>
#include <vector>
#include <algorithm>


template <typename T> 
T ReadValue(std::istream& in) {
    T value;

    if (in >> value) {
        return value;
    }

    if (in.eof()) {
        std::cerr << "Unexpected EOF while reading input" << std::endl;
    }
    else {
        std::cerr << "Invalid input. Expected a number" << std::endl;
        in.clear();
    }
    exit(EXIT_FAILURE);
}


int main(int argc, char* argv[]) {
    std::cout << "Enter 6 doubles:" << std::endl;
    std::vector<double> vec;
    for (int i = 0; i < 6; i++) {
        double input = ReadValue<double>(std::cin);
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end());

    std::cout << "Sorted Doubles:" << std::endl;
    std::vector<double>::iterator it;
    for (it = vec.begin(); it < vec.end(); it++) {
        std::cout << *it << std::endl;
    }

    return EXIT_SUCCESS;
}
