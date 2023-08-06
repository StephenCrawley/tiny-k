#include<stdio.h>
#include<stdlib.h>
typedef char C; typedef long I; typedef void V;
typedef struct {C t;I r,n;C d[];}*K;
#define kT(k) ((k)->t)
#define kR(k) ((k)->r)
#define kN(k) ((k)->n)
#define kD(k) ((void*)((k)->d))
#define xt    (kT(x))
#define xr    (kR(x))
#define xn    (kN(x))
#define xc    ((C*)kD(x))
#define xi    ((I*)kD(x))
#define xk    ((K*)kD(x))
#define yt    (kT(y))
#define yn    (kN(y))
#define yc    ((C*)kD(y))
#define yi    ((I*)kD(y))
#define yk    ((K*)kD(y))
#define zt    (kT(z))
#define zi    ((I*)kD(z))
#define zk    ((K*)kD(z))
#define W while
#define O printf
#define R return
#define DO(n,x) {I _n=(n),i=0;for(;i<_n;++i){x;}}
#define V1(f) K f(K x)
#define V2(g) K g(K x,K y)

C*sc(C *s,C c){W(*s!=c)if(!*s++)R 0;R s;}

// object
enum {KE=-128,KK=0,KI,KS,KU,KV,KW};
K ma(I n){K k=malloc(sizeof(*k)+sizeof(I)*n);R k;}
K tn(C t,I n){K x=ma(n);R xt=t,xr=0,xn=n,x;}
K k1(K a){K x=tn(KK,1);R *xk=a,x;}
K k2(K a,K b){K x=tn(KK,2);R *xk=a,xk[1]=b,x;}
K k3(K a,K b,K c){K x=tn(KK,3);R *xk=a,xk[1]=b,xk[2]=c,x;}
K ks(C a){K x=tn(-KS,1);R *xc=a,x;}
K ki(I i){K x=tn(-KI,1);R *xi=i,x;} K ke(C a){K x=tn(KE,1);R *xc=a,x;}
K ku(I i){K x=tn( KU,1);R *xi=i,x;} K kv(I i){K x=tn(KV,1);R *xi=i,x;}
K kw(I i){K x=tn( KW,1);R *xi=i,x;} K kwv(I w,I v){R k2(kw(w),kv(v));}
K kK(I n){R tn(KK,n);}              K kI(I n){R tn(KI,n);}
V r0(K x){if(xr--)R;if(!xt)DO(xn,r0(xk[i]));free(x);} K r1(K x){R xr++,x;}
K xp(K x){if(!xt)R x;K z=kK(xn);DO(xn,zk[i]=ki(xi[i]))R r0(x),z;}
K sq(K x){K y,z=kI(xn);
 DO(xn,y=xk[i];if(-KI!=yt){r0(z);R x;}zi[i]=*yi;)R r0(x),z;}

// parse
C*ws(C*s){W(' '==*s)++s;R s;} 
I qn(C a){R a>='0'&&a<='9';} I qa(C a){R a>='a'&&a<='z';}
C vt[]=" :+*!#,"; I qv(C a){C *s=sc(vt,a);R s?s-vt:0;}
C wt[]=" /\\"; I qw(C a){C *s=sc(wt,a);R s?s-wt:0;} 
K pi(C**p){C*s=*p;I i=0;W(qn(*s))i=i*10+*s++-'0';R *p=s,ki(i);}
K pe(C *s){s=ws(s);if(!*s)R 0;K x,y;C a=*s++;I w,v=qv(a),n=qn(a);
 if(!v&&!n&&!qa(a)){R ke(a);}if(v){w=qw(*s);s=ws(w?s+1:s);
  R !*s?ke(a):KE==kT(y=pe(s))?y:k2(w?kwv(w,v):ku(v),y);}
 x=n?--s,pi(&s):ks(a);s=ws(s),a=*s++;if(!a)R x;
 v=qv(a);if(v&&(w=qw(*s)))++s;if(!v||!*(s=ws(s)))R r0(x),ke(a);
 R y=pe(s),KE==yt?r0(x),y:k3(w?kwv(w,v):kv(v),x,y);}

K g[26]={0}; //global vars a-z

// verbs
V1(first){K r=xt?ki(*xi):r1(*xk);R r0(x),r;}
V1(til){if(-KI!=xt)R r0(x),ke('!');K y=kI(*xi);DO(yn,yi[i]=i);R r0(x),y;}
V1(count){K y=ki(xn);R r0(x),y;} V1(enlist){R sq(k1(x));}
V2(join){K z=kK(xn+yn);x=xp(x);y=xp(y);
 DO(xn,zk[i]=r1(xk[i]));DO(yn,zk[i+xn]=r1(yk[i]));R r0(x),r0(y),sq(z);}
V2(set){I v=*xc-'a';if(g[v])r0(g[v]);R g[v]=r1(y);}
K n_take(I n,K x){I t=xt<0?-xt:xt;K z=tn(t,n);
 if(!xt)DO(n,zk[i]=r1(xk[i%xn]))else DO(n,zi[i]=xi[i%xn])R r0(x),z;}
V2(take){if(-KI!=xt)R r0(x),r0(y),ke('#');y=n_take(*xi,y);R r0(x),y;}
V2(add){if(xt>=0&&yt>=0&&xn!=yn)R r0(x),r0(y),ke('+');K z,t;
 if(yn>xn||(xt&&!yt)){z=x,x=y,y=z;}z=tn(xt,xn);
 if(!xt){y=xp(n_take(xn,y));DO(xn,t=add(r1(xk[i]),r1(yk[i]));
  if(KE==kT(t)){W(i--)r0(zk[i]);free(z);z=t;break;}zk[i]=t;)R r0(x),r0(y),z;}
 if(xn>yn)DO(xn,zi[i]=xi[i]+*yi)else DO(xn,zi[i]=xi[i]+yi[i])R r0(x),r0(y),z;}
K (*fu[])()={0,0,0,first,til,count,enlist},
  (*fv[])()={0,0,add,0,0,take,join};

// eval
K xscan(K(*v)(K,K),K x,K y){if(!yn)R r0(x),y;K t,z=kK(yn);y=xp(y);*zk=x;
 t=v(x,r1(*yk));if(KE==kT(t))R r0(x),r0(y),t;*zk=t;I j=0;
 DO(yn-1,t=v(r1(zk[i]),r1(yk[++j]));if(KE==kT(t)){
  r0(x);r0(y);W(j--)r0(zk[j]);free(z);R t;}zk[j]=t;)R r0(y),sq(z);}
K xover(K(*v)(K,K),K x,K y){x=xscan(v,x,y);if(KE==xt)R x;
 K r=xt?ki(xi[xn-1]):r1(xk[xn-1]);R r0(x),r;}
K w0(K x){R vt[*xi]==','?kI(0):ki(0);}
K ew(K x,K y,K z){I i=*(I*)kD(*xk);x=xk[1];R (1==i?xover:xscan)(fv[*xi],y,z);}
V1(get){K y=g[*xc-'a'];R y?r1(y):ke(*xc);}
K e0(K x){K y,z;if(xt)R -KS==xt?get(x):r1(x);y=xk[1];
 if(2==xn)R x=*xk,y=e0(y),KE==yt?y:!xt?ew(x,w0(xk[1]),y):fu[*xi]?fu[*xi](y):y;
 z=e0(xk[2]);if(KE==zt)R z;x=*xk;if(-KS==yt&&KV==xt&&vt[*xi]==':')R set(y,z);
 y=e0(y);R KE==yt?r0(z),y:!xt?ew(x,y,z):!fv[*xi]?r0(y),z:fv[*xi](y,z);}
K ev(K x){if(!x)R x;K y=e0(x);R r0(x),y;}

// print
V p0(K x){if(KI==xt){DO(xn,O("%ld ",xi[i]));R;}
 -KI==xt?O("%ld",*xi):-KS==xt?O("`%c",*xc):KW==xt?O("%c",wt[*xi]):
  KE==xt?O("'%c",*xc):O(KU==xt?"%c:":"%c",vt[*xi]);}
V pk(K x){if(xt>=0&&1==xn)O(",");
 if(xt){p0(x);R;}O("(");DO(xn,pk(xk[i]);if(i<xn-1)O(";"))O(")");}
K pr(K x){if(!x)R x;pk(x);O("\n");R r0(x),x;}

// repl
#define SM 64 //source max
K rd(){C b[SM];if(!fgets(b,SM,stdin)||'\\'==*b)exit(0);R *sc(b,'\n')=0,pe(b);}
int main(){W(1){O(" ");pr(ev(rd()));}}
