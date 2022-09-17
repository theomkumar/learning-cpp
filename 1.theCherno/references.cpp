#include <iostream>

#define LOG(x) std::cout << x << std::endl;

void Increment (int& value)
{
    value++;
}
int main () 
{
    int a = 5;
    

    int *ptr = &a; //pointer
    int &ref = a; // ref.

    Increment(a);
    Increment(ref);   

    LOG(a);
    std::cin.get();
}