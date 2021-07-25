/*
ID: Logan
PROG: msquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <utility>
#include <queue>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

string sq = "        ", ans;
map <string, int> u;
queue <pair<string, string> > q;

string v1 (string s)
{
    s = s.substr(4,4)+s;
    s.erase(8,4);
    return s;
}

string v2 (string s)
{
    return (s[3]+s.substr(0,3)+s[7]+s.substr(4,3));
}
string v3 (string s)
{
    char a = s[1], b = s[2], c = s[5], d = s[6];
    s[2] = a;
    s[6] = b;
    s[5] = d;
    s[1] = c;
    return s;
}

void BFS()
{
    while (!q.empty()){
        string str = q.front().FF;
        string answer = q.front().SS;
       // if (answer.SZ == 7) {cout << str << " " << answer << " || " << sq << " SQ.SZ " << sq.SZ << " STR.SZ " << str.SZ  << "\n"; system("PAUSE");}
        if (str == sq) {ans = answer; break;}
        string s1, s2, s3;
        s1 = v1(str);
        s2 = v2(str);
        s3 = v3(str);
        if (!u[s1]){
            u[s1] = 1;
            q.push(MP(s1,answer+'A'));
        }
        if (!u[s2]){
            u[s2] = 1;
            q.push(MP(s2,answer+'B'));
        }
        if (!u[s3]){
            u[s3] = 1;
            q.push(MP(s3,answer+'C'));
        }
        q.pop();
    }
}

void in()
{
    ifstream cin("msquare.in");
    for (int i = 0; i < 8; i++)
        cin >> sq[i];
}

void solution()
{
    char a = sq[4], b = sq[5];
    sq[4] = sq[7];
    sq[5] = sq[6];
    sq[6] = b;
    sq[7] = a;
    //cout << sq << " " << sq.SZ << "\n";
    q.push(MP("12348765",""));
    u["12348765"]=1;
    BFS();
}

void out()
{
    ofstream cout("msquare.out");
    cout << ans.SZ << "\n" << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
