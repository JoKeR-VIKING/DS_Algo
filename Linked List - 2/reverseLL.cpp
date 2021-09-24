// Recursive

Node *reverseLinkedListRec(Node *head)
{
    if (head == NULL || head -> next == NULL)
        return head;
    
    Node* temp = reverseLinkedListRec(head -> next);
    
    head -> next -> next = head;
    head -> next = NULL;
    
    return temp;
}

// Iterative
Node *reverseLinkedList(Node *head)
{
    if (head == NULL)
        return head;
    
    Node* current = head;
    Node* prev = NULL;
    Node* next = head -> next;
    
    while (next != NULL)
    {
        current -> next = prev;
        prev = current;
        current = next;
        next = next -> next;
    }
    
    current -> next = prev;
    return current;
}
