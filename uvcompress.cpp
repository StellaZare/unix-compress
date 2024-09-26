/* uvcompress.cpp
   CSC 485B/CSC 578B

   Stella Zarei
   V00927722

   B. Bird - 2023-05-01
*/

#include <iostream>
#include <string>
#include <vector>

#include "SymbolTable.hpp"
#include "BitStream.hpp"

int main()
{
    // Initialize the symbol table and the bit stream
    SymbolTable symbolTable;
    BitStream stream;

    // Symbols are 9 bits long to start
    int num_bits {9};
    const int max_bits {16};

    // To start, the augmented and working strings are empty
    char c {};
    std::string augmented {""};
    std::string working {""};

    while (std::cin.get(c))
    {
        std::string current {c};

        augmented = working + current;

        if (symbolTable.contains(augmented))
        {
            working = augmented;
        }
        else if (symbolTable.getNextIndex() >= (1 << max_bits))
        {
            uint32_t index = symbolTable.getSymbolIndex(working);
            std::bitset<max_bits> binary{index};
            std::string binaryString = binary.to_string();

            for (int idx = max_bits - 1; idx >= max_bits - num_bits; --idx)
            {
                stream.addBit(binaryString[idx] == '1'); // Convert char '1'/'0' to bool
            }
            working = current;
        }
        else
        {
            symbolTable.addSymbol(augmented);
            uint32_t index = symbolTable.getSymbolIndex(working);
            std::bitset<max_bits> binary{index};
            std::string binaryString = binary.to_string();

            for (int idx = max_bits - 1; idx >= max_bits - num_bits; --idx)
            {
                stream.addBit(binaryString[idx] == '1'); // Convert char '1'/'0' to bool
            }

            working = current;
            if (symbolTable.getNextIndex() > (1U << num_bits))
            {
                ++num_bits;
            }
        }
    }

    if (!working.empty())
    {
        uint32_t index = symbolTable.getSymbolIndex(working);
        std::bitset<max_bits> binary{index};
        std::string binaryString = binary.to_string();

        for (int idx = max_bits - 1; idx >= max_bits - num_bits; --idx)
        {
            stream.addBit(binaryString[idx] == '1'); // Convert char '1'/'0' to bool
        }
    }

    stream.flushStream();

    return 0;
}