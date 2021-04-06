#include <iostream>
#include<math.h>
using namespace std;
int main()
{
    bool flag=true;
    for(int n=1004;flag;n+=5){
        for(int x=n,i=1;i<=5&&flag;++i){
            if((x+1)%5==0){
                x=(x+1)*4/5;
            }
            else{
                flag=false;
            }
        }
        if(flag) {
            cout<<n;
            break;
        }
        else{
            flag=true;
        }
    }
    return 0;
}
/*short sum=pow(5,5)-4*4;
    cout<<sum;*/
