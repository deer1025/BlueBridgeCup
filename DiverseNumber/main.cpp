#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
/*�������4�����֣���ÿһλ�������أ�
������ظ������²���*/
bool pick[10];//���ر�־
int main(){
	srand((unsigned)time(NULL));
	int a=rand()%9+1;
	pick[a]=true;
	cout<<a;
	int cnt=4;
	while(cnt--){
		a=rand()%9;
		if(!pick[a]){
			pick[a]=true;
			cout<<a;
		}
	}
	return 0;
}
/*package example;
//ѡ��������С����
����һ������array{0,1,2,3,4,5,6,7,8,9}����Random(array.length)����ѡ���±�i��
��ȡarray[i]����һλ���Ƴ�array[i];
����Random(array.length-1)ѡ���±�i����ȡarray[i]���ڶ�λ���Ƴ�array[i]�������ơ�
ʱ�临�Ӷ�Ϊ T(n) = O(4)
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
public class disperserNumber {
    public static void main(String[] args) {

        Random rand=new Random();
        List<Integer> set=new ArrayList<Integer>();
        for(int i=0;i<10;i++){set.add(new Integer(i));}

        int multiple=1;
        int result=0;

        for(int i=0;i<4;i++){

            Integer in= set.get(rand.nextInt(9-i));
            set.remove(in);
            result+=in*multiple;
            multiple*=10;
            if(i==2){set.remove(new Integer(0));}
        }
        System.out.println(result);
    }
}
*/
