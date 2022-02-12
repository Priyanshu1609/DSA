#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};



class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    Node* middle(Node * head, Node** head1 , Node** head2){
        if(head == NULL){
            return head ;
        }
        Node * slow = head;
        Node * fast = head;
        while(fast != NULL and fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        *head1 = head;
        *head2 = slow->next;
        slow-> next = NULL;

    }
    
    Node * merge(Node * head1, Node* head2){
        Node * ans = NULL;
        if(!head1) return head2;
        else if(!head2) return head1;
        
        if(head1-> data <= head2-> data){
            ans = head1;
            ans-> next = merge(head1-> next , head2);
        }
        else{
            ans = head2;
            ans -> next = merge(head2-> next , head1);
        }

        return ans;
    }
    
    
    Node* mergeSorting(Node** head) {
        
        Node * curr = *head;
        Node * head1 ;
        Node * head2 ;
        if(!curr or !curr->next ){
            return curr;
        }
        middle(curr, &head1 , &head2);
        mergeSorting(&head1);
        mergeSorting(&head2);
        *head = merge(head1 , head2);
    }
    Node* mergeSort(Node* head){
        mergeSorting(&head);
        return head;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
 
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    
    return 0;
}  // } Driver Code Ends