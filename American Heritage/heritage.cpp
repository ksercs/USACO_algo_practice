/*
ID: Logan
PROG: heritage
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

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

string ss, spre, spost;

void build(string p,string n)
{ //cout << p << " " << n << "\n";
    if(p.SZ == 0) return;
    int pos = n.find(p[0]);
    build(p.substr(1,pos),n.substr(0,pos));
    build(p.substr(pos+1),n.substr(pos+1));
    spost += p[0];
    //cout << " --- " << p[0] << "\n";
}

void in()
{
    ifstream cin("heritage.in");
    cin >> ss >> spre;
}

void solution()
{
    build(spre, ss);
}

void out()
{
    ofstream cout("heritage.out");
    cout << spost << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
