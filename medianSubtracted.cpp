/*
Given an array a length 3
 from integers.
Let's define the operation of changing the array: two different indices are selected i and j (1≤i,j≤3, i≠j), then a[i] becomes equal a[i]-a[j]
...
Operation example: given an array [1,-3,2], have chosen i=2,j=1, got an array [1,-3-1,2] = [1,-4,2]...
Let's define for an array a median m as the value located at the position 2 when sorting array elements a...

For example, the median of the array a = [1,-3,2] is an m = 1, since in the sorted array [-3,1,2] exactly 1 stands in position 2...Let's call the median index such an index i, what ai = m..

Note that the median index is not necessarily the only one: in the array a = [3,0,3] median m = 3and the median indices are i1 = 1 (a1 = m) and i2 = 3 (a3 = m).For each index i array a find out if it can become the median if you can do no more than one operation of changing the array (you can not do any operations at all).

Input format
In a single line are given 3 whole numbers ai (-10^9≤ai≤10^9) separated by spaces.
Output format

For each index i (1≤i≤3) print on a separate line the answer: YES , if after no more than one operation of changing the array i may become the median index; NO  - otherwise.

Sample Input 1 

2 6 5

Sample Output 1

YES
YES
YES

Sample Input 2

0 -3 1

Sample Output 2

YES
NO
YES

*/

#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

bool check(int num, int a, int b){
    return (num >= a && num <= b) || (num >= b && num <= a);
}

bool three(int num, int a, int b){
    int temp = b;
    temp -= num;
    if(check(num, temp, a)){
        cout << "YES\n";
        return true;
    }
    temp = b;
    temp -= a;
    if(check(num, temp, a)){
        cout << "YES\n";
        return true;
    }
    return false;
}

bool two(int num, int a, int b){
    int temp = a;
    temp -= num;
    if(check(num, temp, b)){
        cout << "YES\n";
        return true;
    }
    temp = a;
    temp -= b;
    if(check(num, temp, b)){
        cout << "YES\n";
        return true;
    }
    return false;
}

bool one(int num, int a, int b){
    int temp = num;
    temp -= a;
    if(check(temp, a, b)){
        cout << "YES\n";
        return true;
    }
    temp = num;
    temp -= b;
    if(check(temp, a, b)){
        cout << "YES\n";
        return true;
    }
    return false;
}

signed main(){
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    if(check(a[0], a[1], a[2])){
        cout << "YES\n";
    }
    else{
        if(!one(a[0], a[1], a[2])){
            if(!two(a[0], a[1], a[2])){
                if(!three(a[0], a[1], a[2])){
                    cout << "NO\n";
                }
            }
        }
    }
    if(check(a[1], a[0], a[2])){
        cout << "YES\n";
    }
    else{
        if(!one(a[1], a[0], a[2])){
            if(!two(a[1], a[0], a[2])){
                if(!three(a[1], a[0], a[2])){
                    cout << "NO\n";
                }
            }
        }
    }
    if(check(a[2], a[0], a[1])){
        cout << "YES\n";
    }
    else{
        if(!one(a[2], a[0], a[1])){
            if(!two(a[2], a[0], a[1])){
                if(!three(a[2], a[0], a[1])){
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}
