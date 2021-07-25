/*
ID: Logan
PROG: fence6
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <queue>

#define VEC vector
#define SZ size()
#define PB push_back

using namespace std;

const int MAXN = 100 + 15;

int n, ans = INT_MAX;
int len[MAXN], p[MAXN], u[MAXN];
VEC<VEC <int>> gr;
queue<int> q;

void getAns(int vertex) {
    int i = vertex;
    int res = len[i];
    cout << i << " " << len[i] << "\n";
    i = p[i];
    while(i != vertex) {
        res += len[i];
        i = p[i];
        cout << i << " " << len[i] << "\n";
    }
    cout << "RES = " << res << "\n\n\n";
    ans = min(ans, res);
}

void BFS(int vertex) {
    while(!q.empty()) {
        int ind = q.front();
        u[ind] = 1;
        cout << "V = " << ind << "\n";
        for(int i = 0; i < gr[ind].SZ; ++i) {
            int to = gr[ind][i];
            if (!u[to] && p[ind] != to) {
                cout << "to " << to << "\n";
                q.push(to);
                p[to] = ind;
            } else if (to == vertex && p[ind] != to){
                cout << "MAYBE " << to << "\n";
                p[to] = ind;
                getAns(to);
                return;
            }
        }
        q.pop();
        u[ind] = 0;
    }
}

void in() {
    ifstream cin("fence6.in");
    cin >> n;
    gr.resize(n + 5);
    for(int i = 1; i <= n; ++i) {
        int num = 0, cnt1 = 0, cnt2 = 0;
        cin >> num;
        cin >> len[num] >> cnt1 >> cnt2;
        //cout << "---->>>>>" << num << " " << len[num] << "\n";
        for(int i = 0; i < cnt1; ++i) {
            int a = 0;
            cin >> a;
            gr[a].PB(num);
            gr[num].PB(a);
        }
        for(int i = 0; i < cnt2; ++i) {
            int a = 0;
            cin >> a;
            gr[a].PB(num);
            gr[num].PB(a);
        }
    }
}

void solution() {
    for (int i = 1; i <= n; ++i) {
        u[i] = 1;
        q.push(i);
        cout << "START    " << i << "\n";
        BFS(i);
        while(!q.empty()){
            q.pop();
        }
        fill(u, u + MAXN, 0);
        fill(p, p + MAXN, 0);
    }
}

void out() {
    ofstream cout("fence6.out");
    cout << ans << "\n";
}

int main() {
    in();
    solution();
    out();
    return 0;
}
