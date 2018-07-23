#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>

using namespace std;

int main()
{
	int T;
	long long int K, N, V, lastA, firstA, k;
	int i, j;
	string attractions[60];

	scanf("%d", &T);
	for(i=1; i<=T; i++)
	{
		//input
		scanf("%lld %lld %lld", &N, &K, &V);
		getchar();
		for(j=1; j<=N; j++)
		{
			getline(cin,attractions[j]);
		}

		//solution
		lastA = (V * K) % N;
		if(lastA == 0)
			lastA += N;
		firstA = lastA - K + 1;
		if(firstA <= 0)
			firstA += N;
		
		//answer
		printf("Case #%d:",i);
		if(firstA > lastA)
		{
			for(k = 1; k <= lastA; k++)
			{
				printf(" ");
				cout << attractions[k];
			}
			for(k = firstA; k <= N; k++)
			{
				printf(" ");
				cout << attractions[k];
			}
			printf("\n");
		}
		else
		{
			for(k = firstA; k <= lastA; k++)
			{
				printf(" ");
				cout << attractions[k];
			}
			printf("\n");
		}
	}

	return 0;
}