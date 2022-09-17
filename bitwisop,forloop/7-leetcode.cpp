/*class Solution {
public:
    int subtractProductAndSum(int n) {
        int s=0,p=1;
        while(n!=0) {
            int i=n%10;
            p*=i;
            s+=i;
            n=n/10;
        }
        int a=p-s;
        return a;
    }  
};
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n!=0) {
            if(n&1){
                count++;                
            }
            n=n>>1;
        }
        return count;
    }
};