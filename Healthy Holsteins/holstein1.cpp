/*
ID: Din
PROG: holstein
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define VEC vector
#define SZ size()
#define PB push_back
#define sp " "

using namespace std;

const int MAXM = 25+2, MAXN = 15+2;

int m, n, one;
int vit[MAXM], por[MAXN][MAXM], res[MAXM], u[MAXN];
bool fl;

VEC <int> ans(50,0);

void check()
{
    fl = 1;
    one = 0;
    for (int i = 1; i <= n; i++)
    {
        if (u[i])
        {
            for (int j = 1; j <= m; j++)
            {
                res[j] += por[i][j];
            }
        one++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (res[i] < vit[i]) {fl = 0; break;}
    }
    fill(res, res+m+1, 0);
    if (fl && ans.SZ >= one)
    {
        ans.clear();
        for (int i = 1; i <= n; i++)
        {
            if (u[i]) ans.PB(i);
        }
    }
}

void DFS(int ind)
{
    if (ind == n)
    {
        check();
        /*cout << ind << endl << sp << sp;
        for (int i = 1; i <= n; i++)
        {
            cout << u[i] << sp;
        }
        cout << endl;*/
        u[n] = 1;
        check();
        /*cout << ind << endl << sp << sp;
        for (int i = 1; i <= n; i++)
        {
            cout << u[i] << sp;
        }
        cout << endl;*/
        u[ind] = 0;
    }
    if (/*!fl &&*/ ind < n)
    {
        //if (ind < n)
        {
            DFS(ind+1);
            u[ind] = 1;
            DFS(ind+1);
            u[ind] = 0;
        }
        /*if (ind == n)
        {
           u[ind] = 1;;
            cout << ind << endl << sp << sp;
            for (int i = 1; i <= n; i++)
            {
                cout << u[i] << sp;
            }
            cout << endl;
           check();
        }*/
    }
}

void in()
{
    ifstream cin("holstein.in");
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> vit[i];
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> por[i][j];
        }
    }
}

void solution()
{
    DFS(1);
}

void out()
{
    ofstream cout("holstein.out");
    int answer = ans.SZ;
    cout << answer << sp;
    if (answer > 1)
    for (int i = 0; i < answer-1; i++)
    {
        cout << ans[i] << sp;
    }
    cout << ans[answer-1] << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
