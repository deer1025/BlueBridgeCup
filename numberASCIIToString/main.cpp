#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char str[31],end[20]={"End of file"};
	int a,b,c,d,num;
	while(~(num=scanf("%d.%d.%d.%d",&a,&b,&c,&d))){
		gets(str);
		if(strcmp(str,end)==0){
			return 0;
		}
		else if(str[0]!='\0'){
			cout<<'N'<<endl;
			continue;
		}
		if(num==4&&a>=0&&a<=255&&b>=0&&b<=255&&c>=0&&c<=255&&d>=0&&d<=255){
			cout<<'Y'<<endl;
		}
		else{
            cout<<'N'<<endl;
		}
		fflush(stdin);//Çå¿ÕÊäÈëÁ÷
	}
	return 0;
}
