/*
ID: Logan
PROG: nocows
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int d[100+15][200+15];
int n, k;

int dfs(int deep, int child)
{
    if(deep <= 0) return -1;
	if(child == 1)  return 1;
	int& ans = d[deep][child];
	if(ans != -1) return ans;
	ans = 0;
    for(int i=1; i < child; i+=2)
	{
		int l = dfs(deep-1,i), r=dfs(deep-1,child-i-1);
		if(l == -1 && r == -1) return -1;
		if(l == -1 && r != -1) break;
		if(r == -1 && l != -1) continue;
		ans += l*r;
	}
	ans%=9901;
	if(ans==0)  return -1;
	else        return ans;
}

void in()
{
    ifstream cin("nocows.in");
    cin >> n >> k;
}

void solution()
{
    memset(d, -1, sizeof(d));
    dfs(k, n);
    dfs(k-1, n);
}

void out()
{
    ofstream cout("nocows.out");
    cout << (d[k][n]-d[k-1][n]+9901)%9901 << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
