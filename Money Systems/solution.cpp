/*
ID: Logan
PROG: money
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

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXN = (int)1e5;

int n, x;
LL dp[MAXN];

VEC <int> num;

void in()
{
    ifstream cin("money.in");
    cin >> n >> x;
    num.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        //dp[num[i]] = 1;
    }
    /*for (int i = 0; i < n; i++)
    {
       cout << num[i] << " ";
    }
    cout << endl;*/
}

void solution()
{
   /* for (int i = 1; i < x; i++)
        if (dp[i] > 0)
            for (int j = 0; j < n; j++)
                dp[i+num[j]] += dp[i];*/
    dp[0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = num[i]; j <= x; j++)
            dp[j] += dp[j - num[i]];
    /*for (int i = 1; i <= x; i++)
        cout << dp[i] << " ";*/
}

void out()
{
    ofstream cout("money.out");
    cout << dp[x] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
