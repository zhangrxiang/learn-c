/*=============================================================
// �� �� ����bist
// �������������ֲ���
// ��������� x ����������е�����
//            n ���鳤��
//            a �����ҵ�Ԫ��
// �� �� ֵ��������Ԫ�ص�λ�ã�����Ԫ�ز����ڣ��򷵻�-1
//==============================================================*/
int bist(x, n, a)

int *x, a;
int n;
{
int s, t, k;
s = 0;                             /* ���ó�ֵ*/
t = n - 1;
do{
if(t==s)                      /* ֻ��һ��Ԫ��*/
{
if(x[t] == a)
return(t);
else
return(-1);
}
k = (s + t) / 2;                  /* ����*/
if(x[k] < a)                  /* �Ƚ�*/
s = k;
else if(x[k] > a)
t = k;
else
return(k);                 /* �Ѿ��ҵ�*/
}while(1);
}
