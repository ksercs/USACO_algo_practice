/*
ID: Logan
PROG: milk3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

#define pb push_back
#define SZ size()
#define mp make_pair
#define ff first
#define ss second
#define pa pair<int,int>

const int MAXN = 20+5;

int A, B, C;
int used[MAXN][MAXN][MAXN], mark[MAXN];

vector <int> ans;
queue <pair <pa, int> > q;

void BFS()
{
    while(!q.empty())
    {
        pair <pa, int> p = q.front();
        int a = p.ff.ff, b = p.ff.ss, c = p.ss;
        //cout << a << " " << b << " " << c << "\n"; system("PAUSE");
        used[a][b][c] = 1;
        if (a == 0) ans.pb(c);
        if (c != 0 && b != B)
        {int aa=0, bb=0, cc=0;
            bb = min(B, b+c); cc = max(0,c-(B-b));
            if (!used[a][bb][cc]) {/*cout << "-1-" << a << " " << bb << " " << cc << "\n";*/ q.push(mp(mp(a, bb), cc));}
        }
        if (c != 0 && a != A)
        {int aa=0, bb=0, cc=0;
            aa = min(A, a+c); cc = max(0, c-(A-a));
            if (!used[aa][b][cc]) {/*cout << "-2-" << aa << " " << b << " " << cc << "\n";*/q.push(mp(mp(aa, b), cc));}
        }
        if (b != 0 && c != C)
        {int aa=0, bb=0, cc=0;
            cc = min(C, c+b); bb = max(0,b-(C-c));
            if (!used[a][bb][cc]) {/*cout << "-3-" << a << " " << bb << " " << cc << "\n";*/q.push(mp(mp(a, bb), cc));}
        }
        if (b != 0 && a != A)
        {int aa=0, bb=0, cc=0;
            aa = min(A, a+b); bb = max(0,b-(A-a));
            if (!used[aa][bb][c]) {/*cout << "-4-" << aa << " " << bb << " " << c << "\n";*/q.push(mp(mp(aa, bb), c));}
        }
        if (a != 0 && b != B)
        {int aa=0, bb=0, cc=0;
            bb = min(B, b+a); aa = max(0,a-(B-b));
            if (!used[aa][bb][c]) {/*cout << "-5-" << aa << " " << bb << " " << c << "\n";*/q.push(mp(mp(aa, bb), c));}
        }
        if (a != 0 && c != C)
        {int aa=0, bb=0, cc=0;
            cc = min(C, c+a); aa = max(0,a-(C-c));
            if (!used[aa][b][cc]) {/*cout << "-6-" << aa << " " << b << " " << cc << "\n";*/q.push(mp(mp(aa, b), cc));}
        }
        q.pop();
    }
}

void in()
{
  ifstream cin("milk3.in");
  cin >> A >> B >> C;
}

void solution()
{
  used[0][0][C] = 1;
  q.push(mp(mp(0,0),C));
  BFS();
  sort(ans.begin(), ans.end());
}

void out()
{
  ofstream cout("milk3.out");
  for (int i = 0; i < ans.SZ-1; i++)
  {
      if (!mark[ans[i]])cout << ans[i] << " ";
      mark[ans[i]]=1;
  }
  cout << ans[ans.SZ-1] << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
