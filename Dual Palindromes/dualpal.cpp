/*
ID: Logan
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n, s, cnt, tmp;
vector <int> ans;

string convert(int n, int base)
{
    string str;
    int x;
    char ch;
    while(n)
    {
        x=n%base;
        if(x>9)
            ch='A'+x-10;
        else
            ch='0'+x;
        str+=ch;
        n/=base;
    }
    reverse(str.begin(), str.end());
    return str;
}

bool ispal(string str)
{
    int len=str.size();
    if(str[0]=='0' || str[len-1]=='0')
        return false;

    for(int i=0; i<len/2; i++)
        if(str[i]!=str[len-1-i])
            return false;
    return true;
}

void in()
{
    ifstream cin("dualpal.in");
    cin >> n >> s;
}

void solution()
{
    for(int i=s+1; cnt<n; i++)
    {
        tmp=0;
        for(int j=2; j<11; j++)
        {
            if(ispal(convert(i,j)))
                tmp++;
            if(tmp==2)
            {
                ans.push_back(i);
                cnt++;
                break;
            }
        }
    }
}

void out()
{
    ofstream cout("dualpal.out");
    for (int i = 0 ; i < ans.size(); i++)
    {
        cout << ans[i] <<endl;
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
