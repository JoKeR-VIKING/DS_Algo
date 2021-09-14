// Sort an array A using Quick Sort.
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
// 1 5 2 7 3
// Sample Output 2 :
// 1 2 3 5 7 

void quickSort(int input[], int start, int end)
{
    if (start >= end)
        return;
    
    int current = input[start], minNo = start;
    
    for (int i=start+1;i<end;i++)
    {
        if (input[i] < current)
            minNo++;
    }
    
    int temp = input[minNo];
    input[minNo] = current;
    input[start] = temp;
    
    int i = start, j = minNo + 1;
    
    while (i < minNo && j < end)
    {
        if (input[i] < current && input[j] >= current)
        {
            i++;
            j++;
        }
        else if (input[i] < current)
        {
            i++;
        }
        else if (input[j] >= current)
        {
            j++;
        }
        else
        {
            temp = input[i];
    		input[i] = input[j];
    		input[j] = temp;
            
            i++;
            j++;
        }
    }
    
    quickSort(input, start, minNo);
    quickSort(input, minNo + 1, end);
}

void quickSort(int input[], int size)
{
    int start = 0, end = size;
    
    quickSort(input, start, end);
}
