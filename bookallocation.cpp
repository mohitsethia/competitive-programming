#include<iostream>
#include<climits>
using namespace std;
bool isPossible(int *a, int n, int m, int curr_min){
    int studentused = 1;
    int pages_reading = 0;
    for(int i = 0; i < n; i++){
//        if(a[i] > curr_min){ //Not required
//            return false;
//        }
        if(pages_reading + a[i] > curr_min){
            studentused++;
            pages_reading = a[i];
            if(studentused > m){
                return false;
            }
        }
        else{
            pages_reading += a[i];
        }
    }
    return true;
}
int findpages(int *a, int n, int m){
    int sum = 0;
    if(n < m){
        return -1;
    }
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    int s = a[n-1];
    int e = sum;
    int ans = INT_MAX;
    while(s <= e){
        int mid = (s+e)/2;
        if(isPossible(a, n, m, mid)){
            ans = min(ans, mid);
            e = mid - 1;
        }
        else{
            //It is not possible to divide at x pages
            //increase the number of pages
            s = mid + 1;
        }
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int books[n];
        for(int i = 0; i < n; i++){
            cin >> books[i];
        }
        cout << findpages(books, n, m) << endl;
    }
    return 0;
}
