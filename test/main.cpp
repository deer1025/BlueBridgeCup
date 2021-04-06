#include<iostream>
#include<string.h>
using namespace std;
int main(){
	char s[10001];
	const char a[5]={'i','n','t','i','a'};
	int m;
	for(m=0;;++m){
		s[m]=getchar();
		if(s[m]=='\n'){
            break;
		}
	}
	int n=m,ans=0;
	if((s[0]=='p'||s[0]=='P')&&(s[6]==' '||s[6]==','||s[6]=='.'||n<=6)){
        bool flag=true;
            for(int j=0;j<5;++j){
                if(s[1+j]!=a[j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans++;
            }
	}
	for(int i=1;i<n;++i){
        if((s[i-1]==' '||s[i-1]==','||s[i-1]=='.')&&(s[i]=='p'||s[i]=='P')&&(s[i+6]==' '||s[i+6]==','||s[i+6]=='.'||i+6>=n)){
            bool flag=true;
            for(int j=0;j<5;++j){
                if(s[i+1+j]!=a[j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans++;
            }
        }
	}
	cout<<ans<<endl;
	if(ans==0){
        cout<<"wu gan";
	}
	else if(ans<=3){
        cout<<"you ai";
	}
	else{
        cout<<"zhen ai la";
	}
	return 0;
}
