#include<bits/stdc++.h>
using namespace std;

//n = 2, logs = ["s1 error"]

int countFaults (vector<string> logs, int n){
    int res = 0;

    vector<int> count(n,0);

    for (auto &log : logs){
        int n = log.size();
        int serverNo = 0;

        int i = 1; //number starts here
        while (i < n && isDigit(log[i])){
            serverNo = serverNo * 10 + (log[i]-'0');
        }
        //check success or error
        if (log[n-1] == 'r'){
            ++count[serverNo]; 
            if (count[serverNo] == 3){
                res++;
                count[serverNo] = 0;
            }
                
        }
        else{
            //reset consecutive count;
            count[serverNo] = 0;
        }


    }
}
int countStable (vector<int> &capacity, int n){
    int stableCount = 0;
    //presum, idx
    unordered_map<int,int> mp;
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += capacity[i];
        mp[sum] = i;
    }

    sum = 0;

    //check for l = r = middle element
    for (int i = 0; i < n-2; i++) {

        sum += capacity[i];
        if (mp.find(sum + capacity[i]) != mp.end() && //check middleSum == left exist
            mp.find(sum + 2*capacity[i]) != mp.end() &&  //check right potentially exist...
            capacity[mp[sum + 2*capacity[i]]] == capacity[i])//verify if right = left{
            {
                stableCount++;
            }
    }
    return stableCount;
}

int main() 
{
    

    return 0;
}