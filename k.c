#include<stdio.h>
#include<stdlib.h>
typedef char C; typedef long I;
typedef struct k{C t;I r,n;C d[];}*K;
#define W while
#define O printf

#define SM 64 //source max
void rd(){C b[SM],*s=b;if(!fgets(s,SM,stdin)||'\\'==*s)exit(0);O("%s",s);}
int main(){W(1){rd();}}
