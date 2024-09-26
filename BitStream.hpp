/**
 * BitStream.hpp
 * 
 * Stella Zarei
 * V00927722
 *
 */

#include <iostream>
#include <vector>
#include <bitset>

class BitStream
{
public:

    /**
     * Constructor
     * Initialize the stream with the magic number
     */
    BitStream()
    {
        std::cout.put(0x1f);
        std::cout.put(0x9d);
        std::cout.put(0x90);
    }

    /**
     * Add a bit to the stream
     * If the stream is full (1 byte of data), flush it
     */
    void addBit(bool bit)
    {
        stream.push_back(bit);
        ++size_;

        if (size_ == 8)
        {
            flushStream();
        }
    }

    /**
     * Flush the stream
     * If the stream is not full (less than 1 byte of data), pad with 0s
     */
    void flushStream()
    {
        while (size_ < 8)
        {
            stream.push_back(0);
            ++size_;
        }

        std::bitset<8> bitset;
        for (int i = 0; i < 8; ++i)
        {
            bitset[i] = stream[i];
        }

        unsigned char byte = static_cast<unsigned char>(bitset.to_ulong());
        std::cout.put(byte);
        stream.clear();
        size_ = 0;
    }

private:
    // Current size of the stream (number of bits)
    int size_{0};
    // Stream of bits
    std::vector<bool> stream;
};