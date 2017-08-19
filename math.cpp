2.一元二次方程求解
#include<stdio.h>
#include<math.h>
#define exp 0.0000001
int main()
{
	float a,b,c;
	 double x1=0;
	 double x2=0;

		printf("输入三个数:");
		scanf("%f %f %f",&a,&b,&c);
		
			
		if((b*b-4*a*c)>exp)
		{
			x1=(-b+(sqrt(b*b-4*a*c))/2*a);
			x2=(-b-(sqrt(b*b-4*a*c))/2*a);
			printf("x1=%lf,x2=%lf",x1,x2);
		}
		if(((b*b-4*a*c)<exp)&&((b*b-4*a*c)>-exp))
			x1=(-b+(sqrt(b*b-4*a*c))/2*a);
		printf("%lf",x1);
return 0;
}
