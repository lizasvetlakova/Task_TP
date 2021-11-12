#include <iostream>
#include <algorithm>

using namespace std;

void toBinary(int value) {
	cout << endl << "Число в двоичном виде:" << endl;
	for (int i = (sizeof(value) * 8) - 1; i >= 0; --i)
		cout << ((value >> i) & 1) << " ";
	cout << endl << endl;
}

int findMaxLength(int c) {
	if (~c == 0) return sizeof(c) * 8;
	int current = 0;
	int prev = 0;
	int maxLen = 0;
	for (int i = 0; i < 32; i++) {
		if ((c & 1) == 1) {
			current++;
		}
		else if ((c & 1) == 0) {
			if ((c & 2) == 0) {
				prev = 0;
			}
			else prev = current;
			current = 0;
		}
		maxLen = max(maxLen, current + prev + 1);
		c >>= 1;
	}
	return maxLen;
}

int main(void) {
	setlocale(LC_ALL, "rus");
	int a;
	cout << "Введите число: ";
	while (1) {
		cin >> a;
		if (cin.fail() || a > INT32_MAX || a < INT32_MIN) {
			cin.clear();
			cout << "\nНеккоректный ввод.\nВведите снова: ";
		}
		else {
			break;
		}
		cin.ignore(32767, '\n');
	}
	toBinary(a);
	int M = findMaxLength(a);
	cout << "Максимальная длина последовательности единиц: " << M << endl;
	return 0;
}
