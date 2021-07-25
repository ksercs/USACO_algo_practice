/*
ID: Logan
PROG: inflate
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

const int MAXN = (int)1e4+15;

int n, t;
int d[MAXN];

void in()
{
    ifstream cin("inflate.in");
    cin >> t >> n;
    for (int i = 1; i <= n; i++){
        int p, m;
        cin >> p >> m;
        for (int j = m; j <= t; j ++) d[j] = max(d[j], d[j-m]+p);
    }
}

void out()
{
    ofstream cout("inflate.out");
    cout << d[t] << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
