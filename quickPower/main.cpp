#include <iostream>
using namespace std;
//快速乘法
long long quickMultiply(long long a,long long b,long long MOD){
    long long sum = 0;
    while(b){
        if(b&1){
            sum = (sum%MOD+a%MOD)%MOD;
        }
        a = (a%MOD*2)%MOD;
        b/=2;
    }
    return sum;
}

//快速幂
long long quickPower(long long base,long long power,long long MOD){
    long long ans=1;
    while(power){
        if(power&1){
            ans=quickMultiply(ans,base,MOD);
        }
        base=quickMultiply(base,base,MOD);
        power/=2;
    }
    return ans;
}

int main()
{
    cout << quickPower(10,9,100000000000) << endl;
    return 0;
}
