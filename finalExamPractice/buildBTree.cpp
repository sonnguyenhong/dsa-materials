#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    char c;
    Node *left;
    Node *right;

    Node(char ic){
        c = ic;
        left = NULL;
        right = NULL;
    }
}Node;

Node *insert(Node *h, Node *p, char v)
{
    if(p->left != NULL && p->right != NULL)
        return h;
    Node *tmp = new Node(v);
    if(p->left == NULL)
        p->left = tmp;
    else p->right = tmp;

    return h;
}

Node *find(Node *h, char c)
{
    if(h == NULL)
        return NULL;
    if(h->c == c)
        return h;
    Node *cl = find(h->left, c);
    Node *cr = find(h->right, c);
    if(cl == NULL && cr == NULL)
        return NULL;
    if(cl != NULL)
        return cl;
    if(cr != NULL)
        return cr;
}

void inOrder(Node *h)
{
    if(h == NULL)
        return;
    inOrder(h->left);
    cout<<h->c<<" ";
    inOrder(h->right);
}

void preOrder(Node *h)
{
    if(h == NULL)
        return;
    cout<<h->c<<" ";
    preOrder(h->left);
    preOrder(h->right);
}

void postOrder(Node *h)
{
    if(h == NULL)
        return;
    postOrder(h->left);
    postOrder(h->right);
    cout<<h->c<<" ";
}

int main()
{
    Node *h = new Node('A');
    h = insert(h, h, 'B');
    h = insert(h, h, 'C');

    Node *tmp = find(h, 'B');
    h = insert(h, tmp, 'D');
    //h = insert(h, tmp, 'E');

    //tmp = find(h, 'C');
    //h = insert(h, tmp, 'F');
    //h = insert(h, tmp, 'G');

    inOrder(h);
    cout<<endl;
    preOrder(h);
    cout<<endl;
    postOrder(h);
    cout<<endl;
}
