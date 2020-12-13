#include <chrono>
#include <random>

// this code is a copy paste from stackoverflow.
// I just addapted it by putting it on a function with arguments
// that represent the range of the posible random numebers.

int random_num(const int start_num, const int end_num) {
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
        (std::mt19937::result_type)
        std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()
            ).count() +
        (std::mt19937::result_type)
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch()
            ).count());

    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib(start_num, end_num);

    return distrib(gen); // return the random number
}
