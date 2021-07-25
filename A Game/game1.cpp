/*
ID: Logan
PROG: game1
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

const int MAXN = 105;

int n, sum[MAXN][MAXN], dp[MAXN][MAXN];

void in()
{
    //ifstream cin("game1.in");
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> dp[i][i];
        sum[i][i] = dp[i][i];
    }
}

void solution()
{
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            sum[i][j] = sum[i][j-1] + dp[j][j];
    for(int len = 1; len < n; len++)
        for(int i = 1; i+len <= n; i++)
            dp[i][i+len] = sum[i][i+len] - min(dp[i][i+len-1],dp[i+1][i+len]);
    /*for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++)
            cout << dp[i][j] << " ";
    cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++)
            cout << sum[i][j] << " ";
    cout << "\n";
    }*/
}

void out()
{
    //ofstream cout("game1.out");
    cout << dp[1][n] /*<< " " << sum[1][n]-dp[1][n]*/ << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
