#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
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
	for (int i = 0; i < strlen(temp); i++)
	{
		temp[i] = arr[i];
	}
	for (int i = 0; i < end - 1; i++)
	{
		arr[i] = arr[i + k];
	}
	for (int i = k-1; i < end - 1; i++)
	{

	}
	printf("%d", end);
	for (int i = 0; i < end - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	for (int i = 0; i < end; i++)
	{
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
			secal[i] = secret[i] - 97;
			printf("%d ", secal[i]);
		}

		printf("\n메세지\n");
		for (int i = 0; i < strlen(secret); i++)
		{
			
			printf("%d ", message[i]);
			encal[i] = secal[i] + message[i];
		}
		printf("\n마지막엔크립션\n");
		for (int i = 0; i < strlen(secret); i++)
		{
			
			printf("%c ", encal[i]);
		}
	
	}
	
	else if (!strcmp(iden, "decrypt"))
	{
		printf("디크립션");
	}
	else
	{
		printf("오류입니다");
	}
	
	return 0;
}