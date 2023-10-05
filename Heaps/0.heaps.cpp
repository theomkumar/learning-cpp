//heap is CBT (complete binary tree == every level is completely filled except the last level && nodes always added from the left i.e lean towards left)

//max heap : child is smaller than root
//min heap : child is bigger than root

/*implementation using array
0th index is empty

Node -> ith index(1 to ...)
left child = 2*i index
right child = (2*i+1)
parent = i/2 th index
*/


/*INSERTION  TC: O(log n)
1. insert at the end of array O(1)
2. take it to it's correct position (by swapping it with parents) O(log n)

* DELETION(of first node): TC: O(log n)
1. a[firstNode] = a[lastNode] O(1)
2. delete last node. O(1)
3. put first node to it's correct position by swapping with children O(log n)
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
            if (arr[index] > arr[index/2])
            {
                swap(arr[index], arr[index/2]);
                index = index/2;
            }
            else
                break;
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
        if (size == 1) 
        {
            size--;
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

    h.print();

    h.deleteFromHeap();
    h.deleteFromHeap();
    h.deleteFromHeap();

    h.print();
}