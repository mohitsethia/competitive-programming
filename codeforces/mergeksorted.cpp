/*
#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,pair<int,int>> 
vector<int> mergekarray(vector<vector<int>>arr,int k)
{
priority_queue<pp,vector<pp>,greater<pp>>pq;
vector<int>oarr;
for(int i=0;i<k;i++)
pq.push({arr[i][0],{i,0}});
while(!pq.empty())
{
    pp front=pq.top();
    pq.pop();
    oarr.push_back(front.first);
    int id=front.second.first;
    int j=front.second.second;
    if(j+1<arr[id].size())
    pq.push({arr[id][j+1],{id,j+1}});
}
return oarr;
}

int main() {
    int k,n;
    cin>>k>>n;
    vector<vector<int>>arr(k,vector<int>(n));
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        cin>>arr[i][j];
    }
    vector<int>output=mergekarray(arr,k);
    for(auto i:output)
    cout<<i<<" ";
	return 0;
}
*/
/*
#define custompair pair<int, pair<int, int> >
vector<int> mergearray(vector<vector<int> > arr){
    vector<int> result;
    priority_queue<custompair, vector<custompair>, greater<custompair> > pq;
    for(int i = 0; i < arr.size(); i++){
        pq.push( {arr[i][0], {i, 0} });
    }
    while(!pq.empty()){
        custompair curr = pq.top();
        pq.pop();
        int x = curr.second.first;
        int y = curr.second.second;
        result.push_back(curr.first);   
        if(y+1 < arr[x].size()){
            pq.push( {arr[x][y+1], {x, y+1} });
        }
    }
    return result;
}
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, pair<int, int> > cons;
vector<int> mergearrays(vector<vector<int> > v){
    vector<int> result;
    priority_queue<cons, vector<cons>, greater<cons> > pq;
    for(int i = 0; i < v.size(); i++){
        pq.push({v[i][0], {i, 0} });
    }   
    while(!pq.empty()){
        cons curr = pq.top();
        pq.pop();
        int x = curr.second.first;
        int y = curr.second.second;
        result.push_back(curr.first);
        if(y + 1 < v[x].size()){
            pq.push({v[x][y+1], {x, y+1} });
        }
    }
    return result;
}
int main(){
 //   int k;
   // cin >> k;
    vector<vector<int> > v{ {2, 6, 12, 15},
                            {1, 9, 13, 15},
                            {20, 24, 30, 32} };
/*    for(int i = 0; i < k; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
*/
    vector<int> arr = mergearrays(v);
    for(auto it: arr){
        cout << it << " ";
    }
    return 0;
}
