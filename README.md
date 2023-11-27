# Huffman Encoding

> Encoding and decoding text files containing ASCII characters using Huffman Encoding

Group assignment - Program 5 for the course **CSCI 58000 (Algorithm Design, Analysis and Implementation)**\
Team 6: Ninad Deshpande, Sarth Kulkarni, Arushi Pandit, Aashay Phirke.

## Program parts
1. Generate character frequencies from the given text file.\
   **[clear.txt -> freq.txt]**
1. Generate Huffman codes from the character frequencies.\
   **[freq.txt -> codetable.txt]**
1. \
   a. Encode the original text file using the codetable storing codes as **strings**.\
   **[clear.txt -> codetable.txt -> coded.txt]**\
   b. Decode the coded text file using the codetable / Huffman tree.\
   **[coded.txt -> codetable.txt -> decoded.txt]**
1. \
   a. Encode the original text file using the codetable at **bit level**.\
   **[clear.txt -> codetable.txt -> codedalt.txt]**\
   b. Decode the coded-alt text file using the codetable / Huffman tree, reading **individual bits** from coded-alt.\
   **[codedalt.txt -> codetable.txt -> decodedalt.txt]**


