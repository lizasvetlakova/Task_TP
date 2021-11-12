#include "SetOfStacks.h"

int keyboardInput(int min, int max) {
	while (1) {
		int e;
		cin >> e;
		if (cin.fail() || e > max || e < min) {
			cin.clear();
			cout << "\nНеккоректный ввод. Введите снова: ";
		}
		else return e;;
		cin.ignore(32767, '\n');
	}
}
int main(void) {
	setlocale(LC_ALL, "rus");
	int c, n, v, M;
	bool flag = 1;
	cout << "Введите пороговое значение стека: ";
	M = keyboardInput(1, INT32_MAX);
	SetOfStacks stackSet(M);
	while (flag) {
		system("cls");
		cout << "1. Добавить элемент" << endl
			<< "2. Удалить элемент" << endl
			<< "3. Изменить пороговое значение" << endl
			<< "4. Вывести информацию о сете стеков" << endl
			<< "5. Выход" << endl;
		cout << "Выберите действие >> ";
		c = keyboardInput(1, 5);
		switch (c) {
		case 1:
			cout << "\nВведите число для добавления: ";
			n = keyboardInput(INT32_MIN, INT32_MAX);
			stackSet.push(n);
			break;
		case 2:
			try {
				v = stackSet.pop();
				cout << "\nУдалено число: " << v << endl;
			}
			catch (const char* exc) {
				cout << exc << endl;
			}
			break;
		case 3:
			cout << "\nВведите новое пороговое значение стека: ";
			M = keyboardInput(1, INT32_MAX);
			stackSet.SetMaximum(M);
			break;
		case 4:
			cout << "\tСет стеков\n"
				<< "Пороговое значение для каждого стека: " << M
				<< "\nКоличество стеков: " << stackSet.GetNumOfSt()
				<< "\nКоличество элеметов(всего): " << stackSet.GetNumOfEl() << endl;
			break;
		case 5:
			flag = 0;
			break;
		}
		system("pause");
	}
	return 0;
}