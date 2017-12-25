/*=============================================================
// �� �� ����bsl3
// ���������������͵�һ�������ױ�����������ֵ
// ���������x �Ա���x��ֵ��
//           n �����������Ľ���
// �� �� ֵ�����͵�һ�������ױ�����������ֵ
//==============================================================*/
#include "math.h"
#include "stdio.h"

#define ENUMB 30.0                      /* �������ʱ��������������ݣ�Խ��������Ч����Խ��*/

double bsl3(n, x)

double x;
int n;
{
double t, I0(), I1();
int j, nn, flag;
double ax, nx, bj0, bj1, bj, bjs;
ax = fabs(x);
if(ax==0.0)
return(0.0);
if(n==0)
{
t = I0(ax);
return(t);
}
else if(n==1)
{
t = I1(ax);
return (x<0.0)?-
t: t;
}
else
{
nx = 2.0 / ax;                          /* ����2*n/x��Ҫ��ֵ2/x*/
nn = 2 * ((int) (n + sqrt(ENUMB * n)) / 2);   /* ��֤��ż��*/
bj1 = 0.0;                           /* ��nn+1����Ϊ0*/
bj0 = 1.0;                           /* ��nn����Ϊ1.0*/
for(
j = nn;
j>0; j--)
{
bj = j * nx * bj0 + bj1;                 /* ���Ƽ���*/
bj1 = bj0;
bj0 = bj;
if(j==n)
t = bj1;
if(
fabs(bj)
>1.0e10)                /* �ڵ��ƹ����н��й�һ������ֹ���*/
{
bj0 = bj0 * 1.0e-10;
bj1 = bj1 * 1.0e-10;
t = t * 1.0e-10;
}
}
bjs = I0(ax);
t = t * bjs / bj0;                          /*��һ�����ƽ��*/
return (x<0.0)&&(n&1)?-
t: t;            /* nΪ������xΪ��ʱ������-t*/
}
}

static double I0(x)                     /* ����I0(x)*/
double x;
{
double x1, x2, t;
x1 = fabs(x);
if(x1 < 3.75)                         /* �����ʽ�ƽ�*/
{
x2 = x1 * x1 / 14.0625;
t = 1.0 + x2 * (3.5156229 + x2 * (3.0899424 +
                                  x2 * (1.2067492 + x2 * (0.2659732 +
                                                          x2 * (0.0360768 + x2 * 0.0045813)))));
}
else                                  /* x>3.75�����*/
{
x2 = 3.75 / x1;
t = (0.39894228 + x2 * (0.01328592 +
                        x2 * (0.00225319 + x2 * (-0.00157565 +
                                                 x2 * (0.00916281 + x2 * (-0.02057706 +
                                                                          x2 * (0.02635537 + x2 * (-0.01647633 +
                                                                                                   x2 *
                                                                                                   0.00392377)))))))) *
    exp(x1) / sqrt(x1);
}
return
t;
}

static double I1(x)                           /* ����I1(x)*/
double x;
{
double x1, x2, t;
x1 = fabs(x);
if(x1 < 3.75)                               /* �����ʽ�ƽ�*/
{
x2 = x1 * x1 / 14.0625;
t = x1 * (0.5 + x2 * (0.87890594 + x2 * (0.51498869 +
                                         x2 * (0.15084934 + x2 * (0.02658733 +
                                                                  x2 * (0.00301532 + x2 * 0.32411e-3))))));
}
else                                        /* x>3.75�����*/
{
x2 = 3.75 / x1;
t = 0.02282967 + x2 * (-0.02895312 +
                       x2 * (0.01787654 - x2 * 0.00420059));
t = 0.39894228 + x2 * (-0.03988024 +
                       x2 * (-0.00362018 + x2 * (0.00163801 +
                                                 x2 * (-0.01031555 + x2 * t))));
t = t * exp(x1) / sqrt(x1);
}
return (x<0.0)?-
t: t;
}
