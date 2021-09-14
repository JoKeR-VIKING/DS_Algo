// Check whether a given String S is a palindrome using recursion. Return true or false.
// Input Format :
// String S
// Output Format :
// 'true' or 'false'
// Constraints :
// 0 <= |S| <= 1000
// where |S| represents length of string S.
// Sample Input 1 :
// racecar
// Sample Output 1:
// true
// Sample Input 2 :
// ninja
// Sample Output 2:
// false

#include<string.h>

bool helpCheck(char input[], int i, int j)
{
    if (i >= j)
        return true;
    
    if (input[i] != input[j])
        return false;
    
    return helpCheck(input, i+1, j-1);
}

bool checkPalindrome(char input[]) 
{
    int i = 0, j = strlen(input) - 1;
    return helpCheck(input, i, j);
}
