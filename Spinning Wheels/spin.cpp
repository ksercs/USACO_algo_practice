/*
ID: Logan
PROG: spin
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

const int MAXN = 6;

int ans = -1;

struct W{
    int v;
    int wn;
    int ws[MAXN];
    int wf[MAXN];
} w[MAXN];

void in()
{
    ifstream cin("spin.in");
    for (int i = 0; i < 5; i++){
        cin >> w[i].v >> w[i].wn;
        for (int j = 0; j < w[i].wn; j++){
            cin >> w[i].ws[j] >> w[i].wf[j];
            w[i].wf[j] += w[i].ws[j];
        }
    }
}

void solution()
{
    for (int t = 0; t <= 360; t++){
        int c[361]={0};
        for (int i = 0; i < 5; i++){
            int sp = t*w[i].v%360;
            for (int j = 0; j < w[i].wn; j++)
                for (int k = w[i].ws[j]; k <= w[i].wf[j]; k++)
                {
                    int ind = (k+sp)%360;
                    c[ind]++;
                    if (c[ind] == 5){
                        ans = t;
                        return;
                    }
                }
        }
    }
}

void out()
{
    ofstream cout("spin.out");
    if (ans == -1) cout << "none\n";
    else           cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
