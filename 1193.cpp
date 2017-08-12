#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int input, n = 1, cnt = 0, a = 1, b = 1;
	scanf("%d",&input);
	while (1)
	{
		//printf("엔값은 : %d\n",n);
		if (n % 2 == 0)
			a = 1, b = n;
		else
			a = n, b = 1;
		printf("초기 : %d/%d\n", a, b);
		for (int i = 0; i < n; i++)
		{
			
			if (++cnt == input)
			{
				printf("%d/%d\n",a,b);
				return 0;
			}
			if (n % 2 == 0) ++a, --b;
			else --a, ++b;
			printf("연산 : %d/%d\n", a, b);
			//printf("cnt값 : %d\n", cnt);
		}
		
		n++;
	}
	return 0;
}