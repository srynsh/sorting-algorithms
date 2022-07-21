//
//  bubble_sort.h
//  sorting
//
//  Created by suryansh jain on 21/07/22.
//

#ifndef bubble_sort_h
#define bubble_sort_h

using namespace std;

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void bubble_sort(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (arr[i] > arr[j]) {
                swap(arr + i, arr + j);
            }
        }
    }
}

#endif /* bubble_sort_h */
