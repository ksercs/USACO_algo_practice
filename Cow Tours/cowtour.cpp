/*
ID: Logan
PROG: cowtour
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

const int MAXN = 155;
const double INF = 2*1e18;

int n;
VEC < PII > v;
int gr[MAXN][MAXN];
double s[MAXN][MAXN], d[MAXN][MAXN], maxd[MAXN];
double ans=1e18;

double Len(PII p1, PII p2)
{
    PII v = MP(p2.FF-p1.FF, p2.SS-p1.SS);
    double s = (double)sqrt(1LL*v.FF*v.FF + 1LL*v.SS*v.SS);
    return s;
}

void Floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++){
               // cout << i << " " << j << ": " << d[i][j] << " " << d[i][k] + d[k][j] << "\n";
               d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
}

void obnov()
{
    for (int i = 1; i <= n-1; i++)
        for (int j = i+1; j <= n; j++)
            if (gr[i][j]) {d[i][j] = s[i][j]; d[j][i] = s[i][j];}
            else          {d[i][j] = INF; d[j][i] = INF;}
}

void in()
{
    ifstream cin("cowtour.in");
    ios_base:: sync_with_stdio(false);
    cin >> n;
    v.resize(n+1);
    for (int i = 1; i <= n; i++)
        cin >> v[i].FF >> v[i].SS;
    for (int i = 1; i <= n; i++){
        string str;
        cin >> str;
        for (int j = 0; j < str.SZ; j++)
            gr[i][j+1] = str[j]-'0';
    }
}

void solution()
{
    for (int i = 1; i <= n-1; i++)
        for (int j = i+1; j <= n; j++){
            s[i][j] = Len(v[i], v[j]);
            s[j][i] = s[i][j];
        }
    /*for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cout << s[i][j] << " ";
        cout << "\n";
    }*/
    obnov();
    Floyd();
    /*for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cout << d[i][j] << " ";
        cout << "\n";
    }
    cout << "\n\n";*/
    for (int p = 1; p <= n; ++p)
        for (int src = 1; src <= n; ++src)
            if (d[p][src] != INF) maxd[p] = max(d[p][src], maxd[p]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (d[i][j] != INF) continue;
            ans = min(ans, maxd[i]+maxd[j]+s[i][j]);
        }
    for (int i = 1; i <= n; i++)
        ans = max(ans, maxd[i]);
}

void out()
{
    ofstream cout("cowtour.out");
    cout.precision(6);
    cout << fixed << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
