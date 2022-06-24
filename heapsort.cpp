#include<iostream>
#include<vector>
using namespace std;
void upheapify(vector<int> &heap, int idx){
    int parentidx = (idx - 1)/2;
    if(idx == 0){
        return;
    }
    if(heap[parentidx] < heap[idx]){
        swap(heap[parentidx], heap[idx]);
        upheapify(heap, parentidx);
    }
    else{
        return;
    }
}
void insertinheap(vector<int> &heap, int key){
    heap.push_back(key);
    upheapify(heap, heap.size()-1);
}
void downheapify(vector<int> &heap, int idx){
    int leftidx = 2*idx + 1;
    int rightidx = 2*idx + 2;
    if(leftidx >= heap.size() && rightidx >= heap.size()){
        return ;
    }
    int largestidx = idx;
    if(leftidx < heap.size() && heap[leftidx] > heap[largestidx]){
        largestidx = leftidx;
    }
    if(rightidx < heap.size() && heap[rightidx] > heap[largestidx]){
        largestidx = rightidx;
    }
    if(largestidx == idx){
        return;
    }
    swap(heap[idx], heap[largestidx]);
    downheapify(heap, largestidx);
}
void buildheap(vector<int> &heap){
    for(int i = heap.size() - 1; i >= 0; i--){
        downheapify(heap, i);
    }
}
void downheapifyhelper(vector<int> &heap, int idx, int heapsize){
    int leftidx = 2*idx + 1;
    int rightidx = 2*idx + 2;
    if(leftidx >= heapsize && rightidx >= heapsize){
        return;
    }
    int largestidx = idx;
    if(leftidx < heapsize && heap[leftidx] > heap[largestidx]){
        largestidx = leftidx;
    }
    if(rightidx < heapsize && heap[rightidx] > heap[largestidx]){
        largestidx = rightidx;
    }
    if(largestidx == idx){
        return;
    }
    swap(heap[idx], heap[largestidx]);
    downheapifyhelper(heap, largestidx, heapsize);
}
void heapsort(vector<int> &heap){
    int heapsize = heap.size() - 1;
    for(int i = heap.size() - 1; i >= 0; i--){
        swap(heap[0], heap[i]);
        downheapifyhelper(heap, 0, heapsize);
        heapsize--;
    }
}
void display(vector<int> &heap){
    for(int i = 0; i < heap.size();i++){
        cout << heap[i] << " ";
    }   
}
int median(vector<int> &heap){
    if(heap.size() % 2 == 0){
        int avg = (heap[heap.size()/2]+heap[(heap.size()/2)-1])/2;
        return avg;
    }
    else{
        return heap[heap.size()/2];
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> heap;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        insertinheap(heap, x);
//        buildheap(heap);
//        heapsort(heap);
        display(heap);
        cout << endl;
//        cout << median(heap) << " ";
    }
//    buildheap(heap);
//    display(heap);
    cout << endl;
//    heapsort(heap);
    display(heap);
//    cout << median(heap);
    return 0;
}
