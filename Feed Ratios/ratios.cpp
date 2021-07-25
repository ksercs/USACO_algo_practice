/*
ID: Logan
PROG: ratios
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

int r[4][3], ans[4], k[3], fl;

int check(int t[3])
{
    for(int i=0; i < 3; i++)
        if(r[0][i] && t[i]%r[0][i] != 0)
            return 0;
    int ra;
    if(r[0][0]!=0)  ra = t[0]/r[0][0];
    else if(r[0][1]!=0) ra = t[1]/r[0][1];
    else if(r[0][2]!=0) ra = t[2]/r[0][2];
    else ra = 0;
    if(r[0][1]*ra!=t[1]||r[0][2]*ra!=t[2])
        return 0;
    return ra;
}

void in()
{
    ifstream cin("ratios.in");
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            cin >> r[i][j];
}

void solution()
{
    for (k[0] = 0; k[0] <= 100; k[0]++)
        for (k[1] = 0; k[1] <= 100; k[1]++)
            for (k[2] = 0; k[2] <= 100; k[2]++){
                int t[3]={0};
                for (int i = 1; i < 4; i++)
                    for (int j = 0; j < 3; j++)
                        t[j] += r[i][j]*k[i-1];
                int c = check(t);
                if (c){
                    fl = 1;
                    for (int i = 0; i < 3; i++)
                        ans[i] = k[i];
                    ans[3] = c;
                    return;
                }
            }
}

void out()
{
    ofstream cout("ratios.out");
    if (fl) cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
    else    cout << "NONE\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
