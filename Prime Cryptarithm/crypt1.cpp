/*
ID: Logan
PROG: crypt1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int a[10];
int n, cnt;

bool fnd (int x)
{
    for ( int i = 0; i < n; i++ ) {
        if ( a [i] == x )
            return true;
    }

    return false;
}

void function (int p, int q, int r, int s, int t)
{
    //cout << p << " " << q << " " << r << " " << s << " " << t << "\n";
    int ff = p * 100 + q * 10 + r;
    int ss = s * 10 + t;
    //cout << ff << " " << ss <<  "\n";
    if ( ff * ss > 9999 ) return;

    int tmp = ff * t;
    //cout << tmp << "\n";
    if ( tmp > 999 ) return;

    while ( tmp != 0 ) {
        if ( !fnd (tmp % 10) ) return;
        tmp /= 10;
    }

    //cout << tmp << "\n";
    tmp = ff * s;
    if ( tmp > 999 ) return;

    while ( tmp != 0 ) {
        if ( !fnd (tmp % 10) ) return;
        tmp /= 10;
    }
    //cout << tmp << "\n";
    //system("PAUSE");
    tmp = ff * ss;

    while ( tmp != 0 ) {
        if ( !fnd (tmp % 10) ) return;
        tmp /= 10;
    }

    cnt++;

}

void in()
{
    ifstream cin("crypt1.in");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        //lcout << a[i] << "\n";
    }
}

void solution()
{
  for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            for ( int d = 0; d < n; d++ ) {
                for ( int f = 0; f < n; f++ ) {
                    for ( int g = 0; g < n; g++ )
                        {
                            int I = a[i], J = a[j], D = a[d], F = a[f], G = a[g];
                            function (I, J, D, F, G);
                        }
                }
            }
        }
    }
}

void out()
{
    ofstream cout("crypt1.out");
    cout << cnt << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
