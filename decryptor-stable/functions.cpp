// Ilan Mittelman - 13/3/2020
// Ilan's Encryptor - functions.cpp
// Under the MIT licence.

#include <cstdio>
#include <string>
#include <fstream>
#include <vector>

char decrypt(const std::string &line, const int &index) {
    switch (line[index+1] - '0') {
    case 0: // WORKS
        return ( std::stoi(line.substr(0, index) ) - ( (line[index+2]) - '0') );

    case 1:
        return ( std::stoi(line.substr(0, index) ) + ( (line[index+2]) - '0') );

    case 2:
        return ( std::stoi(line.substr(0, index) ) / ( (line[index+2]) - '0') );
    
    default:
        printf("Default case. This is bad.\n");
        return -1;
    }

    return -1;
}

int count(const std::string &str, const char &chr) {
    int occurrences = 0;
    for (const auto &i : str) {
        if (i == chr)
            ++occurrences;
    }
    return occurrences;
}

void log_to_file(std::ofstream &out_file, const std::vector<char> &decrypted) {
    for (const auto &i : decrypted) {
        out_file << i;
    }
}

void log_to_console(const std::vector<char> &decrypted) {
    printf("\'");
    for (const auto &i : decrypted) {
        printf("%c", i);
    }
    printf("\'\n");
}
