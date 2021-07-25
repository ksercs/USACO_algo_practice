/*
ID: Logan
PROG: humble
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
#include <climits>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXN = 100+5;

int n, k;
LL ans, ch, nch;
LL mass[MAXN];
set <LL> st;
set <LL>:: iterator it;

void in()
{
    ifstream cin("humble.in");
    ios_base:: sync_with_stdio(false);
    cin >> k >> n;
    for (int i = 0; i < k; i++)
        cin >> mass[i];
}

void solution()
{
   // ofstream cout("humble.txt");
    ch = mass[0];
    while (ch <= INT_MAX){
        st.insert(ch);
        if (st.SZ == n || ch*mass[0] > INT_MAX) break;
        //printf("%lu ", ch); system("PAUSE");
        ch *= mass[0];
    }
    /*printf("\n");
    for (it = st.begin(); it != st.end(); it++)
        printf("%lu ", (*it));*/
    for (int i = 1; i < k; i++){
        /*cout << "SZ = " << st.SZ << "\n";
       for (it = st.begin(); it != st.end(); it++)
            cout << (*it) << " ";
        cout << "\n";*/
        ch = mass[i];
        while (ch <= INT_MAX){
            //cout << ch << "\n";
            if (ch < (*st.rbegin()) || st.SZ < n){
                        st.insert(ch);
                        if (st.SZ > n) st.erase((*st.rbegin()));
                       // cout << " -- ";
                        for (it = st.begin(); it != st.end(); it++){
                            if ((*it) % ch != 0 && ((*it)*ch) <= INT_MAX){
                                nch = (*it)*ch;
                                if (nch < (*st.rbegin()) || st.SZ < n) {
                                    //cout  << nch  << " ";
                                    st.insert(nch);
                                    if (st.SZ > n)  st.erase((*st.rbegin()));
                                }
                                else    break;
                            }
                        }
                        //cout << "\n";
            }
            else break;
            ch *= mass[i];
        }
        /*cout << "\nSZ = " << st.SZ << "\n";
       for (it = st.begin(); it != st.end(); it++)
            cout << (*it) << " ";
        cout << "\n\n"; //system("PAUSE");*/
    }
    ans =(*st.rbegin());
    /*cout << st.SZ << "\n";
    for (it = st.begin(); it != st.end(); it++)
        cout << (*it) << " ";*/

}

void out()
{
    ofstream cout("humble.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
