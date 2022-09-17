#include<iostream>

using namespace std;

//227
    int f(int x, int *py, int **ppz) {
    int y, z;
    **ppz += 1;
    z = **ppz;
    *py += 2;
    y = *py;
    x += 3;
    return x + y + z;
}

//165
void swap (char *x, char *y) 
{
  char *t = x;
  x = y;
  y = t;
}

//159
void square(int *p){
    int a = 10;
    p = &a;
    *p = (*p) * (*p);
}


//line 130!
void changeSign(int *p){
    *p = (*p)  *  -1;
}
//line 135
void fun(int a[]) {
    cout << a[0] << " ";
}

int main() {
/*
    float f = 10.5;
    float p = 2.5;
    float* ptr = &f;
    (*ptr)++;

    //cout<<"f: "<<f<<endl;

    *ptr = p;
    cout << *ptr << " " << f << " " << p;   
*/

/*
    int *ptr = 0;
    int a = 10;
    *ptr = a;
    cout << *ptr << endl;
    //ans -> error coz 0 isn't a valid address. we can't write 
    //into invalid address. segementation fault error.

    char ch = 'a';
    char* ptr = &ch;
    ch++;
    cout << *ptr << endl;

   // Assume memory address of variable ‘a’ is : 400 (and an integer takes 4 bytes), what will be the output -
    int a = 7;
    int *c = &a;
    c = c + 3;
    cout  << c << endl;

    int a[5];
    int *c;
    cout << sizeof(a) << “ “ << sizeof(c);
    //ans 20 8
    

    int a[] = {1, 2, 3, 4};
    cout << *(a) << " " << *(a+1);


    //Assume that address of 0th index of array ‘a’ is : 200. What is the output -
    int a[6] = {1, 2, 3};
    cout << (a + 2);





    //error- coz we can't change acetual memory address.
    // though we can increment p++, as pointer is variable and it stores 
    // memory address as value.

    int a[] = {1, 2, 3, 4};
    int *p = a++;
    cout << *p << endl;

    int arr[] = {4, 5, 6, 7};
    int *p = (arr + 1);
    cout << *arr + 9;
    

   // Assume address of 0th index of array ‘b’ is 200. What is the output -
    char b[] = "xyz";
    char *c = &b[0];
    cout << c << endl;


//***
    char s[]= "hello";
    char *p = s;
    cout << s[0] << " " << p[0];


    char arr[20];
    int i;
    for(i = 0; i < 10; i++) {
        *(arr + i) = 65 + i;
    }
    *(arr + i) = '\0'; //arr[11] = '\0'; 
    cout << arr; // this will print all element of array until it finds null character.

    char *ptr; 
    char Str[] = "abcdefg";
    ptr = Str;
    ptr += 5; //size of char is 1 byte so ptr+5byte.
    cout << ptr;


    int numbers[5];
    int * p;
    p = numbers; 
    *p = 10;
    p = &numbers[2]; 
    *p = 20;
    p--; 
    *p = 30;
    p = numbers + 3;
    *p = 40;
    p = numbers;
    *(p+4) = 50;
    for (int n=0; n<5; n++) {
        cout << numbers[n] << ",";
    }
//***
    char st[] = "ABCD";
    cout<<*st<<endl;

    for(int i = 0; st[i] != '\0'; i++) {
        cout << st[i] << *(st)+i << *(i+st) << i[st]; // -> A<< A + i = 65<< A << A
    }
    
//***
    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr[0];
    float *ptr2 = ptr1 + 3;
    cout<<ptr1<<" "<<ptr2<<"\n";
    cout<<*ptr2<<" ";
    cout<< ptr2 - ptr1; //(f ptr1 is x, ptr2 is x + 3. Subtracting these yields 3.)


    int a = 10;
    changeSign(&a); //above int main()
    cout << a << endl;

    int a[] = {1, 2, 3, 4};
    fun(a + 1);
    cout << a[0];


    int main(){
    int a = 10;
    square(&a);
    cout << a << endl;



//*****
//So swap() function doesn’t swap strings. The function just changes local pointer variables and the changes are not reflected outside the function.

#include<iostream>
using namespace std;
void swap (char *x, char *y) 
{
  char *t = x;
  x = y;
  y = t;
}

int main()
{
   char *x = "geeksquiz";
   char *y = "geeksforgeeks";
   char *t;
   swap(x, y);
   cout<<x << " "<<y;
   t = x;
   x = y;
   y = t; 
   cout<<" "<<x<< " "<<y;
   return 0;
}

//***

void Q(int z)
{
  z += z;
  cout<<z << " ";
}

void P(int *y) 
{
  int x = *y + 2;
  Q(x);
  *y = x - 1; 
  cout<<x << " ";
}
int main()
{
  int x = 5;
  P(&x);
  cout<<x;
  return 0;
  //ans 14 7 6


//***
    int a = 10;
    int *p = &a;
    int **q = &p;
    int b = 20;
    *q = &b;
    (*p)++;
    cout << a << " " << b << endl;

//**** function above int main()

        int c, *b, **a;
        c = 4;
        b = &c;
        a = &b;
        cout << f(c, b, a);
*/
    int ***r, **q, *p, i=8;
    p = &i;
    (*p)++;
    q = &p;
    (**q)++;
    r = &q;
    cout<<*p << " " <<**q << " "<<***r;
   

    return 0;
}