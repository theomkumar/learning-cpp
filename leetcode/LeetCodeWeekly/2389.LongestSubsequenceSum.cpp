//https://leetcode.com/problems/longest-subsequence-with-limited-sum/
/*
//Approach 1: using upper bound O(nlogn)
lass Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int q = queries.size();
        sort(nums.begin(), nums.end());
        
        //prefix sum -> 
        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i-1];
        }
       //binary search using upper bound 
        
        for (int i = 0; i < q; i++)
        {
            queries[i] = upper_bound( nums.begin(), nums.end(), queries[i] ) - nums.begin();
        }
        return queries;
/*
EXPLANATION:

Lower bound: first element that is greater-or-equal.
Upper bound : first element that is strictly greater.

queries[i] = upper_bound(nums.begin(), nums.end(), queries[i])  - nums.begin(); 

//upper bound() -> returns iterator of first element that is greater than queries[i] e.g (X + 1)th iterator, but we need less or equal(i.e X th iterator), 
//nums.begin() -> returns iterator to the first element (i.e 1th iterator) ,
therefore upper bound() - nums.begin() = (X+1) - 1 = Xth element.

    }
};


//Approach 2:manual binary search : O(nlogn)
int binary(vector<int> &n, int target)
    {
        int s = 0, e = n.size() - 1, m;
        
        //coz our condition for target is to be < or = mid, if mid is less than target we'll increment start and at some point it'll
        //surpass e, coz end will keep on decreasing and will become less than s, and that'll be the end case;
        while (s <= e)
        {
            m = s + (e-s)/2;
            if (n[m] > target)
                e = m - 1; //it'll point to the required element eventually 
            else if (n[m] < target)
                s = m + 1; //s will pass the required element if(target <   n[m]);
            else // target == n[m]
                return m + 1;
        }
        return 
            e+1;//+1 coz index + 1 = size 
    }
    vector<int> answerQueries(vector<int>& n, vector<int>& q) 
    {
        int a = n.size(), b = q.size();
        sort(n.begin(), n.end());
        
        //prefix sum -> 
        for (int i = 1; i < a; i++)
            n[i] += n[i-1];
        
       //binary search 
        for (int i = 0; i < b; i++)
        {
            q[i] = binary(n, q[i]);
        }
        return q;
    }

//Approach 3: iterative O(n^2) using pre sum
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int q = queries.size();
        
        vector<int> ans(q);
        
        sort(nums.begin(), nums.end());
        
        //prefix sum
        vector<int> preSum(n);
        for (int i = 0, sum = 0; i < n; i++)
        {
            sum += nums[i];
            preSum[i] = sum;
        }
        
        for (int i = 0; i < q; i++)
        {
            int j = 0;
            while (j < n )
            {
                if (preSum[j] <= queries[i]) 
                {
                    j++;
                }
                else 
                    break;
            }
           ans[i] = j;
        }
        return ans;
    }
};
//Approach 4: simple iterative O(n^2);
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans(queries.size());
        int j;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < queries.size(); i++)
        {
            int size = 0;
            int sum = 0;
            for (j = 0; j < nums.size(); j++)
            {
                if (sum + nums[j] <= queries[i]) 
                {
                    sum += nums[j];
                    size++;
                }
                else 
                    break;
            }
            ans[i] = size;
        }
        return ans;
    }
};
*/