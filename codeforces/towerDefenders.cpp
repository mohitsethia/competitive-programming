/*
In a not very distant galaxy on the planet X-Bombiks, the World Cup is also held. On this planet, the sun's rays fall exactly vertically downward throughout the day.
There is a watchtower near the main stadium, which consists of
n
slabs arranged one above the other so that their left edges are attached to a common column. Length
i
th slab is
a
i
...

To hold a post at the watchtower of the stadium volunteered
m
 volunteers - security guards.
j
th volunteer has shoulder width
b
j
, and the height of any of them is less than the distance between adjacent slabs.

The tower offers an excellent view of the stadium, so a lot of volunteers want to get there. At the same time, due to safety precautions, the following conditions must be met in the distribution of guards on the slabs of the tower:

1. The guard will stand sideways on the slab, so the width of the guard's shoulders should not exceed the length of the slab.

2. The guard must be fully positioned on the slab - there are protective fences at the edges of the slab (so that you cannot fall from it).

3. The guard must be completely under the sun's rays (if he is in the shade at least part of his body, he will freeze during the match).

4. On one plate there can be no more than one guard (two volunteers will not share a place in the sun).

Examine the graphical representation of the first test in the note below for a better understanding of the problem.

You need to place the maximum number of volunteers on the plates with the fulfillment of the described conditions. Rather, the match will begin any minute, and the volunteers still do not know who will be taken to guard the main stadium of the galaxy and who will be able to enjoy the cool view of the game!

Input format
The first line of the input contains two numbers n and m (1≤n,m≤2×10^5) - the number of tiles in the tower and the number of volunteers, respectively.
The second line of the input contains
n natural numbers ai(1≤ai≤10^18)) - length
ith plate in order from bottom to top.
The third line of the input contains
m natural numbersbj(1≤bj≤10^18) - shoulder width j volunteer.

Output format
Print on a single line the maximum number of volunteer guards that can be placed on the plates, taking into account the described conditions.

Sample Input - 
5 3
7 3 4 2 2
3 2 1

Sample output - 
3

*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

#define int long long
using namespace std;

signed main(){
    int n, m;
    cin >> n >> m;
    vector<int> towers(n);
    multiset<int> volunteers;
    for(int i = 0; i < n; i++){
        cin >> towers[i];
    }
    for(int j = 0; j < m; j++){
        int x;
        cin >> x;
        volunteers.insert(x);
    }
    int ans = 0;
    vector<int> maxTill(n);
    maxTill[n-1] = 0;
    for(int i = n-2; i >= 0; i--){
        maxTill[i] = max(maxTill[i+1], towers[i+1]);
    }
    for(int i = 0; i < n; i++){
        if(!volunteers.size()) break;
        int temp = towers[i]-maxTill[i];
        if(temp < 0) continue;
        auto it = volunteers.lower_bound(temp);
        if(it == volunteers.end()){
            ans++;
            volunteers.erase(prev(volunteers.end()));
        }
        else{
            if(*it == temp){
                ans++;
                volunteers.erase(it);
                continue;
            }
            int dist = distance(volunteers.begin(), it);
            if(dist >= 1){
                ans++;
                --it;
                volunteers.erase(it);
            }
            else{
                continue;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
