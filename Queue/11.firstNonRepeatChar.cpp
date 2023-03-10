#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

//Using map
class Solution {
	public:
		string FirstNonRepeating(string A){
            unordered_map<char, int> count;
            queue<int> q;
            string ans;

            for (int i = 0; i < A.length(); i++)
            {
                count[A[i]]++;
                q.push(A[i]);

                while (!q.empty())
                {
                    if (count[q.front()] > 1)
                        q.pop();
                    else 
                    {
                        ans.push_back(q.front());
                        break;
                    }
                }
                if (q.empty())
                    ans.push_back('#');
            }
            return ans;
		}
};
//Using Frequency vector
//#ATTEMPT 1:
string FirstNonRepeating(string A){
    int count[26] = {0};
    //vector<int> count(26,0);
    queue<int> q;

    for (int i = 0; i < A.length(); i++)
    {
        count[A[i]-'a']++;
        q.push(A[i]);
        while (!q.empty())
        {
            if (count[q.front()-'a'] > 1)
                q.pop();
            else 
            {
                A[i] = q.front();
                break;
            }
        }
        if (q.empty())
            A[i] = '#';
    }
    return A;
}