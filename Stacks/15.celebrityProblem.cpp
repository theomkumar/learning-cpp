#include<bits/stdc++.h>

using namespace std;


    //Function to find if there is a celebrity in the party or not.

##APPROACH 1: my brute force O(n^2) with O(1) space
    //logic for being celeb, 
    //celeb row = all 0s
    //celeb column = all 1 except diagonal (why, coz it's himself eg. 1,1 2,2 3,3)

   int celebrity(vector<vector<int> >& M, int n) 
    {
        for (int i = 0; i < n; i++)
        {
            //traversing row
            bool isCeleb = 1;
            for (int j = 0; j < n; j++)
            {
                if (M[i][j] == 1)
                    {
                        isCeleb = 0;
                        break;
                    }
            }
            if (isCeleb == 0)   continue;
            
            //traversing col     
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;
                if (M[j][i] == 0)
                {
                    isCeleb = 0;    
                    break;
                }
            }
            if(isCeleb == 1)
                return i;
        }
        return -1;
    }

##APPROCH 2: OPTIMISED USING STACK
//Logic push all indices in stack and compare the top(A) and one below element(B), if A knows B then A is not celeb so we'll pop A and vice versa.
// then check condition for being celeb. 

int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for (int i = 0; i < n; i++)
            st.push(i);

        while (st.size() > 1)
        {
            int A = st.top();
            st.pop();

            int B = st.top();
            st.pop();
        
            //a knows b
            if (M[A][B] == 1)
                st.push(B);

            else //b knows a
                st.push(A);
        }
        //single element present in stack is potential celeb

        //check row 
        int celeb = st.top();
        for (int i = 0; i < n; i++)
        {
            if (M[celeb][i] == 1)
                return -1;
        }
        //check col
        for (int i = 0; i < n; i++)
        {
            if (i == celeb) continue;
            if (M[i][celeb] == 0)
                return -1;
        }
        return celeb;
    }
/*  //did this first intuitively 
        while (st.size() > 1)
        {
            //popping top, so we could compare it with below element 

            int A = st.top();
            st.pop();

            int B = st.top();

            //if both know/don't know each other pop both! A is already popped so we'll pop B

            if (M[B][A] == 1 && M[A][B] == 1 || M[B][A] == 0 && M[A][B] == 0)
                st.pop();

            //only B knows A; (then B is not celeb & A is potential celeb so, we'll push it back)
            else if (M[B][A] == 1 && M[A][B] == 0)
            {
                st.pop();//pop B
                st.push(A);
            }
            //else only A knows B, it means A is not celeb, we have already popped A before and B is potential celeb i.e already +nt in stack so we'll do nothing
        }
        if (st.empty())
            return -1;
        //check row and col
*/
int main() 
{
    
    return 0;
}