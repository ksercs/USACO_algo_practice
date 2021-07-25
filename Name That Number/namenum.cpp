/*
ID: Logan
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector <string> ans;
string str, name;
bool found = false;

string DECODE = "22233344455566670778889990";

char getKeyFor(char c)
{
	return DECODE[c - 'A'];
}

string getIdFor(string name) {
	string id = "";
	for(int i = 0; i < name.length(); i++) {
		char key = getKeyFor(name[i]);
		if(key == 0)
			return 0;
		id += key;
	}
	return id;
}

void in()
{
  ifstream cin("namenum.in");
  cin >> str;
}

void solution()
{
    ifstream dict("dict.txt");
    while(dict >> name)
    {
        string number = getIdFor(name);
        if(number == str)
        {
           // cout << name << "\n";
          ans.push_back(name);
          found = true;
        }
	}
	if(!found) ans.push_back("NONE");
}

void out()
{
    ofstream cout("namenum.out");
    if (ans.size() > 1)
    {
      for (int i = 0; i < ans.size()-1; i++)
      {
          cout << ans[i] << endl;
      }
    }
    cout << ans[ans.size()-1] << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
