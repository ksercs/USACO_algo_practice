/*
ID: Logan
PROG: fence9
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

double n, m, p;
int ans;

void in()
{
    ifstream cin("fence9.in");
    cin >> n >> m >> p;
}

void solution()
{
    for (int i = 1; i < m; i++)
    {
        int L, R;
        L = floor(i * n / m) + 1;
        if(n != p) R = ceil(p + (n - p) * i / m) - 1;
        else       R = n - 1;
        //cout << L << " " << R << "\n";
        ans += R-L+1;
    }
}

void out()
{
    ofstream cout("fence9.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
