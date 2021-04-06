#include <iostream>
using namespace std;
//分解质因数
void disparate(int n){
    int yinzi[],cnt=0;
    while(n)
    for(int i=2;i<sqrt((double)n)+1;++i){
        if(n%i==0){
            yinzi[cnt++]=i;
            n/=i;
        }
    }

}
int x,y;
int Egcd(int a,int b){
    int gcd=Egcd(b,a%b);
    if(b==0){
        x=1;
        y=0;
        return a;
    }

    int x1=x;
    x=y;
    y=x1-a/b*y;

    if(m%gcd==0){
        x*=m/gcd;
        y*=m/gcd;
    }

}
int main()
{

    cout << "Hello world!" << endl;
    return 0;
}
