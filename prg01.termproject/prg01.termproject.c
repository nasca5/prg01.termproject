# include <stdio.h>
# include <windows.h>
# include <conio.h>
# include <stdbool.h>
# include <time.h>
# include <stdlib.h>

# define WIDTH 20
# define HEIGHT 13

char board[HEIGHT + 1][WIDTH];

void start_game();
void make_bad();
void make_good();
void make_stone();
void move_stone();
void remove_stone();
void move_user();
void display();
int reset_game();
void restart();
int manage_life();

// 출력 지연 조절
int set;
// 점수
int score;
// 목숨
int life;

bool play = TRUE;

//돌
typedef struct {
	
	int x;
	int y;
	bool exist;

} STONE ;

//유저
typedef struct {

	int x;

} USER;

STONE stone[WIDTH];
USER user;

//게임 초기화 
void start_game() {

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

//돌 생성
void make_stone() {
	
	for (int i = 0; i < WIDTH; i++) {

		if (!stone[i].exist) {

			stone[i].x = rand() % WIDTH;
			stone[i].y = 1;
			stone[i].exist = TRUE;

			break;

		}

	}

}

//돌 움직이는 함수
void move_stone() {

	for (int i = 0; i < WIDTH; i++) {

		if (stone[i].exist) {

			if (stone[i].y == 1) {

				stone[i].y++;
				board[stone[i].y][stone[i].x] = 'o';

			}
			
			board[stone[i].y][stone[i].x] = ' ';
			stone[i].y++;
			board[stone[i].y][stone[i].x] = 'o';

		}

	}

}

//바닥에 닿은 돌 사라지는 함수
void remove_stone() {

	for (int i = 0; i < WIDTH; i++) {

		if (stone[i].exist && (stone[i].y > HEIGHT - 1)) {

			board[stone[i].y][stone[i].x] = '=';
			stone[i].exist = FALSE;
		
		}

	}

}

//목숨 관리
int manage_life() {

	for (int i = 0; i < WIDTH; i++) {

		if ((stone[i].exist && stone[i].y == HEIGHT - 1) && (stone[i].x == user.x))
			return TRUE;

	}

	return FALSE;

}

//이로운 효과 생성하는 함수
void make_good() {

}

//해로운 효과 생성하는 함수
void make_bad() {

}

//유저 움직이는 함수
void move_user() {

	board[HEIGHT - 1][user.x] = ' ';

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		
	    user.x--;

	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)

	    user.x++;

	if (user.x < 0)
		user.x = 0;

	else if (user.x > (WIDTH - 1))
		user.x = WIDTH - 1;

	board[HEIGHT - 1][user.x] = 'm';

}

//화면 출력 함수
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

}

//조건 충족시 종료시키는 함수
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

//게임 재시작 여부를 묻고 처리하는 함수
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

			printf("\n\n\n\n\n\n\n        %d SECONDS", i);
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

int main(void) {

	srand((int)time(NULL));

	system("mode con:cols=30 lines=15");

	start_game();

	while (play) {

		make_stone();

		move_stone();

		remove_stone();

		if (manage_life())
			life--;

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