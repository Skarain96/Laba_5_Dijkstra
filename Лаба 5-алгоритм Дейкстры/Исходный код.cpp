#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

struct point
{
	float weight;
	bool isVisited = false;
};

int main()
{
	setlocale(LC_ALL, "");
	int n;
	float **m, min;
	int v1 = 1;
	int v2 = 1;
	cout << "Введите количество вершин: ";
	cin >> n;
	point *length = new point[n];
	m = new float*[n];
	for (int i = 0; i < n; i++)
	{
		m[i] = new float[n];
		for (int j = 0; j < n; j++)
		{
			cout << "Расстояние от " << i + 1 << " узла"<< " до " << j + 1 << " = ";
			length[i].isVisited = false;
			length[i].weight = -1; 
			cin >> m[i][j];
		}
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (m[i][j] <= 0)
			{
				m[i][j] = 0;
			}
			printf("%f  ", m[i][j]);
		}
			printf("\n");
	}
	
	length[0].weight = 0;
	for (int r = 0; r < n; r++)
	{
		int num = -1;
		float min = -1;
		for (int i = 0; i < n; i++)
		{
			if ((!length[i].isVisited) && (((length[i].weight < min) || (min == -1)) && (length[i].weight != -1)))
			{
				num = i;
				min = length[num].weight;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if ((m[num][i] != 0) && (!length[i].isVisited))
			{
				if ((length[num].weight + m[num][i] < length[i].weight) || (length[i].weight == -1))
				{
					length[i].weight = length[num].weight + m[num][i];
				}
			}

		}
		length[num].isVisited = true;
	}
	for (int r = 0; r < n; r++)
	{
		cout << length[r].weight << " ";
	}

	_getch();
}
