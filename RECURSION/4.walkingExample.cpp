#include<iostream>

using namespace std;

void reachHome(int src, int dest)
{
    cout<<"source"<<src<<" "; 
    
    //Base case 
    if (src == dest) 
    {
        cout<<"Reached Destination"<<"\n";
        return;
    }
    //processing 
    src++;   

    //recursion call
    reachHome(src,dest);
    
/*
    //recursion call + processing (++src);
    reachHome(src+1,dest);
*/
  

}

int main() {

    int dest = 10;
    int src = 0;

    reachHome(src,dest);    
    
    return 0;
}