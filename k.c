#include<stdio.h>
#include<stdlib.h>
typedef char C; typedef long I; typedef void V;
typedef struct k{C t;I r,n;C d[];}*K;
#define kT(k) (k->t)
#define kR(k) (k->r)
#define kN(k) (k->n)
#define kD(k) ((void*)(k->d))
#define xt    (kT(x))
#define xr    (kR(x))
#define xn    (kN(x))
#define xc    ((C*)kD(x))
#define xi    ((I*)kD(x))
#define W while
#define O printf
#define R return
#define DO(n,x) {I _n=(n),i=0;for(;i<_n;++i){x;}}

// object
enum {KE=-128,KK=0,KI,KU};
K ma(I n){R (K)malloc(sizeof(struct k)+8*n);}
K tn(C t,I n){K x=ma(n);R xt=t,xr=0,xn=n,x;}
K ki(I i){K x=tn(-KI,1);R *xi=i,x;} K ke(C a){K x=tn(KE,1);R *xc=a,x;}
K ku(I i){K x=tn( KU,1);R *xi=i,x;}
V r0(K x){if(xr--)R;free(x);}

// parse
I qn(C a){R a>='0'&&a<='9';} 
C vt[]=" +!#,"; I qv(C a){I i=-1;W(vt[++i])if(a==vt[i])R i;R 0;}
K pi(C**p){C*s=*p;I i=0;W(qn(*s))i=(*s++-'0')+10*i;R *p=s,ki(i);}
K pe(C *s){W(' '==*s)++s;I i;R qn(*s)?pi(&s):(i=qv(*s))?ku(i):ke(*s);}

// print
K pr(K x){-KI==xt?O("%ld",*xi):KU==xt?O("%c:",vt[*xi]):O("'%c",*xc);R O("\n"),r0(x),x;}

// repl
#define SM 64 //source max
K rd(){C b[SM];if(!fgets(b,SM,stdin)||'\\'==*b)exit(0);R pe(b);}
int main(){W(1){O(" ");pr(rd());}}
