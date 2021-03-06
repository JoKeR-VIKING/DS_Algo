// You need to implement a class for Dequeue i.e. for double ended queue. In this queue, elements can be inserted and deleted from both the ends.
// You don't need to double the capacity.
// You need to implement the following functions -
// 1. constructor
// You need to create the appropriate constructor. Size for the queue passed is 10.
// 2. insertFront -
// This function takes an element as input and insert the element at the front of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
// 3. insertRear -
// This function takes an element as input and insert the element at the end of queue. Insert the element only if queue is not full. And if queue is full, print -1 and return.
// 4. deleteFront -
// This function removes an element from the front of queue. Print -1 if queue is empty.
// 5. deleteRear -
// This function removes an element from the end of queue. Print -1 if queue is empty.
// 6. getFront -
// Returns the element which is at front of the queue. Return -1 if queue is empty.
// 7. getRear -
// Returns the element which is at end of the queue. Return -1 if queue is empty.
// Input Format:
// For C++ and Java, input is already managed for you. You just have to implement given functions.

// For Python:
// The choice codes and corresponding input for each choice are given in a new line. The input is terminated by integer -1. The following table elaborately describes the function, their choice codes and their corresponding input - 
// Alt Text

// Output Format:
// For C++ and Java, output is already managed for you. You just have to implement given functions.

// For Python: 
// The output format for each function has been mentioned in the problem description itself. 
// Sample Input 1:
// 5
// 1
// 49
// 1
// 64
// 2
// 99
// 5
// 6
// -1
// Sample Output 1:
// -1
// 64
// 99
// Explanation:
// The first choice code corresponds to getFront. Since the queue is empty, hence the output is -1. 
// The following input adds 49 at the top and the resultant queue becomes: 49.
// The following input adds 64 at the top and the resultant queue becomes: 64 -> 49
// The following input add 99 at the end and the resultant queue becomes: 64 -> 49 -> 99
// The following input corresponds to getFront. Hence the output is 64.
// The following input corresponds to getRear. Hence the output is 99.

/**********
 
 Following is the main function we are using internally.
 Refer this for completing the Dequeue class.
 
 
 int main()
 {
 Deque dq(10);
 int choice,input;
 while(true) {
 cin >> choice;
 switch (choice) {
 case 1:
 cin >> input;
 dq.insertfront(input);
 break;
 case 2:
 cin >> input;
 dq.insertrear(input);
 break;
 case 3:
 dq.deletefront();
 break;
 case 4:
 dq.deleterear();
 break;
 case 5:
 cout << dq.getFront() << "\n";
 break;
 case 6:
 cout << dq.getRear() << "\n";
 break;
 default:
 return 0;
 }
 }
 
 return 0;
 }
 
 ************/
class Node
{
public:
    int data;
    Node* next;
    
    Node(int data)
    {
        this -> data = data;
        next = NULL;
    }
};

class Deque
{
private:
    Node* head;
    Node* tail;
    int size;
public:
    Deque(int size)
    {
        head = NULL;
        tail = NULL;
        this -> size = size;
    }
    
    void insertFront(int data)
    {
        if (size == 0)
        {
            cout<<-1<<"\n";
            return;
        }
        
        size--;
        Node* newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = head;
            return;
        }
        
        newNode -> next = head;
        head = newNode;
    }
    
    void insertRear(int data)
    {
        if (size == 0)
        {
            cout<<-1<<"\n";
            return;
        }
        
        size--;
        Node* newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = head;
            return;
        }
        
        tail -> next = newNode;
        tail = tail -> next;
    }
    
    void deleteFront()
    {
        if (head == NULL)
        {
            cout<<-1<<"\n";
            return;
        }
        
        head = head -> next;
        size++;
    }
    
    void deleteRear()
    {
        if (head == NULL)
        {
            cout<<-1<<"\n";
            return;
        }
        
        size++;
        
        if (head -> next == NULL)
        {
            head = NULL;
            return;
    	}
        
        Node* temp = head;
        
        while (temp -> next != tail)
        {
            temp = temp -> next;
        }
        
        temp -> next = NULL;
        tail = temp;
    }
    
    int getFront()
    {
        if (head == NULL)
            return -1;
        
        return head -> data;
    }
    
    int getRear()
    {
        if (head == NULL)
            return -1;
        
        return tail -> data;
    }
};
