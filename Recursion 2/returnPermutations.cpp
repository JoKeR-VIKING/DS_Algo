// Given a string S, find and return all the possible permutations of the input string.
// Note 1 : The order of permutations is not important.
// Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
// Input Format :
// String S
// Output Format :
// All permutations (in different lines)
// Sample Input :
// abc
// Sample Output :
// abc
// acb
// bac
// bca
// cab
// cba

#include <string>
using namespace std;

void returnPermutations(string input, string output[], int start, int& pos)
{
    if (start == input.length())
    {
        output[pos++] = input;
        return;
    }
    
    for (int i=start;i<input.length();i++)
    {
        swap(input[start], input[i]);
        returnPermutations(input, output, start+1, pos);
        swap(input[start], input[i]);
    }
}

int returnPermutations(string input, string output[])
{
    int pos = 0;
    returnPermutations(input, output, 0, pos);
    
    return pos;
}
