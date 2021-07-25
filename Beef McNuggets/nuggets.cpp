/*
ID: Logan
PROG: nuggets
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

int n, ans;
VEC<int> packages;

int gcd_R(int a, int b) {
    return (a&&b) ? gcd_R(b, a%b) : (a|b);
}

void in()
{
    ifstream cin("nuggets.in");
    cin >> n;
    packages.resize(n);
    for (int i = 0; i < n; ++i){
        cin >> packages[i];
    }
}

void solution()
{
    for(int i = 0; i < n; ++i) {
        if (packages[i] == 1) {
            return;
        }
    }

    int gcd = packages[0];
    for(int i = 1; i < n; ++i) {
        gcd = gcd_R(gcd, packages[i]);
    }
    if (gcd != 1) {
        return;
    }

    int maxi1 = 0, maxi2 = 0;
    for(int i = 0; i < n; ++i) {
        if (maxi1 < packages[i]) {
            maxi1 = packages[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (maxi2 < packages[i] && packages[i] != maxi1) {
            maxi2 = packages[i];
        }
    }

    bool u[maxi1 * maxi2 + 15] = {false};
    u[0] = 1;
    int maxi = maxi1 * maxi2;
    for(int i = 0; i < n; ++i) {
        for (int j = packages[i]; j <= maxi; ++j) {
            if (u[j - packages[i]]) {
                u[j] = 1;
            }
        }
    }
    for(int i = maxi; i >= 1; --i) {
        if (!u[i]) {
            ans = i;
            break;
        }
    }
}

void out()
{
    ofstream cout("nuggets.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
