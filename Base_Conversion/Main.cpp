#include<iostream>


using namespace std;


void main() {
	int result = 0;

	int decimal;
	int base;
	int digit = 1; // 자릿수

	cout << "십진법 수 입력 : ";
	cin >> decimal;


	cout << "진법변환 N 입력 : ";
	cin >> base;

	while (decimal != 0) {
		result += decimal % base * digit;
		decimal = decimal / base;
		digit *= 10;
	}

	cout << base << "진법으로 변환한 결과 : " << result <<endl;
}