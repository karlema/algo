#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
void one_left_rotate(char arr[],int end)
{
	
	printf("�ѹ�����\n");
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

	printf("������ ���� ������Ʈ\n");
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
		printf("��ũ����\n");
		printf("��ũ���ڵ�\n");
		//
		for (int i = 0; i < strlen(secret); i++)
		{
			secal[i] = secret[i] - 97;
			printf("%d ", secal[i]);
		}

		printf("\n�޼���\n");
		for (int i = 0; i < strlen(secret); i++)
		{
			
			printf("%d ", message[i]);
			encal[i] = secal[i] + message[i];
		}
		printf("\n��������ũ����\n");
		for (int i = 0; i < strlen(secret); i++)
		{
			
			printf("%c ", encal[i]);
		}
	
	}
	
	else if (!strcmp(iden, "decrypt"))
	{
		printf("��ũ����");
	}
	else
	{
		printf("�����Դϴ�");
	}
	
	return 0;
}