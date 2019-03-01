## Problem description

Given a set of tuples which indicating the name, the number of requirements met, and the price. Find the one with the maximum number of requirements met; if there are several, find the one with the lowest price; if there are still several, find the firstly appeared one

## Algorithm analysis

Record the best tuple we have ever found. Scan each tuple, comparing it with our chosen one, if it is better in number of requirements met or equivalent with better price, replace the chosen one with this tuple.
Suppose the number of tuples are n, the time complexity is O(n)

## Knowledge base

1. 本题是算法竞赛中另一种输入输出方式。输出中不仅要求对每个test case进行编号，两个test case输出之间还要有空行，这也意味着最后一个test case后不能有多余的空行。因此我们在每个test case输出之前都要检查是不是第一个test case，如果不是就要先输出一个空行来隔开自己与上一个test case

   ```c++
   int caseNo = 1;
   while (caseNo <= n) {
       printf("%s", caseNo == 1 ? "" : "\n");
       // ...
       ++caseNo;
   }
   ```

2. scanf()读取输入截止到空白字符前；
   fgets()读取输入到delimiter character或者null character，并且会包含delimiter character。
   所以假如某个字符串占一行但中间没有空白字符，可以使用scanf()读入；
   如果包含空白字符，一定要用fgets()读入。
   在读题时也要注意，看到字符信息就想到字符串，然后就要注意是否包含空白字符。
3. strcpy()会将source string中所有字符包括null character都复制到destination string中去。