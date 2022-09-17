#include<iostream>
#include<limits.h>
using namespace std;

int getmax(int num[],int size) {
    int maxi=INT_MIN;
    for(int i=0; i<size; i++) {
        //if(num[i]>maxi) maxi=num[i];
        maxi=max(maxi,num[i]);
    }
    return maxi;
}
int getmin(int num[],int size) {
    int mini=INT_MAX;
    for(int i=0; i<size; i++) {
        if(num[i]<mini) mini=num[i];
        //mini=min(mini,num[i]);
    }
    return mini;
}

int main() {
    int size; cin>>size;
    int num[100];
    for(int i=0; i<size; i++) {
        cin>>num[i];
    }
    int max= getmax(num,size);
    cout<<"max value is "<<max<<endl;
    
    int min= getmin(num,size);
    cout<<"min value is "<<min<<endl;
}