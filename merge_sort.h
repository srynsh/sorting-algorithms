//
//  merge_sort.h
//  sorting
//
//  Created by suryansh jain on 21/07/20.
//

#ifndef merge_sort_h
#define merge_sort_h

using namespace std;

void merge_array(int arr1[], int len1, int arr2[], int len2, int arr3[]) {
    int i1 = 0;
    int i2 = 0;
    int index = 0;
    
    while (i1<len1 && i2<len2) {
        if (arr1[i1] < arr2[i2]) {
            arr3[index++] = arr1[i1++];
        }
        else if (arr1[i1] > arr2[i2]) {
            arr3[index++] = arr2[i2++];
        }
        else {
            arr3[index++] = arr1[i1++];
            arr3[index++] = arr2[i2++];
        }
    }
    
    if (i1 == len1) {
        for (int i = i2; i < len2; i++) {
            arr3[index++] = arr2[i];
        }
    } else if (i2 == len2) {
        for (int i = i1; i < len1; i++) {
            arr3[index++] = arr1[i];
        }
    }
}

void merge_sort(int arr[], int len) {
    if (len == 1 || len == 0) return;
    
    int arr1[len/2];
    int arr2[len - len/2];
    
    for (int i = 0; i<len/2; i++) {
        arr1[i] = arr[i];
    }
    for (int i = len/2; i<len; i++) {
        arr2[i - len/2] = arr[i];
    }
    
    merge_sort(arr1, len/2);
    merge_sort(arr2, len - len/2);
    
    merge_array(arr1, len/2, arr2, len - len/2, arr);
}

#endif /* merge_sort_h */
