/*
ID: Logan
PROG: shopping
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

int dp[6][6][6][6][6];
int noffer, nobj, ncode, code[1001], buy[6];
int t, inn;

struct OFFER
{
    int obj[6];
    int p;
} offer[105];

int CODE(int n)
{
    if (!code[n])code[n] = ++ncode;
    return code[n];
}

void in()
{
    ifstream cin("shopping.in");
    cin >> noffer;
    for(int i = 0; i < noffer; i++){
        cin >> t;
        for(int j=0; j < t; j++){
            cin >> inn;
            cin >> offer[i].obj[CODE(inn)];
        }
        cin >> offer[i].p;
    }
    cin >> nobj;
    for(int i = 0; i < nobj; i++){
        cin >> inn;
        int cd = CODE(inn);
        cin >> buy[cd];
        cin >> offer[noffer+i].p;
        offer[noffer+i].obj[cd]=1;
    }
}

void solution()
{
    memset(dp,127,sizeof(dp));
    dp[0][0][0][0][0]=0;
    for(int i = 0; i < nobj+noffer; i++){
        int n1=offer[i].obj[1];
        int n2=offer[i].obj[2];
        int n3=offer[i].obj[3];
        int n4=offer[i].obj[4];
        int n5=offer[i].obj[5];
        for(int a1=0; a1+n1 <= buy[1]; a1++)
            for(int a2=0; a2+n2 <= buy[2]; a2++)
                for(int a3=0; a3+n3 <= buy[3]; a3++)
                    for(int a4=0; a4+n4 <= buy[4]; a4++)
                        for(int a5=0; a5+n5 <= buy[5]; a5++)
                            dp[a1+n1][a2+n2][a3+n3][a4+n4][a5+n5] = min(dp[a1][a2][a3][a4][a5] + offer[i].p, dp[a1+n1][a2+n2][a3+n3][a4+n4][a5+n5]);
    }
}

void out()
{
    ofstream cout("shopping.out");
    cout << dp[buy[1]][buy[2]][buy[3]][buy[4]][buy[5]] <<  "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
