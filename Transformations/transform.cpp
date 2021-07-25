/*
ID: Logan
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int n, result;

struct board
{
    vector< vector<int> > representation;
};

board start, transformed;

bool BoardsAreEqual(board &A, board &B)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(A.representation[i][j] != B.representation[i][j]) return false;
        }
    }
    return true;
}

bool is90deg(board A, board B)
{
    int upperLimit = n-1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(A.representation[i][j] != B.representation[j][upperLimit - i]) return false;
        }
    }
    return true;
}

bool is180deg(board A, board B)
{
    int upperLimit = n-1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(A.representation[i][j] != B.representation[upperLimit-i][upperLimit - j]) return false;
        }
    }
    return true;
}

bool is270deg(board A, board B)
{
    int upperLimit = n-1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(A.representation[i][j] != B.representation[upperLimit - j][i]) return false;
        }
    }
    return true;
}

bool isReflection(board A, board B)
{
    int upperLimit = n-1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(A.representation[i][j] != B.representation[i][upperLimit - j]) return false;
        }
    }
    return true;
}

board reflect(board B)
{
    int uppperLimit = n-1;
    vector< vector<int> > generated;
    generated.resize(n);
    for(int i = 0; i < n; ++i)
    {
        generated[i].resize(n);
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            generated[i][j] = B.representation[i][uppperLimit - j];
        }
    }
    board a;
    a.representation = generated;
    return a;
}

void in()
{
    ifstream cin("transform.in");
    cin >> n;
    vector< vector<int> >rep;
    rep.resize(n);
    for(int i = 0; i < n; ++i)
    {
        rep[i].resize(n);
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            char current;
            cin >> current;
            rep[i][j] = current;
        }
    }
    start.representation = rep;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            char current;
            cin >> current;
            rep[i][j] = current;
        }
    }
    transformed.representation = rep;
}

void solution()
{
    if(is90deg(start, transformed)) result = 1;
    else if(is180deg(start, transformed)) result = 2;
    else if(is270deg(start, transformed)) result = 3;
    else if(isReflection(start, transformed)) result = 4;
    else if(is90deg(reflect(start), transformed) || is180deg(reflect(start), transformed) || is270deg(reflect(start), transformed)) result = 5;
    else if(BoardsAreEqual(start, transformed)) result = 6;
    else result = 7;
}

void out()
{
  ofstream cout("transform.out");
  cout << result << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
