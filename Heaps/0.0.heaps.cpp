//heap is CBT (complete binary tree == every level is completely filled except the last level && nodes always added from the left i.e lean towards left)

//max heap : child is smaller than root
//min heap : child is bigger than root

/*implementation using array for 1 index based:
0th index is empty

Node -> ith index(1 to ...)
left child = 2*i index
right child = (2*i+1)
parent = i/2 th index
*/


/*INSERTION  TC: O(log n)
1. insert at the end of array O(1)
2. take it to it's correct position (by swapping it with parents) O(log n)


* DELETION(of root node): TC: O(log n)
1. a[firstNode] = a[lastNode] O(1)
2. delete last node. O(1)
3. put first node to it's correct position by swapping with children O(log n)


The heapify function takes O(log N) time because it moves an element from the root to the leaf in a binary heap of height log N.
The buildMinHeap function calls heapify for N/2 elements, starting from the middle of the array.
The total time complexity is O(N) because most of the elements are in the bottom layer and take O(1) time to heapify. The formula for the number of elements at height h is N / 2^(h+1).
The summation of (N / 2^(h+1) * O(h)) over all values of h from 0 to log(N) is equal to O(2N), which is equivalent to O(N).
*/
//max heap insertion & deletion


#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap (): size(0) {}

    void insert(int data){
        size++;
        int index = size;
        arr[index] = data;
        while(index > 1)
        {
            //if child > parent then swap
            if (arr[index] > arr[index/2])
            {
                swap(arr[index], arr[index/2]);
                index = index/2;
            }
            else
                return;
        }
    }
    void print(){
        for (int i = 1; i <= size; i++)
            cout << arr[i] <<' ';
        cout <<'\n';
    }

    void deleteFromHeap(){
        if (size == 0)
        {
            cout <<"Can't delete, ARRAY IS EMPTY!! \n";
            return;
        }

        //step 1:
        arr[1] = arr[size];
        //step 2: 
        size--;
        //step 3:take root node to it's correct position

        int i = 1;
        while (i < size)
        {
            int l = 2*i, r = 2*i+1;
            if  (r<=size && arr[i]<arr[r] && arr[r]>arr[l])
            {
                swap(arr[i], arr[r]);
                i = r;
            }
            else if (l <= size && arr[i] < arr[l] && arr[l] > arr[r])
            {
                swap(arr[i], arr[l]);
                i = l;
            }
            else
                return;
        }

    }
};
//HEAPIFY ALGO done by myself:
void heapifySelf(int *arr, int n, int index){
    //base case
    if (index == 0) return;

    int i = index;

    while(i < n)
    {
        int largest = i;
        int l = 2*i, r = 2*i+1;

        if (l < n && arr[largest] < arr[l])
            largest = l;
        if (r < n && arr[largest] < arr[r])
            largest = r;
        if (largest != i)
        {
            swap(arr[largest],arr[i]);
            i = largest;
        }
        else
            break;
    }
    heapifySelf(arr,n,--index);
}
//standard algo
void heapify(int *arr, int n, int i){
    int largest = i;

    int l = 2*i, r = 2*i+1;

    if (l <= n && arr[largest] < arr[l])
        largest = l;
    if (r <= n && arr[largest] < arr[r])
        largest = r;
    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while(size > 1)
    {
        //step 1: swap 
        swap(arr[1],arr[size]);
        size--;

        //step 2: heapify
        heapify(arr,size,1);
    }
}
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();

    h.deleteFromHeap();
    h.deleteFromHeap();
    h.deleteFromHeap();
    h.deleteFromHeap();
    h.deleteFromHeap();
    h.print();
//HEAPIFY

    int arr[6] = {-1,54,53,55,52,50};
//    heapifySelf(arr,6,5/2);//done by myself

    //Standard algo of heapify:
    //heap creation
    int n = 5;
    for(int i = n/2; i > 0; i--)
       heapify(arr,n,i);

    //print
    for (int i = 1; i <= n; i++) cout << arr[i] <<' '; cout<<'\n';
    //heapSort
    heapSort(arr,n);

    //print
    for (int i = 1; i <= n; i++) cout << arr[i] <<' '; cout<<'\n';
}