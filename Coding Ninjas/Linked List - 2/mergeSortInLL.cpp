Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    
    if (head1 -> data < head2 -> data)
    {
        head1 -> next = mergeTwoSortedLinkedLists(head1 -> next, head2);
        return head1;
    }
    
    head2 -> next = mergeTwoSortedLinkedLists(head1, head2 -> next);
    return head2;
}

Node* findMid (Node* head)
{
    Node* slow = head;
    Node* fast = head -> next;
    
    while (fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
	}
    
    return slow;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head -> next == NULL)
        return head;
    
    Node* mid = findMid(head);
    Node* temp = mid -> next;
    mid -> next = NULL;
    
    Node* head1 = mergeSort(head);
    Node* head2 = mergeSort(temp);
    
    head1 = mergeTwoSortedLinkedLists(head1, head2);
    
    return head1;
}
