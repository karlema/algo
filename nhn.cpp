#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
char result[30];
void one_left_rotate(char arr[],int end)
{
	
	printf("한번수행\n");
	char first = arr[0];
	printf("%d",end);
	for (int i = 0; i < end-1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[end-1] = first;
	for (int i = 0; i < end; i++)
	{
		printf("%c", arr[i]);
	}
}
void many_left_rotate(char arr[], int end,int k)
{

	printf("여러번 왼쪽 로테이트\n");
	char temp[30] = { 0, };
	for (int i = 0; i < end; i++)
	{
		temp[i] = arr[i];
	}
	for (int i = 0; i < end; i++)
	{
		printf("%c", temp[i]);
	}
	printf("3개쉬프트\n");
	for (int i = 0; i < end - k; i++)
	{
		arr[i] = arr[i + k];
	}
	for (int i = 0; i < end; i++)
	{
		printf("%c", arr[i]);
	}
	printf("결과값\n");
	for (int i = end - k; i <end ; i++)
	{
		arr[i] = temp[i-end+k];
	}

	//printf("%d", end);
	for (int i = 0; i < end; i++)
	{
		result[i] = arr[i];
		printf("%c", arr[i]);
	}
}
void many_right_rotate(char arr[], int end, int k)
{

	printf("여러번 오른쪽 로테이트\n");
	char temp[30] = { 0, };
	for (int i = 0; i < end; i++)
	{
		temp[i] = arr[i];
	}
	for (int i = 0; i < end; i++)
	{
		printf("%c", temp[i]);
	}
	printf("3개쉬프트\n");
	for (int i =0; i < end-k; i++)
	{
		arr[i+k] = temp[i];
		printf("%d %d\n",i+k,i);
	}
	for (int i = 0; i < end; i++)
	{
		printf("%c", arr[i]);
	}
	printf("결과값\n");
	for (int i = 0; i <k; i++)
	{
		arr[i] = temp[end - k+i];
	}

	//printf("%d", end);
	for (int i = 0; i < end; i++)
	{
		result[i] = arr[i];
		printf("%c", arr[i]);
	}
}
int main()
{
	char iden[10];
	scanf("%s", iden);
	char secret[30];
	char secal[30];
	char encal[30];
	int rotate=0;
	char message[30];
	scanf("%s", secret);
	scanf("%d",&rotate);
	scanf("%s", message);
	//one_left_rotate(secret, strlen(secret));
	if (!strcmp(iden, "encrypt"))
	{
		printf("엔크립션\n");
		printf("시크릿코드\n");
		//
		for (int i = 0; i < strlen(secret); i++)
		{
			secal[i] = (secret[i] - 'a' + message[i] - 'a') % 26;
			printf("%d ", secal[i]);
		}

		printf("\n메세지\n");
		for (int i = 0; i < strlen(secret); i++)
		{
			printf("%d ", message[i]);
			encal[i] = (secal[i])+'a';
		}
		printf("\n마지막엔크립션\n");
		for (int i = 0; i < strlen(secret); i++)
		{
			
			printf("%c ", encal[i]);
		}
		if (rotate > 0)
		{
			many_left_rotate(encal, strlen(secret), rotate);
		}
		else
		{
			many_right_rotate(encal, strlen(secret), rotate);
		}
	}
	
	else if (!strcmp(iden, "decrypt"))
	{
		printf("디크립션");
		if (rotate > 0)
		{
			many_right_rotate(message, strlen(message), rotate);
		}
		else
		{
			many_left_rotate(message, strlen(message), rotate);
		}
		printf("시크릿코드\n");
		//
		for (int i = 0; i < strlen(secret); i++)
		{
			secal[i] = ( (result[i] - 'a')- (secret[i] - 'a') ) % 26;
			printf("%d ", secal[i]);
			if (secal[i] < 0)
			{
				secal[i] = secal[i] + 26;
			}
		}

		printf("\n메세지\n");
		for (int i = 0; i < strlen(secret); i++)
		{
			printf("%d ", result[i]);
			encal[i] = (secal[i]) + 'a';
		}
		printf("\n마지막엔크립션\n");
		for (int i = 0; i < strlen(secret); i++)
		{

			printf("%c ", encal[i]);
		}
		
	}
	else
	{
		printf("오류입니다");
	}
	
	return 0;
}