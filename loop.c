#include<stdio.h>
#include<math.h>
int isprime(int x){
  int j;
  if(x == 1)
    return 0;
  for(j = 2; j <= sqrt(x); j++)
  {
    if(x % j == 0)
      return 0;
  }
  return 1;
}
int main(){
  int T, a, b, i;
  scanf("%d", &T);
  while(T--){
      scanf("%d%d", &a, &b);
      for(i = a; i <= b; i++){
        if(isprime(i))
          printf("%d\n", i);
      }
  }
  return 0; 
}