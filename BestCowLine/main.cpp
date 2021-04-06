#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int n;
char s[2001];
string str="";
int compare(char *str,int b,int e){
    int left=b,right=e;
    while(left<=right){
        if(str[left]<str[right]) return 1;
        else if(str[left]>str[right]) return -1;
        left++;
        right--;
    }
    return 0;
}
void dfs(int a,int b){
    int t=n;
    while(t--){
        if(compare(s,a,b)==1){
           putchar(s[a++]);
           char i;
           i=getchar()==scanf("%c",&i);
           putchar(i)==printf("%c",i);
        }
        else{
            putchar(s[b--]);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>s[i];//s
    }
    dfs(0,n-1);
    return 0;
}

