/*¸çµÂ°ÍºÕ²ÂÏë*/
#include <iostream>
#include<math.h>
using namespace std;
bool isPrime(int i){
    if(i<=1) return false;
     else if(i==2) return true;
    else{
        for(int p=2;p<(int)(sqrt((double)i))+1;++p){
            if(i%p==0) return false;
        }
        return true;
    }
}
int main()
{
    for(int n=4;n<=2000;n+=2){
        for(int i=2;i<n;++i){
            if(isPrime(i)){
                if(isPrime(n-i)){
                    cout<<n<<" = "<<i<<" + "<<n-i<<endl;
                    break;
                }
            }
            if(i==n){
                cout<<"error"<<endl;
            }
        }
    }
    return 0;
}
