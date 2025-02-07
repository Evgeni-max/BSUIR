#include <iostream>

int main()
{
	std::cout << "Enter the size of the field: ";
	int n, m;
	std::cin >> n >> m;
	int q = n + 2, p = m + 2;
	char** a;
	//ввод
    a = (char**)malloc(q  * sizeof(char*));
	for (int i = 0; i < q; i++) {
		a[i] = (char*)malloc(p * sizeof(char));
	}

	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2 ; j++) {
			a[i][j] = '.';
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			std::cout << a[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	//ввод мин
	std::cout << "Enter the min coordinates: ";
	int x, y;
	while (std::cin >> x >> y) {
		a[x][y] = '*';
	}

	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			if (a[i][j] == '.') a[i][j] = 48;
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (a[i][j] == '*') {
				if (a[i + 1][j + 1] != '*') a[i + 1][j + 1]++;
				if (a[i + 1][j] != '*') a[i + 1][j]++;
				if (a[i + 1][j - 1] != '*') a[i + 1][j - 1]++;
				if (a[i][j + 1] != '*') a[i][j + 1]++;
				if (a[i][j - 1] != '*') a[i][j - 1]++;
				if (a[i - 1][j - 1] != '*') a[i - 1][j - 1]++;
				if (a[i - 1][j] != '*') a[i - 1][j]++;
				if (a[i - 1][j + 1] != '*') a[i - 1][j + 1]++;
			}
		}
	}
	//вывод
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			std::cout << a[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	//удаление
	for (int i = 0; i < n + 2; i++) {
		free(a[i]);
		a[i] = nullptr;
	}
	free(a);
	a = nullptr;

}

