//
//  counting_sort.h
//  sorting
//
//  Created by suryansh jain on 21/07/22.
//

#ifndef counting_sort_h
#define counting_sort_h

//#include "mylib.h"

using namespace std;

int min(int arr[], int len) {
    int m = arr[0];
    
    for (int i = 1; i < len; i++)
        m = min(m, arr[i]);
    
    return m;
}

int max(int arr[], int len) {
    int m = arr[0];
    
    for (int i = 1; i < len; i++) {
        m = max(m, arr[i]);
    }
    
    return m;
}

void counting_sort(int arr[], int len) {
    int minE = min(arr, len);
    int maxE = max(arr, len);
    
    vector<int>v1(maxE - minE + 1);
    
    for (int i = 0; i < len; i++) {
        v1[arr[i] - minE]++;
    }
    
    int index = 0;
    for (int i = 0; i < (int)v1.size(); i++) {
        for (int j = 0; j < v1[i]; j++) {
            arr[index++] = i + minE;
        }
    }
}

#endif /* counting_sort_h */
