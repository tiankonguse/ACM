judge.cpp 是裁判程序
judge 程序需要调用三个文件
1. e.in 输入文件
2. e.out 将选手程序的输出
3. 相应的单词列表文件（在 e.in 中指出）

题目中需要注意的几点：
INPUT: The words in the dictionary may have both upper and lower case letters.  For this problem however, case is immaterial. 
OUTPUT: All the letters in every word should be in upper case. 
此外，输入文件虽然已经排好序，但是全部转换为大写字母后，不一定是排好序的。如果要利用排序的性质（比方说需要二分查找），则必须对单词表排序。