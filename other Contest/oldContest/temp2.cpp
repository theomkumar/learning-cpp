class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        vector<int> ans;
        int min = INT_MAX, max = 0;
        
        //max and min of array
        for (int i = 0; i<special.size(); i++) {
            if (special[i] < min) {
                min = special[i];
            }
            if (special[i] > max)
                max = special[i];
        }
        
        ans.push_back(top-max);
        ans.push_back(min-bottom);
        
        max = 0;
        
        //max difference in array
        sort (special.begin(), special.end() );
        
          for (int i = 1; i<special.size(); i++) 
        {
            int temp = special[i]-special[i-1] - 1;
            if ( temp > max )
                max = temp;
        }
        ans.push_back(max);
        
        max = 0;
        
        // max in array
        for (int i = 0; i<ans.size(); i++) {
            if (ans[i] > max)
                max = ans[i];
        }
        return max;

    }
};