#include<iostream>


using namespace std;


void main() {
	int result = 0;

	int decimal;
	int base;
	int digit = 1; // �ڸ���

	cout << "������ �� �Է� : ";
	cin >> decimal;


	cout << "������ȯ N �Է� : ";
	cin >> base;

	while (decimal != 0) {
		result += decimal % base * digit;
		decimal = decimal / base;
		digit *= 10;
	}

	cout << base << "�������� ��ȯ�� ��� : " << result <<endl;
}