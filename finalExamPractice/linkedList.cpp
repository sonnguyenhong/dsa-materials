#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int key;
    Node *next;
}Node;

void printList(Node *h)
{
    Node *p = h;
    while(p != NULL){
        cout<<p->key<<" ";
        p = p->next;
    }
}

Node *findLast(Node *h)
{
    Node *p = h;
    if(p == NULL)
        return NULL;
    while(p->next != NULL)
        p = p->next;
    return p;
}

Node *makeNode(int x)
{
    Node *tmp = new Node();
    tmp->key = x;
    tmp->next = NULL;
    return tmp;
}

Node *insertAfter(Node *h, Node *p, int x)
{
    if(p == NULL)
        return h;
    Node *tmp = makeNode(x);
    if(h == NULL)
        return tmp;
    tmp->next = p->next;
    p->next = tmp;
    return h;
}

Node *insertLast(Node *h, int x)
{
    Node *p = h;
    Node *tmp = makeNode(x);
    if(h == NULL)
        return tmp;
    while(p->next != NULL)
        p = p->next;
    p->next = tmp;
    return h;
}

Node *locate(Node *h, int x)
{
    Node *p = h;
    while(p != NULL){
        if(p->key == x)
            return p;
        p = p->next;
    }
    return NULL;
}

Node *prev(Node *h, Node *p)
{
    Node *tmp = h;
    while(tmp != NULL){
        if(tmp->next == p)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

Node *insertAt(Node *h, Node *p, int x)
{
    if(p == NULL)
        return h;
    Node *tmp = makeNode(x);
    Node *q = h;
    if(q == p){
        return tmp;
    }
    while(q->next != p){
        q = q->next;
    }
    q->next = tmp;
    return h;
}

Node *insertAtRecursive(Node *h, Node *p, int x)
{
    if(p == NULL)
        return h;
    if(h == NULL || p == h)
        return makeNode(x);
    else{
        h->next = insertAtRecursive(h->next, p, x);
        return h;
    }
}

Node *remove(Node *h, Node *p)
{
    Node *tmp = h;
    if(p == tmp){
        h = h->next;
        delete p;
        return h;
    }
    while(tmp->next != p){
        tmp = tmp->next;
    }
    tmp->next = p->next;
    return h;
}

Node *removeRecursive(Node *h, Node *p)
{
    if(h == NULL || p == NULL)
        return h;
    if(h == p){
        h = h->next;
        delete p;
        return h;
    }
    else{
        h->next = removeRecursive(h->next, p);
        return h;
    }
}

int sum(Node *h)
{
    if(h == NULL)
        return 0;
    return h->key + sum(h->next);
}

int main()
{
    Node *h = makeNode(1);
    h = insertLast(h, 2);
    h = insertLast(h, 3);
    h = insertLast(h, 4);
    h = insertLast(h, 5);
    h = insertLast(h, 6);
    //printList(h);
    Node *p = h;
    while(p->key != 3)
        p = p->next;



    Node *last = findLast(h);
    h = removeRecursive(h, p);
    printList(h);
    cout<<endl;
    cout<<sum(h);
}
