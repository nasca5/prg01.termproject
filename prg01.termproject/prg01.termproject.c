# include <stdio.h>
# include <Windows.h>
# include <conio.h>
# include <stdbool.h>
# include <time.h>
# include <stdlib.h>

# define WIDTH 20
# define HEIGHT 12

void start();
void restart();
void make_bad();
void make_good();
void make_stone();
void move_stone();
void remove_stone();
void move_user();
void display();
bool reset_game();

// ��� ���� ����
int set;
// ����
int score;
// ���
int life;
// ��� ȭ�� ī��Ʈ
int cnt_dis = 1;

bool play = TRUE;

//��
typedef struct {
	
	int x;
	int y;
	bool exist;

} STONE ;

//����
typedef struct {

	int x;

} USER;

STONE stone[WIDTH];
USER user;

//���� �ʱ�ȭ 
void start() {
	
	set = 100;
	score = 0;
	life = 3;

	for (int i = 0; i < WIDTH; i++) {

		stone[i].exist = FALSE;
		user.x = WIDTH / 2;

	}

}

//�� ����
void make_stone() {
	
	for (int i = 0; i < WIDTH; i++) {

		if (!stone[i].exist) {
			
			stone[i].x = rand() % WIDTH;
			stone[i].y = (HEIGHT -1);
			stone[i].exist = TRUE;

		}

	}

}

//�� �����̴� �Լ�
void move_stone() {

	for (int i = 0; i < WIDTH; i++) {

		if (stone[i].exist) {

			stone[i].y--;

		}

	}

}

//�ٴڿ� ���� �� ������� �Լ�
void remove_stone() {

}

//�̷ο� ȿ�� �����ϴ� �Լ�
void make_good() {

}

//�طο� ȿ�� �����ϴ� �Լ�
void make_bad() {

}

//���� �����̴� �Լ�
void move_user() {

}

//ȭ�� ��� �Լ�
void display() {

}

//���� ������ �����Ű�� �Լ�
bool reset_game() {

	if (life == 0 || score == 10) {
		
		if (life == 0)
			printf("����� 0���Դϴ�.\n");

		else
			printf("������ 10���� �Ǿ����ϴ�! ���ϵ帳�ϴ�!\n");
		
		return TRUE;

	}

	return FALSE;
	
}

//���� ����� ���θ� ���� ó���ϴ� �Լ�
void restart() {

	int result;

	while (true) {
		
		printf("�ٽ� �Ͻðڽ��ϱ�? (Y = 1 / N = 0) : ");
		scanf_s("%d", &result);

		if ((result == 1) || (result == 0))
			break;

		printf("1(Yes) or 0(No)���� �Է����ּ���.\n");
			
	}

	if (result == 1) {

		printf("-GAME START-");
		start();

	}

	else {

		play = FALSE;
		printf("-THE END-");

	}

}

int main(void) {

	start();

	while (play) {

		srand((int)time(NULL));

		make_stone();

		move_stone();

		remove_stone();

		move_user();

		make_bad();

		make_good();

		display();
	
		if (reset_game()) {

			restart();

		}

		system("cls");
		Sleep(set);
		
	}

	return 0;

}