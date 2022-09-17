 #include<iostream>

using namespace std;


void update2 (int& n) 
{
    n++;
}   
void update1 (int n) 
{
    n++;
}   
int main() {
    //. Declaration of Reference variable is preceded with ‘&’ symbol ( but do not read it as “address of”).
    //reference variable- same memory but different names basically   
/*    int i = 5;
    int &j = i; // & -> do not read it as “address of”.
    cout<<i<<" "<<j<<" \n";

    cout<<++j<<" "<<i<<"\n";
*/
    int n = 5;
    update1 (n);
    cout<<"before: "<<n<<"\n";

    update2 (n); 
    cout<<"after: "<<n<<"\n";




    
    return 0;
}
/*
int& update (int n)
{
    int a = 5;
    int& ans = a;
    return ans;
}
  //bad practice as the refernce is reffering to a that will be only 
  //valid until its in scope. so returning ref. here is very bad practic

Similarly , here pointer the variable will be out of scope if returned .
thus bad practice.

int* update (int n)
{
    int a = 5;
    int* ptr = &a;
    return ptr;
}
*/