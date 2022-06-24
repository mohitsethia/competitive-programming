/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool mycompare(pair<int, int> a, pair<int, int> b){
//    if(a.second == b.second){
  //      return a.first < b.first;
    //}
//    else
  //      return a.second < b.second;
    if(a.first == b.first){
        return a.second < b.second;
    }
    else{
        return a.first < b.first;
    }
}
int main(){
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    for(int i = 0; i < n; i++){
        int x, u;
        cin >> x >> u;
        v.push_back(make_pair(x, u));
    }
    sort(v.begin()+1, v.end(), mycompare);
    for(auto i: v){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
*/
/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
void downheapify(vector<int> &heap, int idx){
    int leftidx = 2*idx + 1;
    int rightidx = 2*idx + 2;
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
    swap(heap[idx], heap[largestidx]);
    downheapify(heap, largestidx);
}
void upheapify(vector<int> &heap, int idx){
    if(idx == 0){
        return;
    }
    int parentidx = (idx-1)/2;
    if(heap[parentidx] < heap[idx]){
        swap(heap[parentidx], heap[idx]);
        upheapify(heap, parentidx);
    }
    else{
        return;
    }
}
void buildheap(vector<int> &heap){
    for(int i = heap.size()-1; i >= 0; i--){
        downheapify(heap, i);
    }
}
void deletepeek(vector<int> &heap){
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    downheapify(heap, 0);
}
void deletenode(vector<int> &heap, int data){
    for(int i = 0; i < heap.size(); i++){
        if(heap[i] == data){
            heap[i] = INT_MAX;
            upheapify(heap, i);
            break;
        }
    }
    deletepeek(heap);
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
    int heapsize = heap.size()-1;
    for(int i = heap.size()-1; i >= 0; i--){
        swap(heap[0], heap[i]);
        downheapifyhelper(heap, 0, heapsize);
        heapsize--;
    }
}
void display(vector<int> &heap){
    for(auto it:heap){
        cout << it << " ";
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
//    display(heap);
//    cout << endl;
//    deletepeek(heap);
//    display(heap);
//    cout << endl;
//    int y;
//    cin >> y;
//    deletenode(heap, y);
//    display(heap);
//    cout << endl;
    heapsort(heap);
    display(heap);
    return 0;
}
*/
#include<iostream>
#include<numeric>
using namespace std;
int main(){
    int numbers[10];    
    iota(numbers, numbers+5, 1);
    iota(numbers+5, numbers+10, 1);
    for(auto i:numbers){
        cout << i << " ";
    }
    return 0;
}
