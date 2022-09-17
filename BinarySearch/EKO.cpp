#include <iostream>

/*https://www.spoj.com/problems/EKO/
Lumberjack Mirko needs to chop down M metres of wood. 

Input
N (the number of trees, 1 ≤ N ≤ 1 000 000) and M (Mirko‟s required wood amount, 1 ≤ M ≤ 2 000 000 000).
The second line of input contains N space-separated positive integers less than 1 000 000 000,
 the heights of each tree (in metres). The sum of all heights will exceed M, thus Mirko will always
  be able to obtain the required amount of wood.
Output
The first and only line of output must contain the required height setting.

Example
Input:4 7
20 15 10 17
Output:15
Input:5 20
4 42 40 26 46
Output:36
*/
using namespace std;

bool isPossible(int arr[], int N, int M,int mid) {
	int woodCut = 0;
	for(int i = 0; i<N; i++) {
		if (arr[i]>mid) woodCut+=arr[i]-mid;
		if (woodCut>=M) return true;
	}
	return false;
}
int main() {
	int arr[5]={4,42,40,26,46};
	int M = 20, N = 5;
	int maxi = -1;
	int Height = -1;
	
	for(int i=0; i<N; i++) {
		maxi = max(arr[i],maxi);
	}
	int start = 0, end = maxi, mid = start+(end-start)/2;
	
	for(; start<=end; mid = start+(end-start)/2) {
		if (isPossible(arr,N,M,mid)) {
			Height = mid;
			start = mid + 1;
		}else {
			end = mid-1;
	    }
    }
    cout<<Height<<"\n";
}