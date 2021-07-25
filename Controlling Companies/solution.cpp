/*
ID: Logan
PROG: concom
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

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXN = 100+5;

int n;
int d[MAXN][MAXN], u[MAXN][MAXN];

void in()
{
    ifstream cin("concom.in");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
    }
}

void solution()
{
    for(int i = 1; i < MAXN; i++){
        for(int j = 1; j < MAXN; j++){
            if(i != j && !u[i][j] && d[i][j] > 50){
                u[i][j] = 1;
                for(int k = 1; k < MAXN; k++){
                    d[i][k] += d[j][k];
                    if(u[j][k]) u[i][k] = 1;
                }
                j = 0;
            }
        }
    }
}

void out()
{
    ofstream cout("concom.out");
    for(int i = 1; i < MAXN; i++){
        for(int j = 1; j < MAXN; j++){
            if(i != j && u[i][j]) cout << i << " " << j << endl;
        }
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
