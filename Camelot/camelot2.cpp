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

const int INF = (int)1e7;

int n, m, cnt, ans = INF;
PII horse[800], king;
int dp[32][32][32][32];

int di[] = {-2,-1,1,2, 2, 1,-1,-2},
    dj[] = { 1, 2,2,1,-1,-2,-2,-1};

queue < PII > q;

void BFS(int r, int c)
{
    while(!q.empty()){
        PII p = q.front();
        q.pop();
        for(int d = 0; d < 8; d++){
            int tr = p.FF+ di[d];
            int tc = p.SS+ dj[d];
            if(tr >= 1 && tc >= 1 && tr <= n && tc <= m && dp[r][c][tr][tc] == INF){
                dp[r][c][tr][tc] = dp[r][c][p.FF][p.SS]+1;
                q.push(MP(tr,tc));
            }
        }
    }
}

void in()
{
    ifstream cin("camelot.in");
    cin >> n >> m;
    char a;
    cin >> a >> king.FF;
    king.SS = a-'A'+1;
    int b;
    //cout << king.FF << " " <<king.SS << "\n";
    while (cin >> a >> b){
        //cout << a << " " << b << "\n";
        horse[cnt].SS = a-'A'+1;
        horse[cnt].FF = b;
        cnt++;
    }
}

void solution()
{
    for (int i = 0; i <= 31; i++)
        for (int j = 0; j <= 31; j++)
            for (int k = 0; k <= 31; k++)
                for (int c = 0; c <= 31; c++)
                    dp[i][j][k][c] = INF;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            q.push(MP(i,j));
            dp[i][j][i][j]=0;
            BFS(i, j);
        }
    int kiL = king.FF < 3 ? 1 : king.FF-2;
    int kjL = king.SS < 3 ? 1 : king.SS-2;
    int kiR = king.FF > n-2 ? n : king.FF+2;
    int kjR = king.SS > m-2 ? m : king.SS+2;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            int step = 0;
            for(int k = 0; k < cnt; k++){
                step += dp[horse[k].FF][horse[k].SS][i][j];
                //cout << dp[horse[k].FF][horse[k].SS][i][j] << "\n"; system("PAUSE");
            }
            int minn = max(abs(king.FF-i), abs(king.SS-j));
            for(int pi = kiL; pi <= kiR; pi++)
                for(int pj = kjL; pj <= kjR; pj++)
                    for(int k = 0; k < cnt; k++){
                        int tmp = max(abs(king.FF-pi), abs(king.SS-pj))
                            + dp[horse[k].FF][horse[k].SS][pi][pj]
                            + dp[pi][pj][i][j]
                            - dp[horse[k].FF][horse[k].SS][i][j];
                        minn = min(tmp, minn);
                    }
           //cout << minn << " " << step << "\n"; system("PAUSE");
           ans = min(minn+step, ans);
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
