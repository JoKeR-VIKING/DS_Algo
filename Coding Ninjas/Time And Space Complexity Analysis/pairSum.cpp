// You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.
// Note:
// Given array/list can contain duplicate elements. 
// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// First line of each test case or query contains an integer 'N' representing the size of the first array/list.

// Second line contains 'N' single space separated integers representing the elements in the array/list.

// Third line contains an integer 'num'.
// Output format :
// For each test case, print the total number of pairs present in the array/list.

// Output for every test case will be printed in a separate line.
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^4
// 0 <= num <= 10^9

// Time Limit: 1 sec
// Sample Input 1:
// 1
// 9
// 1 3 6 2 5 4 3 2 4
// 7
// Sample Output 1:
// 7
// Sample Input 2:
// 2
// 9
// 1 3 6 2 5 4 3 2 4
// 12
// 6
// 2 8 10 5 -2 5
// 10
// Sample Output 2:
// 0
// 2


//  Explanation for Input 2:
// Since there doesn't exist any pair with sum equal to 12 for the first query, we print 0.

// For the second query, we have 2 pairs in total that sum up to 10. They are, (2, 8) and (5, 5).

void mergeSort(int *arr, int start, int end)
{
    if (start >= end)
        return;
    
    int mid = (start + end)/2;
    
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    
    int i=start,j=mid+1,current=0;
    int temp[end-start+1];
    
    while (i != mid+1 || j != end+1)
    {
        if (i == mid+1)
        {
            temp[current] = arr[j];
            j++;
        }
        else if (j == end+1)
        {
            temp[current] = arr[i];
            i++;
        }
        else if (arr[i] < arr[j])
        {
            temp[current] = arr[i];
            i++;
        }
        else
        {
            temp[current] = arr[j];
            j++;
        }
        
        current++;
    }
    
    current = 0;
    
    for (int i=start;i<=end;i++)
    {
        arr[i] = temp[current++];
    }
}

int pairSum(int *arr, int n, int num)
{
    int count = 0,i=0,j=n-1,s_c=0,e_c=0,k,l;
    mergeSort(arr, 0, n-1);
    
    if(arr[0]==arr[n-1])
    {
        return (n*(n-1))/2;
    }
    
    while (i < j)
    {
        s_c = 0;
        e_c = 0;
        if (arr[i] + arr[j] > num)
        {
            j--;
        }
        else if (arr[i] + arr[j] < num)
        {
            i++;
        }
        else
        {
            k = arr[i];
            l = arr[j];
            while ((arr[i] == k || arr[j] == l) && i <= j)
            {
                if (arr[i] == k)
                {
                    s_c++;
                    i++;
                }
                if (arr[j] == l)
                {
                    e_c++;
                    j--;
                }
            }
            
            count += s_c*e_c;
        }
    }
    
    return count;
}
