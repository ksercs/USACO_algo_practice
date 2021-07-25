/*
ID: Logan
PROG: prefix
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#define VEC vector
#define SZ size()
#define PB push_back

using namespace std;

const int MAXLEN = (int)2*1e5 + 15;

VEC <string> s;
string str;

int ans;
int u[MAXLEN];

void in()
{
    ifstream cin("prefix.in");
    string word;
    while (word != ".")
    {
        cin >> word;
        s.PB(word);
    }
    s.pop_back();
    while ( cin.good() )
    {
        string S;
        cin >> S;
        str += S;
    }
}

void solution()
{
    for (int i = 0; i <= str.SZ; i++)
    {
        for (int j = 0; j < s.SZ; j++)
        {
            string word = s[j];
            int st = i-(int)word.SZ;
            if (st < 0) continue;
            if (str.substr(st, word.SZ) != word) continue;
            if (st > 0 && !u[st]) continue;
            u[i] = 1;
            ans = i;
            break;
        }
    }
}

void out()
{
    ofstream cout("prefix.out");
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
