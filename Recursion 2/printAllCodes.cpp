// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
// Note : The order of codes are not important. Just print them in different lines.
// Input format :
// A numeric string S
// Output Format :
// All possible codes in different lines
// Constraints :
// 1 <= Length of String S <= 10
// Sample Input:
// 1123
// Sample Output:
// aabc
// kbc
// alc
// aaw
// kw

#include <string.h>
using namespace std;

void help(string input, string s)
{
    if (input == "")
    {
        cout<<s<<"\n";
        return;
    }
    
    string sub = s + (char)(input[0] - '0' + 96);
    help(input.substr(1), sub);
    
    if (input.length() > 1)
    {
        int check = (10*(input[0] - '0') + input[1] - '0');
        
        if (check < 27)
        {
        	sub = s + (char)(check + 96);
        	help(input.substr(2), sub);
        }
    }
}

void printAllPossibleCodes(string input)
{
    string s;
    
    help(input, s);
}

