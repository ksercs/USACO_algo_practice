/*
ID: Logan
PROG: preface
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int n;

char seq[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
map <int, int> cnt;
map <int, int>:: iterator it;
map <char, int> roman2int;
map <int, char> int2roman;

string mp[4][10] =
    {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
    {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
    {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
    {"", "M", "MM", "MMM", "", "", "", "", "", ""}};

string getRoman(int ch)
{
    string ret = "";
    int pos = 0;
    while (ch > 0) {
        int p = ch % 10;
        ch = ch / 10;
        ret += mp[pos][p];
        pos++;
    }
    return ret;
}

void get_ans(string r)
{
    for (int i = 0; i < r.size(); i++)
    {
        char c = r[i];
        cnt[roman2int[c]]++;
    }
}

void in()
{
    ifstream cin("preface.in");
    cin >> n;
}

void solution()
{
    for (int i = 0; i < 7; ++i)
    {
        roman2int[seq[i]] = i;
        int2roman[i] = seq[i];
    }
    for (int i = 1; i <= n; ++i) get_ans(getRoman(i));
}

void out()
{
    ofstream cout("preface.out");
    for (it = cnt.begin(); it != cnt.end(); it++)
    {
        pair <int, int> p = (*it);
        cout << int2roman[p.first] << " " << p.second << endl;
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
