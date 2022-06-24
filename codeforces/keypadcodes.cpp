#include<iostream>
using namespace std;
char keypad[][10]={" ","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};
void printKeypadString(char*inp,char*out,int i,int j,int& ctr){
    if(inp[i]=='\0')
    {
    	ctr++;
        out[j]='\0';
        cout<<out<<" ";
        
    }
    int digit=inp[i]-'0';
    for(int k=0;keypad[digit][k]!='\0';k++)
    {
        out[j]=keypad[digit][k];
        printKeypadString(inp,out,i+1,j+1,ctr);

    }

}
int main() {
    char inp[100];
    char out[100];
    cin>>inp;
    int ctr=0;
    printKeypadString(inp,out,0,0,ctr);
    cout<<endl;
    cout<<ctr;
	return 0;
}
