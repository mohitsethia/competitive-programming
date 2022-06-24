#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
#define int long long
int32_t main(){
    int t;
    scanf("%lld", &t);
    while(t--){
        int n;
        scanf("%lld", &n);
        std::vector<int> prefixMax(n);
        for(int i = 0; i < n; i++){
            scanf("%lld", &prefixMax[i]);
        }
        std::vector<int> minimal, maximal;
        std::set<int> nums;
        for(int i = 1; i <= n; i++){
            nums.insert(i);
        }
        int curr_max = 0;
        for(int i = 0; i < n; i++){
            int chosenNumber;
            if(prefixMax[i] > curr_max){
                chosenNumber = prefixMax[i];
            }
            else{
                chosenNumber = *nums.begin();
            }
            nums.erase(chosenNumber);
            minimal.push_back(chosenNumber);
            curr_max = max(curr_max, minimal.back());
        }
        curr_max = 0;
        for(int i = 1; i <= n; i++){
            nums.insert(i);
        }
        for(int i = 0; i < n; i++){
            int chosenNumber;
            if(prefixMax[i] > curr_max){
                chosenNumber = prefixMax[i];
            }
            else{
                chosenNumber = *(--(nums.lower_bound(prefixMax[i])));
            }
            nums.erase(chosenNumber);
            maximal.push_back(chosenNumber);
            curr_max = max(curr_max, maximal.back());
        }
        for(int i = 0; i < n; i++){
            printf("%lld ", minimal[i]);
        }
        printf("\n");
        for(int i = 0; i < n; i++){
            printf("%lld ", maximal[i]);
        }
        printf("\n");
    }
    return 0;
}
