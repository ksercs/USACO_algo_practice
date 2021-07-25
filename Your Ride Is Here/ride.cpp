/*
ID: Logan
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using  namespace std;

int i, g, sum1=1, sum2=1, y, x, rez1, rez2 ;
unsigned char mass1, mass2;
char comet[7], group[7];

int main()
{
    ifstream cin ("ride.in");
    ofstream cout ("ride.out");
    cin >>comet >>group;
    
y=strlen(comet);
for (i=0; i<=y-1; i++)
    { 
      mass1=comet[i];
      mass1=(int)mass1-64;
      sum1=sum1*(int)mass1;
    }
   //     cout <<sum1<<"\n";
x=strlen(group);
for (g=0; g<=x-1; g++)
    { 
      mass2=group[g];
      mass2=(int)mass2-64;
      sum2=sum2*(int)mass2;
    }
  //  cout <<sum2<<"\n";
rez1=sum1%47;
rez2=sum2%47;
if (rez1==rez2) {cout <<"GO\n";}
else            {cout <<"STAY\n";}
return 0;
}
