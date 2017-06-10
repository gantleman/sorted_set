// testsortset.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "sorted_set.h"

int _tmain(int argc, _TCHAR* argv[])
{
	SortedSet<int> sortedSetview;

	for (int i = 0; i< 20; i++)
	{
		sortedSetview.zadd(i, rand()%10);
	}
	sortedSetview.zprint();

	printf("///////////////////////////\n");

	for (int i = 0; i< 10; i++)
	{
		int r = rand()%10;

		if (r%2 == 1)
			sortedSetview.zincrby(5, -r);
		else
			sortedSetview.zincrby(5, r);

		sortedSetview.zprint();

		unsigned long rank=0;

		sortedSetview.zrank(5, rank);

		printf("%d///////////////////////////\n", rank);
	}

	SortedSet<int> sortedSet;

	for (int i = 0; i< 10; i++)
	{
		sortedSet.zadd(i, rand()%10);
	}

	sortedSet.zprint();
	printf("///////////////////////////\n");

	for (int i = 0; i< 10; i++)
	{
		unsigned long rank=0;
		sortedSet.zrank(i, rank);
		printf( "name %d rank %d\n",i, rank);
	}

	printf("///////////////////////////\n");

	SortedSet<int> sortedSetspeed;
	for (int i = 0; i < 10000; i++)
	{
		sortedSetspeed.zadd(i, rand() % 100);
	}

	clock_t start = clock();
	for (int i = 0; i< 10000; i++)
	{
		int r = rand()%10;
		if (r%2 == 0)
			sortedSetspeed.zincrby(50, -r);
		else
			sortedSetspeed.zincrby(50, r);
	}
	clock_t finish = clock();

	double duration = (double)(finish - start) / CLOCKS_PER_SEC;

	unsigned long rank;
	sortedSetspeed.zrank(50, rank);

	printf( "%f seconds, %d\n", duration, rank);

	system("pause");
	return 0;
}

