#include<bits/stdc++.h>

using namespace std;

typedef struct Node{
    int x;
    int y;
    Node *next;
    Node *prev;

    Node(int ix, int iy){
        x = ix;
        y = iy;
        next = NULL;
        prev = NULL;
    }
}Node;

typedef struct Queue{
    Node *head;
    Node *tail;
    Queue(){
        head = NULL;
        tail = NULL;
    }

    void enqueue(Node *v){
        Node *tmp = new Node(v->x, v->y);
        if(head == NULL && tail == NULL){
            head = tmp;
            tail = tmp;
        }
        tail->prev = tmp;
        tmp->next = tail;
        tail = tmp;
    }

    Node* dequeue(){
        if(isEmpty())
            return NULL;
        Node *tmp = head;
        head = head->prev;
        return tmp;
    }

    bool isEmpty(){
        return head == NULL && tail == NULL;
    }
}Queue;

Queue *q = new Queue();
Node *start;
bool visited[1000][1000];   //if visited[a][b] == true -> da duoc tham
int a = 6;
int b = 8;
int c = 4;

void init()
{
    for(int i = 0 ; i < 1000 ; i++)
        for(int j = 0 ; j < 1000 ; j++)
            visited[i][j] = false;
}

bool isFinal(Node *p)
{
    return p->x == c || p->y == c || p->x + p->y == c;
}

bool fillJug1(Node *p)
{
    if(visited[a][p->y])
        return false;
    Node *tmp = new Node(a, p->y);
    q->enqueue(tmp);
    visited[tmp->x][tmp->y] = true;
    if(isFinal(tmp))
        return true;
    return false;
}

bool fillJug2(Node *p)
{
    if(visited[p->x][b])
        return false;
    Node *tmp = new Node(p->x, b);
    q->enqueue(tmp);
    visited[tmp->x][tmp->y] = true;
    if(isFinal(tmp))
        return true;
    return false;
}

bool pour1to2(Node *p)
{
    if(p->x + p->y > b){
        if(visited[p->x + p->y - b][b])
            return false;
        Node *tmp = new Node(p->x + p->y - b, b);
        q->enqueue(tmp);
        visited[tmp->x][tmp->y] = true;
        if(isFinal(tmp))
            return true;
        return false;
    }else{
        if(visited[0][p->x + p->y])
            return false;
        Node *tmp = new Node(0, p->x + p->y);
        q->enqueue(tmp);
        visited[tmp->x][tmp->y] = true;
        if(isFinal(tmp))
            return true;
        return false;
    }
}

bool pour2to1(Node *p)
{
    if(p->x + p->y > a){
        if(visited[a][p->x + p->y - a])
            return false;
        Node *tmp = new Node(a, p->x + p->y - a);
        q->enqueue(tmp);
        visited[tmp->x][tmp->y] = true;
        if(isFinal(tmp))
            return true;
        return false;
    }else{
        if(visited[p->x + p->y][0])
            return false;
        Node *tmp = new Node(p->x + p->y, 0);
        q->enqueue(tmp);
        visited[tmp->x][tmp->y] = true;
        if(isFinal(tmp))
            return true;
        return false;
    }
}

bool emptyJug1(Node *p)
{
    if(visited[0][p->y])
        return false;
    Node *tmp = new Node(0, p->y);
    q->enqueue(tmp);
    visited[tmp->x][tmp->y] = true;
    if(isFinal(tmp))
        return true;
    return false;
}

bool emptyJug2(Node *p)
{
    if(visited[p->x][0])
        return false;
    Node *tmp = new Node(p->x, 0);
    q->enqueue(tmp);
    visited[tmp->x][tmp->y] = true;
    if(isFinal(tmp))
        return true;
    return false;
}

bool solve(int a, int b, int c)
{
    start = new Node(0, 0);
    q->enqueue(start);
    visited[0][0] = true;
    while(!q->isEmpty()){
        Node *tmp = q->dequeue();
        bool isOK = fillJug1(tmp);
        if(isOK)    return true;
        isOK = fillJug2(tmp);
        if(isOK)    return true;
        isOK = pour1to2(tmp);
        if(isOK)    return true;
        isOK = pour2to1(tmp);
        if(isOK)    return true;
        isOK = emptyJug1(tmp);
        if(isOK)    return true;
        isOK = emptyJug2(tmp);
        if(isOK)    return true;
    }
    return false;
}

int main()
{
    cout<<solve(a, b, c);
}
