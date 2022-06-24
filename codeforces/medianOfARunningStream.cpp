#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
class MedianFinder{
private:
    priority_queue<int> leftArray;
    priority_queue<int, vector<int>, greater<int> > rightArray;
public:
    MedianFinder(){}
    void addNum(int num){
        int sz1 = leftArray.size();
        if(sz1 == 0){
            leftArray.push(num);
            return;
        }
        int sz2 = rightArray.size();
        if(sz1 == sz2){
            int first = rightArray.top();
            if(first >= num){
                leftArray.push(num);
            }
            else{
                rightArray.pop();
                rightArray.push(num);
                leftArray.push(first);
            }
        }
        else{
            int last = leftArray.top();
            if(last <= num){
                rightArray.push(num);
            }
            else{
                leftArray.pop();
                leftArray.push(num);
                rightArray.push(last);
            }
        }
    }
    double findMedian(){
        int sz1 = leftArray.size();
        int sz2 = rightArray.size();
        double median;
        if(sz1 == sz2){
            median = leftArray.top() + rightArray.top();
            median /= 2.0;
        }
        else{
            median = leftArray.top();
        }
        return median;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    MedianFinder* obj = new MedianFinder();
    while(cin >> n){
        obj->addNum(n);
        double median = obj->findMedian();
        cout << median << "\n";
    }
    return 0;
}
