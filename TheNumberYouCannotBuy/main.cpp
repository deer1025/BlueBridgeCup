#include<iostream>
using namespace std;
int x,y;//记录贝祖等式的解
int Egcd(int m,int n){
    if(n==0){
        x=1;
        y=0;
        return m;
    }
    int d=Egcd(n,m%n);
    int x1=x;
    x=y;
    y=x1-m/n*y;
    return d;
}
bool beizuEquation(int a,int b,int sum){//利用拓展欧几里得算法求出贝祖等式的解，如果都是整数就返回true
    int gcd=Egcd(a,b);//用拓展欧几里得算法求出最大公因数
    if(sum%gcd){
        return false;
    }
    x*=sum/gcd;
    y*=sum/gcd;
    //求出最小的正整数x
    x=(x%b+b)%b;
    y=(sum-a*x)/b;
    if(x>=0&&y>=0) return true;
    return false;
    /*这样也可以
	求最小的正整数y
    y=(y%a+a)%a;
    x=(sum-b*y)/a;
    if(x>=0&&y>=0) return true;
    return false;*/
}
int main(){
    int a,b;
    cin>>a>>b;
    //由于如果a、b互质，那么他们最小公倍数为a*b，故从a*b开始判断
    for(int i=a*b;i>=1;--i){
        if(beizuEquation(a,b,i)==false){
            cout<<i;
            break;
        }
    }
    return 0;
}
