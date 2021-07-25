/*
ID: Logan
PROG: stamps
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

#define PII pair <int, int>
#define MP make_pair
#define FF first
#define SS second

using namespace std;

const int MAXN = 50+5, MAXX = (int)2*1e6+5;

int n, k, answer;
int mass[MAXN];
int ans[MAXX];

void in()
{
    ifstream cin("stamps.in");
    cin >> k >> n;
    for (int i = 0; i < n; i++){
        cin >> mass[i];
        ans[mass[i]]=1;
    }
}

void solution()
{
    int i;
    for (i = 1; i < (int)2*1e6-1; i++){
        if (ans[i] == 0) break;
        if (ans[i] < k){
            for (int j = 0; j < n; j++){
                if (i+mass[j] > (int)2*1e6) continue;
                if (ans[i+mass[j]]==0) ans[i+mass[j]] = ans[i]+1;
                else                    ans[i+mass[j]] = min(ans[i+mass[j]], ans[i]+1);
            }
        }
    }
    answer = i-1;
}

void out()
{
    ofstream cout("stamps.out");
    cout << answer << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
