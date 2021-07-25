/*
ID: Logan
PROG: subset
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
//#include <vector>

using namespace std;

const int MAXN = 45, MAXS = 400;

int n, ans, sum, s;
long long dp[MAXN][MAXS];

void get_ans()
{
    for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                dp[i][j] = dp[i-1][j];
            }
            dp[i][i]++;
            for (int j = 1; j <= sum; j++)
            {
                if (dp[i-1][j]>0 && j+i<=sum)  dp[i][j+i] += dp[i-1][j];
            }
        }
}

//int u[MAXN];

/*void DFS(int ind)
{
    //u[ind] = 1;
    if (ind == n)
    {
        //cout << s << " ";
        if (s == sum) ans++;
        s += ind;
        //cout << s << endl;
        if (s == sum) ans++;
        //u[ind] = 0;
        s -= ind;
        return;
    }
    DFS(ind+1);
    s += ind;
    //u[ind] = 1;
    DFS(ind+1);
    s -= ind;
    //u[ind] = 0;
}*/

void in()
{
    ifstream cin("subset.in");
    cin >> n;
}

void solution()
{
    sum = n*(n+1)/2;
    dp[1][1] = 1;
    if ( !(sum%2) )
    {
        sum /= 2;
        get_ans();
        ans = dp[n][sum]/2;
        /*cout << "   ";
        for (int i = 0; i <= sum; i++)
        {
            cout << i <<  " ";
        }
        cout << endl;
        for (int i = 0;  i <= n; i++)
        {
            cout << i << ": ";
            for (int j = 0; j <= sum; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/
        /*DFS(1);*/
    }
    //ans /= 2;
}

void out()
{
    ofstream cout("subset.out");
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
