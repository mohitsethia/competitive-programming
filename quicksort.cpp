#include<iostream>
using namespace std;
int partition(int *a, int start, int end){
    int pivot = a[end];
    int partitionIndex = start;
    for(int i = start; i < end; i++){
        if(a[i] <= pivot){
            swap(a[i], a[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(a[partitionIndex], a[end]);
    return partitionIndex;
}
void quicksort(int *a, int start, int end){
    if(start >= end){
        return;
    }
    int partitionIndex = partition(a, start, end);
    quicksort(a, start, partitionIndex - 1);
    quicksort(a, partitionIndex + 1, end);
}
int main(){
    int n, i;
    cin >> n;
    int a[n];
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    quicksort(a, 0, n-1);
    for(i = 0; i < n; i++){
        cout << a[i];
    }
    return 0;
}
