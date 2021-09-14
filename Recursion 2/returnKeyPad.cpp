// Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
// Return empty string for numbers 0 and 1.
// Note : 1. The order of strings are not important.
// 2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
// Input Format :
// Integer n
// Output Format :
// All possible strings in different lines
// Constraints :
// 1 <= n <= 10^6
// Sample Input:
// 23
// Sample Output:
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf

#include <bits/stdc++.h>
using namespace std;

string m[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void help(string output[], string s, int num, int& i)
{
    if (num == 0)
    {
        output[i++] = s;
        return;
    }
    
    int size = m[(num % 10)].length();
    
    for (int j=0;j<size;j++)
    {
        string sub = m[num % 10][j] + s;
        help(output, sub, num/10, i);
    }
}

int keypad(int num, string output[])
{
    int i = 0;
    string s;
    
    help(output, s, num, i);
    
    return i;
}
