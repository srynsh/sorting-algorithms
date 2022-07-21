//
//  heap_sort.h
//  sorting
//
//  Created by suryansh jain on 21/07/22.
//

#ifndef heap_sort_h
#define heap_sort_h

using namespace std;

void swap(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

class MaxHeap {
private:
    vector<int> heap_vector;
    
    int parent(int index) {
        return (index-1)/2;
    }
    
    int left(int i) {
        return 2*i + 2;
    }
    
    int right(int i) {
        return 2*i + 1;
    }
public:
    MaxHeap(){}
    
    void add(int key) {
        heap_vector.push_back(key);
        
        int i = (int)heap_vector.size() - 1;
        while (heap_vector[i] > heap_vector[parent(i)]) {
            swap(heap_vector[i], heap_vector[parent(i)]);
            i = parent(i);
        }
    }
    
    void print() {
        for (auto x: heap_vector)
            cout<<x<<" ";
        cout<<endl;
    }
    
    int getMax() {
        return heap_vector[0];
    }
    
    void make_maxHeap(int root) {
        int l = left(root);
        int r = right(root);
        int max = root;
        int len = (int)heap_vector.size();
        
        if (l < len && heap_vector[l] > heap_vector[root])
            max = l;
        if (r < len && heap_vector[r] > heap_vector[root])
            max = r;
        
        if (max != root) {
            swap(heap_vector[root], heap_vector[max]);
            make_maxHeap(max);
        }
    }
    
    int extract_max() {
        int max = heap_vector[0];
        
        if (heap_vector.size() == 1) {
            heap_vector.pop_back();
            return max;
        }
        
        heap_vector[0] = *(heap_vector.end() - 1);
        heap_vector.pop_back();
        make_maxHeap(0);
        return max;
    }
    
    int size() {
        return (int)heap_vector.size();
    }
};

void heap_sort(int arr[], int len) {
    MaxHeap h1;
    
    for (int i =  0; i<len; i++) {
        h1.add(arr[i]);
    }
    
    for (int i = len-1; i>=0; i--) {
        int val = h1.extract_max();
        arr[i] = val;
        h1.make_maxHeap(0);
    }
}

void kthMin() {
    int k; cin>>k;
    
    MaxHeap h1;
    
    for (int i = 0; i<k; i++) {
        int n; cin>>n;
        
        h1.add(n);
    }
    h1.print();
    
    while (1) {
        int n;
        cin>>n;
        
        if (h1.getMax() > n) {
            h1.extract_max();
            h1.make_maxHeap(0);
            h1.add(n);
        }
        
        h1.print();
    }
}

#endif /* heap_sort_h */
