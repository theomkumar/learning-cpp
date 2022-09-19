#include <bits/stdc++.h> 
using namespace std;


//logic : a backet is redundant if it doesn't enclose an operator within it (ignore alphabets), eg: (a+b) == (+) is not redundent;
//eg: ((4+8)) => ((+)) (inner bracket has operator in it so it's not redundant but..) => (12) outer bracket has no operator so it's redundant overall; 


bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' ||
                                                     ch == '/' )
        {
            st.push(ch);
        }
        else //(ch == ')' or alphabet)
        {
            if (ch == ')')
            {
                bool isReduntant = true;
                while ( st.top() != '(')
                {
                    char top = st.top();
                    // if (top == '+' || top == '-' || top == '*' || top == '/')
                     if (top != ')') // coz the stack only contains ')' and operators.
                    {
                        isReduntant = false;
                    }
                    st.pop();
                }
                if (isReduntant == true)
                    return true;
                //to remove opening bracket
                st.pop();
            }
        }
    }
    return false;
}

