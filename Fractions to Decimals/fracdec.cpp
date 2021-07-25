/*
ID: Logan
PROG: fracdec
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

#define SZ size()

using namespace std;

ifstream in("fracdec.in");
ofstream out("fracdec.out");

int N, D, r, fl = 1;

string convertInt(int number)
{
   stringstream ss;
   ss << number;
   return ss.str();
}

void output(string answer){
    if(answer.SZ <= 76) out << answer << endl;
    else{
        for(int i = 0; i < answer.length(); i += 76){
            out << answer.substr(i, 76) << endl;
        }
    }
}

int main()
{
    in >> N >> D;
    int R[D];
    memset(R, -1, sizeof(R));

    r = N % D;
    R[r] = 0;
    string frac = "";
    while(fl){
        frac += convertInt(r * 10 / D);
        r = r * 10 % D;
        if(r == 0){
            output(convertInt(N / D) + "." + frac);
            return 0;
        }
        if(R[r] != -1) fl = 0;
        else R[r] = frac.SZ;
    }
    frac = frac.substr(0, R[r]) + "(" + frac.substr(R[r], frac.SZ) + ")";
    if(frac.substr(frac.SZ - 3, 3) == "(0)") frac = frac.substr(0, frac.SZ - 3);
    output(convertInt(N / D) + "." + frac);
}
