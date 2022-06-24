//given a rotated sorted array, we need to find an element using binary search
#include<iostream>
#include<algorithm>
using namespace std;
int findnum(int *a, int n, int target){
    int s = 0, e = n-1, mid = 0;
    while(s <= e){
        mid = (s+e)/2;
        if(a[mid] == target){
            return mid;
        }
        else if(a[s] <= a[mid]){
            if(target >= a[s] and target <= a[mid]){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        else{
            if(target <= a[e] and target >= a[mid]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int target;
    cin >> target;
    cout << findnum(a, n, target) << endl;
    return 0;
}
