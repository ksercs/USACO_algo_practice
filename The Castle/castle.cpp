/*
ID: Logan
PROG: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

#define sp " "

using namespace std;

const int MaxN = 50+5, MaxRoomCnt = 50*50 + 5;

int n, m, rnum, rmax, r2max, cnt, ax, ay;
char ad;
int cs[MaxN][MaxN], u[MaxN][MaxN], c[MaxN][MaxN];
int room[MaxRoomCnt];

void DFS(int x,int y)
{
   // cout << rnum << ":  " << x << sp << y << sp << cs[x][y] << endl;
    u[x][y] = 1;
    c[x][y] = rnum;
    cnt++;
    if(!(cs[x][y]&1) && !u[x][y-1]) DFS(x,y-1);
    if(!(cs[x][y]&2) && !u[x-1][y]) DFS(x-1,y);
    if(!(cs[x][y]&4) && !u[x][y+1]) DFS(x,y+1);
    if(!(cs[x][y]&8) && !u[x+1][y]) DFS(x+1,y);
}

void in()
{
    ifstream cin ("castle.in");
    cin >> n >> m;
    swap(n,m);
    for (int i = 0; i <= n+1; i++)
        for (int j = 0; j <= m+1; j++)
            u[i][j] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            {
                cin >> cs[i][j];
                u[i][j] = 0;
            }
    /*for (int i = 1; i <= n; i++)
    {
            for (int j = 1; j <= m; j++)
            {
                cout << cs[i][j] << sp;
            }
            cout << endl;
    }*/
}

void solution()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!u[i][j])
            {
                rnum++;
                cnt = 0;
                DFS(i, j);
                room[rnum] = cnt;
                rmax = max(rmax, cnt);
            }
    for (int j = 1; j <= m; j++)
        for (int i = n; i >= 1; i--)
        {
            int v, to;
            v = c[i][j], to = c[i-1][j];
            if(to != v && room[to] && room[to] + room[v] > r2max)
            {
                r2max = room[to] + room[v];
                ax = i,ay = j, ad = 'N';
            }
            v = c[i][j], to = c[i][j+1];
            if(to != v && room[to] && room[to] + room[v] > r2max)
            {
                r2max = room[to] + room[v];
                ax = i,ay = j, ad = 'E';
            }
        }
}

void out()
{
     ofstream cout ("castle.out");
     cout << rnum << endl << rmax << endl << r2max << endl << ax << sp << ay << sp << ad << endl;
}

int main()
{
    in();
    solution();
    out();
return 0;
}
