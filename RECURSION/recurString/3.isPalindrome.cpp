#include<iostream>
using namespace std;

bool isPalindrome(string str, int l, int r)
{
    //base case
    if (l>r)
        return true;
    if (str[l]!=str[r])
        return false;
    else 
        //Recursive call
        return isPalindrome(str, l+1, r-1);   
}

bool isPalindrome2(string str, int l)
{
    //base case 
    if ( l > (str.size())/2 )
        return true;
    if ( str[l] != str[ str.size()-l-1] )
        return false;
    else 
        return (str,l+1);

}
int main() 
{
    string str;
    cout<<"INPUT STRING: ";
    cin >> str;
    
    isPalindrome(str,0,str.size()-1) ? cout<<"It's a palindrome! \n" : (cout<<"not a palindrome! \n");

    isPalindrome2(str,0) ? cout<<"It's a palindrome! \n" : (cout<<"not a palindrome! \n");

    return 0;
}