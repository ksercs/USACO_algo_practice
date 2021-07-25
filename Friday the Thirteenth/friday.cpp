/*
ID: Logan
PROG: friday
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

int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int ans[8];
int n, day = 1;

void in()
{
     ifstream cin ("friday.in");
     cin >> n;
}

void solution()
{
   for (int year = 1900; year < 1900 + n; year++)
   {
       if ( !(year%100)&&!(year%400) || (year%100!=0 && year%4==0) ) month[2]=29;
       else                                                          month[2]=28;
       //cout << year << " " << (bool)(month[2]==29) << "\n";
       for(int m = 1; m <= 12; m++)
       {
           int res;
           if (day == 1) res = 6;
           if (day == 2) res = 7;
           if (day != 1 && day != 2) res = day-2;
           ans[res]++;
           //cout << res << " ";
           day = (month[m]-(8-day))%7+1;
           //cout << day << "\n";
       }
       //system("PAUSE");
   }
}

void out()
{
        ofstream cout ("friday.out");
        cout << ans[6] << " " <<ans[7] << " " <<ans[1] << " " <<ans[2] << " " <<ans[3] << " " <<ans[4] << " " <<ans[5] << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
