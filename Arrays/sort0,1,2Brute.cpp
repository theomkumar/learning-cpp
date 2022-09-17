#include<iostream>
using namespace std;

void print(int arr[],int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void sorting(int arr[],int n) {
    int count0=0, count1=0, count2=0;
    for(int i=0; i<n; i++) {
        switch(arr[i]) {
            case 0 :    count0++; 
                        break;
            case 1 :    count1++;
                        break;
            case 2 :    count2++;
                        break;
        }
    }
    for(int i=0; i<n; i++) {
        if(count0>0) {
            arr[i]=0; count0--;            
        }
        else if (count1>0) {
            arr[i]=1; count1--;
        }
        else {
            arr[i]=2; count2--;       
        }
    }
}
int main() {
    int arr[6]={2,0,2,1,1,0};
    sorting(arr,6);
    print(arr,6);
}