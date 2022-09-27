using namespace std;

#include <bits/stdc++.h> 

bool findRedundantBrackets(string &s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' ||s[i] == '/')
        {
            st.push(s[i]);
        }
        else // ')' or alphabet
        {
            bool isRedundant = 1;
            if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    if (st.top() != ')')//this mean st.top is operator
                    {
                        isRedundant = 0;
                    }
                    st.pop();
                }
                if (isRedundant == 1) return 1;
                st.pop(); //popping corresponding '('
            }
        }
        return 0;
    }

}