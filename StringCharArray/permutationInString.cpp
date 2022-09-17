class Solution {
private:
    bool isEqual(int a[26], int b[26]) {
        for (int i = 0; i<26; i++) {
            if (a[i] != b[i]) 
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        int count1[26]={0};
        
        //Storing count of s1 
        for(int i = 0; i<n1; i++) {
            int index = s1[i]-'a';
            count1[index]++;
        }
        //traversing s2 string in window size of s1 and comparing them 
        int i=0, count2[26] = {0};
        
        //first window
        for (; i<n1 && i<n2; i++) {
            int index = s2[i]-'a';
            count2[index]++;
        }
        
        
        if ( isEqual(count1,count2) )
            return true;
        
        //shifting fist window -one forward element  and (i-n1)index backwards.
        for(; i<n2 ; i++) {
            int newIndex = s2[i]-'a'; 
            int oldIndex = s2[i-n1] - 'a';
            
            count2[newIndex]++;
            count2[oldIndex]--;
            
            if ( isEqual(count1,count2) )
                return true;
        }
        return 0;
    } 
};