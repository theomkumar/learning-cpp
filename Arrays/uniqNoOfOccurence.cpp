class Solution {
public:
    bool isUnique(vector<int> &temp) {
        for(int i = 0; i<temp.size(); i++) {
            int count = 0;
            for(int j = i+1; j < temp.size(); j++) {
                if (temp[i]==temp[j]) count++;
                if (count==1) return 0; 
            }
        }
        return 1;
    }
    
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int> temp;
        
        int count = 0;
        int i = 0, j = 0;
        
        while(j<n) {
            if (arr[i]==arr[j]) {
                count++;
                j++;
            }
            else if (arr[i]!=arr[j]) {
                i = j;
                temp.push_back(count);
                count = 0;
            }
        }
       if(i== j-1){
            temp.push_back(1);
        }
        
        if (isUnique(temp)) return 1;
        return 0;
    }
};