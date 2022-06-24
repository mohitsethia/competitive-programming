#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class BestCoverofArray {
public:
	// DO NOT read from stdin or write to stdout
	// Input is given as function argument
	// Output is taken as the function return value
int findcover(std::vector<int> A, int K, int Q) {
		// Code here
		if(A.size() == 0) return 0;
		priority_queue<pair<int, int> > pq;
		int total = 0;
		for(int i = 0; i < A.size(); i++){
			total += A[i] == 0;
		}
		if(total == 0) return 0;
		else if(K == 0 || Q == 0) return total;
		else if(K == 1) return total-Q;
		else if((A.size() <= K && Q > 0) || (K > 0 && Q >= A.size())) return 0;
		int count = 0;
		for(int i = 0; i < K; i++){
			count += A[i] == 0;
		}
		total = count;
		if(count) pq.push({count, 0});
		for(int i = 1; i < A.size()- K+1; i++){
			if(A[i-1] == 0) count--;
			if(A[i+K-1] == 0){
				count++;
				total++;
			}
			if(count){
				pq.push({count, i});
			}
		}
		while(Q && pq.size()){
			pair<int, int> temp = pq.top();
			pq.pop();
			if(temp.first == 0) continue;
			count = 0;
			vector<int> pt = A;
			for(int i = temp.second; i < temp.second+K; i++){
				if(temp.second+K-1 >= A.size()) break;
				count += A[i] == 0;
				pt[i] = 1;
			}
			if(count == 0) continue;
			if(count == temp.first){
				A = pt;
				Q--;
			}
			else{
				pq.push({count, temp.second});
			}
		}
		count = 0;
		for(int i = 0; i < A.size(); i++){
			count += A[i] == 0;
		}
		return count;
	}
};


int main(){
    int n, K, Q;
    cin >> n >> K >> Q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    BestCoverofArray *obj = new BestCoverofArray();
    cout << obj->findcover(a, K, Q);
    return 0;
}

