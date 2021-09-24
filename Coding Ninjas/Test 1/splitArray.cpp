// Given an integer array A of size N, check if the input array can be splitted in two parts such that -
// - Sum of both parts is equal
// - All elements in the input, which are divisible by 5 should be in same group.
// - All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
// - Elements which are neither divisible by 5 nor by 3, can be put in any group.
// Groups can be made with any set of elements, i.e. elements need not to be continuous. And you need to consider each and every element of input array in some group.
// Return true, if array can be split according to the above rules, else return false.
// Note : You will get marks only if all the test cases are passed.
// Input Format :
// Line 1 : Integer N (size of array)
// Line 2 : Array A elements (separated by space)
// Output Format :
// true or false
// Constraints :
// 1 <= N <= 50
// Sample Input 1 :
// 2
// 1 2
// Sample Output 1 :
// false
// Sample Input 2 :
// 3
// 1 4 3
// Sample Output 2 :
// true

bool help(int* input, int size, int sum1, int sum2)
{
    if (size == 0)
        return sum1 == sum2;
    
    if (input[0] % 5 == 0)
    {
        return help(input+1, size-1, sum1 + input[0], sum2);
    }
    else if (input[0] % 3 == 0)
    {
        return help(input+1, size-1, sum1, sum2 + input[0]);
    }
    else
    {
        return help(input+1, size-1, sum1 + input[0], sum2) || help(input+1, size-1, sum1, sum2 + input[0]);
    }
}

bool splitArray(int *input, int size)
{
    return help(input, size, 0, 0);
}
