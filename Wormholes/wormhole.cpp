/*
ID: Logan
PROG: wormhole
LANG: C++
*/

#include <iostream>
#include <fstream>

#define MAX_N 12

using namespace std;

int N, X[MAX_N+1], Y[MAX_N+1];
int wife[MAX_N+1];
int next_on_right[MAX_N+1];

bool cycle_exists()
{
    //cout << "YES\n";
  for (int start=1; start<=N; start++) {
    int pos = start;
    for (int count=0; count<N; count++)
      pos = next_on_right[wife[pos]];
    if (pos != 0) return true;
  }
  return false;
}

int solve()
{
  int i, total=0;
  //cout << i << endl;
  for (i=1; i<=N; i++)
    if (wife[i] == 0) {cout << "-----FIRST_BREAK:  " << i << endl; break;}

  if (i > N) { cout <<"!!!" <<i << ">N\n";
    if (cycle_exists()) return 1;
    else return 0;
  }

  for (int j=i+1; j<=N; j++)
    if (wife[j] == 0)
    {
        cout <<j << "\n";
      wife[i] = j;
      wife[j] = i;
      total += solve();
      wife[i] = wife[j] = 0;
    }
  return total;
}

void in()
{
    ifstream cin("wormhole.in");
    cin >> N;
    for (int i=1; i<=N; i++) cin >> X[i] >> Y[i];
}

void solution()
{
    for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
      if (X[j] > X[i] && Y[i] == Y[j])
            if (next_on_right[i] == 0 || X[j]-X[i] < X[next_on_right[i]]-X[i])
                next_on_right[i] = j;

   /* for (int i = 1; i <= N; i++)
    {
        cout << i <<" " << next_on_right[i] << "\n";
    }*/
}

void out()
{
    ofstream cout("wormhole.out");
    cout << solve() << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
