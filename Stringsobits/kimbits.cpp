/*
ID: Logan
PROG: kimbits
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

int L, I, N, ind;
string ans;
set <string> st;

bool check(string s1, string s2)
{
    for (int i = 0; i < s1.SZ; i++)
        if (s1[i] != s2[i]) return s1[i] < s2[i];
    return false;
}

void DFS(string s, int cnt)
{
    //cout << s << " " << cnt << "\n"; system("PAUSE");
	if (s.SZ > N || cnt > L)
		return;
	if (s.SZ == N && cnt <= L){
		if (st.SZ < I) {st.insert(s); }//cout << "---" << s << "\n";}
		else if ( check(s,(*st.rbegin()))){
                //cout << "---" << s << "\n";
                st.insert(s);
                if (st.SZ > I) st.erase((*st.rbegin()));
            }
	}
	DFS(s+'1',cnt+1);
	DFS(s+'0',cnt);
}

void in()
{
    ifstream cin("kimbits.in");
    cin >> N >> L >> I;
}

void solution()
{
    DFS("",0);
    ans = (*st.rbegin());
}

void out()
{
    ofstream cout("kimbits.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
