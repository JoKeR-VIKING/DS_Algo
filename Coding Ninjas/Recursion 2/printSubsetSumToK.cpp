// Given an array A and an integer K, print all subsets of A which sum to K.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important. Just print them in different lines.
// Input format :
// Line 1 : Size of input array
// Line 2 : Array elements separated by space
// Line 3 : K 
// Sample Input:
// 9 
// 5 12 3 17 1 18 15 3 17 
// 6
// Sample Output:
// 3 3
// 5 1

#include<bits/stdc++.h>

void help(int input[], int size, int k, vector<int> vect)
{
    if (k == 0)
    {
        for (auto& it : vect)
            cout<<it<<" ";
        
        cout<<"\n";
        return;
    }
    
    if (size == 0 || k < 0)
        return;
    
    help(input+1, size-1, k, vect);
    vect.push_back(input[0]);
    help(input+1, size-1, k - input[0], vect);
}

void printSubsetSumToK(int input[], int size, int k)
{
    vector<int> vect;
    
    help(input, size, k, vect);
}
