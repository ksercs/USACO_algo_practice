/*
ID: Logan
PROG: barn1
LANG: C++
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;


const int MAXN = 1e3 ;

int m, s, c, totalStalls, totalBoard;

vector <int> stall;

bool used[MAXN];

int minStall()
{
	int mini = MAXN + 123 ;
	int minIndex = MAXN + 123 ;

	for (int i=0; i<stall.size()-1; i++)
	{
		if (stall[i+1] - stall[i] < mini && !used[i] )//&& stall[i+1] - stall[i])
		{
			mini = stall[i+1] - stall[i];
			minIndex = i;
		}

	}
	mini -- ;
	used[minIndex] = true;
	cout << minIndex << " " << mini << "\n";
	return mini;
}

void in()
{
    ifstream cin("barn1.in");
    cin >> m >> s >> c;
    for (int i = 0; i < c; i++)
	{
		int inp;
		cin >> inp;
		stall.push_back(inp);
	}
}

void solution()
{
    sort(stall.begin(), stall.end());
    totalStalls = c;
	totalBoard = c;
    while (totalBoard > m)
	{
		int a = minStall();
		totalBoard -- ;
		totalStalls += a ;

	}
}

void out()
{
    ofstream cout("barn1.out");
    cout << totalStalls << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
