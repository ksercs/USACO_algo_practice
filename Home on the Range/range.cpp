/*
ID: Logan
PROG: range
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

const int MAXN = 255;

int n, dp[MAXN][MAXN], ans[MAXN];

void in()
{
    ifstream cin("range.in");
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            char a;
            cin >> a;
            dp[i][j] = (a == '0'? 1 : 0);
            if(i > 0) dp[i][j] += dp[i - 1][j];
            if(j > 0) dp[i][j] += dp[i][j - 1];
            if(i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
        }
}

void solution()
{
    for(int i = 0; i < n; i++)
          for(int j = 0; j < n; j++)
               for(int k = min(n-i, n-j) - 1; k >= 1; k--){
                    int s = dp[i + k][j + k];
                    if(i > 0) s -= dp[i - 1][j + k];
                    if(j > 0) s -= dp[i + k][j - 1];
                    if(i > 0 && j > 0) s += dp[i - 1][j - 1];
                    if(s == 0){
                         for(int t = k + 1; t >= 2; t--) ans[t]++;
                         break;
                    }
               }
}

void out()
{
    ofstream cout("range.out");
    for(int i = 2; i <= n; i++)
        if(ans[i]) cout << i << " " << ans[i] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
