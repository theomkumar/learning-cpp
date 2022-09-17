/*
APPROACH 1: very bad, no need to take extra space look at approach 3(same code but optimised) and approach 2 is simplest!

TC: worst case & best case O(n) , SC: O(n)

    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size();
        int carry = 1;//we are taking carry as one coz we need to add it to the array.
        
        for (int i = n-1; i >= 0; i--)
        {
            int sum = carry + digits[i];
            ans.push_back(sum % 10);
            carry = sum/10;
        }
        //if the sum is greater than array size eg. 99+1 , in this case carry 1 will be present and loop will end, so we need to deal with it later.

        if (carry)
            ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }

APPROACH 2: 

TC: worst case = O(n) best case O(1), SC: O(1)

    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() -1;
        for (int i = n; i >= 0; i--)
        {
            if (digits[i] == 9)
                digits[i] = 0;
            else //eg = 5,4 + 1 return-> 5,5 | 9099 -> 9100 
            {
                digits[i] += 1;
                return digits;
            }
        }

            digits[0] = 1;  //in case where digits.size() increase by adding 0 eg. 999 + 1 = 1,0,0,0
            digits.push_back(0); //our digits is 0, 0, 0 we need to put 1 in the front without loosing our 0s
        
            return digits;
    }
Approach 3: approach1 without extra space.
TC: best case O(1) worst case O(n), SC: O(1);

//Approach 1's variation with O(1) space && Approach 2 is simpler
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;//we are taking carry as one coz we need to add it to the array.
        
        for (int i = n-1; i >= 0; i--)
        {
            int sum = carry + digits[i];
            digits[i] = (sum % 10);
            carry = sum/10;
            
            if (carry == 0)
                return digits;
        }
        //if the sum is greater than array size eg. 99+1 , in this case carry 1 will be present and loop will end, so we need to deal with it later.

        if (carry)
        {
            digits[0] = 1;//eg: 9,9,9,9+1 = [1],0,0,0,0,[0];
            digits.push_back(0);
        }
        return digits;
    }
*/