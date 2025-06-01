#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define SIZE 100
int UFSets[SIZE]; //集合元素数组

void Initial(int S[])
{
	for (int i = 0; i < SIZE; i++)
		S[i] = -1;
}
int Find(int S[], int x)
{
	int root = x;
	while (S[root] >= 0) root = S[root]; //循环找到根
	while (x != root) //x不为根结点，则压缩路径
	{
		int t = S[x]; //t指向x的父节点
		S[x] = root; //x直接挂到根结点下
		x = t;
	}
	return root; //返回根节点编号
}
void Union(int S[], int x1, int x2)
//每个根结点不再用-1表示，用根结点的绝对值表示树的结点总数
{
	int Root1 = Find(S, x1);
	int Root2 = Find(S, x2);
	//要求Root1与Root2是不同的，且表示子集合的名字
	if (Root1 == Root2) return;
	if (S[Root2] > S[Root1]) //Root2结点数更少
	{
		S[Root1] += S[Root2];
		S[Root2] = Root1; //小树合并到大树，即Root2指向Root1
	}
	else
	{
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
}