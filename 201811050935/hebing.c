#include <stdio.h>
int hebing(int a,int b)
{
int c=10*(b%10)+(a/10)+1000*(b/10)+100*(a%10);
return c;
}
int main() {
int a;
int b;
printf("�������һ����duλ��a:");
scanf("%d",&a);
printf("������ڶ�����λ��b:");
scanf("%d",&b);

int c=hebing(a,b);
printf("���Ϊ:%d",c);
return 0��
}
ͨ�����ò�������������������
#include <stdio.h>
int hebing(int *a,int *b){
int c=10*(*b%10)+(*a/10)+1000*(*b/10)+100*(*a%10);
return c;
}
int main() {
int *a;
int *b;
int c;
printf("�������һ����duλ��a:");
scanf("%d",&a);
printf("������ڶ�����λ��b:");
scanf("%d",&b);
c=hebing(*a,*b);
printf("���Ϊ:%d",c);
return 0;
}