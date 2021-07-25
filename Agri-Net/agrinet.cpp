/*
ID: Logan
PROG: agrinet
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

const int MAXN = (int)1e2+15, INF = (int)2*1e9;

int n, ans, treeSZ;
int s[MAXN], d[MAXN], w[MAXN][MAXN], inTree[MAXN];

void in()
{
    ifstream cin("agrinet.in");
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> w[i][j];
}

void solution()
{
    treeSZ = 1;
    inTree[1] = 1;
    for (int i = 2; i <= n; i++) d[i] = w[1][i];
    while(treeSZ < n){
        int small = INF, sID;
        for(int i = 1; i <= n; i++){
            if( !inTree[i] && d[i] < small){
                small = d[i];
                sID = i;
            }
        }
        treeSZ++;
        ans += d[sID];
        inTree[sID] = 1;
        for(int i = 1; i <= n; i++){
            if( !inTree[i] && d[i] > w[sID][i]){
                d[i] = w[sID][i];
                s[i] = sID;
            }
        }
    }
}

void out()
{
    ofstream cout("agrinet.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
