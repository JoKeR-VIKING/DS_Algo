// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
// Note : The order of codes are not important. And input string does not contain 0s.
// Input format :
// A numeric string
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

void getCodes(string input, string output[10000], string temp, int& pos)
{
    if (input == "")
    {
        output[pos++] = temp;
        return;
    }
    
    char ch = (input[0] - '0' + 'a' - 1);
	getCodes(input.substr(1), output, temp + ch, pos);
    
    if (input.length() > 1)
    {
    	ch = (input[0] - '0') * 10 + (input[1] - '0');
    	ch += 'a' - 1;
    
        if (ch >= 97 && ch <= 122)
        	getCodes(input.substr(2), output, temp + ch, pos);
    }
    
}

int getCodes(string input, string output[10000])
{
    int pos = 0;
    getCodes(input, output, "", pos);
    
    return pos;
}

