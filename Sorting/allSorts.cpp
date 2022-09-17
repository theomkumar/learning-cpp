#include<iostream>
#include<vector>

using namespace std;
/*
 Selection Sort
 different rounds -> smallest element is placed in right place.
//use case:when 1.array/vector/list size is small.
             // 2.memory constraint
//time complexity of Selection Sort is O(N2)
it never makes more than O(n) swaps and can be useful when memory write is a costly operation. 
*/
void selectionSort(vector<int> &v) {
    int n = v.size();

    for(int i=0; i<n-1; i++) {
        int minIndex=i;
        for(int j=i+1; j<n; j++) {
            if (v[minIndex]>v[j]) {
                minIndex = j;
            }
        }
        swap(v[minIndex],v[i]);
    }
}
/*
 Bubble sort (swap adjacent)
i'th round - i'th largest element is placed at right spot
diff round/pass -> largest element is placed at right place;
//Best Case Time Complexity: O(N). The best case occurs when an array is already sorted.
//Worst and Average Case Time Complexity: O(N2). The worst case occurs when an array is reverse sorted.
//Use case: mainly used in educational purposes for helping students understand the foundations of sorting. This is used to identify whether the list is already sorted. When the list is already sorted (which is the best-case scenario), the complexity of bubble sort is only O(n)
*/
void bubbleSort(vector<int> &v) {
    for(int i = 0; i<v.size()-1; i++) {
        bool swapped = 0;
        for(int j=0; j<v.size()-1-i; j++) {
           
           if (v[j]>v[j+1]) {
               swap(v[j],v[j+1]);
               swapped = 1;
           }
       }
       if (!swapped) break;
    }
}

/*
Insertion Sort
it is stable, adaptable
when array is partially sorted or small in size 
Insertion sort is used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.
//best case: O(n);
//worst case: O(n^2);
*/
void insertionSort (vector<int>& arr)
{

    for (int i = 1; i<arr.size(); i++)
    {
        int key = arr[i];
        int j = i-1; 

        while ( j>=0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }  
}
/*

void insertionSort(vector<int> &v) {
    for(int i = 1; i<v.size(); i++) {
        int temp = v[i];
        int j = i-1;
        for(; j>=0; j--) {
            if (v[j]>temp) {
                v[j+1]=v[j];
            }
            else break;
        }
        v[j+1]=temp;
    }
}
*/


void print(vector<int> v) {
    for(int i = 0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }cout<<'\n';
}

int main() {
    vector<int> v1{1,8,3,6,0,7,4,4,8};

    vector<int> v2{5,6,2,7,0,3,5,2,0};

    vector<int> v3;
    v3.insert(v3.end(),{3,6,2,8,4,7,9,7,1,0,15});

    selectionSort(v1);
    bubbleSort(v2);
    insertionSort(v3);

    print(v1);
    print(v2);
    print(v3);

    return 0;
}