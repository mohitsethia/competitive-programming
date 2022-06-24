#include<iostream>
using namespace std;
void generate(char *out, int n, int i){
    if(i == n){
        out[i] = '\0';
        cout << out << endl;
        return;
    }
    out[i] = 'a';
    generate(out, n, i + 1);
    if(i == 0){
        out[i] = 'b';
        generate(out, n, i + 1);
    }
    else if(out[i-1] != 'b'){
        out[i] = 'b';
        generate(out, n, i+1);
    }
    return;
}
int main(){
    int n;
    cin >> n;
    char out[n+1];
    generate(out, n, 0);
    return 0;
}
