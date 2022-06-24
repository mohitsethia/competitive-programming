#include<iostream>
#include<algorithm>
#include<cstdio>
#include<random>
#include<vector>
#include<numeric>
#include<climits>
#include<map>
#include<set>
#include<cstring>
#include<cmath>

using namespace std;
#define int long long

#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H
#define left(i) (2*i + 1)
#define right(i) (2*i + 2)
#define parent(i) ((i-1)/2)

template<class T>
class SegmentTree
{
    public:
        //tree constructors.
        SegmentTree(std::vector<T> data, T value, T (*combine)(T obj1, T obj2));
        SegmentTree(T ar[], int n, T value, T (*combine)(T obj1, T obj2));
        
        //query the range l to r, 0 based array indexing.
        T query(int l, int r);
        
        //update the element at index idx to val.
        void update(int idx, T val);
        ///TODO lazy propagation
    private:
        //represents the segment tree.
        T *tree;
    
        //builds the segment tree.
        void buildTree(std::vector<T> data);
        
        //size of the segment tree array.
        int segTreeSize;
    
        //extra nodes must be added to array to make its size a power of 2
        //this is the value to be filled for the those nodes.
        T valueForExtraNodes;
    
        //specifies how to combine child node results to form parent node result.
        T (*combine)(T obj1, T obj2);
    
        //used to calculate the size of array needed to store the tree.
        int calculateSize(int n);
    
        //helps to solve a range query.
        T queryHelper(int l,int r, int st, int ed, int node);
};

template<class T> SegmentTree<T>::SegmentTree(std::vector<T> data,
                                                T value, T (*combine)(T obj1, T obj2))
{
   this->combine = combine;
   valueForExtraNodes = value;
   segTreeSize = calculateSize(data.size());
   buildTree(data);
}

template<class T> SegmentTree<T>::SegmentTree(T ar[], int n,
                                            T value, T (*combine)(T obj1, T obj2))
{
   this->combine = combine;
   valueForExtraNodes = value;
   segTreeSize = calculateSize(n);

   std::vector<T> data;
   for(int i = 0; i < n; i++)
         data.push_back(ar[i]);

   buildTree(data);
}


template<class T> int SegmentTree<T>::calculateSize(int n)
{
    int pow2 = 1;
    while( pow2 < n)
    {
        pow2 = pow2 << 1;
    }
    return 2*pow2 - 1;
}

template<class T> T SegmentTree<T>::query(int l, int r)
{
    int st = 0, ed = segTreeSize/2;
    return queryHelper(l, r, st, ed, 0);
}

template<class T> T SegmentTree<T>::queryHelper(int l,int r, int st, int ed, int node)
{
    if( (r < st) || (l > ed) || (l > r) )
        return valueForExtraNodes;
    if(st >= l && ed <= r)
        return tree[node];
    T leftVal = queryHelper(l, r, st, (st + ed)/2, left(node));
    T rightVal = queryHelper(l, r, (st+ed)/2 + 1, ed, right(node));
    return combine(leftVal, rightVal);
}

template<class T> void SegmentTree<T>::buildTree(std::vector<T> data)
{
   int n = data.size();
   tree = new T[segTreeSize];
   int extraNodes = (segTreeSize/2 + 1) - n;
   for(int i = segTreeSize - 1; i >= 0; i--)
   {
       if(extraNodes>0)
           {
               tree[i] = valueForExtraNodes;
               extraNodes--;
           }
       else if(n>0)
           {
               tree[i] = data[n-1];
               n--;
           }
       else
           tree[i] = combine(tree[left(i)], tree[right(i)]);
   }
}

template<class T> void SegmentTree<T>::update(int idx, T val)
{
    int segTreeIdx = (segTreeSize/2) + idx;
    tree[segTreeIdx] = val;
    while(parent(segTreeIdx) >= 0)
    {
        segTreeIdx = parent(segTreeIdx);
        if(right(segTreeIdx) < segTreeSize)
          tree[segTreeIdx] = combine(tree[left(segTreeIdx)], tree[right(segTreeIdx)]);
        if(segTreeIdx == 0)
            break;
    }
}

#endif // SEGMENTTREE_H


int merge(int a, int b){
    return gcd(a, b);
}

bool check(SegmentTree<int> &st, vector<int> &a, int &mid){
    for(int i = 0; i < (int)a.size(); i++){
        if(i + mid < (int)a.size()){
            int q = st.query(i, i+mid);
            if(q > 1){
                return true;
            }
        }
        else{
            return false;
        }
    }
    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(n == 1){
            cout << "1\n";
            continue;
        }
        for(int i = 0; i+1 < n; i++){
            a[i] = abs(a[i]-a[i+1]);
        }
        a.pop_back();
        n--;
        SegmentTree<int> st(a, 0, merge);
        /*
        int l = 1, r = n;
        while(l <= r){
            int mid = (l+r)>>1;
            if(check(st, a, mid)){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        cout << l+1 << "\n";
        */
        int curr_gcd = 0;
        int ans = 0, l = 0;
        for(int r = 0; r < n; r++){
            while(r < n){
                curr_gcd = gcd(curr_gcd, a[r]);
                if(curr_gcd == 1) break;
                ans = max(ans, r-l+1);
                r++;
            }
            while(l <= r){
                l++;
                curr_gcd = st.query(l, r);
                if(curr_gcd != 1){
                    break;
                }
            }
        }
        cout << ans+1 << "\n";
    }
    return 0;
}
