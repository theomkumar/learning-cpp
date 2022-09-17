#include<iostream>
using namespace std;

/* //double pointer
void reverse (string &str, int l, int r)
{
    cout<<"test : "<<str<<"\n";
    //base case
    if (l>r)
        return;
    //processing
    swap( str[l++], str[r--]);

    //recursive call
    return reverse(str, l, r);
}
*/
//single pointer
void reverse (string &str, int l)
{
    //base case
    if (l>(str.size())/2)
        return;
    //processing
    swap( str[l], str[str.size()-l-1]);
    l++;

    //recursive call
    return reverse(str, l);
}
int main() 
{
    string str;
    cout<<"INPUT STRING: ";
    cin>>str;
    cout<<"OUTPUT STRING: ";

    reverse(str,0);

    cout<<str<<"\n";


    return 0;
}