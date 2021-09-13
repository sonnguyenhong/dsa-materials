#include<bits/stdc++.h>
using namespace std;

int n = 3;
int a[100];

void solution()
{
    for(int i = 1 ; i <= n ; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void Try(int i)
{
    for(int v = 0 ; v <= 1 ; v++){
        a[i] = v;
        if(i == n)
            solution();
        else Try(i+1);
    }
}

int main()
{
    Try(1);
}
