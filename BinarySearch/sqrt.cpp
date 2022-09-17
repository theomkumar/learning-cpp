class Solution {
public:
    int mySqrt(int x) {
        for (long int i=1; i<INT_MAX; i++) {
            if (x>=i*i && x<((i+1)*(i+1))) return i;
        }
        return 0;
    }
};
//binary method
int mySqrt(int x) {
        long int start = 0, end = x, mid = start+(end-start)/2;
        while (start<=end) {
            if(x>=mid*mid && x<(mid+1)*(mid+1)) return mid;

            if (x>mid*mid) start=mid+1;
            else end=mid-1;

            mid = start+(end-start)/2;
        }
        return -1;
    }