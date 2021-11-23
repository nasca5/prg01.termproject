# include <stdio.h>
# include <windows.h>
# include <conio.h>
# include <stdbool.h>
# include <time.h>
# include <stdlib.h>

//���� ����
# define WIDTH 20
//���� ����
# define HEIGHT 13

//�� ���ϱ� ���� ������
char board[HEIGHT + 1][WIDTH];

void start_menu();
void design_console();
void start_game();
void make_good();
void make_stone();
void move_stone();
void remove_stone();
void move_user();
void display();
void restart();
void manage_effects();
int manage_game();
int reset_game();

// ��� ���� ����
int set;
// ����
int score;
// ���
int life;
// ȭ�� ��� ī��Ʈ
int cnt;

bool play = TRUE;

//��
typedef struct {
	
	int x;
	int y;
	int type;
	bool exist;

} STONE ;

//����
typedef struct {

	int x;

} USER;

STONE stone[WIDTH];
USER user;

//�ܼ� ������ ����
void design_console() {

	system("mode con:cols=30 lines=17");
	system("title �� ���ϱ� ����");
	system("color 70");

}

//���� �ʱ�ȭ 
void start_game() {

	set = 100;
	score = 0;
	life = 3;
	cnt = 0;

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

//���� ���� �Ѱ� ����
void start_menu() {

	while (true) {

		system("cls");

		printf("\n\n���۹� : ��(LEFT) / ��(RIGHT)");
		printf("\n\n\n        �� ���ϱ� ����\n\n");
		printf("        Hannam Univ.\n");
		printf("        termproject\n");
		printf("\n    PRESS THE ENTER KEY...\n");

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {

			system("cls");

			printf("\n\n\n\n\n\n\n          GOOD LUCK!");
			Sleep(1000);
			break;

		}

	}

	start_game();

}

//���� �̷ο� ȿ�� ����
void make_stone() {
	
	for (int i = 0; i < WIDTH; i++) {

		if ((!stone[i].exist) && (cnt % 50 == 0)) {

			stone[i].x = rand() % WIDTH;
			stone[i].y = 1;
			stone[i].exist = TRUE;
			stone[i].type = rand() % 2;

			break;

		}

		else if (!stone[i].exist) {

			stone[i].x = rand() % WIDTH;
			stone[i].y = 1;
			stone[i].exist = TRUE;
			stone[i].type = 2;

			break;

		}

	}

}

//���� �̷ο� ȿ�� �����̴� �Լ�
void move_stone() {

	char var[20] = "GAo";
	char* cp = var;

	for (int i = 0; i < WIDTH; i++) {

		if (stone[i].exist) {
		
			if (stone[i].type == 0) {

				board[stone[i].y][stone[i].x] = ' ';
				stone[i].y++;
				board[stone[i].y][stone[i].x] = *cp;

			}

			else if (stone[i].type == 1) {

				board[stone[i].y][stone[i].x] = ' ';
				stone[i].y++;
				board[stone[i].y][stone[i].x] = *(cp + 1);

			}

			else if (stone[i].type == 2) {

				board[stone[i].y][stone[i].x] = ' ';
				stone[i].y++;
				board[stone[i].y][stone[i].x] = *(cp + 2);

			}
		
		}

	}

}

//�ٴڿ� ���� �� ������� �Լ�
void remove_stone() {

	for (int i = 0; i < WIDTH; i++) {

		if (stone[i].exist && (stone[i].y > HEIGHT - 1)) {

			board[stone[i].y][stone[i].x] = '=';
			stone[i].exist = FALSE;
		
		}

	}

}

//������ �浹�� �� �Ǻ�
int manage_game() {

	for (int i = 0; i < WIDTH; i++) {

		if ((stone[i].exist && stone[i].y == HEIGHT - 1) && (stone[i].x == user.x)) {

			if (stone[i].type == 0)
				return 0;

			else if (stone[i].type == 1)
				return 1;

			else if (stone[i].type == 2)
				return 2;

		}

	}

	return 3;

}

//���� ���� ����
void manage_effects() {

	if (manage_game() == 0) {

		score++;
		set += 10;

		if (set > 100)
			set = 100;

	}

	else if (manage_game() == 1) {

		score++;
		life++;

		if (life > 3)
			life = 3;

	}

	else if (manage_game() == 2) {

		life--;
		set -= 10;

		if (set < 10)
			set = 10;

	}

}

//���� �̵�
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

//ȭ�� ���
void display() {

	system("cls");

	for (int i = 0; i < HEIGHT + 1; i++) {

		if (i == 0)
			printf("life : %d  score : %d", life, score);

		else if (i == 1) 
			printf ("    MADE BY K.H.S");

		else {

			for (int j = 0; j < WIDTH; j++) {

				printf("%c", board[i][j]);

			}

		}

		printf("\n");

	}

	printf ("G : +1 SCORE, +1 LIFE\n");
	printf("A : +1 SCORE, SPEED ��0.1\n");

}

//���� ������ ����
int reset_game() {

	if (life == 0 || score == 10) {

		system("cls");
		
		if (life == 0)
			printf("\n\n\n\n\n\n\n         -YOU DIE-\n");

		else
			printf("\n\n\n\n\n\n\n         -YOU WIN-\n");
		
		Sleep(2000);
		return TRUE;

	}

	return FALSE;
	
}

//���� ����� ���� Ȯ��
void restart() {

	int result;

	system("cls");

	while (true) {
		
		printf("TRY AGAIN (Y = 1 / N = 0) : ");
		scanf_s("%d", &result);

		if ((result == 1) || (result == 0)) {
			
			system("cls");
			break;
		
		}
		
		system("cls");
		printf("PLEASE 1(Yes) or 0(NO)!\n");
			
	}

	if (result == 1) {

		printf("\n\n\n\n\n\n\n        -GAME START-\n");
		Sleep(1000);
		system("cls");
		
		for (int i = 5; i >= 1; i--) {

			printf("\n\n\n\n\n\n\n          %d SECONDS", i);
			Sleep(1000);
			system("cls");
			
		}

		start_game();

	}

	else {

		play = FALSE;
		printf("\n\n\n\n\n\n\n          -THE END-");
		Sleep(2000);

	}

}

//���� �Լ�
int main(void) {

	design_console();

	srand((int)time(NULL));

	start_menu();

	while (play) {

		cnt++;

		make_stone();

		move_stone();

		remove_stone();
			
		move_user();

		manage_effects();

		display();
	
		if (reset_game()) {

			restart();

		}

		Sleep(set);
		
	}

	return 0;

}