#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int key;
    Node *left;
    Node *right;

    Node(int v){
        key = v;
        left = NULL;
        right = NULL;
    }
}Node;

Node *insert(Node *r, int v)
{
    Node *t = new Node(v);
    if(r == NULL)
        return t;
    if(r->key > v)
        r->left = insert(r->left, v);
    else if(r->key <= v)
        r->right = insert(r->right, v);
    return r;
}

void inOrder(Node *r)
{
    if(r == NULL)
        return;
    inOrder(r->left);
    cout<<r->key<<" ";
    inOrder(r->right);
}

Node *search(Node *r, int v)
{
    if(r == NULL)
        return NULL;
    if(r->key == v)
        return r;
    if(r->key > v)
        return search(r->left, v);
    if(r->key < v)
        return search(r->right, v);
}

Node *findMin(Node *r)
{
    if(r == NULL)
        return NULL;
    if(r->left == NULL)
        return r;
    else return findMin(r->left);
}

Node *del(Node *r, int v)
{
    if(r == NULL)
        return NULL;
    else if(r->key > v)
        r->left = del(r->left, v);
    else if(r->key < v)
        r->right = del(r->right, v);
    else{
        if(r->left != NULL && r->right != NULL){
            Node *t = findMin(r->right);
            r->key = t->key;
            r->right = del(r->right, t->key);
        }else{
            Node *tmp = r;
            if(r->left == NULL)
                r = r->right;
            else r = r->left;
            delete tmp;
        }
    }
    return r;
}

// AVL

int height(Node *r, Node *p)
{
    if(p == NULL)
        return 0;
    int maxH = 0;
    int hleft = 0;
    int hright = 0;
    hleft = 1 + height(r, p->left);
    hright = 1 + height(r, p->right);
    maxH = hleft > hright ? hleft : hright;

    return maxH;
}

int balanceFactor(Node *r)
{
    return height(r, r->left) - height(r, r->right);
}

bool checkAVL(Node *r)
{
    if(r == NULL)
        return true;
    if(abs(height(r, r->left) - height(r, r->right)) > 1)
        return false;
    bool checkLeft = checkAVL(r->left);
    bool checkRight = checkAVL(r->right);
    return checkLeft && checkRight;
}

//Perform rotation
Node *leftRotation(Node *r)
{
    Node *p = r;
    Node *tp = p->right;
    p->right = tp->left;
    tp->left = p;
    return tp;
}

Node *rightRotation(Node *r)
{
    Node *p = r;
    Node *tp = p->left;
    p->left = tp->right;
    tp->right = p;
    return tp;
}

Node *LRRotation(Node *r)
{
    Node *p = r;
    Node *tp = p->left;
    Node *tp2 = p->left->right;

    p->left = tp2;
    tp->right = tp2->left;
    tp2->left = tp;
    tp2->right = p;
    return tp2;
}

Node *RLRotation(Node *r)
{
    Node *p = r;
    Node *tp = r->right;
    Node *tp2 = r->right->left;

    p->right = tp2;
    tp->left = tp2->right;
    tp2->right = tp;
    tp2->left = p;
    return tp2;
}

Node *insertAVL(Node *r, int v)
{
    Node *t = new Node(v);
    if(r == NULL)
        return t;
    if(r->key < v)
        r->right = insertAVL(r->right, v);
    else r->left = insertAVL(r->left, v);

    //Rotate
    if(balanceFactor(r) == 2 && balanceFactor(r->left) == 1)
        r = rightRotation(r);
    if(balanceFactor(r) == -2 && balanceFactor(r->right) == -1)
        r = leftRotation(r);
    if(balanceFactor(r) == 2 && balanceFactor(r->left) == -1)
        r = LRRotation(r);
    if(balanceFactor(r) == -2 && balanceFactor(r->right) == 1)
        r = RLRotation(r);

    return r;
}

Node *delAVL(Node *r, int v)
{
    if(r == NULL)
        return NULL;
    else if(r->key > v)
        r->left = delAVL(r->left, v);
    else if(r->key < v)
        r->right = delAVL(r->right, v);
    else{
        if(r->left != NULL && r->right != NULL){
            Node *tmp = findMin(r->right);
            r->key = tmp->key;
            r->right = del(r->right, tmp->key);
        }else{
            Node *tmp = r;
            if(r->left == NULL)
                r = r->right;
            else r = r->left;
            delete tmp;
        }
    }

    //Rotate
    if(balanceFactor(r) == 2 && balanceFactor(r->left) == 1)
        r = rightRotation(r);
    if(balanceFactor(r) == -2 && balanceFactor(r->right) == -1)
        r = leftRotation(r);
    if(balanceFactor(r) == 2 && balanceFactor(r->left) == -1)
        r = LRRotation(r);
    if(balanceFactor(r) == -2 && balanceFactor(r->right) == 1)
        r = RLRotation(r);

    return r;
}

int main()
{
    Node *r = new Node(20);
    r = insert(r, 10);
    r = insert(r, 26);
    r = insert(r, 7);
    r = insert(r, 15);
    r = insert(r, 23);
    r = insert(r, 30);
    r = insert(r, 3);
    r = insert(r, 8);

    inOrder(r);
    cout<<endl;
    cout<<checkAVL(r)<<endl;
    r = delAVL(r, 15);
    cout<<checkAVL(r);
}
