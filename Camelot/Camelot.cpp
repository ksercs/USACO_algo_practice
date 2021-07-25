/*
ID: Logan
PROG: camelot
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

const int INF = (int)1e5;

int n, m, ans = INF, cnt, mini, fl;
PII horse[800], king;
int ks[30][30][30][30], hs[30][30][30][30];
map < PII, set <PII> > kgr, hgr;

int di[] = { -2, -2, -1, 1, 2, 2, 1, -1 },
    dj[] = { -1, 1, 2, 2, 1, -1, -2, -2 },
    dx[] = { -1, 0, 1,  0, -1, 1,  1, -1 },
    dy[] = {  0, 1, 0, -1,  1, 1, -1, -1 };

void make_gr()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k < 8; k++){
                if (i+di[k] >= 1 && i+di[k] <= n && j+dj[k] >= 1 && j+dj[k] <= m){
                    hgr[MP(i,j)].insert(MP(i+di[k], j+dj[k]));
                    hgr[MP(i+di[k],j+dj[k])].insert(MP(i, j));
                    //cout << i << " " << j << " " << i+di[k] << " " << j+dj[k] << "\n";
                }
                if (i+dx[k] >= 1 && i+dx[k] <= n && j+dy[k] >= 1 && j+dy[k] <= m){
                    kgr[MP(i,j)].insert(MP(i+dx[k], j+dy[k]));
                    kgr[MP(i+dx[k],j+dy[k])].insert(MP(i, j));
                }
            }
}

void Floyd()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int ni = 1; ni <= n; ni++)
                for (int nj = 1; nj <= m; nj++){
                    if (ni == i && nj == j) continue;
                    if (hgr[MP(i,j)].count(MP(ni,nj))) {/*out <<i<<" "<<j<<" "<<ni<<" "<<nj<<"\n";*/ hs[i][j][ni][nj] = 1;}
                    else                                       hs[i][j][ni][nj] = INF;
                    if (kgr[MP(i,j)].count(MP(ni,nj))) ks[i][j][ni][nj] = 1;
                    else                                       ks[i][j][ni][nj] = INF;
                }
    for (int k1 = 1; k1 <= n; k1++)
        for (int k2 = 1; k2 <= m; k2++)
            for (int i1 = 1; i1 <= n; i1++)
                for (int i2 = 1; i2 <= m; i2++)
                    for (int j1 = 1; j1 <= n; j1++)
                        for (int j2 = 1; j2 <= m; j2++){
                            if (i1 == j1 && i2 == j2 || i1 == k1 && i2 == k2 || j1 == k1 && j2 == k2) continue;
                            hs[i1][i2][j1][j2] = min(hs[i1][i2][j1][j2], hs[i1][i2][k1][k2] + hs[k1][k2][j1][j2]);
                            ks[i1][i2][j1][j2] = min(ks[i1][i2][j1][j2], ks[i1][i2][k1][k2] + ks[k1][k2][j1][j2]);
                        }
    /*for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int ni = 1; ni <= n; ni++){
                for (int nj = 1; nj <= m; nj++){
                    cout << "("<<i<<","<<j<<") - (" <<ni<<","<<nj<<") = " << hs[i][j][ni][nj] <<"\n";
                }
                cout << "\n";system("PAUSE");
            }*/
}

void in()
{
    ifstream cin("camelot.in");
    cin >> n >> m;
    char a;
    cin >> a >> king.SS;
    king.FF = a-'A'+1;
    int b;
    //cout << king.FF << " " <<king.SS << "\n";
    while (cin >> a >> b){
        //cout << a << " " << b << "\n";
        horse[cnt].FF = a-'A'+1;
        horse[cnt].SS = b;
        cnt++;
    }
}

void solution()
{
    make_gr();
    Floyd();
    mini = hs[horse[0].FF][horse[0].SS][king.FF][king.SS];
    int ind = 0;
    for (int i = 1; i < cnt; i++){
        int s = hs[horse[i].FF][horse[i].SS][king.FF][king.SS];
        if (s < mini){
            mini = s;
            ind = i;
        }
    }
   // cout << "CNT = " << cnt << "\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            int answer = 0;
            for (int k = 0; k < cnt; k++){
                if (k == ind) continue;
                //cout << k <<": \n";
                if (hs[horse[k].FF][horse[k].SS][i][j] == INF) {fl = 1; break;}
                answer += hs[horse[k].FF][horse[k].SS][i][j];
                //cout << horse[k].FF << " " << horse[k].SS << " " << i << " " << j << " " << hs[horse[k].FF][horse[k].SS][i][j] << "\n";
            }
            if (fl) {fl = 0; continue;}
           // cout << answer << "\n";
            if (ks[king.FF][king.SS][i][j] != INF && hs[king.FF][king.SS][i][j] != INF && hs[horse[ind].FF][horse[ind].SS][king.FF][king.SS] != INF)
                answer += min(ks[king.FF][king.SS][i][j] + mini, hs[horse[ind].FF][horse[ind].SS][king.FF][king.SS] + hs[king.FF][king.SS][i][j]);
            else{
                if (ks[king.FF][king.SS][i][j] != INF) answer += hs[horse[ind].FF][horse[ind].SS][king.FF][king.SS] + hs[king.FF][king.SS][i][j];
                else if (hs[king.FF][king.SS][i][j] != INF && hs[horse[ind].FF][horse[ind].SS][king.FF][king.SS] != INF) answer += ks[king.FF][king.SS][i][j] + mini;
            }
            if (ks[king.FF][king.SS][i][j] != INF || hs[king.FF][king.SS][i][j] != INF && hs[horse[ind].FF][horse[ind].SS][king.FF][king.SS] != INF) {/*cout << answer << "\n";*/ ans = min(ans, answer);}
        }
}

void out()
{
    ofstream cout("camelot.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
