#include <iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    long sum = pow(n,n+1)-(n-1)*m;
    cout<<sum<<endl;
    return 0;
}
