/*
ID: Logan
PROG: ttwo
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

const int MAXN = 15;

int cd = 1, cf = 1, answer, ans;
PII cow, fr;

char mass[MAXN][MAXN];
int gr[MAXN][MAXN],
    dx[]={-1, 0, 1,  0},
    dy[]={ 0, 1, 0, -1};

queue < PII > c, f;

void BFS()
{
    while (!c.empty() && !f.empty())
    {
        int ncd = cd-1, nfd = cf-1;
        PII cw = c.front(), jh = f.front(), cto = MP(cw.FF+dx[ncd], cw.SS+dy[ncd]), fto = MP(jh.FF+dx[nfd], jh.SS+dy[nfd]);
        //cout << cw.FF << " " << cw.SS << " " << cd << "\n";
        //cout << jh.FF << " " << jh.SS << " " << cf << "\n\n"; system("PAUSE");
        if (cw == jh) {answer = 1; break;}
        if (ans == 8000) break;
        ans++;
        if (gr[cw.FF][cw.SS]&(int)pow(2,ncd)) c.push(cto);
        else {
            c.push(cw);
            cd+=1;
            if (cd == 5) cd=1;
        }
        if (gr[jh.FF][jh.SS]&(int)pow(2,nfd)) f.push(fto);
        else {
            f.push(jh);
            cf+=1;
            if (cf == 5) cf=1;
        }
        c.pop();
        f.pop();
    }
}

void in()
{
    ifstream cin("ttwo.in");
    for (int i = 0; i <= 11; i++)
        for (int j = 0; j <= 11; j++)
            mass[i][j] = '*';
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            cin >> mass[i][j];
}

void solution()
{
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++){
            if (mass[i][j] == 'F') cow = MP(i,j);
            if (mass[i][j] == 'C') fr = MP(i,j);
            if (mass[i][j] != '*')
                for (int k = 0; k < 4; k++)
                    gr[i][j] += (int)(mass[i+dx[k]][j+dy[k]] != '*')*(int)pow(2,k);
        }
    /*for (int i = 1; i <= 10; i++){
        for (int j = 1; j <= 10; j++)
            cout << gr[i][j] << " ";
    cout << "\n";
    }*/
    c.push(cow);
    f.push(fr);
    BFS();
    if (!answer) ans = 0;
}

void out()
{
    ofstream cout("ttwo.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
