#include "random.hpp" 

int encrypt(const char &chr, int &method, int &seed) {
    seed = random_num(1,3);
    method = random_num(0,2);

    switch (method) {
    case 0:
        return chr + seed;
    case 1:
        return chr - seed;
    case 2:
        return chr * seed;
    default:
        return -1;
    }

    return -1;
}
