#include<iostream>
#include<vector>
using namespace std;


    //Function to find if there is a celebrity in the party or not.

##APPROACH 1: my brute force O(n^2) with O(1) space
    //logic for being celeb, 
    //celeb row = all 0s
    //celeb column = all 1 except diagonal (why, coz it's himself eg. 1,1 2,2 3,3)
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int celeb;
        for (int i = 0; i < n; i++)
        {
            celeb = i;
            //checking vertically, if all 1 can be celeb
            for (int j = 1; j < n; j++)
            {
                if (i != j && M[j][i] != 1)
                {
                    celeb = -1;
                    break;
                }
            }
            //checking horizontally if all 0 then it is celeb
            if (celeb == i)
            {
                int k = 0;
                while (k < n && M[celeb][k] == 0)
                    k++;
                if (k == n)
                    return celeb;
            }
        }
        return -1;
    }

int main() 
{
    
    return 0;
}