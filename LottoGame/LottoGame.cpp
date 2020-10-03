#include "pch.h"
#include <iostream>
#include<time.h>
using namespace std;

//로또를 돌리는 프로그램
//필요한것 : 랜덤한 숫자 생성, 배열에 오름차순으로 저장, 입력한것과 대조
//예외조건 : 0~45를 넘어가는 숫자, 같은숫자, 6개가 넘어가는 숫자 입력 제한

int LottoNumber[45] = {};


void Swap(int *a, int *b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

//로또넘버 45개의 숫자를 각각의 배열에 저장
void initLottoNumber() {
	for (int i = 0; i < 45; i++) {
		LottoNumber[i] = i + 1;
	}
}

void Shuffle() {
	int index1, index2;
	srand((unsigned int)time(0));

	//저장된 로또넘버를 100번 셔플
	for (int i = 0; i < 100; i++) {
		index1 = rand() % 45;
		index2 = rand() % 45;

		Swap(&LottoNumber[index1], &LottoNumber[index2]);
	}
}

void Sort(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (*(arr + i) < *(arr + j)) {
				swap(*(arr + i), *(arr + j));
			}
		}
	}
}

int main(){
	int InputNumber[6] = {};
	bool run = true;
	int count = 0;
	
	//사용자 숫자 입력
	while (run) {
		cout << "로또 번호를 적어주세요(1~45의 숫자 중 6개) : ";
		for (int i = 0; i < 6; i++) {
			cin >> InputNumber[i];
			for (int j = 0; j < i; j++) {
				if (InputNumber[i] == InputNumber[j]) {
					cout << "중복 된 값을 입력하셨습니다. 다시 입력해주세요. ";
					i--;
				}
			}

			if (InputNumber[i] < 1 || InputNumber[i]>45) {
				cout << "잘못된 값을 입력하셨습니다 1~45 사이의 숫자를 입력해주세요. : ";
				i--;
			}
			else
				run = false;
		}
	}

	initLottoNumber();
	Shuffle();
	Sort(LottoNumber, 6);
	Sort(InputNumber, 6);

	//입력한 번호를 출력
	cout << "입력번호는  ";
	for (int i = 0; i < 6; i++) {
		cout << InputNumber[i] << " ";
	}
	cout << "입니다.";
	cout << "" << endl;


	//정렬된 추첨번호를 출력
	cout << "추첨번호는  ";
	for (int i = 0; i <6; i++) {
		cout << LottoNumber[i] << " ";
	}
	cout << "입니다.";
	cout << "" << endl;

	cout << "맞춘 숫자는 ";
	//입력한 숫자와 로또번호를 대조
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 5; j++) {
			if (InputNumber[i] == LottoNumber[j]) {
				cout << LottoNumber[j] << " ";
				count++;
			}
		}
	}

	switch (count) {
	case 0:
		cout << "없습니다." << endl;
		break;
	case 1:
		cout << "입니다. 다음 기회를 노리세요" << endl;
		break;
	case 2:
		cout << "입니다. 다음 기회를 노리세요" << endl;
		break;
	case 3:
		cout << "입니다. 축하드립니다 4등입니다." << endl;
		break;
	case 4:
		cout << "입니다. 축하드립니다 3등입니다." << endl;
		break;
	case 5:
		cout << "입니다. 축하드립니다 2등입니다." << endl;
		break;
	case 6:
		cout << "입니다. 축하드립니다 1등입니다." << endl;
		break;
	}
	cout << "" << endl;


}

