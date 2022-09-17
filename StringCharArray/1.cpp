#include<iostream>
#include<string.h>
using namespace std;
int main() {
    //input/output char array

    //using getline function; without custom delimiter;
    char name1[30];
    cout<<"input one: ";
    cin.getline(name1,30,'x');

    char name[30];
    cout<<"Input 2 enter your name"<<"\n";
    cin>>name;
    cout<<"your name is "<<name<<'\n';


    //using strlen() ; length of array

    int len = strlen(name);
    cout<<"length of char array: "<<len<<'\n';
     
    //using strcmp() If the strings are equal, the function returns 0.
    cout<<"zero if strings are equal: "<<strcmp(name,name1)<<"\n";
    
    //using strcpy ; copy strcpy(destination,source);
    strcpy(name,name1);
    cout<<"copying 1st int0 second: "<<name<<"\n";
    
    //null
    name[2]='\0';
    cout<<"after inserting null at name[2] : "<<name<<'\n';       

    

   

    return 0;
}