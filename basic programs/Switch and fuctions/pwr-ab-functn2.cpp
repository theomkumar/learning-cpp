#include <iostream>
using namespace std;
int power() {
    int a,b;
    cin>>a>>b;
    int ans=1;
    for (int i=1; i<=b; i++) {
        ans*=a;
    }
    return ans;
}
int main() {
   //in one line like this 
   cout<<power()<<endl;

      int ans=power();
   cout<<"answer is "<<ans<<endl;

      ans=power();
   cout<<"answer is "<<ans<<endl;

      ans=power();
   cout<<"answer is "<<ans<<endl;


}