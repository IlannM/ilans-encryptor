// Ilan Mittelman - 13/3/2020
// Ilan's Encryptor - main.cpp
// Under the MIT licence.

#include "functions.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <cstring> // strcmp()
#include <cstdio> // printf()

// entrer '-l' as an argument to log the results to the console too.

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Not enough given arguments. Try again\n");
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
        printf("There was an error opening \'%s\'.\n", argv[arguments[1]]);
        return 1;
    }

    std::string line(std::istreambuf_iterator<char>{in_file}, {}); // read the entire file
    in_file.close();

    int column_nums = count(line, ':'); // amount corresponding to the amount of encypted chars on the string
    char current_char = 0;
    
    std::vector<char> decrypted_chars {}; // store here everything

    for (int i = 0; i < column_nums; ++i) {

        current_char = decrypt(line); // this is the most important line of the program.
        if (current_char == -1) {
            printf("ERROR. Could not decrypt line.\n");
            return 1;
        }

        decrypted_chars.push_back(current_char); // save the decrypted char to the vector.

        line.erase(0, line.find(':')+1);
    }

    // -- log the results --

    line = argv[arguments[1]]; // create the new file name
    line.insert(0, "decrypted-"); // ' decrypted-[FILENAME].txt '

    std::ofstream out_file(line); // output file
    log_to_file(out_file, decrypted_chars);
    out_file.close();
    
    if (argc > 2 && strcmp(argv[arguments[0]], "-l") == 0) {
        log_to_console(decrypted_chars);
    }

    return 0;
}
