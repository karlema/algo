#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include<string>
using namespace std;
int main()
{
	int a[4];
	int q, w;
	int result=0;
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + 3);
	/*for (int i = 0; i < 3; i++)
	{
		printf("%d ",a[i]);
	}*/
	q = a[2] - a[1];
	w = a[1] - a[0];
	if (q == w)
	{
		a[3] = a[2]+q;
	}
	else if (q > w)
	{
		a[3] = a[2] - w;
	}
	else
	{
		a[3] = a[1] - q;
	}
	printf("%d",a[3]);
	return 0;
}
