#include <Windows.h>
#include <iostream>
#include <vector>
#include <iomanip>      // std::setw
using namespace std;

void main() {
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	int n;
	cout << "Number of vertices = ";
	SetConsoleTextAttribute(hConsole, 3);
	cin >> n;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "Matrix:" << endl;

	vector<vector<bool>> a(n, vector<bool>(n));
	{
		bool temp;

		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
			cin >> temp;
			a[i][j] = temp;
		}
	}

	for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) a[i][j] = max(i == j, (bool)max(a[i][j], (bool)(a[i][k] + a[k][j] == 2)));

	cout << "Paths:" << endl;

	SetConsoleTextAttribute(hConsole, 87);

	cout << '+';

	for (int i = 0; i < n; ++i) cout << std::setw(2) << i + 1;

	cout << endl;

	int i = 0;

	SetConsoleTextAttribute(hConsole, 3);
	for (auto vec : a) {
		SetConsoleTextAttribute(hConsole, 87);
		++i;
		cout << i;
		for (auto i : vec) {
			SetConsoleTextAttribute(hConsole, 2);
			if (!i) {
				SetConsoleTextAttribute(hConsole, 4);
				cout << std::setw(2) << 'N';
			}
			else cout << std::setw(2) << 'Y';
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, 15);

}

/*
9
0 1 0 1 1 0 0 0 0
1 0 0 1 0 0 1 0 0
0 0 0 0 0 0 0 0 0
1 1 0 0 0 1 1 0 0
1 0 0 0 0 1 0 1 0
0 0 0 1 1 0 0 0 0
0 1 0 1 0 0 0 1 1
0 0 0 0 1 0 1 0 0
0 0 0 0 0 0 1 0 0

5
0 1 0 0 0
0 0 1 0 0
0 0 0 1 1
0 1 0 0 0
0 0 0 1 0

7
0 0 1 0 0 0 0
0 0 1 0 0 0 1
0 0 0 1 0 0 0
0 0 0 0 0 0 0
0 1 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 1 0
*/