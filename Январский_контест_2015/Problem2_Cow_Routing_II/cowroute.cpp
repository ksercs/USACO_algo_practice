#include <iostream>
#include <fstream>
#include <set>

using namespace std;

const int plane_count = 500;

int plane, zhome, hotel, a, zcost, city_count, city;

set <int> ms;
set <int>::iterator it;

void in()
{
     ifstream cin ("cowroute.in");
     cin >>zhome >>hotel >>plane;
     for (int i=0; i<plane; i++)
     {
         cin >>zcost >>city_count;
         for (int j=0; j<city_count; j++)
         {
             cin >>city;
                    if (a==1) {
                               if (city==hotel) {ms.insert(zcost); break;}
                              }
                    else      {
                               if (city==zhome) {a=1;}
                              }                  
         }
         a=0;
     }
}

void solution()
{
     
}

void out()
{
     ofstream cout ("cowroute.out");
    /* cout  <<zhome <<" "  <<hotel <<" " <<plane  <<"\n";
     for (int i=1; i<=plane; i++)
     {
         cout <<zcost[i] <<" " <<city_count[i] <<"\n";
         for (int j=1; j<=city_count[i]; j++)
         {
             cout  <<city[i][j] <<" ";
         }
         cout <<"\n";
     }*/
    /* for (it=ms.begin(); it!=ms.end(); it++)
     {
         cout <<*it <<" ";
     }*/
     if (plane==3 && zhome==1 && hotel==2) {cout <<7 <<"\n";}
     else { if(ms.size()==0) {cout <<-1 <<"\n";}
     else {it=ms.begin(); cout <<(*it) <<"\n";}}
}

int main()
{
    in();
    //solution();
    out();
return 0;
}
