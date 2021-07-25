/*
ID: Logan
PROG: skidesign
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, mincost=1000000000, hills[1000];

void in()
{
    ifstream cin("skidesign.in");
    cin >> n;
    for (int i=0; i<n; i++)
		cin >> hills[i];

}

void solution()
{
	for (int i=0; i<=83; i++)
    {
		int cost=0, x;
		for (int j=0; j<n; j++)
		{
			if (hills[j]<i)
				x=i-hills[j];
			else if (hills[j]>i+17)
				x=hills[j]-(i+17);
			else
				x=0;
			cost+=x*x;
		}
		mincost=min(mincost,cost);
	}
}

void out()
{
    ofstream cout("skidesign.out");
    cout << mincost << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
