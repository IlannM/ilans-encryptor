// Ilan Mittelman - 13/3/2020
// Ilan's Encryptor - functions.cpp
// Under the MIT licence.

#include "random.hpp"
#include "functions.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Not enough arguments. Try again.\n";
        return 0;
    }

    std::ifstream in_file(argv[1]);
    if (!in_file.is_open()) {
        std::cout << "There was an error opening \'" << argv[1] << "\'.\n";
        return 1;
    }
    
    std::string line(std::istreambuf_iterator<char>(in_file), {}); // read everything from the input file
    
    in_file.close();

    std::string file_name = "encrypted-";
    file_name.append(argv[1]); // encrypted-[FILE_NAME].txt

    std::ofstream out_file(file_name);
    if (!out_file.is_open()) {
        std::cout << "There was an error opening \'" << file_name << "\'.\n";
        return 1;
    }

    int seed = 0;
    int method = 0;
    int loop = 1;

    for (const auto &i : line) {
        out_file << encrypt(i, method, seed) << '!' << method << seed << ':';
        
        if (loop % 10 == 0) { // newline every ten iteretions for aesthetic pruposes
            out_file << '\n';
        }
        
        loop++;
    }

    out_file.close();

    return 0;
}
