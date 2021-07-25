/*
ID: Logan
PROG: rockers
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

const int MAXN = 22;

int n, m, t;
int mass[MAXN], dp[MAXN][MAXN][MAXN];
VEC <int> v;

void in()
{
    ifstream cin("rockers.in");
    cin >> n >> t >> m;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
}

void solution()
{
    for (int i = 1; i <= m; ++i)
      for (int j = 0; j <= t; ++j)
        for (int k = 0; k < n; ++k){
            if (j == 0)         dp[i][j][k] = dp[i-1][t][k];
            else if (v[k] <= j) dp[i][j][k] = max(dp[i][j][k-1], dp[i][j-v[k]][k-1]+1);
                  else          dp[i][j][k] = max(dp[i-1][t][k], dp[i][j][k-1]);
        }
}

void out()
{
    ofstream cout("rockers.out");
    cout << dp[m][t][n-1] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
