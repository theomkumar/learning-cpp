vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    /*You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.
Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.
*/
    vector<int> ans;
    int i=0,j=0;
	while (i<n && j<m) {   
        //we'll check all three conditions,if arr[i]==arr[j] i++ j++,
        // arr[i]<arr[j] i++ & arr[i]>arr[j] j++;
            if(arr1[i]==arr2[j]) { 
                     ans.push_back(arr1[i]);
                     i++;
                	 j++;
            } 
        	else if (arr1[i]<arr2[j]) i++;
        
            else j++;
    }
    return ans;
}
    
    
     