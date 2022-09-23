#include<iostream>
using namespace std;
//Approach : INTUITION it's basically like fibonacci


// num_ways(3stairs) = num_ways(2stairs) + num_ways(1)

// num_ways(n) = num_ways(n-1) + num_ways(n-2);

//https://leetcode.com/problems/climbing-stairs/
int climbStairs(int n) {
        //logic to go n steps we have to calculate :ways for going (n-1) + (n-2) steps
        //let c be total ways of going n steps,c = (n-1) ways  + (n-2) ways
        
        if (n == 1) //there's only one way for going to step 1;
            return 1;
        
        //let a & b, be the no. of ways of going (n-2) & (n-1) steps respectively.
        
        //( i'th step is nth steps)
        //for step,n = 1, i = 1;
        //a->(n-2 = 1-2 = -1 ,0 ways to -1,so a = 0 ways
        //b->(n-1 = 1-1 = 0),1 way to reach 0 ,b = 1 
        
        //for step,n = 2, i = 2;
        //a -> n-2 = 0, one way to reach 0, a = 1
        //b -> n-1 = 1, one way to reach 1, b = 1;
        
        //for step, n = 3, i = 3
        //a -> n - 2 = 1, one way , a = 1;
        //b -> n - 1 = 2, two ways to go b, b = 2;
        
        //we can use any of the above value for a and b wrt.corresponding value of i;
        int a = 0, b = 1;
        for (int i = 1; i <= n; i++)
        {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }

//SLOW APPROACH

// https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_10

int countDistinctWayToClimbStair(long long nStairs)
{
	//base case
	if (nStairs < 0)
		return 0;
	if (nStairs == 0)
		return 1;
	
	int ans = countDistinctWayToClimbStair(nStairs-1) + 
		countDistinctWayToClimbStair(nStairs-2);
	return ans;
}
/*
int climbStairs(int N)
{
    if ( N < 2 )
        return 1;
    else
        return climbStairs(N-1) + climbStairs(N-2);
}
*/

int main() 
{
    int n;
    cin>>n;
    
    cout<<countDistinctWayToClimbStair(n);
    return 0;
}