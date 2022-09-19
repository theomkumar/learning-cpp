#include <bits/stdc++.h> 
using namespace std;

bool findRedundantBrackets(string &s)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' ||
            s[i] == '-' ||
            s[i] == '*' ||
            s[i] == '/' ||
            s[i] == ')'  )
        {
                cnt++;
        }
    }
    while (cnt-- && s.size())
    {
        s.pop_back();
    }
    if (s.empty())
        return 0;
    return 1;
}