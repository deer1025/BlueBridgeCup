#include<iostream>
using namespace std;
int x,y;//��¼�����ʽ�Ľ�
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
bool beizuEquation(int a,int b,int sum){//������չŷ������㷨��������ʽ�Ľ⣬������������ͷ���true
    int gcd=Egcd(a,b);//����չŷ������㷨����������
    if(sum%gcd){
        return false;
    }
    x*=sum/gcd;
    y*=sum/gcd;
    //�����С��������x
    x=(x%b+b)%b;
    y=(sum-a*x)/b;
    if(x>=0&&y>=0) return true;
    return false;
    /*����Ҳ����
	����С��������y
    y=(y%a+a)%a;
    x=(sum-b*y)/a;
    if(x>=0&&y>=0) return true;
    return false;*/
}
int main(){
    int a,b;
    cin>>a>>b;
    //�������a��b���ʣ���ô������С������Ϊa*b���ʴ�a*b��ʼ�ж�
    for(int i=a*b;i>=1;--i){
        if(beizuEquation(a,b,i)==false){
            cout<<i;
            break;
        }
    }
    return 0;
}
