/*
ID: Logan
PROG: ariprog
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

#define MAX_CNT 125005

bool arr[MAX_CNT]={false}, answer;
int M,N;

ifstream fin("ariprog.in");
ofstream fout("ariprog.out");

void in()
{
   fin >> N >> M;
}

void solution()
{
    for (int i=0;i<=M;i++)
        for(int j=i;j<=M;j++)
            arr[(i*i+j*j)]=true;
    for(int d=1;d<=M*M*2/(N-1);d++){
        for(int a=0;a<=((M*M));a++){
            bool found=true;
            for(int n=0;n<N;n++){
                if(!arr[a+n*d]){
                    found=false; break;
                }
            }
            if(found){
                fout << a <<" " <<d <<endl;
                answer = true;
                }
        }
    }
}

void out()
{
    if (!answer) fout << "NONE"<<endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
