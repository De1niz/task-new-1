#pragma once
#include <array>

template <typename T, size_t maxSize>
class CircularBuffer
{
private:
    std::array<T, maxSize> buffer{};
    size_t firstToRead;
    size_t firstFree;
    size_t count = 0;

public:
    CircularBuffer() noexcept
    {
       firstToRead = 0;
       firstFree = 0;
       count = 0;

    }
    size_t size() const noexcept 
    {
        return count;

    }

    bool push(T const& v) noexcept 
    {
        if (count == maxSize) {
            return false;

        }

        buffer[firstFree] = v;
        firstFree = (firstFree + 1) % maxSize;
        count++;

        return true;

    }

    bool pop(T& out) noexcept 
    {
        if (count == 0) {
            return false;

        }

        out = buffer[firstToRead];
        firstToRead = (firstToRead + 1) % maxSize;
        count--;

        return true;

    }

};
