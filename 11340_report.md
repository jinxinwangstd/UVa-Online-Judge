## Problem description

Given the values of some characters, calculate the total value of an essay (combination of all kinds of characters)

## Algorithm analysis

We need to build a mapping between each character and its value. Cause the characters can be viewed as distinct integers, we can use directed addressing table (DAT) instead of map class.
Then we just make a linear scan over the essay, sum up all the values of characters.
The time complexity is O(n) where n is the number characters in the essay.

## Knowledge base

1. Directed Addressing Table (DAT):
   This is a simple form of Hash Table that we can use in programming contest. The special property of DAT is that the keys itself are the indices, or their identities are the indices.
   For example, in this problem, the internal values of characters are the indices of DAT, and the number of different values are only 256, so we can use a small array to serve as DAT.
2. Use internal values of characters as indexing:
   The possible values of a char object is machine-dependent. Some are [0, 255], Others are [-128, 127]. The C standards guarantee that the printable character are always positive.
   In the UVaOJ platform, it seems that the machine is [-128, 127], so we need to use an offset of 128 to map the value range of char object to [0, 255] (all positive) to serve as array indices.