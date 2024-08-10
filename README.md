

# Huffman Code

## Overview

The Huffman Coder is a simple implementation of Huffman Encoding and Decoding, which is a popular algorithm used for lossless data compression. This program takes an input string, compresses it using Huffman coding, and then decompresses it back to its original form.

## Features

- **Encoding:** Converts a given string into its compressed Huffman code representation.
- **Decoding:** Decompresses the encoded Huffman string back to its original form.

## How It Works

1. **Frequency Analysis:** Calculates the frequency of each character in the input string.
2. **Huffman Tree Construction:** Constructs a Huffman Tree based on character frequencies using a priority queue (min-heap).
3. **Encoding:** Creates a mapping of characters to their Huffman codes and encodes the input string.
4. **Decoding:** Uses the Huffman codes to decode the compressed string back to the original.


