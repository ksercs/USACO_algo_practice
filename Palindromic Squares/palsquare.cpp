/*
ID: Logan
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int osn;
vector <string> ans1, ans2;

string vecString(vector<char> number)
{
    string res;
    for(int i = 0; i < number.size(); ++i)
    {
        res.push_back(number[i]);
    }
    return res;
}

bool isPalindromic(vector<char>  number)
{
    int size = number.size();
    int median = size / 2;
    for(int i = 0; i <= median; ++i)
    {
        if(number[i] != number[size - i - 1]) return false;
    }
    return true;
}

vector <char> convert(int number, int base)
{
    vector<char> representation;
    while(number != 0)
    {
        int remainder = number % base;
        number /= base;
        if(remainder <= 9) representation.push_back(remainder + '0');
        else representation.push_back((remainder - 10) + 'A');
    }
    reverse(representation.begin(), representation.end());
    return representation;
}

void in()
{
    ifstream cin("palsquare.in");
    cin >> osn;
}

void solution()
{
    for (int i = 1; i <= 300; ++i)
    {
        vector <char> toCheckInBase = convert(i*i, osn);
        if(isPalindromic(toCheckInBase))
        {
            ans1.push_back(vecString(convert(i, osn)));
            ans2.push_back(vecString(toCheckInBase));
        }
    }
}

void out()
{
    ofstream cout("palsquare.out");
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << ans1[i] << " " << ans2[i] << endl;
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
