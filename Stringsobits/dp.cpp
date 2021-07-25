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

const int MAXN = 32;

int L, N;
LL I;
int C[MAXN+2][MAXN+2];
string ans;

void iniz()
{
    for(int i = 0; i <= MAXN; ++i)
        C[i][0] = 1;
    for(int i = 1; i <= MAXN; ++i)
        for(int j = 1; j <= MAXN; ++j)
            C[i][j] = C[i-1][j] + C[i-1][j-1];
}

void in()
{
    ifstream cin("kimbits.in");
    cin >> N >> L >> I;
}

void solution()
{
    iniz();
    for (int bit = 1; bit <=N; ++bit) {
        LL sum = 0;
        for (int j = 0; j <= L; ++j)
            sum += C[N - bit][j];
        if (I > sum) {
            ans += '1';
            L--;
            I -= sum;
        } else ans += '0';
    }

}

void out()
{
    ofstream cout("kimbits.out");
    for(int i = 1; i <= MAXN; ++i){
        cout << i << ": ";
        for(int j = 1; j <= MAXN; ++j)
            cout << C[i][j] << " ";
        cout << "\n";
    }
    //cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
