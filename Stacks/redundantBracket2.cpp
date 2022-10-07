using namespace std;
#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            bool isRedundant = 1;
            while (!st.empty() && st.top() != '(')
            {
                if (st.top() != ')')
                    isRedundant = 0;
                st.pop();
            }
            if (isRedundant)
                return 1;
            st.pop();
        }
    }
    return false;
}
