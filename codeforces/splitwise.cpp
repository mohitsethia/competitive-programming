#include<iostream>
#include<set>
#include<map>
using namespace std;
#define int long long
class person_compare{
public:
	bool operator()(pair<string, int> p1, pair<string, int> p2) const {
		return p1.second < p2.second;
	}
};
int32_t main(){
    int no_of_transactions, friends;
    cin >> no_of_transactions >> friends;
 	string x, y;
 	int amt;
 	map<string, int> net;
 	while(no_of_transactions--){
 		cin >> x >> y >> amt;
 		if(net.count(x) == 0){
 			net[x] = 0;
 		}
 		if(net.count(y) == 0){
 			net[y] = 0;
 		}
 		net[x] -= amt;
 		net[y] += amt;
 	}
 	multiset<pair<string, int>, person_compare > m;
 	for(auto p : net){
 		string person = p.first;
 		int amount = p.second;
 		if(net[person] != 0){
 			m.insert(make_pair(person, amount));
 		}
 	}
 	int cnt = 0;
 	while(!m.empty()){
 		auto low = m.begin();
 		auto high = prev(m.end());
 		string debit_person = low->first;
 		int debit = low->second;
 		int credit = high->second;
 		string credit_person = high->first;
 		m.erase(low);
 		m.erase(high);
 		int settle_amt = min(-debit, credit);
 		debit += settle_amt;
 		credit -= settle_amt;
 		cout << debit_person << " will pay Rs " << settle_amt << " to " << credit_person << endl;
 		if(debit != 0){
 			m.insert(make_pair(debit_person, debit));
 		}
 		if(credit != 0){
 			m.insert(make_pair(credit_person, credit));
 		}
 		cnt++;
 	}
 	cout << cnt << endl;
 /*   int x, y, amount;
    int net[100000] = {0};
    while(no_of_transactions--){
    	cin >> x >> y >> amount;
    	net[x] -= amount;
    	net[y] += amount;
    }
    multiset<int> m;
    for(int i = 0; i < friends; i++){
    	if(net[i] != 0){
    		m.insert(net[i]);
    	}
    }
    int cnt = 0;
    while(!m.empty()){
    	auto low = m.begin();
    	auto high = prev(m.end());
    	int debit = *low;
    	int credit = *high;
    	m.erase(low);
    	m.erase(high);
    	int settle_amt = min(-debit, credit);
    	cnt++;
    	debit += settle_amt;
    	credit -= settle_amt;
    	if(debit!=0){
    		m.insert(debit);
    	}
    	if(credit != 0){
    		m.insert(credit);
    	}
    }
    cout << cnt << endl;
   */
    return 0;
}
