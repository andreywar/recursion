#include <iostream>
#include <time.h>
using namespace std;



const int n = 5;
int a[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int b[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int h[n][n];
int try0(int, int, int);

void horse()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			h[i][j] = 0;
	h[2][2] = 1;
	if (try0(2, 2, 2))
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) cout << " " << h[i][j];
	}
	else cout << "there not solution for that step" << endl;
}



int try0(int i, int x, int y)
{
	int u, v, k = 0, q1 = 0;
	while (q1 == 0 && k < n)
	{
		u = x + a[k];
		v = y + b[k];
		k++;
		if (u >= 0 && u < n && v >= 0 && v < n)
			if (h[u][v] == 0)
			{
				h[u][v] = i;
				if (i < n * n && try0(i + 1, u, v) == 0) h[u][v] = 0;
				else q1 = 1;
			}
	}
	return q1;
}

int search(int* array, int max_number, int current_index, int size)
{
	int temp = 0;
	if (array[current_index] > max_number) { temp = current_index; max_number = array[current_index]; }
	if (current_index == size - 1) return temp;
	int temp2 = search(array, max_number, current_index + 1, size);
	if (temp < temp2) return temp2; else return temp;
}

int main()
{
	cout << "Enter size of array: ";
	int N;
	cin >> N;
	int* a = new int[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
	int max_index = search(a, a[0], 1, N);
	cout << "\nMaximum element a[" << max_index << "]=" << a[max_index] << endl;
	system("pause");
	delete[] a;
	return 0;
	horse();
}



