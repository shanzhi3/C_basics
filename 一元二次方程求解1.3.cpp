#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,x1,x2,t,p,q;
    scanf("%f %f %f",&a,&b,&c);
        t=sqrt(b*b-4*a*c);
        x1=(-b+t)/2/a;
        x2=(-b-t)/2/a;
    if((b*b-4*a*c)==0)
        printf("x1=x2=%0.5f",x1);
    if((b*b-4*a*c)>0)
    {
        if(a>0)
            printf("x1=%0.5f;x2=%0.5f",x1,x2);
        if(a<0)
            printf("x1=%0.5f;x2=%0.5f",x2,x1);
    }
    else if((b*b-4*a*c)<0)
        {
        t=sqrt(-(b*b-4*a*c));
        p=(-b)/2/a;
        if (p == 0)
            p = fabs(p);
        q=fabs(t/2/a);
             printf("x1=%0.5f+%0.5fi;x2=%0.5f-%0.5fi",p,q,p,q);
        }
}
     
