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
#define MAX 2020
using namespace std;

struct node
{
	int Left, Right;	
}list[MAX];
vector<int> pre, post;
int tree[MAX];

void preOrder(int root)
{
	int l,r;
	//root left right
	if(root)
	{
		l=list[root].Left;
		r=list[root].Right;
		pre.push_back(root);
		preOrder(l);
		preOrder(r);
	}
}
void postOrder(int root)
{
	int l,r;
	//left right root
	if(root)
	{
		l=list[root].Left;
		r=list[root].Right;
		postOrder(l);
		postOrder(r);
		post.push_back(root);
	}
}
void update(int preID, int postID)
{
	if(tree[preID] <= tree[postID])
	{
		if(postID != tree[postID])
			update(preID, tree[postID]);
		tree[postID]=tree[preID];
	}
	else
	{
		if(preID != tree[preID])
			update(tree[preID], postID);
		tree[preID]=tree[postID];
	}
}
int main()
{
	int T, N, K, group, k;
	int ans[MAX];
	bool possible;
	scanf("%d", &T);
	for(int t=1;t<=T;t++)
	{
		//input
		scanf("%d %d", &N, &K);
		for(int i=1;i<=N;i++)
		{
			scanf("%d %d", &list[i].Left, &list[i].Right);
		}
		//initialize
		pre.clear();
		post.clear();
		for(int i=1;i<=N;i++)
		{
			tree[i]=i;
			ans[i]=0;
		}
		possible=true;
		group=0;
		k=0;

		preOrder(1);
		postOrder(1);

		for(int i=0; i<N; i++)
		{
			update(pre[i], post[i]);
		}
		for(int id=1; id<=N; id++)
		{
			if(id == tree[id])
			{
				group++;
				ans[id]=(k%K)+1;
				k++;
			}
		}
		if(group<K)
			possible=false;
		else
		{
			for(int id=1; id<=N;id++)
			{
				if(!ans[id])
				{
					ans[id]=ans[tree[id]];
				}
			}
		}

		//ans
		printf("Case #%d: ", t);
		if(possible)
		{
			for(int id=1; id<=N; id++)
			{
				if(id!=1)
					printf(" ");
				printf("%d",ans[id]);
			}
			printf("\n");
		}
		else
		{
			printf("Impossible\n");
		}
	}
	return 0;
}