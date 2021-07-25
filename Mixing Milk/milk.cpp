/*
ID: Logan
PROG: milk
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair <int, int> pa;

#define pb push_back
#define mp make_pair
#define SZ size()
#define ff first
#define ss second

int n, m;
long long ans;

vector < pa > ferm;

void in()
{
    ifstream cin("milk.in");
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int milk_cnt, prc;
        cin >> prc >> milk_cnt;
        ferm.pb(mp(prc, milk_cnt));
    }
}

void solution()
{
    sort(ferm.begin(), ferm.end());
    for (int i = 0; i < ferm.SZ; i++)
    {
        int pric = ferm[i].ff, cnt = ferm[i].ss;
        //cout << cnt << " " << n << endl;
        if (cnt >= n){
            ans += n*pric; break;
        }
        else {
            ans += cnt*pric; n -= cnt; //cout << ans << endl;
        }
    }
}

void out()
{
    ofstream cout("milk.out");
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
