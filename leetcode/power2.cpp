class Solution {
public:
    bool isPowerOfTwo(int n) {
        int i=0;
        bool t=1,f=0;
        
        for(;i<=INT_MAX,i>=INT_MIN;i++){
            int a=pow(2,i);
            if (a==n) {
                return t;
            }
        }
        
        }    
        return f;
    }
};



class Solution {
public:
    bool isPowerOfTwo(int n) {
        int i=0;
        bool t=1,f=0;
            if (n==1) {
                return t;
            }
            if (n%2!=0) {
               return f; 
            }

        while(i<n) {
            int a=pow(2,i);
            if (a==n) {
                 return t;
            }
            i++;
        }    
        return f;
    }
};