# include <stdio.h>
# include <Windows.h>
# include <conio.h>
# include <stdbool.h>
# include <time.h>
# include <stdlib.h>

# define WIDTH 20
# define HEIGHT 10

char board[HEIGHT + 1][WIDTH];

void start();
void restart();
void make_bad();
void make_good();
void make_stone();
void move_stone();
void remove_stone();
void move_user();
void display();
int reset_game();

// ��� ���� ����
int set;
// ����
int score;
// ���
int life;
// �� ���� ī��Ʈ
int cnt = 0;

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

	}

	user.x = WIDTH / 2;

	board[HEIGHT - 1][user.x] = 'm';

	for (int i = 0; i < HEIGHT + 1; i++) {

		for (int j = 0; j < WIDTH; j++) {

			board[i][j] = ' ';

			if (i == HEIGHT)
				board[i][j] = '=';

		}

	}

}

//�� ����
void make_stone() {
	
	for (int i = 0; i < WIDTH; i++) {

		if (!stone[i].exist) {
			
			if (cnt <= 9) {

				stone[i].x = rand() % WIDTH;
				stone[i].y = 0;
				stone[i].exist = TRUE;
				board[stone[i].y][stone[i].x] = 'o';
				cnt++;

			}

		}

	}

}

//�� �����̴� �Լ�
void move_stone() {

	for (int i = 0; i < WIDTH; i++) {

		if (stone[i].exist) {
			
			board[stone[i].y][stone[i].x] = ' ';
			stone[i].y++;
			board[stone[i].y][stone[i].x] = 'o';

		}

	}

}

//�ٴڿ� ���� �� ������� �Լ�
void remove_stone() {

	for (int i = 0; i < WIDTH; i++) {

		if (stone[i].exist && (stone[i].y > HEIGHT - 1)) {

			board[stone[i].y][stone[i].x] = '=';
			stone[i].exist = FALSE;
			cnt--;
		
		}

	}

}

//�̷ο� ȿ�� �����ϴ� �Լ�
void make_good() {

}

//�طο� ȿ�� �����ϴ� �Լ�
void make_bad() {

}

//���� �����̴� �Լ�
void move_user() {

	board[HEIGHT - 1][user.x] = ' ';

	if (GetAsyncKeyState(VK_LEFT))
		
	    user.x--;

	else if (GetAsyncKeyState(VK_RIGHT))

	    user.x++;

	if (user.x < 0)
		user.x = 0;

	else if (user.x > (WIDTH - 1))
		user.x = WIDTH - 1;

	board[HEIGHT - 1][user.x] = 'm';

}

//ȭ�� ��� �Լ�
void display() {

	system("cls");

	for (int i = 0; i < HEIGHT + 1; i++) {

		for (int j = 0; j < WIDTH; j++) {

			printf("%c", board[i][j]);

		}

		printf("\n");

	}

}

//���� ������ �����Ű�� �Լ�
int reset_game() {

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

		//make_bad();

		//make_good();

		display();
	
		if (reset_game()) {

			restart();

		}

		Sleep(set);
		
	}

	return 0;

}