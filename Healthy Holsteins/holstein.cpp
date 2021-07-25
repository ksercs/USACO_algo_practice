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

int m, n, one = 1;
int vit[MAXM], por[MAXN][MAXM], res[MAXM], u[MAXN];

VEC <int> way, ans;

bool check()
{
    one = 0;
    bool fl = 1;
    for (int i = 0; i < way.SZ; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            res[i] += por[way[i]][j];
        }
        if (u[way[i]]) one++;
    }
    for (int i = 1; i <= m; i++)
    {
        if (res[i] < vit[i]) {fl = 0; break;}
    }
    if (fl) ans = way;
    return fl;
}

void DFS(int ind)
{
    if (!one) return;
    u[ind] = 1;
    way.PB(ind);
    cout << ind << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << u[i] << sp;
    }
    cout << endl;
    for (int i = 1; i < way.SZ; i++)
    {
        cout << way[i] << sp;
    }
    cout << endl;
    cout <<"ONE = " << one << endl;
    system("PAUSE");
    if ( !check() )
    {
        if (ind < n)
        {
            //cout << "  " << ind << " 1\n";
            DFS(ind+1);
            u[ind] = 0;
            way.pop_back();
            //cout << "  " << ind << " 0\n";
            DFS(ind+1);
        }
        else
        {
            u[ind] = 0;
            way.pop_back();
            cout << ind << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << u[i] << sp;
            }
            cout << endl;
            one--;
            cout <<"ONE = " << one << endl;
            system("PAUSE");
            if (!one) return;
            check();
        }
    }
    if (way.SZ > 0) way.pop_back();
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
