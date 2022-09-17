/*
###APPROACH 1: using stack with time O(n) SC O(n)

class Solution {
public:
    bool isValid(string str) {

        stack<char> s;

        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];

            //if opening bracket, push in stack
            if (ch == '{' || ch == '[' || ch == '(')
                s.push(ch);

            //if closing bracket
            else
            {
                if (!s.empty())
                {   
                    //top contains previous opening bracket, while ch contains closing bracket;
                    char top = s.top();

                    if (top == '[' && ch == ']' || 
                        top == '(' && ch == ')' ||
                        top == '{' && ch == '}')
                    {
                        s.pop();
                    }
                    else
                        return 0;
                }
                else //if stack is empty and we found closing bracket then 
                    return 0;
            }
        }
        if (s.empty())
            return true;
        return false;
    }
};

*/