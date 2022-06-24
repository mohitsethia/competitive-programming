/*
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        string s;
        for(int i = 0; i < n-2; i++){
            s[i] = 'a';
        }
        s[n-2] = 'b';
        s[n-1] = 'b';
        next_permutation(s.begin(), s.end(), k);
        cout << s;
    }
    return 0;
}

// Find the next lexicographically 
// greater permutation of a word 

#include <iostream> 
using namespace std; 
#define ll long long int
void swap(char* a, char* b) 
{ 
	if (*a == *b) 
		return; 
	*a ^= *b; 
	*b ^= *a; 
	*a ^= *b; 
} 
void rev(string& s, int l, int r) 
{ 
	while (l < r) 
		swap(&s[l++], &s[r--]); 
} 

int bsearch(string& s, int l, int r, int key) 
{ 
	int index = -1; 
	while (l <= r) { 
		int mid = l + (r - l) / 2; 
		if (s[mid] <= key) 
			r = mid - 1; 
		else { 
			l = mid + 1; 
			if (index == -1 || s[index] >= s[mid]) 
				index = mid; 
		} 
	} 
	return index; 
} 

bool nextpermutation(string& s) 
{ 
	int len = s.length(), i = len - 2; 
	while (i >= 0 && s[i] >= s[i + 1]) 
		--i; 
	if (i < 0) 
		return false; 
	else { 
		int index = bsearch(s, i + 1, len - 1, s[i]); 
		swap(&s[i], &s[index]); 
		rev(s, i + 1, len - 1); 
		return true; 
	} 
} 

int main() 
{
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k; 
	    string s;
        for(int i = 0; i < n-2; i++){
            s[i] = 'a';
        } 
        s[n-2] = 'b';
        s[n-1] = 'b';
        for(int i = 0; i < k; i++){ 
	        nextpermutation(s);
        }
        cout << s << endl;
    } 
	return 0; 
} 
#include<iostream>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        char s[100005];
        for(int i = 0; i < n-2; i++){
            s[i] = 'a';
        }
        s[n-2] = 'b';
        s[n-1] = 'b';
        next_permutation(s, s+n, k);
    }
    return 0;
}
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std; 
#define ll long long int
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, k; 
        cin >> n >> k;
        char s[100005];
        for(int i = 0; i < n-2; i++){
            s[i] = 'a';
        }
        s[n-2] = 'b';
        s[n-1] = 'b';
        
        for(int i = 0; i < k-1; i++){
        	next_permutation(s, s+n);
        }
        cout << s << endl;
        s[0] = '\0';
    }
    return 0;
}

