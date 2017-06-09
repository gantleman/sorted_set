// testsortset.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "sorted_set.h"

int _tmain(int argc, _TCHAR* argv[])
{
	SortedSet<int> sortedSetview;

	for (int i = 0; i< 20; i++)
	{
		sortedSetview.zadd(i, rand()%100);
	}
	sortedSetview.zprint();

	for (int i = 0; i< 100; i++)
	{
		int r = rand()%10;

		if (r%2 == 0)
			sortedSetview.zincrby(5, -r);
		else
			sortedSetview.zincrby(5, r);

		sortedSetview.zprint();
	}



	SortedSet<int> sortedSet;

	for (int i = 0; i< 10000; i++)
	{
		sortedSet.zadd(i, rand()%100);
	}

	for (int i = 0; i< 100; i++)
	{
		unsigned long rank=0;
		sortedSet.zrank(i, rank);
		printf( "name %d rank %d\n",i, rank);
	}

	clock_t start = clock();
	for (int i = 0; i< 10000; i++)
	{
		int r = rand()%10;

		if (r%2 == 0)
			sortedSet.zincrby(5, -r);
		else
			sortedSet.zincrby(5, r);
		
		unsigned long rank=0;
		sortedSet.zrank(5, rank);

		printf( "rank %d\n", rank);
	}
	clock_t finish = clock();

	double duration = (double)(finish - start) / CLOCKS_PER_SEC;

	unsigned long rank;
	sortedSet.zrank(5, rank);

	printf( "%f seconds, %d\n", duration, rank);

	system("pause");
	return 0;
}

