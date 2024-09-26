# Overview

- An implementation of the compressor for the old Unix `compress` program in C++
- Resulting files can be uncompressed with the real `compress` decompressor

# Prodecure
- Compile the code using the provided `MakeFile`
- Compress files using the command `./uvcompress < input.txt > compressed.Z`
- Decompress files using the command `compress -d < compressed.Z > decompressed.txt`

# Features
- Produced bitstream is compatible with the `compress -d` command
- Symbol values begin at 9 bits and increase
- Input accepted from standard input (not read from a file)
- Ouput generated to standard output
- The ‘reset marker’ feature not  used anywhere in the generated bitstream
