/*
ID: Logan
PROG: runround
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

#define LL long long
#define SZ size()

using namespace std;

int n, ans, fl, cnt;
int u[19], used[19];
string s;

string IntToStr(int num)
{
    string str;
    while (num > 0)
    {
        int a = num%10;
        //if (used[a] || a == 0) fl = 1;
        //used[a]++;
        str = (char)(a+'0')+str;
        num /= 10;
    }
    return str;
}

/*bool get_ans(int i, int r, char res)
{
    cnt++;
    u[i] = 1;
    int w = s[i]-'0';
    i = (i+w)%r;
    //cout << s[i] << " " << res << endl;
    if (s[i] == res && cnt == r) return true;
    if (u[i]) return false;
    get_ans(i, r, res);
}*/

bool check(int ch)
{
    fill(u, u+19, 0);
    /*fill(used, used+19, 0);
    fl = 0; cnt = 0;
    //cout << "ch:" << ch << endl;
    s = LLtoStr(ch);
    //cout <<"s: " << s << " " << fl << endl;
    if (fl) return false;*
    return get_ans(0, (int)s.SZ, s[0]);*/
    s = IntToStr(ch);
    //cout << s << ": ";
    int sz = (int)s.SZ;
    int ind = 0, w = s[0]-'0';
    for ( int i = 0; i < sz; i++ )
    {
        ind = (ind + w) % sz;
        w = s[ind] - '0';
        u[w]++;
        if(!w || u[w] > 1)  return false;
    }
    return true;
}

void in()
{
    ifstream cin("runround.in");
    cin >> n;
}

void solution()
{
    while(1)
    {
        n++;
        if (check(n)) break;
    }
}

void out()
{
    ofstream cout("runround.out");
    cout << n << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
