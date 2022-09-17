#include<iostream>
using namespace std;

void printarray(int array[],int size) {
    cout<<"Print the array"<<endl;
    for(int i=0;i<size;i++) {
        cout<<array[i]<<" ";
    }
}

int main() {
    int third [12]={2,7};
    int n=12;
    printarray(third,n);
    //print size of array/length
    cout<<endl<<sizeof(third)/sizeof(int);
    
}
    
