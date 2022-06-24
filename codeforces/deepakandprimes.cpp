#include<iostream>
#include<climits>
#include<vector>
#include<cstring>
using namespace std;
#define MAX_SIZE 10000007
#define int long long
int np[10000007] = {0};
bool primes[10000007] = {0};
void findnthprime(){ 
//    bool primes[10000007];
    //memset(primes, false, sizeof(primes));
    for(int i = 3; i < MAX_SIZE; i+=2){
        primes[i] = 1;
    }
    for(int i = 3; i < MAX_SIZE; i+=2){
        if(primes[i] == 1){
            for(int j = i*i; j < MAX_SIZE; j += i){
                primes[j] = 0;
            }
        }
    }
    primes[2] = 1;
    primes[0] = primes[1] = 0;
    np[0] = 2;
    int x = 1;
    for(int i = 3; i < MAX_SIZE; i += 2){
        if(primes[i]){
            np[x++] = i;
        }
    }
}
int32_t main(){
    int n;
	cin >> n;
//    int primes[MAX_SIZE];
    findnthprime();
    cout << np[n-1];
    return 0;
}
