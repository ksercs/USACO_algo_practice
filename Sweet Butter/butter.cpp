/*
ID: Logan
PROG: butter
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
#include <string.h>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXN = 810, INF = 2*(int)1e9;

int n, c, m, ans = INF, answer;
int w[MAXN], u[MAXN], cw[MAXN];
set < PII > way;
VEC <VEC < PII > > gr;

void dijkstra(int v)
{
    //cout << v << "\n"; system("PAUSE");
    u[v] = 1;
    way.erase(way.begin());
    for (int i = 0; i < gr[v].SZ; i++)
    {
        PII to = gr[v][i];
        int tmp = w[v]+to.SS;
        if (!u[to.FF])
        {
            if (w[to.FF] > tmp)
            {
                way.erase(MP(w[to.FF], to.FF));
                way.insert(MP(tmp, to.FF));
                w[to.FF] = tmp;
            }
        }
    }
    if (way.SZ > 0)  dijkstra((*way.begin()).SS);
}

void in()
{
    ifstream cin("butter.in");
    cin >> c >> n >> m;
    gr.resize(n+1);
    for (int i = 0; i < c; i++){
        int a;
        cin >> a;
        cw[a]++;
    }
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        gr[a].PB(MP(b,c));
        gr[b].PB(MP(a,c));
    }
}

void solution()
{
    for (int j = 1; j <= n; j++){
        w[j] = 0;
        way.insert(MP(0, j));
        answer = 0;
        //cout << j << " : ";
        for (int i = 1; i <= n; i++)
            if (i != j)  {way.insert(MP(INF, i)); w[i]=INF;}
        dijkstra(j);
        for (int i = 1; i <= n; i++)
            if (i != j && cw[i] > 0){
                if (w[i] == INF) {answer = INF; break;}
                else answer += w[i]*cw[i];
            }
        ans = min(ans, answer);
        memset(u, 0, sizeof(u));
        way.clear();
        //cout << answer  << "\n";
    }
}

void out()
{
    ofstream cout("butter.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
