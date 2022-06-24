#include<iostream>
#include<cmath>
using namespace std;
#define int long long
#define prime 3
int createHashValue(string str, int n){
    int result = 0;
    for(int i = 0; i < n; i++){
        result += (int)(str[i]*(int)pow(prime, i));
    }
    return result;
}
int recalculateHash(string str, int oldIndex, int newIndex, int oldHash, int patlen){
    int newHash = oldHash - str[oldIndex];
    newHash /= prime;
    newHash += (int)(str[newIndex]*(int)(pow(prime, patlen-1)));
    return newHash;
}
bool checkequal(string str1, string str2, int start1, int end1, int start2, int end2){
    if(end1 - start1 != end2-start2){
        return false;
    }
    while(start1 <= end1 && start2 <= end2){
        if(str1[start1] != str2[start2]){
            return false;
        }
        start1++;
        start2++;
    }
    return true;
}
int32_t main(){
    string str, pat;
    cin >> str >> pat;
    int patHash = createHashValue(pat, pat.length());
    int strHash = createHashValue(str, pat.length());
    for(int i = 0; i <= str.length()-pat.length(); i++){
//        cout << "Finding.. " << i << endl;
        if(patHash == strHash && checkequal(str, pat, i, i+pat.length()-1, 0, pat.length()-1)){
            cout << i << endl;
//            return 0;
        }
        if(i < str.length()-pat.length()){
            strHash = recalculateHash(str, i, i+pat.length(), strHash, pat.length());
        }
    }
    return 0;
}
