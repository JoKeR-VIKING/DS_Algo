Node *skipMdeleteN(Node *head, int M, int N)
{
    if (M == 0)
        return NULL;
    if (N == 0)
        return head;
    
    Node* temp = head;
    int storeM = M, storeN = N;
    
    while (temp != NULL)
    {
        while (temp != NULL && M-- != 1)
            temp = temp -> next;
        
        if (!temp)
            break;
        
        Node* afterM = temp;
        temp = temp -> next;
        
        while (temp != NULL && N--)
            temp = temp -> next;
        
        afterM -> next = temp;
        
        M = storeM;
        N = storeN;
    }
    
    return head;
}
