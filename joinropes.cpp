
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void upheapify(vector<int> &heap, int idx){
    if(idx == 0){
        return;
    }
    int parentidx = (idx-1)/2;
    if(heap[parentidx] > heap[idx]){
        swap(heap[parentidx], heap[idx]);
        upheapify(heap, parentidx);
    }
    else{
        return;
    }
}
void downheapify(vector<int> &heap, int idx){
    int leftidx = 2*idx + 1;
    int rightidx = 2*idx + 2;
    if(leftidx >= heap.size() && rightidx >= heap.size()){
        return;
    }
    int smallidx = idx;
    if(leftidx < heap.size() && heap[leftidx] < heap[smallidx]){
        smallidx = leftidx;
    }
    if(rightidx < heap.size() && heap[rightidx] < heap[smallidx]){
        smallidx = rightidx;
    }
    if(smallidx == idx){
        return;
    }
    swap(heap[idx], heap[smallidx]);
    downheapify(heap, smallidx);
}
void buildheap(vector<int> &heap){
    for(int i = heap.size()-1; i >= 0; i--){
        downheapify(heap, i);
    }
}
void push_front(vector<int> &heap, int key){
    heap.push_back(1);
    for(int i = heap.size()-2; i >= 0; i--){
        heap[i+1] = heap[i];
    }
    heap[0] = key;
} 
int pop_front(vector<int> &heap){
    int x = heap[0];
    heap.erase(heap.begin());
    return x;
}
void joinrope(vector<int> &heap, int heapsize, int n){
    static int cost = 0;
    if(heapsize >= n - 1){
        cout << cost;
        return;
    }
    int x = pop_front(heap);
    for(int i = heap.size()-1; i >= 0; i--){
        downheapify(heap,i);
    }
    int y = pop_front(heap);
    cost += x + y;
    int z = x + y;
    cout << heap.size() << " ";
    heap.push_back(z);
    cout << heap.size() << endl;
    for(int i = heap.size()-1; i >= 0; i--){
        downheapify(heap,i);
    }
    joinrope(heap, heapsize+1, n);
}
void display(vector<int> &heap){
    for(auto i: heap){
        cout << i << " ";
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> heap;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        heap.push_back(x);
    }
    buildheap(heap);
    display(heap);
    cout << endl;
    joinrope(heap, 0, heap.size());
//    push_front(heap, 76);
    //display(heap);
}
/*
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int connect(int *ropes, int n){
    priority_queue<int, vector<int>, greater<int> > pq(ropes, ropes + n);
    int cost = 0;
    while(pq.size() > 1){
        int first = pq.top();   
        pq.pop();
        int second = pq.top();
        pq.pop();
        cost += (first+second);
        pq.push(first+second);
        cout << first+second << " " << pq.top() << endl;
    }
    return cost;    
}
int main(){
    int n;
    cin >> n;   
    int *arr = new int[n]();
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << connect(arr, n);
    return 0;
}
*/
