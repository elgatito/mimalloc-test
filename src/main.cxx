#include <cstdint>
#include <iostream>
#include <chrono>
#include <stdexcept>
#include <thread>

#ifdef USE_MIMALLOC
#include <mimalloc.h>
#include <mimalloc-override.h>
#endif

#include "memory_storage.h"

using clk = std::chrono::steady_clock;

int main(int argc, char *argv[]) {
    std::cout << "Starting" << std::endl;

    std::int64_t piece_length = 4 * 1024 * 1024;
    std::int64_t memory_capacity = 150 * 1024 * 1024;

    for (int i = 1; i <= 10; ++i) {
        std::cout << "Creating memory storage. Iteration: " << i << std::endl;
        auto ms = memory_storage(piece_length * i, memory_capacity);
        std::cout << "Sleeping" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    return 0;
}
