#include<iostream>
#include<algorithm>
using namespace std;
int sum=0;
int N;
typedef struct zhu{
	int value;
	zhu* next;
}Lnode,*Linklist;
void creatLink(Linklist& L,int n){
	Linklist head,p;
	L=(Linklist)malloc(sizeof(Lnode));//带头结点的链表
	if(L==NULL){
		return ;
	}
	L->next=L;//构成循环链表
	head=L;//尾结点指向头结点，即无数值的结点

	for(int i=0;i<N;++i){
		p=(Linklist)malloc(sizeof(Lnode));//生成新节点
		if(p==NULL){
			return ;
		}
		cin>>p->value;
		p->next=L;
		head->next=p;//尾插法插入新节点
		head=p;
	}
}
void printLink(Linklist& L){
    Linklist p;
    p=L->next;
    int i=0;
    while(i<8){
        cout<<p->value;
        p=p->next;
        if(p==L){
            p=p->next;
        }
        i++;
    }
}
void dfs(Linklist& L,int n){
	Linklist s,MAX,q;
	while(L->next){
        s=L;
        int max_=s->next->value;
		while(s->next!=L){
			if(max_>s->value){
				max_=s->value;
				MAX=s;
			}
			s=s->next;
		}
		sum+=(MAX->value*(MAX->next->value)*(MAX->next->next->value));
		q=MAX->next;
		MAX->next=q->next;
		free(q);
	}
}
int main(){
	cin>>N;
	Linklist L;
	creatLink(L,N);
	printLink(L);
	dfs(L,N);
	cout<<sum<<endl;
	return 0;
}
