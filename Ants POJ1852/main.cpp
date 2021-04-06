#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--){
        int L,n,x[1000001];
        cin>>L>>n;
        int Min=0,Max=0;
        for(int i=0;i<n;++i){
            cin>>x[i];
            Min=max(Min,min(x[i],L-x[i]));
            Max=max(Max,max(x[i],L-x[i]));
        }
        cout<<Min<<" "<<Max<<endl;
    }
    return 0;
}
