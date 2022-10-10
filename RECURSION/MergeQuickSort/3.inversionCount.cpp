//gfg
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// APPROACH 1: declaring ans in class;
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    typedef long long ll;
    ll ans = 0; 

    long long int inversionCount(long long arr[], long long N)
    {
        ans = 0;
        mergeSort(arr, 0, N-1);
        return ans;
    }
    void merge(ll arr[], ll low, ll mid, ll high)
    {
        ll n1 = mid - low + 1, n2 = high - mid;
        ll* a = new ll[n1], *b = new ll[n2]; //ll a[n1], b [n2];

        for (ll i = 0; i < n1; i++)
            a[i] = arr[low + i];

        for (ll i = 0; i < n2; i++)
            b[i] = arr[mid + 1 + i];
        
        ll i = 0, j = 0, k = low; 
        while (i < n1 && j < n2)
        {
            if (b[j] < a[i])
            {
                ans += n1 - i;
                arr[k++] = b[j++];
            }
            else
                arr[k++] = a[i++];
        }
        while (j < n2)
            arr[k++] = b[j++];
        while (i < n1)
            arr[k++] = a[i++];

        delete []a;
        delete []b;
    }

    void mergeSort(ll arr[], ll low, ll high)
    {
        if (low < high)
        {
            ll mid = low + (high - low)/2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }
    }

};

//APPROACH 2: using ans as reference variable
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    typedef long long ll;
    
    void merge(ll arr[], ll low, ll mid, ll high, ll &ans)
    {
        ll n1 = mid - low + 1, n2 = high - mid;
        ll* a = new ll[n1], *b = new ll[n2]; //ll a[n1], b[n2];

        for (ll i = 0; i < n1; i++) a[i] = arr[low + i];
        for (ll i = 0; i < n2; i++) b[i] = arr[mid + 1 + i];
        
        ll i = 0, j = 0, k = low; 
        while (i < n1 && j < n2)
        {
            if (b[j] < a[i])
            {
                ans += n1 - i;
                arr[k++] = b[j++];
            }
            else arr[k++] = a[i++];
        }
        while (j < n2)  arr[k++] = b[j++];
        while (i < n1)  arr[k++] = a[i++];

        delete []a; delete []b;
    }
    
    void mergeSort(ll arr[], ll low, ll high, ll &ans)
    {
        if (low < high)
        {
            ll mid = low + (high - low)/2;
            mergeSort(arr, low, mid, ans);
            mergeSort(arr, mid+1, high, ans);
            merge(arr, low, mid, high, ans);
        }
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        ll ans = 0;
        mergeSort(arr, 0, N-1, ans);
        return ans;
    }
};