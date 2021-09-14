// Sort an array A using Merge Sort.
// Change in the input array itself. So no need to return or print anything.
// Input format :
// Line 1 : Integer n i.e. Array size
// Line 2 : Array elements (separated by space)
// Output format :
// Array elements in increasing order (separated by space)
// Constraints :
// 1 <= n <= 10^3
// Sample Input 1 :
// 6 
// 2 6 8 5 4 3
// Sample Output 1 :
// 2 3 4 5 6 8
// Sample Input 2 :
// 5
// 2 1 5 2 3
// Sample Output 2 :
// 1 2 2 3 5 

void mergeFunc(int input[], int start, int mid, int end)
{
    int i = start, j = mid+1, curr = 0;
    int output[end - start + 1];
    
    while (i <= mid && j <= end)
    {
        if (input[i] < input[j])
            output[curr++] = input[i++];
        else
            output[curr++] = input[j++];
    }
    
    while (i <= mid)
        output[curr++] = input[i++];
    
    while (j <= end)
        output[curr++] = input[j++];
    
    for (int k=start;k<=end;k++)
        input[k] = output[k - start];
}

void sortFunc(int input[], int start, int end)
{
    if (start == end)
        return;
    
    int mid = (start+end)/2;
    
    sortFunc(input, start, mid);
    sortFunc(input, mid+1, end);
    
    mergeFunc(input, start, mid, end);
}

void mergeSort(int input[], int size)
{
    int start = 0, end = size-1;
    
    sortFunc(input, start, end);
}
