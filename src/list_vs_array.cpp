#include <cstddef>  // size_t
#include <cstdint>  // uint64_t
#include <iostream>  // cout
#include <list>
#include <random>
#include <vector>

#include "timer.h"

constexpr size_t SIZE = 16000000;

int main() {
    std::mt19937_64 rng(0);
    Timer timer;

    std::list<uint64_t> list;
    for (size_t i = 0; i < SIZE; ++i) {
        list.push_back(rng());
    }
    std::cout << "list insertion: " << timer.click<Timer::Micros>()
              << " microseconds\n";

    uint64_t listSum = 0;
    for (uint64_t value : list) {
        listSum += value;
    }
    std::cout << "list sum: " << listSum << " ("
              << timer.click<Timer::Micros>() << " microseconds)\n";

    rng.seed(0);
    std::vector<uint64_t> vector;
    for (size_t i = 0; i < SIZE; ++i) {
        vector.push_back(rng());
    }
    std::cout << "vector insertion without reserve: "
              << timer.click<Timer::Micros>() << " microseconds\n";

    uint64_t vectorSum = 0;
    for (uint64_t value : vector) {
        vectorSum += value;
    }
    std::cout << "vector sum: " << vectorSum << " ("
              << timer.click<Timer::Micros>() << " microseconds)\n";

    rng.seed(0);
    std::vector<uint64_t> reservedVector;
    reservedVector.reserve(SIZE);
    for (size_t i = 0; i < SIZE; ++i) {
        reservedVector.push_back(rng());
    }
    std::cout << "vector insertion with reserve: "
              << timer.click<Timer::Micros>() << " microseconds\n";

    uint64_t reservedVectorSum = 0;
    for (uint64_t value : reservedVector) {
        reservedVectorSum += value;
    }
    std::cout << "reserved vector sum: " << reservedVectorSum << " ("
              << timer.click<Timer::Micros>() << " microseconds)\n";
    return 0;
}
