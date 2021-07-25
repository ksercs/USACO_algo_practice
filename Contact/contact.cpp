/*
ID: Logan
PROG: contact
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
#include <queue>
#include <iterator>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

int a, b, n;
string sq;

map <string, int> mp;
map <int, VEC <string> > ans;

bool comp(string s1, string s2)
{
    if (s1.SZ != s2.SZ) return s1.SZ < s2.SZ;
    else
        for (int i = 0; i < s1.SZ; i++)
            if (s1[i] != s2[i]) return s1[i] < s2[i];
    return false;
}

void in()
{
    ifstream cin("contact.in");
    cin >> a >> b >> n;
    string str;
    while (cin >> str)
        sq += str;
}

void solution()
{
    for (int i = a; i <= b; i++)
        if ((int)sq.SZ-i+1 > 0) for (int j = 0; j < sq.SZ-i+1; j++)
                                mp[sq.substr(j,i)]++;

    map <string, int>:: iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
        ans[it->SS].PB(it->FF);
}

void out()
{
    ofstream cout("contact.out");
    int cnt = 0;
    map <int, VEC<string> >:: reverse_iterator it;
    it = ans.rbegin();
    while (it != ans.rend() && cnt < n){
        cout << it->FF << "\n";
        VEC <string> v = it->SS;
        sort(v.begin(), v.end(), comp);
        int ch = 0;
        for (int i = 0; i < v.SZ-1; i++){
            cout << v[i];
            ch++;
            if (ch%6 == 0) cout << "\n";
            else           cout << " ";
        }
        cout << v[v.SZ-1] << "\n";
        it++;
        cnt++;
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
