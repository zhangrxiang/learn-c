/*=============================================================
// �� �� ����popo
// ����������ð������
// ��������� x ��Ŵ��������ݵ�����
//            n ���鳤��
// �� �� ֵ����
//==============================================================*/
void popo(x, n)

int *x;
int n;
{
int head, tail, i, j, t, flag;
head = 0;
tail = n - 1;
flag = 1;
while((head<tail)&&(flag==1))
{
flag = 0;
j = tail;
for(
i = head;
i<j;
i++)             /* ��ͷ���ɨ��*/
if(x[i]>x[i+1])
{
t = x[i];
x[i] = x[i+1];
x[i+1] =
t;
tail = i;                  /* ��ǰ�����������ֵλ��*/
flag = 1;                  /* ���н�������˵����δ��ȫ����*/
}
j = head;
for(
i = tail;
i>
j;
i--)          /* �Ӻ���ͷɨ��*/
if(x[i-1]>x[i])
{
t = x[i];
x[i] = x[i-1];
x[i-1] =
t;
head = i;                  /* ����������Сֵλ��*/
flag = 1;                  /* ���н�������˵����δ��ȫ����*/
}
}
return;
}
