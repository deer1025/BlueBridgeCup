#include <iostream>
using namespace std;
int x,y;
//GCD�㷨-ŷ������㷨
int gcd(int m,int n){//���m��n�����Լ��
    return n==0?m:gcd(n,m%n);
}
//��չ��ŷ������㷨
int Egcd(int m,int n){//���ax+by=gcd(m,n)��һ���ؽ⣬�����gcd(m,n)
    //�ݹ����
    if(n==0){
        //����ʱ��x��y��ֵ
        x=1;
        y=0;
        return m;
    }
    //���ǰһ��״̬��x��y
    int d=Egcd(n,m%n);
    //״̬ת�ƹ�ʽ
    int x1=x;
    x=y;
    y=x1-m/n*y;
    return d;
}
//��ⱴ���ʽ��һ���ؽ�
bool beizuEquation(int a,int b,int m){
    int gcd=Egcd(a,b);//���ax+by=gcd(a,b)�Ľ�
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
