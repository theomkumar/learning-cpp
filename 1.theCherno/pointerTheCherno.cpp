#include <iostream>
#include <cstring>

#define LOG(x) std::cout << x << std::endl

int main()
{   

/*
    int var = 8;
    //void *ptr = null or 0 or null ptr;
    //void *ptr = &var;
    int *ptr = &var;
    //double* ptr = (double*)&var;
    *ptr = 10;
    LOG(var);
    std::cin.get();
*/
    char * buffer = new char[8];
    memset(buffer,0,8);
    char **ptr = &buffer;
    //int** ptr = (int**)&buffer;
    delete[] buffer;
    std::cin.get();     
}
