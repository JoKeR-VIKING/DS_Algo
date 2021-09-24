// Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
// Return -1 if x is not present in the given array.
// Note : If given array size is even, take first mid.
// Input format :

// Line 1 : Array size

// Line 2 : Array elements (separated by space)

// Line 3 : x (element to be searched)

// Sample Input :
// 6
// 2 3 4 5 6 8 
// 5 
// Sample Output:
// 3 

int helpSearch(int input[], int start, int end, int element)
{
    if (start > end)
        return -1;
    
    int mid = (start + end)/2;
    
    if (input[mid] == element)
        return mid;
    
    if (input[mid] > element)
        return helpSearch(input, start, mid-1, element);
    
    return helpSearch(input, mid+1, end, element);
}

int binarySearch(int input[], int size, int element)
{
    return helpSearch(input, 0, size-1, element);
}
