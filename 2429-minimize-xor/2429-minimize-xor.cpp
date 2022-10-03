class Solution {
public:
    int minimizeXor(int num1, int num2) {
        //note : case1 and case2 are not necessary for this code to run just for awareness!
        
       //case 1 : if setbits of num1 and num2 are same simply return num1;
        if (__builtin_popcount(num1) == __builtin_popcount(num2))  return num1;
        
        int cnt = __builtin_popcount(num2);
        
       //case 2 : if num1 < smallest no. made by cnt 
        int mini = (1 << cnt) - 1;
        if (num1 < mini)  
            return mini; 
        
        int ans = 0;
        //XOR of 1 and 1 is 0, we want minimal value of ans, so we can think of neutralising 1's from num1 from most significant position to least....
        for (int i = 31; cnt && i >=0; i--)
        {
            if (num1 & (1<<i))
            {
                ans |= (1<<i); 
                cnt--;
            }
        }      
        //if setbits in num1 < setbits in num2, we'll have to insert 1's as we ran out of 1's in num1, we want minimal value of ans, so we'll add 1's in ans from right to left.
        
        for (int i = 0; cnt && i < 32; i++)
        {
            if ((num1 & (1<<i)) == 0) 
            {
                ans |= (1<<i);
                cnt--;
            }
        }
        return ans;
    }
};