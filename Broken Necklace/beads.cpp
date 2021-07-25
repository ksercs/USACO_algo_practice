/*
ID: Logan
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int n, ch, size, ans;
string str;

int st[750][2], fn[750][2];

void in()
{
    ifstream cin("beads.in");
    cin >> n;
    cin >> str;
}

void solution()
{
   str = str+str;
   size = str.size();
   for(int i = 1; i < size; ++i)
    {
        if(str[i-1] == 'r')
        {
            st[i][0] = st[i-1][0] + 1;
            st[i][1] = 0;
        }
        else if(str[i-1] == 'b')
        {
            st[i][1] = st[i-1][1] + 1;
            st[i][0] = 0;
        }
        else
        {
            st[i][0] = st[i-1][0] + 1;
            st[i][1] = st[i-1][1] + 1;
        }
    }
    for(int i = size-1; i >= 0; --i)
    {
        if(str[i] == 'r')
        {
            fn[i][0] = fn[i+1][0] + 1;
            fn[i][1] = 0;
        }
        else if(str[i] == 'b')
        {
            fn[i][1] = fn[i+1][1] + 1;
            fn[i][0] = 0;
        }
        else
        {
            fn[i][0] = fn[i+1][0] + 1;
            fn[i][1] = fn[i+1][1] + 1;
        }
    }
    for(int i = 0; i < size; ++i)
    {
        ans = max(ans, max(st[i][0], st[i][1]) + max(fn[i][0], fn[i][1]));
    }
    ans = min(n, ans);
}

void out()
{
    ofstream cout("beads.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
