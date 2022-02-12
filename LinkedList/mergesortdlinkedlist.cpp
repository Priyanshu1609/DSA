#include<bits/stdc++.h> 

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

node* merge(node* &head1, node* &head2){
    node* p1= head1;
    node* p2 = head2;
    node* dummyNode = new node(-1);
    node* p3 = dummyNode;
    while (p1!= NULL and p2 != NULL)
    {
        if(p1->data < p2->data){
            p3->next = p1;
            p1 = p1->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;

    }
    while (p1 != NULL)
    {
        p3-> next = p1;
        p1= p1->next;
        p3= p3->next;
    }
    while (p2 != NULL)
    {
        p3-> next = p2;
        p2= p2->next;
        p3= p3->next;
    }
    
    return dummyNode->next;
}

int main(){
    node * head1 = NULL;
    node* head2 = NULL;
    for (int i = 1; i <= 4; i+=2)
    {
        insertAtTail(head1, i);
    }
    for (int i = 2; i <= 3; i+=2)
    {
        insertAtTail(head2, i);
    }
    display(head1);
    display(head2);
    node* newHead  = merge(head1, head2);
    display(newHead);
    
    return 0;
}