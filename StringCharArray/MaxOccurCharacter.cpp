#include<iostream>
#include<algorithm>
using namespace std;

//counting occurences of given elements
int freq(string &str,int s) {
    int count = 0;
    for(int i = 0; i<str.size(); i++) {
        if (s==str[i])
            count++;
    }
    return count;
}

int main() {
    string str = "output";
    
    int n = str.size();
    int count= 0;
    char max = 0;
    sort(str.begin(),str.end());
    
    for(int i = 0; i<n; i++) {
        if (freq(str,str[i])>count) {
            count = freq(str,str[i]);
            max = str[i];
        }
       
    }
    cout<<max<<'\n';
}
/* without using sort function;
 else if (freq(str,str[i])==count) {
            if (max>str[i]) max = str[i];
        }
*/