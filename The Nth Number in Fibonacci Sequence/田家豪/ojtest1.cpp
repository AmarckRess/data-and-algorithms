#include"stdio.h"

int main()
{
	int n;
	scanf("%d",&n);
	int *num=new int [n];	
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);
	for(int i=0;i<n;i++)
	{
		int Fk1=0,Fk2=1;
		if(num[i]==0)num[i];
		else
		{
			for(int k=0;k<num[i]%19948-1;k++)			//쳲���������ģ9973����������
			{
				int temp;
				temp=Fk2;
				Fk2=Fk1+Fk2;
				Fk1=temp;
				Fk2=Fk2%9973;							//���������е���ģ9973������ģ�����ʣ�
														//ȡ��������Ӻ���Ӻ���ȡ�����
			}
		    num[i]=Fk2;
		}
	}

	for(int i=0;i<n;i++)								//һ�����������������
		printf("%d\n",num[i]);

	return 0;
}