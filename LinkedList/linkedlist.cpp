#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{

    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deleteAtHead(node *&head)
{

    node *toDelete = head;
    head = head->next;

    delete toDelete;
}

void deletion(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        deleteAtHead(head);
    }

    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

node *reverse(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

node *reversek(node *&head, int k)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr = NULL;
    int count = 0;
    while (count < k and currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if (nextptr != NULL)
    {
        head->next = reversek(nextptr, k);
    }
    return prevptr;
}

bool detectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL and fast->next != NULL )
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast== slow)
        {
            return true;    
        }
        
    }
    return false;
}
void makeCycle (node* &head, int pos){
    node * temp = head;
    node* startNode;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count==pos)
        {
            startNode= temp;
        }
        temp = temp->next;
        count ++;
    }
    temp->next = startNode;
}
void removeCycle(node * &head){
    
    node *slow = head;
    node *fast = head;
    do
    {
        slow = slow-> next;
        fast = fast->next->next;

    } while (fast!=slow);
    fast = head;
    while (fast->next != slow->next)
    {
        slow = slow-> next;
        fast = fast-> next;
    }
    slow-> next = NULL;
}

int main()
{

    node *head = NULL;

    insertAtTail(head, 9);
    insertAtTail(head, 5);
    insertAtTail(head, 3);
    insertAtTail(head, 9);
    insertAtTail(head, 6);
    insertAtTail(head, 5);
    display(head);
    int k ; cin >> k;
    node* ans = reversek(head, k);
    display(ans);


    return 0;
}