#include "math.h"
#include "simps1.c"

/*======================================================
// ��������simps2
// �����������䲽������������ػ���
// ���������a ����x����, b ����x����,
//           n0 ��ʼ������
//           eps ����Ҫ��
//           h0 x�������С����
//           f ָ�򱻻�������ָ��
//           fy ָ�����y���������޵ĺ�����ָ��
// ����ֵ��  ���ֽ���ֵ
=========================================================*/
double simps2(a, b, n0, eps, h0, f, fy)
double a, b, eps, h0;
int n0;

double (*f)();

void (*fy)();

{
int n, k;
double z, z2, s, s2, h, d, x, t1, t2;

double g();

n = n0;                            /* ��ʼ�Ļ�����*/
h = (b - a) / n;                       /* ��ó�ʼ����*/
t1 = g(a, n0, eps, f, fy);
t2 = g(b, n0, eps, f, fy);
z = (t1 + t2) / 2.0;                   /* �����ʼ�Ļ���ֵ*/
for(
k = 1;
k<n;
k++)
{
x = a + k * h;                        /* �۴����*/
t1 = g(x, n0, eps, f, fy);
z = z + t1;
}
z = z * h;                           /* �������ٳ˷�����*/
s = z;
do
{
z2 = 0.0;
for(
k = 0;
k<n;
k++)
{
x = a + (k + 0.5) * h;               /* �ۼӼ���*/
t1 = g(x, n0, eps, f, fy);
z2 = z2 + t1;
}
z2 = (z + h * z2) / 2.0;
s2 = (4.0 * z2 - z) / 3.0;             /* �����µĻ���ֵ*/
d = fabs(s2 - s);                  /* �������λ���ֵ�Ĳ�*/
z = z2;
s = s2;                          /* ���»���ֵ*/
h = h / 2.0;                       /* ���²���*/
n = 2 * n;                         /* ���»�����*/
}while((d>eps)&&(h>h0));
return(s);
}

static double g(t, n0, eps, f, fy)   /* �Ӻ������ڼ���һά����*/
double t, eps;
int n0;

double (*f)();

void (*fy)();

{
int n, k;
double y[2], a, b;                   /* ��Ż������޺�����*/
double z, z2, s, s2, h, d, x;
(*fy)(t,y);                        /* ����������*/
a = y[0];
b = y[1];
n = n0;                            /* ��ʼ�Ļ�����*/
h = (b - a) / n;                       /* ��ó�ʼ����*/
z = ((*f)(t, a) + (*f)(t, b)) / 2.0;     /* �����ʼ�Ļ���ֵ*/
for(
k = 1;
k<n;
k++)
{
x = a + k * h;
z = z + (*f)(t, x);                   /* �۴����*/
}
z = z * h;                           /* �������ٳ˷�����*/
s = z;
do
{
z2 = 0.0;
for(
k = 0;
k<n;
k++)
{
x = a + (k + 0.5) * h;               /* �ۼӼ���*/
z2 = z2 + (*f)(t, x);
}
z2 = (z + h * z2) / 2.0;
s2 = (4.0 * z2 - z) / 3.0;             /* �����µĻ���ֵ*/
d = fabs(s2 - s);                  /* �������λ���ֵ�Ĳ�*/
z = z2;
s = s2;                          /* ���»���ֵ*/
h = h / 2.0;                       /* ���²���*/
n = 2 * n;                         /* ���»�����*/
}while((d>eps)&&(n<1000));         /* �������������������޶�*/
return(s);
}
