/*
ID: Logan
PROG: lamps
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

#define VEC vector
#define SZ size()
#define PB push_back

using namespace std;

int n, c, lvl=1;

VEC <int> ON, OFF;
queue < VEC <bool> > q;
map < VEC <bool>, bool> u;
set <VEC <bool> > ans;

bool check(VEC <bool> V)
{
    for (int i = 0; i < ON.SZ; i++)
        if (!V[ON[i]])  return false;
    for (int i = 0; i < OFF.SZ; i++)
        if (V[OFF[i]])  return false;
    return true;
}

VEC <bool> pressB(int B, VEC <bool> v)
{
    /*for (int i = 0; i < v.SZ; i++)
        {
            cout << v[i] << " ";
        }*/
    switch (B)
    {
        case 0:
            for ( int i = 1; i < v.SZ; i++ ) v[i] = !v[i];
            break;
        case 1:
            for ( int i = 1; i < v.SZ; i += 2 ) v[i] = !v[i];
            break;
        case 2:
            for ( int i = 2; i < v.SZ; i += 2 ) v[i] = !v[i];
            break;
        case 3:
            for ( int i = 1; i < v.SZ; i += 3 ) v[i] = !v[i];
            break;
    }
    return v;
}

void BFS()
{
     while ( !q.empty() )
     {
        VEC <bool> step;
        step = q.front();
        /*for (int i = 0; i < step.SZ; i++)
        {
            cout << step[i] << " ";
        }
        cout << endl;*/
        if( check(step) ) ans.insert(step);
        if(lvl > 0)
        {
            VEC <bool> to;
            for ( int i = 0; i < 4; i++ )
            {
                to = pressB (i, step);
                if(!u[to])
                {
                    u[to] = 1;
                    q.push(to);
                }
                lvl--;
            }
        }
        q.pop();
     }
}

void in()
{
    ifstream cin("lamps.in");
    cin >> n;
    cin >> c;
    c = min(c, 4);
    int elem = 0;
    while (elem != -1)
    {
        cin >> elem;
        ON.PB(elem);
    }
    ON.pop_back();
    elem = 0;
    while (elem != -1)
    {
        cin >> elem;
        OFF.PB(elem);
    }
    OFF.pop_back();
    /*for (int i = 0; i < ON.SZ; i++)
        cout << ON[i] << " ";
    cout << endl;
    for (int i = 0; i < OFF.SZ; i++)
        cout << OFF[i] << " ";
    cout << endl;*/
}

void solution()
{
    VEC <bool> st(n+1, true);
    q.push(st);
    u[st] = 1;
    for ( int i = 0; i < c; i++ ) lvl *= (4 - i);
    if(c == 0) lvl = 0;
    BFS();
}

void out()
{
    ofstream cout("lamps.out");
    if(ans.SZ == 0)   cout <<"IMPOSSIBLE\n";
    else
    {
        set< VEC <bool> >::iterator it;
        for(it = ans.begin(); it != ans.end(); it++)
        {
            for (int i = 1; i < (*it).size(); i++ )
            {
                cout << (int)(*it)[i];
            }
            cout << endl;
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
