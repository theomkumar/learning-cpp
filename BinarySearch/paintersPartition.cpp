bool isPossible(vector<int> &boards, int n, int mid, int k) {

//https://www.codingninjas.com/codestudio/problems/painter's-partition-problem_1089557?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=0

	int painterCount = 1;
    //paintTime = paintUnits
    int paintTime = 0;
    
    for(int i=0; i<n; i++) {
		if(paintTime+boards[i] <= mid) {
			paintTime+=boards[i];
        }else {
            painterCount++;
            paintTime=boards[i];
            if(painterCount>k || paintTime>mid) return false;
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    int ans = -1;
    int sum = 0;
    
    for(int i=0; i<n; i++) {
        sum+=boards[i];
    }
    int s = 0;
    int e = sum;
    int mid = s+(e-s)/2;
    
    while(s<=e) {
		if (isPossible(boards,n,mid,k)) {
            ans=mid; e = mid-1;
        }else{
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}