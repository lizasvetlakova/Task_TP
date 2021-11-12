#include "SetOfStacks.h"

int keyboardInput(int min, int max) {
	while (1) {
		int e;
		cin >> e;
		if (cin.fail() || e > max || e < min) {
			cin.clear();
			cout << "\n������������ ����. ������� �����: ";
		}
		else return e;;
		cin.ignore(32767, '\n');
	}
}
int main(void) {
	setlocale(LC_ALL, "rus");
	int c, n, v, M;
	bool flag = 1;
	cout << "������� ��������� �������� �����: ";
	M = keyboardInput(1, INT32_MAX);
	SetOfStacks stackSet(M);
	while (flag) {
		system("cls");
		cout << "1. �������� �������" << endl
			<< "2. ������� �������" << endl
			<< "3. �������� ��������� ��������" << endl
			<< "4. ������� ���������� � ���� ������" << endl
			<< "5. �����" << endl;
		cout << "�������� �������� >> ";
		c = keyboardInput(1, 5);
		switch (c) {
		case 1:
			cout << "\n������� ����� ��� ����������: ";
			n = keyboardInput(INT32_MIN, INT32_MAX);
			stackSet.push(n);
			break;
		case 2:
			try {
				v = stackSet.pop();
				cout << "\n������� �����: " << v << endl;
			}
			catch (const char* exc) {
				cout << exc << endl;
			}
			break;
		case 3:
			cout << "\n������� ����� ��������� �������� �����: ";
			M = keyboardInput(1, INT32_MAX);
			stackSet.SetMaximum(M);
			break;
		case 4:
			cout << "\t��� ������\n"
				<< "��������� �������� ��� ������� �����: " << M
				<< "\n���������� ������: " << stackSet.GetNumOfSt()
				<< "\n���������� ��������(�����): " << stackSet.GetNumOfEl() << endl;
			break;
		case 5:
			flag = 0;
			break;
		}
		system("pause");
	}
	return 0;
}