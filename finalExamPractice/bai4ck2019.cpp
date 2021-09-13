#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int info;
    Node *next;
    Node *prev;
    Node(int v){
        info = v;
        next = NULL;
        prev = NULL;
    }
}Node;

void printList(Node *head)
{
    Node *p = head;
    while(p != NULL){
        cout<<p->info<<" ";
        p = p->next;
    }
}

Node *insert(Node *head, int v)
{
    Node *tmp = new Node(v);
    if(head == NULL)
        return tmp;
    if(v < head->info){
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
        return head;
    }
    Node *p = head;
    while(p->info < v && p->next != NULL)
        p = p->next;
    if(p->next == NULL && p->info < v){
        p->next = tmp;
        tmp->prev = p;
        return head;
    }else{
        p->prev->next = tmp;
        tmp->prev = p->prev;
        p->prev = tmp;
        tmp->next = p;
        return head;
    }
}

int main()
{
    Node *head = new Node(4);
    head = insert(head, 2);
    head = insert(head, 6);
    head = insert(head, 5);
    head = insert(head, 3);
    head = insert(head, 8);
    head = insert(head, 10);
    head = insert(head, 1);
    printList(head);
}
