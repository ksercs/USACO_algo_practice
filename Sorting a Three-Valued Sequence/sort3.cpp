/*
ID: Logan
PROG: sort3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

const int MAXN = 1000 + 5;

using namespace std;

int n, ans;

int mass[MAXN], smass[MAXN];

void in()
{
    ifstream cin ("sort3.in");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> mass[i];
        smass[i] = mass[i];
    }
}

void solution()
{
    sort(smass, smass+n);
    for (int i = 0; i < n; ++i)
    {
        if (smass[i] != mass[i])
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (mass[j] == smass[i] && smass[j] == mass[i])
                {
                    ans++;
                    swap(mass[i], mass[j]);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (smass[i] != mass[i])
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (mass[j] == smass[i] && smass[j] == mass[i])
                {
                    ans++;
                    swap(mass[i], mass[j]);
                    break;
                }
            }
        }
    }
    /*for (int i = 0; i < n; i++)
    {
        cout << mass[i] << " ";
    }
    cout << endl;*/
    for (int i = 0; i < n; ++i)
    {
        if (smass[i] != mass[i] && mass[i] == 1)
        {
            ans += 2;
        }
    }
}

void out()
{
     ofstream cout ("sort3.out");
     cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
