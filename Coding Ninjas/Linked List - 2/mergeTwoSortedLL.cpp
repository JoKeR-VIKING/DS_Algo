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
