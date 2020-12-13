// Ilan Mittelman - 13/3/2020
// Ilan's Encryptor - main1.cpp
// Under the MIT licence.

/*
    destination file name as a arg.
    if none is given then do the current way
*/

#include "functions.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring> // strcmp()
#include <vector>

// ENTRER '-l' AS AN ARGUMENT TO LOG THE RESULTS TO THE CONSOLE TOO.

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Not enough given arguments. Try again\n";
        return 1;
    }

    int arguments[2] {1,1}; // by default everything should be the second argument
    // -arguments[0] is the command arg
	// -arguments[1] is the file name

    // loop to know which argument is what.

    if (argc > 2) {
        for (int i = 1; i < argc; ++i) {
            if (strcmp(argv[i], "-l") == 0) {
                arguments[0] = i;
                arguments[1] = ((i == 1) ? 2 : 1);
                break;
            }
        }
    }

    std::ifstream in_file; // input file
    in_file.open(argv[arguments[1]]);
    if (!in_file.is_open()) {
        std::cout << "There was an error opening \'" << argv[arguments[1]] << "\'.\n";
        return 1;
    }

    std::string line(std::istreambuf_iterator<char>{in_file}, {}); // read the entire file
    in_file.close();

    int index = 0;
    int column_nums = 0;
    char tmp = 0;
    
    std::vector<char> decrypted_chars {};

    column_nums = count(line, ':'); // amount corresponding to the amount of encypted chars on the string
    if (column_nums < 1) {
        std::cout << "The " << argv[arguments[1]] << " is corrupted.\n";
        return 1;
    }

    for (int i = 0; i < column_nums; ++i) {

        index = line.find('!');
        if (index == -1) {
            std::cout << "ERROR. could not find the '!' character.\n";
            break;
        }

        tmp = decrypt(line, index); // this is the most important line of the program.
        if (tmp == -1) {
            std::cout << "ERROR. could not decrypt line.\n";
            break;
        }

        line.erase(0, line.find(':')+1);

        decrypted_chars.push_back(tmp); // save the decrypted char to a vector.
    }

    // -- log the results --

    line = argv[arguments[1]]; // create the new file name
    line.insert(0, "decrypted-");

    std::ofstream out_file; // output file
    out_file.open(line);
    if (!out_file.is_open()) {
        std::cout << "There was an error opening \'" << line << "\'\n";
        return 1;
    }

    log_to_file(out_file, decrypted_chars);
    out_file.close();
    
    if (argc > 2 && strcmp(argv[arguments[0]], "-l") == 0)
        log_to_console(decrypted_chars);

    return 0;
}
