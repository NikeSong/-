#include <stdio.h>
int hebing(int a,int b)
{
int c=10*(b%10)+(a/10)+1000*(b/10)+100*(a%10);
return c;
}
int main() {
int a;
int b;
printf("请输入第一个两du位数a:");
scanf("%d",&a);
printf("请输入第二个两位数b:");
scanf("%d",&b);

int c=hebing(a,b);
printf("结果为:%d",c);
return 0；
}
通过引用参数将新数传给主函数
#include <stdio.h>
int hebing(int *a,int *b){
int c=10*(*b%10)+(*a/10)+1000*(*b/10)+100*(*a%10);
return c;
}
int main() {
int *a;
int *b;
int c;
printf("请输入第一个两du位数a:");
scanf("%d",&a);
printf("请输入第二个两位数b:");
scanf("%d",&b);
c=hebing(*a,*b);
printf("结果为:%d",c);
return 0;
}