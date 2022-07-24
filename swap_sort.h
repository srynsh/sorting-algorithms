//
//  swap_sort.h
//  sorting
//
//  Created by suryansh jain on 21/07/20.
//

#ifndef swap_sort_h
#define swap_sort_h

using namespace std;

int max_till_index(int arr[], int index) {
    int max = arr[0];
    int max_index= 0;
    
    for (int i = 0; i<index; i++) {
        if (max < arr[i]) {
            max = arr[i];
            max_index = i;
        }
    }
    
    return max_index;
}

void swap_sort(int arr[], int len) {
    for (int i = 0; i<len; i++) {
        int ind = max_till_index(arr, len-i);
        swap (arr + ind, arr + len - i - 1);
    }
}


#endif /* swap_sort_h */
