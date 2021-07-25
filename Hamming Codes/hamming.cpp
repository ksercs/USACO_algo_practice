/*
ID: Logan
PROG: hamming
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

#define VEC vector
#define SZ size()
#define PB push_back

using namespace std;

int n, b, d, cnt;

VEC <int> cod;

string toBinaryString (int ch)
{
    string binary = "";
    int mask = 1;
    for(int i = 0; i < 31; i++)
    {
        if(mask&ch)
            binary = "1"+binary;
        else
            binary = "0"+binary;
        mask<<=1;
    }
    return binary;
}

int hamming(int a, int b)
{
     int ch = 0;
     string A = toBinaryString(a), B = toBinaryString(b);
     if (A.SZ > B.SZ)
        while (A.SZ > B.SZ) B = "0" + B;
     else if (A.SZ < B.SZ)
        while (A.SZ < B.SZ) A = "0" + A;
     for (int i = 0; i < A.SZ; i++) if (A[i] != B[i]) ch++;
     return ch;
}

void in()
{
    ifstream cin ("hamming.in");
    cin >> n >> b >> d;
}

void solution()
{
    cod.PB(0);
    cnt++;
    for (int i = 0; i < (int) pow(2, b); i++)
    {
        if (cnt == n) break;
        bool fl = true;
        for (int j = 0; j < cod.SZ; j++)
        {
            if ( hamming(i, cod[j]) < d) fl = false;
        }
        if (fl)
        {
            cod.PB(i);
            cnt++;
        }
    }
}

void out()
{
    ofstream cout ("hamming.out");
    for (int i = 0; i < n; i++)
    {
        if (i % 10 == 0 && i > 0) cout << endl;
        !(i % 10)  ? cout << cod[i] : cout << " " << cod[i];
    }
    cout << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
