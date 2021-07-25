/*
ID: Logan
PROG: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e3 + 5;

int ans, r;

int a[MAX_N][MAX_N], dp[MAX_N][MAX_N];

int dfs(int i,int j,int end)
{
  if(dp[i][j] != -1)
  {
    return dp[i][j];
  }
  else if(i <= end)
  {
    return dp[i][j] = a[i][j] + max(dfs(i+1,j,end), dfs(i+1,j+1,end));
  }
  else
  {
    return 0;
  }
}

void in()
{
    ifstream cin("numtri.in");
    cin >> r;
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= i; j++)
            {
                cin >> a[i][j];
                dp[i][j]=-1;
            }
}

void solution()
{
  ans = dfs(1,1,r);
}

void out()
{
    ofstream cout("numtri.out");
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
