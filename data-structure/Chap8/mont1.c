#include "math.h"
#include "stdlib.h"

/*======================================================
// ��������mont1
// �������������ؿ��޷���һԪ����
// ���������a �������ޣ�b ��������,
//           f ָ�򱻻�������ָ��
// ����ֵ��  ���ֽ���ֵ
=========================================================*/
double mont1(a, b, f)

double a, b;

double (*f)();

{
int k, n;
double z, p, x;
unsigned long r;            /* ���������*/
n = 5000;                  /* ����5000�������*/
z = 0.0;
for(
k = 0;
k<n;
k++)
{
r = rand();               /* ���������*/
p = (double) r / RAND_MAX;
x = a + (b - a) * p;
z = z + (*f)(x) / n;          /* ���*/
}
z = z * (b - a);
return(z);
}
