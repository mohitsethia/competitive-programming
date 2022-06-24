#include<stdio.h>
#include<time.h>
#include<iostream>
using namespace std;
int main(){
    time_t mytime;
    mytime = time(NULL);
    printf(ctime(&mytime));
    return 0;
}
