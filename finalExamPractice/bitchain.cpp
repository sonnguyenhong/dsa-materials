#include<bits/stdc++.h>
using namespace std;

int maxchain(string s)
{
    int l = s.length();
    int cmax = 0;

    for(int i = 0 ; i < l ; i++){
        int c = 0;
        while(s[c + i] == '1')
            c++;
        i = i+c;
        if(c > cmax)
            cmax = c;
    }
    return cmax;
}

int main()
{
    string s = "0001111111111101111111111110011110000000001";
    cout<<maxchain(s)<<endl;
}
