#include<iostream>
using namespace std;
void generate_subsequence(char *in, char *out, int i, int j){
    if(in[i] == '\0'){
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    out[j] = in[i];
    generate_subsequence(in, out, i+1, j+1);
    generate_subsequence(in, out, i+1, j);
} 
int main(){
    char input[1000];
    cin >> input;
    char output[1000];
    generate_subsequence(input, output, 0, 0);
    return 0;
}
/*
#include <iostream>
#include<string.h>
using namespace std;

 int subseq(string q, string ans) {

		if (q.length() == 0) {
			return 1;
		}
		char ch = q[0];
		string ros = q.substr(1);

		int count = 0;
		count += subseq(ros, ans);

		count += subseq(ros, ans + ch);

		return count;

	}

void printsubseq(string q, string ans) {

		if (q.length() == 0) {
			cout<<ans<<" ";
			return;
		}

		char ch = q[0];
		string ros = q.substr(1);

		printsubseq(ros, ans);

		printsubseq(ros, ans + ch);

	}


int main() {
    string a;
    cin>>a;

    cout<<subseq(a,"")<<endl;
    printsubseq(a,"");
    
    return 0;
    
}
*/
