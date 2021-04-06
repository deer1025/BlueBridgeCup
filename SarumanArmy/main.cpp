#include <iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,R;
int a[1001];
int countOfMark(){
    int ans=0,i=0;
    sort(a,a+n);
    while(i<n){
        int notTag=a[i++];
        while(notTag+R>=a[i]&&i<n){
            i++;
        }
        int yesTag=a[i-1];
        while(yesTag+R>=a[i]&&i<n){
            i++;
        }
        ans++;
    }
    return ans;
}
int main()
{
    while(scanf("%d %d",&R,&n)==2){
        if(n==-1&&R==-1){
            break;
        }
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        cout << countOfMark() << endl;
    }
    return 0;
}
