#include<stdio.h>
#include<math.h>

float f(float x)
{
    //return (x-2.5)*(x+3)*(x-12);
	return sin(x);
}

main()
{
	float ex,ef,a,b,x,ksi,fx,fa;
	a=1;
	b=4;
	ex=1e-6;
	ef=1e-6;

    x=(a+b)/2;
    fx=f(x);
    fa=f(a);

    do  {
        if(fa*fx<0)
            b=x;
        else if
        (fa*fx>0){
            a=x; fa=fx;
        }
        else {
            break;
        }

        x=(a+b)/2;
        fx=f(x);
            }
        while((b-a)/2>ex && fabs(fx)>ef);

        ksi = x;-
        printf("%f\n",ksi);
}
