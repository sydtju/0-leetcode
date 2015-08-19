/*
If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form of "Galleon.Sickle.Knut" 
(Galleon is an integer in [0, 107 ], Sickle is an integer in [0, 17), and Knut is an integer in [0, 29)).
*/
#include <iostream>
struct Money{
    int G, S, K;
    Money(){}
    Money(int g, int s, int k):G(g),S(s),K(k){}
    void print(){
        printf("%d.%d.%d",G,S,K);
    }
};
 
Money Add(Money A, Money B){
    int g, s, k;
    g = A.G + B.G;
    s = A.S + B.S;
    k = A.K + B.K;
    s += k/29;
    g += s/17;
    k %= 29;
    s %= 17;
    return Money(g,s,k);
}
 
int main(){
    Money A, B;
    scanf("%d.%d.%d %d.%d.%d",&A.G,&A.S,&A.K,&B.G,&B.S,&B.K);
    Add(A,B).print();
    return 0;
}
//
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<memory>
using namespace std;
 
int atoi_nk(int *dat,char *str){
    int temp=0;
    int i=0;
    for(int j=0;j<3;++j){
    while(str[i]){
        if(str[i]>='0'&&str[i]<='9')  temp=temp*10+str[i++]-'0';
        else if(str[i]=='.') {i++;break;}
        else
                break;
    }
    dat[j]=temp;
    temp=0;
    }
    return i;
}
void core_sum(int *a,int *b,int length){
    int *temp=new int[length];
    int next=0;
    for(int i=length-1;i>=0;--i){
        if(2==i) {temp[2]=(a[2]+b[2])%29;next=(a[2]+b[2])/29;}
        else if(1==i) {temp[1]=(a[1]+b[1]+next)%17;next=(a[1]+b[1]+next)/17;}
        else if(0==i) {temp[0]=(a[0]+b[0]+next)%100000000;next=(a[0]+b[0]+next)/100000000;}
        else
            break;
    }
    printf("%d.%d.%d\n",temp[0],temp[1],temp[2]);
    delete[] temp;
    return ;
}
int main(){
int  dataA[3],dataB[3];
char s[30];
memset(s,0,30);
memset(dataA,0,12);
memset(dataB,0,12);
scanf("%s",s);
atoi_nk(dataA,s);
memset(s,0,30);
scanf("%s",s);
atoi_nk(dataB,s);
core_sum(dataA,dataB,3);
return 0;
}
