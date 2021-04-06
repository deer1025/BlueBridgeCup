#include <iostream>
using namespace std;
int x,y;
//GCD算法-欧几里得算法
int gcd(int m,int n){//求出m和n的最大公约数
    return n==0?m:gcd(n,m%n);
}
//拓展的欧几里得算法
int Egcd(int m,int n){//求出ax+by=gcd(m,n)的一组特解，并求出gcd(m,n)
    //递归出口
    if(n==0){
        //出口时的x和y的值
        x=1;
        y=0;
        return m;
    }
    //求出前一个状态的x和y
    int d=Egcd(n,m%n);
    //状态转移公式
    int x1=x;
    x=y;
    y=x1-m/n*y;
    return d;
}
//求解贝祖等式的一个特解
bool beizuEquation(int a,int b,int m){
    int gcd=Egcd(a,b);//求出ax+by=gcd(a,b)的解
    if(m%gcd){
        return false;
    }
    x*=m/gcd;
    y*=m/gcd;
    return true;
}
int main()
{
    if(beizuEquation(4,7,17))
        cout <<x<<" * 4 + 7 * "<<y<<" = 17"<< endl;
    return 0;
}
