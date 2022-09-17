#include<iostream>
//pass by value
using namespace std;

void print(int* p) {
    cout<<"befor update address of value:"<<p<<"\n";
    cout<<"address of pointer:"<<&p<<endl;
    cout<<"value: "<<*p<<"\n";
}

void update (int *p) {
    
    (*p)++;
    p++;
    cout<<"INSIDE function: "<< p<< *p <<"\n";
}

// int getSum(int arr[],int n) {   //both are same
int getSum(int *arr,int n) {

    //this prints size of pointer nor array why?
    // coz internally -> int arr[]=int *arr.
    cout<<"size: "<<sizeof(arr)<<"\n";

    int sum = 0;
    for (int i = 0; i<n; i++) {
        sum += arr[i];
    }
    cout<<"sum: "; 
    return sum;

}
int main() {
    int value = 5;
    int *p = &value;
    //print(p);   
    
    cout<<"before update: "<<p<<" "<<*p<<"\n";
    update(p);
    //before and after address of pointer p is identical because it is passed by value not reference.
    cout<<"after update: "<<p<<" "<<*p<<"\n";

    int arr[5] = {1,2,3,4,5};
    cout<<getSum(arr,5) <<endl;
    cout<<getSum(arr+2,3)<<endl; //sum from arr[2].
    
    return 0;
}