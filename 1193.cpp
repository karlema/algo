#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int input, n = 1, cnt = 0, a = 1, b = 1;
	scanf("%d",&input);
	while (1)
	{
		//printf("������ : %d\n",n);
		if (n % 2 == 0)
			a = 1, b = n;
		else
			a = n, b = 1;
		printf("�ʱ� : %d/%d\n", a, b);
		for (int i = 0; i < n; i++)
		{
			
			if (++cnt == input)
			{
				printf("%d/%d\n",a,b);
				return 0;
			}
			if (n % 2 == 0) ++a, --b;
			else --a, ++b;
			printf("���� : %d/%d\n", a, b);
			//printf("cnt�� : %d\n", cnt);
		}
		
		n++;
	}
	return 0;
}