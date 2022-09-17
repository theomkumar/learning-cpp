#include<iostream>
using namespace std;
// num_ways(3stairs) = num_ways(2stairs) + num_ways(1)
// num_ways(n) = num_ways(n-1) + num_ways(n-2);


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