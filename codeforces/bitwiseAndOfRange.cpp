#include<iostream>
#include<algorithm>

using namespace std;

class Solution{
    int msbPos(int n){
        int pos = -1;
        while(n){
            pos++;
            n >>= 1;
        }
        return pos;
    }
    public:
    int andOfRange(int left, int right){
        int res = 0;
        while(left && right){
            int msbOfLeft = msbPos(left);
            int msbOfRight = msbPos(right);
            if(msbOfLeft != msbOfRight) break;
            int msbVal = (1 << msbOfLeft);
            res += msbVal;
            left -= msbVal;
            right -= msbVal;
        }
        return res;
    }
};

int main(){
    int left, right;
    cin >> left >> right;
    Solution *obj = new Solution();
    cout << obj->andOfRange(left, right) << "\n";
    return 0;
}
