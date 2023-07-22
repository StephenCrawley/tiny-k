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
#define xk    ((K*)kD(x))
#define yt    (kT(y))
#define W while
#define O printf
#define R return
#define DO(n,x) {I _n=(n),i=0;for(;i<_n;++i){x;}}

C*sc(C *s,C c){W(*s!=c)if(!*s++)R 0;R s;}

// object
enum {KE=-128,KK=0,KI,KS,KU,KV,KW};
K ma(I n){R (K)malloc(sizeof(struct k)+8*n);}
K tn(C t,I n){K x=ma(n);R xt=t,xr=0,xn=n,x;}
K k2(K a,K b){K x=tn(KK,2);R *xk=a,xk[1]=b,x;}
K k3(K a,K b,K c){K x=tn(KK,3);R *xk=a,xk[1]=b,xk[2]=c,x;}
K ks(C a){K x=tn(-KS,1);R *xc=a,x;}
K ki(I i){K x=tn(-KI,1);R *xi=i,x;} K ke(C a){K x=tn(KE,1);R *xc=a,x;}
K ku(I i){K x=tn( KU,1);R *xi=i,x;} K kv(I i){K x=tn(KV,1);R *xi=i,x;}
K kw(I i){K x=tn( KW,1);R *xi=i,x;} K kwv(I w,I v){R k2(kw(w),kv(v));}
V r0(K x){if(xr--)R;if(!xt)DO(xn,r0(xk[i]));free(x);}
K r1(K x){R xr++,x;}

// parse
C*ws(C*s){W(' '==*s)++s;R s;} 
I qn(C a){R a>='0'&&a<='9';} I qa(C a){R a>='a'&&a<='z';}
C vt[]=" :+!#,"; I qv(C a){C *s=sc(vt,a);R s?s-vt:0;}
C wt[]=" /\\"; I qw(C a){C *s=sc(wt,a);R s?s-wt:0;} 
K pi(C**p){C*s=*p;I i=0;W(qn(*s))i=i*10+*s++-'0';R *p=s,ki(i);}
K pe(C *s){s=ws(s);K x,y;C a=*s++;I w,v=qv(a),n=qn(a);
 if(!v&&!n&&!qa(a))R ke(a);if(v&&(w=qw(*s)))++s;
 if(v){s=ws(s);if(!*s)R ke(a);R y=pe(s),KE==yt?y:k2(w?kwv(w,v):ku(v),y);}
 --s,x=n?pi(&s):ks(*s++);if(KE==xt)R x;s=ws(s),a=*s++;if(!a)R x;
 v=qv(a);if(v&&(w=qw(*s)))++s;if(!v||!*(s=ws(s)))R r0(x),ke(a);
 R y=pe(s),KE==yt?r0(x),y:k3(w?kwv(w,v):kv(v),x,y);}

// print
V p0(K x){-KI==xt?O("%ld",*xi):-KS==xt?O("`%c",*xc):KW==xt?O("%c",wt[*xi]):
           KE==xt?O("'%c",*xc):O(KU==xt?"%c:":"%c",vt[*xi]);}
V pk(K x){if(xt){p0(x);R;}O("(");DO(xn,pk(xk[i]);if(i!=xn-1)O(";"))O(")");}
K pr(K x){pk(x);O("\n");R r0(x),x;}

// repl
#define SM 64 //source max
K rd(){C b[SM];if(!fgets(b,SM,stdin)||'\\'==*b)exit(0);R *sc(b,'\n')=0,pe(b);}
int main(){W(1){O(" ");pr(rd());}}
