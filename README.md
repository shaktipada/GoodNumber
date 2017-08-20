Given input n, find out the smallest good number with “n” digits.  A number is termed as good only if:
a. All the digits in it are just 1 or 2 or 3.
b. No two adjacent  substrings of the given number is same

Example for good numbers: 1 121 1213 1213121

Example for bad numbers: 11 1212 1221 1231231
11 is a bad number since 1 follows 1.
Similarly 1212 is bad because the substring “12” is present adjacent to the substring “12”
1221 is a bad number because the substring “2” follows “2”
1231231 is a bad number because the substring “123” is adjacent to substring “123” 

123132 is a good number because there are no two adjacent substrings repeating themselves. But given n=6, it is not the smallest 6-digit good number. The smallest 6-digit good number would be:
121312

Your program should find out the smallest n-digit good number where n is passed to it as a command line argument.
Your program would be invoked as:

find_good <n>
