#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = count;
	*p_MPPotion = count;
	return;
}


int main(void)
{
	const int Num = 4;
	int status[Num] = { 0, };
	int choice = 0;
	int HPPotion = 0;
	int MPPotion = 0;

	while (1)
	{
		cout << "HP와 MP를 입력! : "; // 값 입력 후 enter키 누를 시 개행이 되지 않게 하는법
		cin >> status[0] >> status[1];

		if (50 < status[0] && 50 < status[1]) //HP와 MP모두 50보다 크면 
		{
			break; //다음 실행(반복문 탈출)
		}
		// 다시 입력하라는 안내를 출력
		cout << "HP나 MP가 작습니다. 다시 입력하세요! " << endl;
		cout << "둘 다 50 보다 크게 입력하세요!\n" << endl;

	}

	while (1)
	{
		cout << "공격력과 방어력 입력! : ";
		cin >> status[2] >> status[3];

		if (0 < status[2] && 0 < status[3])
		{
			break; //다음 실행(반복문 탈출)
		}
		// 다시 입력하라는 안내를 출력
		cout << "공격력이나 방어력이 작습니다. 다시 입력하세요! " << endl;
		cout << "둘 다 0보다 크게 입력하세요!\n" << endl;
	}

	setPotion(5, &HPPotion, &MPPotion);


	// 스탯관리 시스템중 하나를 선택하고, 다음 행동이 입력, 0입력시 프로그램 종료
	cout << "------------------------------------------" << endl;
	cout << "1.HP UP / 2.MP UP / 3.공격력 UP / 4.방어력 UP / 5.현재 능력치 / 6.Level Up / 0.나가기" << endl;
	cout << "다음 선택지 중 하나를 선택해 숫자를 입력하세요! : " << endl << "현재 HP포션 : 5개, MP포션 : 5개" << endl;

	while (1)
	{
		cin >> choice;

		if (choice == 0)
		{
			cout << "게임을 종료합니다!" << endl;
			break;
		}

		switch (choice)
		{
		case 1:
			if (HPPotion <= 0)
			{
				cout << "포션이 없습니다!" << endl;
				continue;
			}

			status[0] += 20;
			HPPotion--;
			cout << "HP가 20 증가했습니다! " << "현재 HP : " << status[0] << endl;
			cout << "포션이 차감되었습니다!" << "현재포션 : " << HPPotion << endl;

			break;

		case 2:
			if (MPPotion <= 0)
			{
				cout << "포션이 없습니다!";
				continue;
			}
			status[1] += 20;
			MPPotion--;
			cout << "MP가 20 증가했습니다! " << "현재 HP : " << status[1] << endl;
			cout << "포션이 차감되었습니다!" << "현재포션 : " << MPPotion << endl;

			break;

		case 3:
			status[2] *= 2;
			cout << "공격력 2배!" << endl;
			cout << "현재 공격력 : " << status[2] << endl;

			break;

		case 4:
			cout << "방어력 2배!" << endl;
			status[3] *= 2;

			break;

		case 5:
			cout << "현재 스탯 : " << "HP : " << status[0] << ", MP : " << status[1] << ", 공격력 : " << status[2] << ", 방어력 : " << status[3] << endl;

			break;

		case 6:
			HPPotion++;
			MPPotion++;
			cout << "Level UP! 포션이 각 1개씩 증가 했습니다! " << endl;
			cout << "현재 HP포션 : " << HPPotion << endl;
			cout << "현재 MP포션 : " << MPPotion << endl;
			break;

		default:
			cout << " 해당 상태창만 입력해주세요!" << endl;
			break;


		}



	}
	return 0;
}