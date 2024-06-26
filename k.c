#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char C; typedef long long I; typedef void V;
typedef struct  {C t;I r,n;C d[];}*K;
#define kT(k)   ((k)->t)
#define kR(k)   ((k)->r)
#define kN(k)   ((k)->n)
#define kD(k)   ((void*)((k)->d))
#define xt      (kT(x))
#define xr      (kR(x))
#define xn      (kN(x))
#define xc      ((C*)kD(x))
#define xi      ((I*)kD(x))
#define xk      ((K*)kD(x))
#define yt      (kT(y))
#define yn      (kN(y))
#define yi      ((I*)kD(y))
#define zi      ((I*)kD(z))
#define zk      ((K*)kD(z))
#define W       while
#define R       return
#define O       printf
#define Oc(c)   O("%c",c)
#define DO(n,x) {I _n=(n),i=0;for(;i<_n;++i){x;}}
#define V1(f)   K f(K x)
#define V2(g)   K g(K x,K y)
#define Zi(n,e) ({K z=kI(n);DO(n,zi[i]=e);z;})
#define Zk(n,e) ({K z=kK(n),t;DO(n,if(QE(t=e))R Z0(t);zk[i]=t);z;})
#define X0(e)   ({K _e=(e);r0(x),_e;})
#define Y0(e)   ({K _e=(e);r0(y),_e;})
#define Z0(e)   ({K _e=(e);r0(z),_e;})
#define QE(e)   (KE==kT(e))

// object
enum {KE=-128,KK=0,KI,KS,KU,KV,KW};
K tn(C t,I n){K x=calloc(1,sizeof(*x)+sizeof(I)*n);R xt=t,xr=0,xn=n,x;}
K k1(K a){K x=tn(KK,1);R *xk=a,x;}
K k2(K a,K b){K x=tn(KK,2);R *xk=a,xk[1]=b,x;}
K k3(K a,K b,K c){K x=tn(KK,3);R *xk=a,xk[1]=b,xk[2]=c,x;}
K ka(I t,I i){K x=tn(t,1);R *xi=i,x;} K ki(I i){R ka(-KI,i);} 
K ku(I i){R ka(KU,i);} K kv(I i){R ka(KV,i);} K ks(I a){R ka(-KS,a);}
K ke(I a){R ka(KE,a);} K kw(I i){R ka(KW,i);} K kK(I n){R tn( KK,n);} 
K kI(I n){R tn(KI,n);} K kwv(I w,I v){R k2(kw(w),kv(v));}
V r0(K x){if(!x||xr--)R;if(!xt)DO(xn,r0(xk[i]));free(x);} K r1(K x){R xr++,x;}
K xp(K x){R xt?X0(Zk(xn,ki(xi[i]))):x;}
K sq(K x){DO(xn,if(kT(xk[i])!=-KI)R x;)R X0(Zi(xn,*(I*)kD(xk[i])));}
K ix(I i,K x){R 0>xt?r1(x):xt?ki(xi[i]):r1(xk[i]);}

// parse
#define EOE(c) strchr(");\0",(c)) //end of expression
C ws(C**p){W(' '==**p)++*p;R **p;} I qb(C a){R '('==a;}
I qi(C a){R a>='0'&&a<='9';} I qa(C a){R a>='a'&&a<='z';}
C vt[]=" :+*!#,@"; I qv(C a){C *s=strchr(vt,a);R s?s-vt:0;}
C wt[]=" /\\"; I qw(C a){C *s=strchr(wt,a);R s?s-wt:0;} 
K pi(C**p){C*s=*p;I i=0;W(qi(*s))i=i*10+*s++-'0';R *p=s,ki(i);}
K pE();K pb(C**p){K x;R !ws(p)?ke(')'):')'==**p?++*p,kK(0):
 QE(x=pE(',',p))?x:')'==**p?++*p,x:X0(ke(')'));}
K pe(C**p){K x,y;C a=ws(p);++*p;I w,v=qv(a),n=qi(a),b=qb(a);
 if(!v&&!n&&!b&&!qa(a)){R ke(a);}if(v){w=qw(**p);
  R (*p)+=!!w,!ws(p)?ke(a):QE(y=pe(p))?y:k2(w?kwv(w,v):ku(v),y);}
 x=n?--*p,pi(p):b?pb(p):ks(a);if(QE(x))R x;if(EOE(a=ws(p)))R x;
 v=qv(a);if(v&&(w=qw(*++*p)))++*p;if(!v||EOE(ws(p)))R X0(ke(a));
 R QE(y=pe(p))?X0(y):k3(w?kwv(w,v):kv(v),x,y);}
K Cat();K pE(I u,C**p){K t,x=kK(0);
 do{t=pe(p);if(QE(t))R X0(t);x=Cat(x,k1(t));}W(';'==*(*p)++);--*p;
 R 1==xn?X0(ix(0,x)):Cat(k1(ku(qv(u))),x);}

// verbs
K g[26]={0}; // variable table a-z
V1(nyi){R X0(ke(0));} V2(Nyi){R X0(Y0(ke(0)));}
V1(top){R xn?X0(ix(0,x)):x;} V1(til){R X0(-KI!=xt?ke('!'):Zi(*xi,i));}
V1(cnt){R X0(ki(xn));} V1(enl){R sq(k1(x));}
V2(Cat){R X0(Y0(sq(Zk(xn+yn,i<xn?ix(i,x):ix(i-xn,y)))));}
V2(set){I v=*xc-'a';if(g[v])r0(g[v]);R g[v]=r1(y);}
V2(Tak){R X0(Y0(-KI!=xt?ke('#'):yt?Zi(*xi,yi[i%yn]):Zk(*xi,ix(i%yn,y))));}
#define OP(f,op) if(-KI==xt)R -KI==yt?X0(Y0(ki(*xi op *yi))):f(y,x); \
 R X0(Y0(-KI==yt?xt?Zi(xn,xi[i] op *yi):Zk(xn,f(ix(i,x),r1(y))):     \
 xn!=yn?ke(*#op):xt&&yt?Zi(xn,xi[i] op yi[i]):Zk(xn,f(ix(i,x),ix(i,y)))));
V2(Add){OP(Add,+)} V2(Mlt){OP(Mlt,*)}
V2(Ind){R X0(Y0(0>xt?ke('@'):!yt?Zk(yn,Ind(r1(x),ix(i,y))):
 0>yt?ix(*yi,x):sq(Zk(yn,xn>yi[i]?ix(yi[i],x):ki(0)))));}
K scan(K(*v)(),K x,K y){if(!yn)R Y0(x);
  R yn?sq(Y0(Zk(yn,i?v(ix(i-1,z),ix(i,y)):v(x,ix(i,y))))):X0(y);}
K over(K(*v)(),K x,K y){R QE(x=scan(v,x,y))||!xn?x:X0(ix(xn-1,x));}
K (*fu[])()={0,nyi,nyi,top,til,cnt,enl,nyi},
  (*fv[])()={0,Nyi,Add,Mlt,Nyi,Tak,Cat,Ind},(*fw[])()={0,over,scan};

// eval
K w0(K x){R vt[*xi]==','?kI(0):ki(vt[*xi]=='*');}
K ew(K x,K a,K b){K y=xk[1];x=*xk;R fw[*xi](fv[*yi],a?a:w0(y),b);}
K ee(K x){K y,z;if(!xn)R r1(x);if(xt)R y=-KS!=xt?x:g[*xc-'a'],y?r1(y):ke(*xc);
 if(xn>2&&KU==kT(*xk)){I i=xn-1;z=kK(i);
  W(i){K t;if(QE(t=ee(xk[i])))R Z0(t);zk[--i]=t;}R sq(z);}
 y=xk[1];if(2==xn)R x=*xk,QE(y=ee(y))?y:xt?fu[*xi](y):ew(x,0,y);
 if(QE(z=ee(xk[2]))){R z;}x=*xk;if(-KS==yt&&KV==xt&&vt[*xi]==':')R set(y,z);
 R QE(y=ee(y))?Z0(y):xt?fv[*xi](y,z):ew(x,y,z);}
K eE(K x){DO(xn-1,r0(ee(xk[i+1])));R ee(xk[xn-1]);}
K ev(K x){R !x?x:X0((xn&&!xt&&KU==kT(*xk)&&qv(';')==*(C*)kD(*xk)?eE:ee)(x));}

// print
V pk(K x){if(xt<0||xt>KS){-KI==xt?O("%lld",*xi):-KS==xt?O("`%c",*xc):
 QE(x)?*xc?O("'%c",*xc):O("'nyi"):Oc((KW==xt?wt:vt)[*xi]);R;}r1(x);
 C l="\0("[!xt];if(KI==xt)x=xp(x);if(1==xn){Oc(','),pk(*xk);r0(x);R;}
 Oc(l);DO(xn-1,pk(xk[i]);Oc("; "[!l]));pk(xk[xn-1]);Oc(")\0"[!l]);r0(x);}
K pr(K x){if(!x)R x;xn?pk(x):O(xt?"!0":"()");O("\n");R X0(x);}

// repl
K rd(){C b[64],*s;if(!fgets(b,64,stdin)||'\\'==*b){DO(26,r0(g[i]));exit(0);}
 K x;R *strchr(b,'\n')=0,s=b,x=!ws(&s)?0:pE(';',&s),*s?X0(ke(*s)):x;}
int main(){W(1){O(" ");pr(ev(rd()));}}
