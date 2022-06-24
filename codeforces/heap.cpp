#include<iostream>
#include<vector>
using namespace std;
void upheapify(vector<int> &heap, int idx){
    if(idx == 0){
        return;
    }
    int parent = (idx-1)/2;
    if(heap[parent] < heap[idx]){
        int temp = heap[parent];
        heap[parent] = heap[idx];   
        heap[idx] = temp;
        upheapify(heap, parent);
    }
    else{
        return;
    }
}
void insertinheap(vector<int> &heap, int key){
    heap.push_back(key);
    upheapify(heap, heap.size() - 1);
}
void downheapify(vector<int> &heap, int idx){
    int leftidx = 2*idx + 1;
    int rightidx = 2*idx +2;
    if(leftidx >= heap.size() && rightidx >= heap.size()){
        return;
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
    swap(heap[largestidx], heap[idx]);
    downheapify(heap, largestidx);
}
void deletepeek(vector<int> &heap){
    swap(heap[0], heap[heap.size()-1]);
    heap.pop_back();
    downheapify(heap, 0);
}
void deletenode(vector<int> &heap, int data){
    vector<int>::iterator it = find(heap.begin(), heap.end(), data);
    int y;
    if(it != heap.end()){
        y = distance(heap.begin(), it);
    }
    heap[y] = INT_MAX;
    upheapify(heap, y);
    deletepeek(heap);
}
void display(vector<int> &heap){
    for(vector<int>::iterator it = heap.begin(); it != heap.end(); it++){
        cout << *it << " ";
    }
}

//build heap in O(n) time complexity
void buildheap(vector<int> &heap){
    for(int i = heap.size() - 1; i >= 0; i--){
        downheapify(heap, i);
    }
}
int main(){
    int n;
    cin >>  n;
    vector<int> heap;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        insertinheap(heap,x);
//        heap.push_back(x);
    }
    buildheap(heap);
    display(heap);
    cout << endl;
    deletepeek(heap);
    display(heap);
    cout << endl;
    int x;
    cin >> x;
    deletenode(heap, x);
    display(heap);
    return 0;
}
