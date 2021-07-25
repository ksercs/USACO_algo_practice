/*
ID: Logan
PROG: maze1
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

const int INF = (int)1e9, MAXN=220;

int w, h, answer;
char mass[MAXN][MAXN];
int u[MAXN][MAXN], gr[105][105], ans[105][105];
int dx[]={-1, 0, 1,  0},
    dy[]={ 0, 1, 0, -1};
string str;

VEC < PII > ex;
PII pa;

queue < pair<PII,int> > q;

void BFS()
{
    while (!q.empty()){
        pair <PII,int> v = q.front();
        int i = v.FF.FF, j = v.FF.SS, c = v.SS;
        //cout << i << " " << j << " " << c << "\n";
        pa = v.FF;
        for (int k = 0; k < 4; k++){
            int ni = i+dx[k], nj = j+dy[k];
            if ((gr[i][j]&((int)pow(2,k))) && (!u[ni][nj])){
               //cout << "--" << i << " " << j << " " << gr[i][j] << " " << (gr[i][j]&(k+1)) << "\n";
                u[ni][nj] = 1;
                ans[ni][nj] = min(c+1, ans[ni][nj]);
                q.push(MP(MP(ni, nj), c+1));
            }
        }
        q.pop();
    }
}

void in()
{
    ifstream cin("maze1.in");
    cin >> w >> h;
    memset(mass, ' ', sizeof(mass));
    getline(cin, str);
    for (int i = 1; i <= 2*h+1; i++){
        getline(cin, str);
        //cout <<"(" << str <<")\n";
        for (int j = 0; j < str.SZ; j++)
            mass[i][j+1] = str[j];
    }
    /*cout << "\n\n";
    for (int i = 1; i <= 2*h+1; i ++){
        for (int j = 1; j <= 2*w+1; j++)
            cout << mass[i][j];
    cout << "\n";
    }*/
}

void solution()
{
    for (int i = 2; i < 2*w+1; i+=2){
        if (mass[1][i] == ' ') {gr[1][i/2] -= 1; ex.PB(MP(1, i/2));}
        if (mass[2*h+1][i] == ' ') {gr[h][i/2] -= 4; ex.PB(MP(h, i/2));}
    }
    for (int i = 2; i < 2*h+1; i+=2){
        if (mass[i][1] == ' ') {gr[i/2][1] -= 8; ex.PB(MP(i/2, 1));}
        if (mass[i][2*w+1] == ' ') {gr[i/2][w] -= 2; ex.PB(MP(i/2, w));}
    }
    for (int i = 2; i <= 2*h; i += 2)
        for (int j = 2; j <= 2*w; j += 2)
            for (int k = 0; k < 4; k++)
                gr[i/2][j/2] += (int)(mass[i+dx[k]][j+dy[k]] == ' ')*(int)pow(2, k);
    /*for (int i = 0; i < 2; i++)
        cout << ex[i].FF << " " << ex[i].SS << "\n";*/
    /*for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++)
            cout << gr[i][j] << " ";
        cout << "\n";
    }*/
    u[ex[0].FF][ex[0].SS] = 1;
    ans[ex[0].FF][ex[0].SS] = 1;
    q.push(MP(ex[0],1));
    memset(ans, 25, sizeof(ans));
    ans[ex[0].FF][ex[0].SS] = 1;
        /*for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++)
            cout << ans[i][j] << " ";
            //answer = max(answer, ans[i][j]);
        cout << "\n";
    }*/
    BFS();
    memset(u, 0, sizeof(u));
    u[ex[1].FF][ex[1].SS] = 1;
    ans[ex[1].FF][ex[1].SS] = 1;
    q.push(MP(ex[1],1));
    BFS();
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++)
            //cout << ans[i][j] << " ";
            answer = max(answer, ans[i][j]);
        //cout << "\n";
    }
}

void out()
{
    ofstream cout("maze1.out");
    cout << answer << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
