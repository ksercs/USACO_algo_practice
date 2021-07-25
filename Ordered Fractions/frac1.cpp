/*
ID: Logan
PROG: frac1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

#define mp make_pair
#define SZ size()
#define pb push_back
#define pii pair <int, int>
#define vec vector
#define ss second
#define ff first

using namespace std;

int n;

vec < pii > ans;

void DFS(int ch1, int zn1, int ch2, int zn2)
{
    cout << ch1 << " " << zn1 << " " << ch2 << " " << zn2 << endl;
    if (zn1+zn2 > n) return;
    DFS(ch1, zn1, ch1+ch2, zn1+zn2);
    ans.pb(mp(ch1+ch2, zn1+zn2));
    DFS(ch1+ch2, zn1+zn2, ch2, zn2);
}

void in()
{
    //ifstream cin("frac1.in");
    cin >> n;
}

void solution()
{
    ans.pb(mp(0, 1));
    DFS(0, 1, 1, 1);
    ans.pb(mp(1, 1));
}

void out()
{
    //ofstream cout("frac1.out");
    for (int i = 0; i < ans.SZ; i++)
    {
        cout << ans[i].ff << "/" << ans[i].ss << endl;
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
