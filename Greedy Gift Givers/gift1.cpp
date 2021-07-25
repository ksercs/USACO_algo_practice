/*
ID: Din
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

const int maxNP=10+2, minNP=2, maxName=14+2, maxMoney=2000;
string g, t, f;
string name[maxNP];
int ost, dal, n, m, k;
map < string, int > mp;
map < string, int >::iterator it;
pair <string, int> p_ch_int;

void in()
{
     ifstream cin ("gift1.in");
        cin >>n;
    for (int i=1; i<=n; i++)
    {
        cin >>name[i];
        p_ch_int.first=name[i];p_ch_int.second=0;
        mp.insert(p_ch_int);
    }
    for(int i=1; i<=n; i++)
    {
        cin >>g;
        cin >>m >>k;
        if (k==0) {mp[g]+=m;}
        else    {
        ost=m%k;
        dal=m/k;
        mp[g]+=ost; mp[g]-=m;
        for (int i=1; i<=k; i++)
        {
            cin >>t;
            mp[t]+=dal;
        }}
    }
}

void solution()
{

}

void out()
{
        ofstream cout ("gift1.out");
            for(int i=1; i<=n; i++)
    {
        f=name[i];
       cout <<f <<" " <<mp[f] <<"\n";
    }
}

int main()
{
in();
//solution();
out();
return 0;
}
