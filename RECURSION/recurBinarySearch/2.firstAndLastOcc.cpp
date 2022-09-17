#include<iostream>
#include<vector>
using namespace std;

int firstP(vector<int> &arr, int s, int e, int k,int ans)
{	
		int m = s + (e-s)/2;
	//base case
		if (s>e) return ans;
		if (arr[m]==k) 
		{
			ans = m;
			return firstP(arr,s,m-1,k,ans);
		}
		else if (arr[m]<k)
			return firstP(arr,m+1,e,k,ans);
		else return firstP(arr,s,m-1,k,ans);
	
	return ans;
}

int lastP(vector<int> &arr, int s, int e, int k, int ans)
{
	int m = s + (e-s)/2;
	//base case
	if (s>e) return ans; 	
	if (arr[m]==k) 
	{
		ans = m;
		return lastP(arr,m+1,e,k,ans);
	}
	else if (arr[m]<k)
		return lastP(arr,m+1,e,k,ans);
	else return lastP(arr,s,m-1,k,ans);

	return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int, int> p;
	int ans = -1;
	p.first  =  firstP(arr, 0, n-1, k, ans);
	p.second =  lastP(arr, 0,n-1, k, ans);

	return p;
}


int main() 
{
	//test cases
	int t; cout << "Test Cases: "; cin >> t; cout<<"\n";

	for (int i = 0; i<t; i++)
	{
		//input
		int size;
		cout << "size: "; 
		cin >> size;
		
		vector<int> arr(size);
		cout<<"Input elements: ";

		for (int i = 0; i<size; i++)
		{
			cin >> arr[i];
		} cout<<"\n";

		cout << "Input Key: "; 
		int k;
		cin >> k; 
		cout <<'\n';
		//processing
		pair<int, int> ans = firstAndLastPosition(arr, size, k);
		// output
		cout << ans.first <<" "<<ans.second<<'\n';
	}
       return 0;
}