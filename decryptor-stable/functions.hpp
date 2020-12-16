#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>
#include <vector>

char decrypt(const std::string &line);
int count(const std::string &str, const char &chr);
void log_to_file(std::ofstream &out_file, const std::vector<char> &decrypted);
void log_to_console(const std::vector<char> &decrypted);

#endif