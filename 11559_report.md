## Problem description

Given a set of tuples which indicating the price and available beds for a hotel, find the one tuple with smallest prices and enough beds for certain number of people. If there are two hotel has the same prices, choose the firstly appeared one.

## Algorithm analysis

Record the lowest price of the hotel satisfying capacity condition. Scan each hotel's parameters, if it is lower than the chosen one, replace the chose one with this hotel.
Suppose the number of hotels is n, the time complexity is O(n)

## Knowledge base

