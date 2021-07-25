/*
ID: Logan
PROG: comehome
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

const int INF = (int)2*1e9;

int n, ans2 = INF;
char ans1;

map <char, VEC < pair<char,int> > > gr;
map <char, int > u;
map <char, VEC <pair<char,int> > >:: iterator it;
map <char, int> d;
set < pair <int,  char > > st;
set <char> Ver, Big;
set <char>:: iterator it2, it1;

void dijkstra()
{
    char v = (*st.begin()).SS;
    //cout << v << "\n";
    u[v] = 1;
    st.erase(st.begin());
    for (int i = 0; i < gr[v].SZ; i++){
        pair<char,int> to = gr[v][i];
        int tov = to.FF, tow = to.SS;
        int nw = d[v] + tow;
        if (!u[tov] && d[tov] > nw){
            st.erase(MP(d[tov],tov));
            d[tov] = nw;
            st.insert((MP(d[tov],tov)));
        }
    }
    if (st.SZ > 0) dijkstra();
}

void in()
{
    ifstream cin("comehome.in");
    cin >> n;
    for (int i = 0; i < n; i++){
        char a, b;
        int c;
        cin >> a >> b >> c;
        if (a != b){
            gr[a].PB(MP(b,c));
            gr[b].PB(MP(a,c));
            if ( a >= 'A' && a <= 'Y' ) Big.insert(a);
            if ( b >= 'A' && b <= 'Y' ) Big.insert(b);
            Ver.insert(b);
            Ver.insert(a);
        }
    }
}

void solution()
{
    for (it1 = Big.begin(); it1 != Big.end(); it1 ++){
        for (it2 = Ver.begin(); it2 != Ver.end(); it2++){
            if (*it1 != *it2){
                d[*it2] = INF;
                st.insert(MP(INF, *it2));
            }
        }
        d[*it1] = 0;
        st.insert(MP(0, *it1));
        dijkstra(); //cout << "\n\n";
        u.clear();
        if (d['Z'] < ans2){
            ans2 = d['Z'];
            ans1 = *it1;
        }
        d['Z'] = 0;
    }
}

void out()
{
    ofstream cout("comehome.out");
    cout << ans1 << " " << ans2 << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
