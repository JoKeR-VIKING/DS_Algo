// Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).
// Note: You don't need to print the elements, just update the elements and return the head of updated LL.
// Input Constraints:
// 1 <= Length of Linked List <=10^6.
// Input format :
// Line 1 : Linked list elements (separated by space and terminated by -1)
// Output Format :
// Line 1: Updated linked list elements 
// Sample Input 1 :
// 3 9 2 5 -1
// Sample Output 1 :
// 3 9 2 6
// Sample Input 2 :
// 9 9 9 -1
// Sample Output 1 :
// 1 0 0 0 

Node* NextLargeNumber(Node *head, int& carry)
{
    if (head -> next == NULL)
    {
        if (head -> data + 1 > 9)
        {
            head -> data = 0;
            carry = 1;
        }
        else
            head -> data += 1;
        
    	return head;
    }
    
    NextLargeNumber(head -> next, carry);
    
    if (carry)
    {
        if (head -> data + 1 > 9)
            head -> data = 0;
        else
        {
            carry = 0;
       		head -> data += 1;
    	}
    }
    
    return head;
}

Node* NextLargeNumber(Node *head)
{
    int carry = 0;
    head = NextLargeNumber(head, carry);
    
    if (carry)
    {
        Node* newNode = new Node(1);
        newNode -> next = head;
        return newNode;
    }
    
    return head;
}
