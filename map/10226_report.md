## Problem description

Given a sequence of string, determine the percentage each string appeared in the whole sequence.

## Algorithm analysis

Use a map to record the appearance of each string.
The total time complexity is O(nlogn).

## Knowledge base

1. The parameter of the setprecision() function denotes the number of decimal bits in a floating-point number, not the number of decimal part bits.

2. The format string ""%s" in a printf() function can only be replaced with a C string, not the C++ string object.
   The reason is that printf() simply replace the %s with the address of the first character in a C string and print the following characters until null character. But the C++ string object is not an array of character like C string.

3. How to detect the blank line between test cases?
   Usually the blank line would contain only one newline character ('\n'), but occasionally there may be other blank character inside it, like spaces, tabs, etc. Basically now I have two ways to handle the blank line in the input:

   1. Using getline() and string object in C++:

      ```c++
      while (getline(cin, s)) {
          if (s.compare(""))
          	break;
          // ...
      }
      ```

      One thing to notify in this method is that getline() will discard the delimiter, in our case the newline character. So after reading the input, we will get a empty string object. It is truly empty, not like the empty C string which actually have one character left, so we cannot use any character manipulating function to check it (that's where I made mistakes in this problem: I use isalpha(s[0]) to check the first character in an empty C++ string)

   2. Using fgets() and C string:

      ```c++
      while (fgets(buffer, sizeof(buffer), stdin) && isalnum(buffer[0])) {
          // ...
      }
      ```

      This method is more robust because you can just read in the whole line and check the first element in the C string is not meaningful, like not alphanumeric. Using fgets() would guarantee the buffer has at least one character, which is easier to handle.