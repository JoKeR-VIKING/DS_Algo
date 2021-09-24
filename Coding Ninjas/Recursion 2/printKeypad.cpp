// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
// Note : The order of strings are not important. Just print different strings in new lines.
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

#include <iostream>
#include <string>
using namespace std;

string arr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void helpPrint(int num, string s)
{
    if (num == 0)
    {
        cout<<s<<"\n";
        return;
	}
    
    int size = arr[num%10].length();
    
    for (int i=0;i<size;i++)
    {
        string sub = arr[num % 10][i] + s;
        helpPrint(num / 10, sub);
    }
}

void printKeypad(int num)
{
    string s;
    
    helpPrint(num, s);
}
