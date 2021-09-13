#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    double a;
    int e;
    Node *next;
    Node(double ia, int ie){
        a = ia;
        e = ie;
        next = NULL;
    }
}Node;

Node *insert(Node *h, int a, int e)
{
    Node *tmp = new Node(a, e);
    if(h == NULL)
        return tmp;
    Node *p = h;
    while(p->next != NULL)
        p = p->next;
    p->next = tmp;
    return h;
}

int check(Node *h)
{
    if(h == NULL)
        return 0;
    Node *p = h;
    while(p->next != NULL){
        if(p->next->e > p->e)
            return 0;
        p = p->next;
    }
    return 1;
}

double eval(Node *h, int v)
{
    if(h == NULL)
        return 0;
    Node *p = h;
    double rs = 0;
    while(p != NULL){
        rs = rs + p->a * pow(v, p->e);
        p = p->next;
    }
    return rs;
}

Node *sum(Node *h1, Node *h2)
{
    Node *p1 = h1;
    Node *p2 = h2;

    Node *res = NULL;
    while(p1 != NULL && p2 != NULL){
        if(p1->e > p2->e){
            res = insert(res, p1->a, p1->e);
            p1 = p1->next;
        }else if(p1->e < p2->e){
            res = insert(res, p2->a, p2->e);
            p2 = p2->next;
        }else{
            res = insert(res, p1->a + p2->a, p1->e);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return res;
}

void printList(Node *h)
{
    Node *p = h;
    while(p != NULL){
        cout<<p->a<<"* x^"<<p->e<<" + ";
        p = p->next;
    }
}

int main()
{
    Node *h1 = new Node(3, 4);
    h1 = insert(h1, -2, 2);
    h1 = insert(h1, 4, 1);
    h1 = insert(h1, 5, 0);

    Node *h2 = new Node(2, 4);
    h2 = insert(h2, 3, 3);
    h2 = insert(h2, 3, 2);
    h2 = insert(h2, 3, 0);

    Node *res = sum(h1, h2);
    printList(res);
}
