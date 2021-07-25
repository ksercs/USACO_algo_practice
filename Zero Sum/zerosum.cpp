/*
ID: Logan
PROG: zerosum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <utility>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

int n;

VEC <string> ans;

bool eval(string s)
{
    //cout << s << " ";
    int res = 0, ch = 0, fl = 1, last = 1, f = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i-1] == ' ')
        {
            //if (f == 1 && s[1] != ' ') {ch = 10+i+1; fl = 0;}
           // else        {ch = ch*10+i+(i==1); fl = 0;}
           if (fl == 0) {ch = ch*10+i; fl = 0;}
           else         {ch = ((i)*10+i+1); fl = 0;}
        }
        else
        {
            f = 0;
            if (last == 1) res += max(ch,i);
            else   if (last == -1) res -= max(ch,i);
            ch = 0;
        }
        if (s[i-1] == '+') {fl = 1; last = 1;}
        if (s[i-1] == '-') {fl = -1; last = -1;}
    }
    if (fl != 0) ch = n;
    if (last == 1) res += ch;
    else           res -= ch;
    //cout << res << "\n";
    if (res == 0) return true;
    return false;
}

void gen(string str)
{
    //cout << str << "\n";
    if (str.SZ == n-1) {if (eval(str)) ans.PB(str);}
    else
    {
        gen(str+"+");
        gen(str+"-");
        gen(str+" ");
    }
    /*for (int i = 0; i < ans.SZ; i++)
    {
        cout << str << "\n";
    }*/
}

void in()
{
    ifstream cin("zerosum.in");
    cin >> n;
}

void solution()
{
    gen("");
    sort(ans.begin(), ans.end());
}

void out()
{
    ofstream cout("zerosum.out");
    for (int i = 0; i < ans.SZ; i++)
    {
        cout << "1";
        for (int j = 2; j <= n; j++)
        {
            cout << ans[i][j-2] << j;
        }
        cout <<"\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
