#include<stdio.h>
using namespace std;
#define mod 9973

struct Node  //��fib��
{
	int right;
	int left;
	Node(int a, int b) { left = a, right = b; }
	Node() {}
};

Node fib(int n1, int n2)
{
	if (n1 == 1)  //�ݹ��
		return Node(1, 1);
	int m1;
	Node temp;
	int left, right; 
	if (n1 % 2 == 1)  //����nΪ�����ĵݹ�
	{
		m1 = n1 / 2;
		temp = fib(m1, m1 + 1);
		left = temp.left*temp.left + temp.right*temp.right;
		right = temp.right*(temp.left * 2 + temp.right);
		left %= mod;
		right %= mod;
		return Node(left, right);
	}
	else
	{
		m1 = n1 / 2;  //����nΪż���ĵݹ�
		temp = fib(m1, m1 + 1);
		left = temp.left*(2 * temp.right - temp.left);
		right = temp.left*temp.left + temp.right*temp.right;
		left %= mod;
		right %= mod;
		return Node(left, right);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int c;
	int* input = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &(input[i]));
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", fib(input[i], input[i + 1] + 1).left);
}