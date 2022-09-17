vector<vector<int>> pairSum(vector<int> &arr, int s){
    vector<vector<int>>ans;
    int i=0;
    int n=arr.size();
    //You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return 
    //the list of all pairs of elements such that each sum of elements of each pair equals 'S'.
    //SORT EVERYTHING INCREASING ORDER
    
    while(i<n) {
        int j=i+1;
        
     
        while (j<n) {
            if(arr[i]+arr[j]==s){ 
                vector<int> temp;
                //if (arr[i]>arr[j]) {temp.push_back(arr[j]);temp.push_back(arr[i]);}
                //else {temp.push_back(arr[i]);temp.push_back(arr[j]);} 
                
                //temp.push_back(arr[i]);temp.push_back(arr[j]);
                //sort(temp.begin(),temp.end());
                
                temp.push_back(min(arr[i],arr[j]));
                temp.push_back(max(arr[i],arr[j]));
                
                ans.push_back (temp);
            }
            j++;
            
        }
        i++;
    }
    sort(ans.begin(),ans.end());
    return ans;
}