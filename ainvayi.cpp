#include<iostream>
using namespace std;
int func (int array[], int n){
    int low=0, mid=0, high = n - 1;
    while(mid <= high)
    if (array[mid] == 0){
        swap (array[low], array[mid]);
        low++;
        mid++;
    }
    else if(array[mid] == 1){
        mid++;
    }
    else{
        swap(array[high], array[mid]);
        high--;
    }
    return low;
}
int main(){
    int array[9] = {0, 2, 2, 2, 1, 1, 1, 0, 1};
    cout << func(array, 9);
    for(int i = 0; i < 9; i++){
        cout << array[i] << " ";
    }
    return 0;
}
