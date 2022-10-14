
#include<bits/stdc++.h>
#define MAX 100
using namespace std;

void fillSpiral(int mat[][MAX], int m, int n, int temp[])
{
	int i, k = 0, l = 0;

	int tIdx = 0;
	while (k < m && l < n)
	{
		for (int i = l; i < n; ++i)
			mat[k][i] = temp[tIdx++];
		k++;

		for (int i = k; i < m; ++i)
			mat[i][n-1] = temp[tIdx++];
		n--;

		if (k < m)
		{
			for (int i = n-1; i >= l; --i)
				mat[m-1][i] = temp[tIdx++];
			m--;
		}

		if (l < n)
		{
			for (int i = m-1; i >= k; --i)
				mat[i][l] = temp[tIdx++];
			l++;
		}
	}
}

void spiralRotate(int mat[][MAX], int M, int N, int k)
{

	int temp[M*N];

	int m = M, n = N, s = 0, l = 0;

	int *start = temp; 
	int tIdx = 0; 
	while (s < m && l < n)
	{
		int *end = start;

		for (int i = l; i < n; ++i)
		{
			temp[tIdx++] = mat[s][i];
			end++;
		}
		s++;

		for (int i = s; i < m; ++i)
		{
			temp[tIdx++] = mat[i][n-1];
			end++;
		}
		n--;
		if (s < m)
		{
			for (int i = n-1; i >= l; --i)
			{
				temp[tIdx++] = mat[m-1][i];
				end++;
			}
			m--;
		}

		if (l < n)
		{
			for (int i = m-1; i >= s; --i)
			{
				temp[tIdx++] = mat[i][l];
				end++;
			}
			l++;
		}

		if (end-start > k)
		{

			reverse(start, start+k);
			reverse(start+k, end);
			reverse(start, end);

			start = end;
		}
	}

	fillSpiral(mat, M, N, temp);
}

int main()
{

	int M = 4, N = 4, k = 3;
	int mat[][MAX]= {{1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12},
					{13, 14, 15, 16} };

	spiralRotate(mat, M, N, k);

	for (int i=0; i<M; i++)
	{
		for (int j=0; j<N; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	return 0;
}
