/*
ID: Logan
PROG: combo
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int a, b, c, x, y, z, n, cnt;

bool check1(int d, int f)
{
    if(abs(d-f)<=2) return 1;
    if(abs(d-f)>=n-2) return 1;
    return 0;
}

bool check(int a1,int b1,int c1,int a2,int b2,int c2)
{
    return (check1(a1,a2) && check1(b1,b2) && check1(c1,c2));
}

void in()
{
    ifstream cin("combo.in");
    cin >> n;
    cin >> a >> b >> c >> x >> y >> z;
}

void solution()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(check(i,j,k,a,b,c)||check(i,j,k,x,y,z))
                    cnt++;
}

void out()
{
   ofstream cout("combo.out");
   cout <<cnt <<endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
