//https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=1

/*

// APPROACH 1 : my method by observation and dry run
/2/look at refined approach 2 (same as this one)

##ODD
//do dry run with }}}{{{ odd no. of close and open .

}}} -> 1 operation -> { one invalid left
{{{ -> 1 operation -> } one invalid left
 1 more operation needed to { and } valid
 open brackets (n+1)/2 

#2 we can also think like (odd - 1) = even and for even we need to do n/2 operation, and then we'll add the one!

#EVEN
}}}} -> even 4/2 operation needed or 4+1/2 == 2



int findMinimumCost(string str) {
    if (str.size() % 2)    return -1;
 
    stack<char> st;

    int invalid = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '{')
            st.push(str[i]);
        
        else if (!st.empty())
            st.pop();
        
        else
            invalid++;
    }
    // eg -> }}}} if invalid is even we need invalid/2 operation ({{ -> we need one operation to make it valid, while 
// for odd eg-> {{{ we need 1 operation for {{ and one more for } 
//same logic with st.size();
    
    invalid = invalid % 2 ? (invalid - 1)/2 + 1 : invalid / 2; 
    invalid += st.size() % 2 ? (st.size()-1)/2 + 1 : st.size() / 2;

    return invalid;

    /*
    if (invalid % 2 == 0)
        invalid /= 2;
    else
        invalid = (invalid - 1)/2 + 1;

    int ans = st.size();
    if (ans % 2 == 0)
        ans /= 2;
    else 
        ans = (ans-1)/2 + 1;
    
    ans += invalid;
    
    return ans;

Approach 2: same as above refined

//invalid will store (invalid '}') while st will store invalid '{'

int findMinimumCost(string str) {
    if (str.size() % 2)    return -1;
 
    stack<char> st;

    int invalid = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '{')
            st.push(str[i]);
        
        else if (!st.empty())
            st.pop();
        
        else
            invalid++;
    }
    
    invalid = (invalid + 1)/2;  // (a-1)/2 + 1 == (a+1)/2
    invalid += (st.size()+1)/2;

    return invalid;
}
Approach 3: Babbar Approach

int findMinimumCost(string str) 
      
{
    //odd condition
    if (str.length() % 2)
        return -1;
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
        {
            s.push('{');
        }
        else
        {
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else //we'll push invalid '}'
            {
                s.push('}');
            }
        }
    }
        //stack contains invalid expression we'll count a and b (i.e opening and closing bracket);

        int a = 0, b = 0;
        while (!s.empty())
        {
            if (s.top() == '{')
                a++;
            else 
                b++;
        }
        return ((a+1)/2 + (b+1)/2);

}
*/