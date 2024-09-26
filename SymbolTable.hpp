/**
 * SymbolTable.hpp
 * 
 * Stella Zarei
 * V00927722
 * 
 */

#include <unordered_map>
#include <string>

class SymbolTable
{
public:

    /**
     * Constructor
     * Iniliaze the table with all 256 ASCII characters
     */
    SymbolTable()
    {
        for (uint16_t idx = 0; idx < 256; ++idx)
        {
            table_[std::string(1, char(idx))] = idx;
        }
    }

    /**
     * Adds a symbol to the table
     */
    void addSymbol(const std::string &symbol)
    {
        table_[symbol] = next_idx_;
        ++next_idx_;
    }

    /**
     * Check if the symbol is in the table
     */
    bool contains(const std::string &symbol) const
    {
        return table_.find(symbol) != table_.end();
    }

    /**
     * Get the index of the symbol
     */
    uint32_t getSymbolIndex(const std::string &symbol) const
    {
        auto result = table_.at(symbol);
        return result;
    }

    /**
     * Get the next index to insert
     */
    uint32_t getNextIndex() const
    {
        return next_idx_;
    }

private:
    // Next index to insert (256 reserved for the reset flag)
    uint32_t next_idx_{257};
    // Dictionary of (key: symbol , value: index)
    std::unordered_map<std::string, uint16_t> table_;
};
