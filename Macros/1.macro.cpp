//A macro is a piece of code in a program that is replaced by the value of the macro. Macro is defined by #define directive.
// Whenever a macro name is encountered by the compiler, it replaces the name with the definition of the macro. Macro definitions need not be terminated by a semi-colon(;).
#include <iostream> //pre processor directive

#define LOG(x) std::cout<<x<<" ";
#define PI 3.14
#define AREA(l,b) (l*b) 

#define CAR WHEELS
#define WHEELS 4

#define NUMS 1, \
             2, \
             3,

int main()
{
    int i = 5;
    LOG(i);

    int r = 5;
    double area = 3.14 * r * r;
    LOG(area);
    
    int len = 6, br = 3;
    LOG(AREA(len,br));

    LOG("wheels:"); 
    LOG(CAR);

    LOG("\n");


    int arr[] = {NUMS};
    
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i<n; i++) {
        LOG(arr[i]); 
    }
 
}
