#include "memory_storage.h"
#include <cstdint>

memory_piece::memory_piece(int i, int length) : index(i), length(length) {
    size = 0;
    bi = -1;
    is_completed = false;
    is_read = false;
};

bool memory_piece::is_buffered() const { return bi != -1; };

void memory_piece::reset() {
    bi = -1;
    is_completed = false;
    is_read = false;
    size = 0;
}

memory_buffer::memory_buffer(int index, int length) : index(index), length(length) {
    pi = -1;
    is_used = false;

    buffer.resize(length);
};

bool memory_buffer::is_assigned() const { return pi != -1; };

void memory_buffer::reset() {
    is_used = false;
    pi = -1;
    accessed = std::chrono::system_clock::now();
    std::fill(buffer.begin(), buffer.end(), '\0');
};

memory_storage::memory_storage(std::int64_t i_piece_length, std::int64_t i_capacity) {
    piece_count = 0;
    piece_length = 0;

    buffer_size = 0;
    buffer_limit = 0;
    buffer_used = 0;
    buffer_reserved = 0;

    is_logging = false;
    is_initialized = false;
    is_reading = false;

    capacity = i_capacity;
    piece_count = 1000;
    piece_length = i_piece_length;

    std::cout << "Creating memory storage with size: " << capacity << ", Pieces count: " << piece_count << ", Piece size: " << piece_length << std::endl;;

    // Using max possible buffers + 2
    buffer_size = int(rint(ceil(capacity / double(piece_length))));
    if (buffer_size > piece_count) {
        buffer_size = piece_count;
    };
    buffer_limit = buffer_size;
    std::cout << "Using " << (buffer_size * piece_length) << " memory for " << buffer_size << " buffer items" << std::endl;

    for (int i = 0; i < buffer_size; i++) {
        buffers.emplace_back(i, piece_length);
    }

    is_initialized = true;
};

memory_storage::~memory_storage() {
    std::cout << "Destroying memory storage" << std::endl;
}
