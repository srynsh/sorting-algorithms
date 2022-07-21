#include "mylib.h"
#include "counting_sort.h"
#include "merge_sort.h"
#include "bubble_sort.h"
#include "swap_sort.h"
#include "heap_sort.h"
#include "quick_sort.h"

using namespace std;

void print(int arr[], int len) {
    for (int i = 0; i<len; cout<<arr[i++]<<" ");
    cout<<endl;
}

int main() {
//    int arr[] = {6,4,7,9,8,3,2,1};
//    int len = sizeof(arr)/sizeof(arr[0]);
//
//    heap_sort(arr, len);
//
//    print(arr, len);
    
    kthMin();
    
    return 0;
}
