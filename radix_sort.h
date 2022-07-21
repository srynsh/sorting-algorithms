//
//  radix_sort.h
//  sorting
//
//  Created by suryansh jain on 21/07/22.
//

#ifndef radix_sort_h
#define radix_sort_h

using namespace std;

void countSort(int arr[], int n, int exp) {
    int output[n];
    int i;
    int count[10] = { 0 };
    
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n) {
    int m = max(arr, n);
    
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

#endif /* radix_sort_h */
