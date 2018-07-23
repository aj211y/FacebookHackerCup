#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#define MAX 1050
#define MOD 1000000007
using namespace std;

int grid[3][MAX];
int choise[550];
int main()
{
	int T,N,ans,tmp;
	char c;
	bool possible;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		memset(grid, 0,sizeof(grid));
		possible=true;
		ans=1;
		scanf("%d",&N);
		for(int i=0;i<3;i++)
		{
			scanf("%c",&c);
			for(int n=0;n<N;n++)
			{
				scanf("%c", &c);
				if(c=='.')
				{
					grid[i][n]=0;
				}
				else if(c=='#')
				{
					grid[i][n]=1;
				}
			}
		}

		for(int i=0;i<550;i++)
		{
			choise[i]=2;
		}

		tmp=grid[0][0]+grid[1][0]+grid[1][N-1]+grid[2][N-1];
		if(tmp>0 || N%2==1)
		{
			possible=false;
		}
		else
		{
			tmp=0;
			for(int n=1;n<=N-3;n=n+2)
			{
				if((grid[1][n]+grid[1][n+1])>0)
				{
					possible=false;
					break;
				}
				if((grid[0][n]+grid[0][n+1])>0)
				{
					choise[tmp]--;
				}
				if((grid[2][n]+grid[2][n+1])>0)
				{
					choise[tmp]--;
				}
				if(choise[tmp]==0)
				{
					possible=false;
					break;
				}
				tmp++;
			}
		}

		//ans
		if(possible)
		{
			tmp=(N-2)/2;
			for(int i=0;i<tmp;i++)
				ans=(ans*choise[i])%MOD;
		}
		else
		{
			ans=0;
		}
		printf("Case #%d: %d\n",t, ans);
	}
	return 0;
}
