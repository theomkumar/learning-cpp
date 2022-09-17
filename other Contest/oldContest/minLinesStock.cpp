 #include<iostream>
 #include<vector>
 #include<algorithm>
// https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/
 using namespace std;
 
int minimumLines(vector<vector<int>>& stockPrices) {
    
    //this will sort points along x axis in contiguous manner.
    sort (stockPrices.begin(),stockPrices.end());

    //to create a line we need atleast 2 points
    if (stockPrices.size()<2)
        return 0;
    int line = 1;

    for (int i = 2; i<stockPrices.size(); i++) {
        //prev 
        long long int Y2 = (stockPrices[i][1] - stockPrices[i-1][1]);
        long long int X2 = (stockPrices[i][0]-stockPrices[i-1][0]);
        //prev prev
        long long int Y1 = (stockPrices[i-1][1] - stockPrices[i-2][1]);
        long long int X1 = (stockPrices[i-1][0]-stockPrices[i-2][0]);
       
        if ((Y2*X1)!=(Y1*X2)) { //to avoid decimal , we are basically doing cross multiplication.
            line++;
        }

    }
    return line;
        
    }
}
 
 int main() 
 {  //{1,2},{4,2},{2,1}   {3,4},{1,2},{7,8},{2,3}    [[72,98],[62,27],[32,7],[71,4],[25,19],[91,30],[52,73],[10,9],[99,71],[47,22],[19,30],[80,63],[18,15],[48,17],[77,16],[46,27],[66,87],[55,84],[65,38],[30,9],[50,42],[100,60],[75,73],[98,53],[22,80],[41,61],[37,47],[95,8],[51,81],[78,79],[57,95]]
    vector<vector<int>> stockPrices{ {1,2},{4,2},{2,1} };
    
    int ans = minimumLines(stockPrices);
    cout<<"final ans : "<< ans<<"\n";
    return 0;
 }
 