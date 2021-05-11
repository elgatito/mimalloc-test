#pragma once

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <memory>
#include <mutex>
#include <vector>

#include <utility>

struct memory_piece {
  public:
    int index;
    int length;

    int size;
    int bi;
    bool is_completed;
    bool is_read;

    memory_piece(int i, int length);

    bool is_buffered() const;

    void reset();
};

struct memory_buffer {
  public:
    int index;
    int length;
    std::vector<char> buffer;

    int pi;
    bool is_used;
    std::chrono::time_point<std::chrono::system_clock> accessed;

    memory_buffer(int index, int length);

    bool is_assigned() const;

    void reset();
};

struct memory_storage {
  private:

    std::string id;
    std::int64_t capacity;

    int piece_count;
    std::int64_t piece_length;
    std::vector<memory_piece> pieces;

    int buffer_size;
    int buffer_limit;
    int buffer_used;
    int buffer_reserved;
    std::vector<memory_buffer> buffers;

    bool is_logging;
    bool is_initialized;
    bool is_reading;
    bool is_handled;

  public:
    memory_storage(std::int64_t i_piece_length, std::int64_t i_capacity);
    
    ~memory_storage();

};
