#include<bits/stdc++.h>
using namespace std;

int table[100];

void init()
{
    for(int i = 0 ; i < 100 ; i++)
        table[i] = 0;
}

void solve(int a[], int n)
{
    table[1] = 1;
    for(int i = 1 ; i < n ; i++){
        if(a[i] > a[i-1])
            table[i+1] = table[i] + 1;
        else    table[i+1] = 1;
    }

    for(int i = 1 ; i <= n ; i++)
        cout<<table[i]<<" ";
    cout<<endl;
}

int main()
{
    init();

    int a[8] = {1, 3, 2, 4, 6, 8, 7, 9};

    solve(a, 8);
}
