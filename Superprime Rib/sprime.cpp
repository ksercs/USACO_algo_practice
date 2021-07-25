/*
ID: Logan
PROG: sprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#define pb push_back
#define SZ size()

using namespace std;

int n;
vector <int> ans;

bool isprime(int ch)
{
    if(ch == 1) return false;
    int k=sqrt(ch);
    for(int i=2;i<=k;i++)
    {
        if(ch%i==0) return false;
    }
    return true;
}

void dfs(int L, int ch)
{
    if(L == n)
    {
        ans.pb(ch);
    }
    for(int i=1; i <= 9; i++)
    {
        int new_ch=ch*10+i;
        if(isprime(new_ch))
            dfs(L+1,new_ch);
    }
}

void in()
{
    ifstream cin("sprime.in");
    cin >> n;
}

void solution()
{
    dfs(0, 0);
}

void out()
{
    ofstream cout("sprime.out");
    for (int i = 0; i < ans.SZ; i++)
    {
        cout << ans[i] << endl;
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
