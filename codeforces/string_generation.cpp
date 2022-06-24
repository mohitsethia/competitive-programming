#include<iostream>
using namespace std;
void generate(char *in, char *out, int i, int j){
    if(in[i] == '\0'){
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    int digit = in[i] - '0';
    char ch = digit + 'A' - 1;
    out[j] = ch;
    //one digit at a time
    generate(in, out, i+1, j+1);
    //two digits at a time
    if(in[i+1] != '\0'){
        int secondDigit = in[i+1] - '0';
        int no = 10*digit + secondDigit;    
        if(no <= 26){
            ch = no + 'A' - 1;
            out[j] = ch;
            generate(in, out, i+2, j+1);
        }
    }
    return;
}
int main(){
    char in[100];
    cin >> in;
    char out[100];
    generate(in, out, 0, 0);
    return 0;
}
