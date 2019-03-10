## Problem description

Find the middle-value one among three integers

## Algorithm analysis

Scan each line (each test case) and sort the three integers, then output the middle one. The time complexity is O(n).

## Knowledge base

1. 本题是算法竞赛中另一种输入输出方式，输入依然是首行给出test case数量，输出中要对各个test case进行编号，解决方法就是利用一个局部变量记录当前test case编号。

   ```c++
   int caseNo = 1;
   while (caseNo <= n) {
       // ...
       ++caseNo;
   }
   ```

   

