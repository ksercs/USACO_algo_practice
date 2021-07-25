/*
ID: Logan
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 5000+5;

int n, start_continue, finish_continue, max_continue, max_stop;
int times[2][MAX_SIZE];

void in()
{
    ifstream cin("milk2.in");
    cin >> n;
    for (int i = 0; i < n; i++ )
    {
        cin >> times[0][i];
        cin >> times[1][i];
    }
}

void solution()
{
    for (int  i = 0; i < n; i++)
    {
        for ( int j = i+1; j < n; j++ )
        {
            if ( times[0][i] > times[0][j] )
            {
                swap(times[0][i], times[0][j]);
                swap(times[1][i], times[1][j]);
            }
        }
    }
    start_continue = times[0][0];
    finish_continue =
    times[1][0];
    max_continue = finish_continue - start_continue;
    max_stop = 0;
    for (int i = 1; i < n; i++ )
    {
         if ( finish_continue < times[1][i] )
         {
            if ( times[0][i] <= finish_continue ) finish_continue = times[1][i];
            else
            {
                max_continue = max(max_continue, finish_continue - start_continue);
                max_stop = max(max_stop, times[0][i] - finish_continue);
                start_continue = times[0][i];
                finish_continue = times[1][i];
            }
        }
    }
}

void out()
{
    ofstream cout("milk2.out");
    cout << max_continue << " " << max_stop  << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
