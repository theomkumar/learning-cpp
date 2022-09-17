    #include<iostream>
    #include<vector>
    using namespace std;
    //sieve of eratothenes
    //count all primes strictly less than n
    // https://leetcode.com/problems/count-primes/

    int simpleSieve(int n) {
        int count = 0;
        vector<bool> prime(n,true);
        cout<<"Primes: ";
        for (int i = 2; i<n; i++) {
            if (prime[i]) {
                count++;
                cout<<i<<" ";
                for (int j = i*2; j<n; j+=i){
                    prime[j]=0;
                }
            }
        }
        return count;
    }
    int main() {
        int n; cin>>n;
        int ans = simpleSieve(n);
        cout<<"\ntotal primes less than: "<<n<<" = "<<ans<<" \n";
        
        return 0;
    }
    