/*
ID: Logan
PROG: fact4
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

int n, cnt2, cnt5, ans=1;

void in()
{
    ifstream cin("fact4.in");
    cin >> n;
}

void solution()
{
    for (int i = 2; i <= n; i++){
        int ch = i;
        while (!(ch%2)) {cnt2++; ch /= 2;}
        while (!(ch%5)) {cnt5++; ch /= 5;}
        ans = (ans*ch)%10;
    }
    for (int i = 1; i <= (cnt2-cnt5); i++)
        ans = (ans*2)%10;
}

void out()
{
    ofstream cout("fact4.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
