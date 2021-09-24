// Given an array A of size n and an integer K, return all subsets of A which sum to K.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important.
// Input format :
// Line 1 : Integer n, Size of input array
// Line 2 : Array elements separated by space
// Line 3 : K 
// Constraints :
// 1 <= n <= 20
// Sample Input :
// 9 
// 5 12 3 17 1 18 15 3 17 
// 6
// Sample Output :
// 3 3
// 5 1

void help(int input[], int n, int output[][50], int k, int preSum[], int& i, int pos)
{
    if (k == 0)
    {
        output[i][0] = pos;
        int j = 1;
        for (int it=0;it<pos;it++)
        {
            output[i][j++] = preSum[it];
        }
        
        i++;
        return;
    }
    if (k < 0 || n == 0)
        return;
    
    help(input+1, n-1, output, k, preSum, i, pos);
    preSum[pos] = input[0];
    help(input+1, n-1, output, k - input[0], preSum, i, pos + 1);
}

int subsetSumToK(int input[], int n, int output[][50], int k)
{
    int preSum[50];
    int i = 0;
    help(input, n, output, k, preSum, i, 0);
    
    return i;
}
