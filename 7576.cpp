#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <stdio.h>
#include <queue>
#include<iostream>
using namespace std;

bool visit[1001][1001] = { 0, };
int y, x;
int cnt;
int inx[4] = { 0,0,1,-1 }, iny[4] = { 1,-1,0,0 };
int map[1001][1001] = { 0, };
int ay, ax;
int findi = 0;
int t;
int main()
{
	int t = 0;
	scanf("%d %d", &x, &y);
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j]==1)
			{
				findi = 0;
			}
		}
	}
	queue <pair<int, int>> q;


	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (map[i][j] ==1)
			{
				//printf("값%d %d\n",i,j);
				pair <int, int> p = make_pair(i, j);
				q.push(p);
				visit[p.first][p.second] = 1;
			}
		}
	}

	while (!q.empty())
	{
		int size;
		size = q.size();
		cnt++;
		for (int i = 0; i < size; i++)
		{

			pair <int, int> a = q.front();
			q.pop();
			//printf("\n");

			for (int i = 0; i < 4; i++)
			{

				ay = a.first + iny[i];
				ax = a.second + inx[i];

				if (ay >= y || ax >= x || ay < 0 || ax < 0)
				{
					continue;
				}

				if (ay < y && ax < x && ay >= 0 && ax >= 0 && !visit[ay][ax] && !map[ay][ax])
				{
					map[ay][ax] = cnt;
					visit[ay][ax] = 1;
					q.push(make_pair(ay, ax));

					if (cnt > findi)
					{
						findi = cnt;
					}
					//printf("%d %d %d\n", ay, ax, map[ay][ax]);
				}
			}

		}

	}

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (map[i][j] == 0)
			{
				findi = -1;

			}
			//printf("%d ", map[i][j]);
		}
		//printf("\n");
	}
	printf("%d\n", findi);

	return 0;
}

//주의점 : 1. 조건문에 !기호쓰면 1이아니라 -1 일때도 조건을 만족한다.
//         2. 큐에 넣을때 함수형식으로 집어넣으면 1이 여러군데있을경우 동시에 익어야하는데 한군데만 익는다.