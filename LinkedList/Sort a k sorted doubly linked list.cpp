#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

struct compare
{
    bool operator()(struct node *first, struct node *second)
    {
        return first->data > second->data;
    }
};
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

void insertAtTail(node *&head, int val)
{

    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *sort( node *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    priority_queue<node *, vector<node *>, compare> pq;
     node *newHead = NULL, *curr;
    for (int i = 0; head != NULL and i <= k; i++)
    {
        pq.push(head);
        head = head->next;
    }
    while (!pq.empty())
    {
        if (newHead == NULL)
        {
            newHead = pq.top();
            newHead->prev = NULL;
            curr = newHead;
        }
        else
        {
            curr->next = pq.top();
            pq.top()->prev = curr;
            curr = pq.top();
        }
        pq.pop();
        if(head != NULL){
            pq.push(head);
            head = head-> next;
        }
    }
    curr-> next = NULL;
    return newHead;
}

int main()
{

    node *head = NULL;

    insertAtTail(head, 3);
    insertAtTail(head, 6);
    insertAtTail(head, 2);
    insertAtTail(head, 12);
    insertAtTail(head, 56);
    insertAtTail(head, 8);
    display(head);
    node * newHead = sort(head, 2);
    display(newHead);

    return 0;
}