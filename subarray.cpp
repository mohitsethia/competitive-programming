
/*
//Finding subarray using cummmulative sum method

#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n], cs[n], i, j, p = -1, q = -1, tempsum = 0, maxsum= 0;
    cin >> a[0];
    cs[0] = a[0];
    for(i = 1; i < n; i++){
        cin >> a[i];
        cs[i] = cs[i-1] + a[i];
    }
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            tempsum = cs[j] - cs[i-1];
            if(tempsum > maxsum){
                maxsum = tempsum;
                p = i;
                q = j;
            }
        }
    }
    cout << "Maximum sum is: " << maxsum << endl;
    for(i = p; i <= q; i++){
        cout << a[i] << " ";
    }
    return 0;
}
*/


//Finding subarray using kadane's algorithm

#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n], i, p = -1, q = -1, cs = 0, maxsum = 0;
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    for(i = 0; i < n; i++){
        cs = cs + a[i];
        if(cs < 0){
            cs = 0;
        }
        if(cs > maxsum){
            maxsum = cs;
        }
    }
    return 0;
}
