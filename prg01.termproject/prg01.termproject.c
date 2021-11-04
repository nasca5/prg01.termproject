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

// 출력 지연 조절
int set;
// 점수
int score;
// 목숨
int life;
// 출력 화면 카운트
int cnt_dis = 1;

bool play = TRUE;

typedef struct {
	
	int x;
	int y;
	bool exist;

} STONE ;

typedef struct {

	int x;

} USER;

STONE stone[WIDTH];
USER user;

void start() {
	
	int set = 100;
	int score = 0;
	int life = 3;

	for (int i = 0; i < WIDTH; i++) {

		stone[i].exist = FALSE;
		user.x = WIDTH / 2;

	}

}

void make_stone() {
	
	for (int i = 0; i < WIDTH; i++) {

		if (!stone[i].exist) {
			
			stone[i].x = rand() % WIDTH;
			stone[i].y = (HEIGHT -1);
			stone[i].exist = TRUE;

		}

	}

}

void move_stone() {

	for (int i = 0; i < WIDTH; i++) {

		if (stone[i].exist) {

			stone[i].y--;

		}

	}

}

void remove_stone() {

}

void make_good() {

}

void make_bad() {

}

void move_user() {

}

void display() {

}

bool reset_game() {

	if (life == 0) {
		
		printf("목숨이 0개입니다.\n");

		return TRUE;
	
	}

	else if (score == 10) {

		printf("점수가 10점이 되었습니다! 축하드립니다!\n");
		return TRUE;

	}

	return FALSE;
	
}

void restart() {

	int result;

	while (true) {
		
		printf("다시 하시겠습니까? (Y = 1 / N = 0) : ");
		scanf_s("%d", &result);

		if ((result == 1) || (result == 0))
			break;

		printf("1(Yes) or 0(No)으로 입력해주세요.\n");
			
	}

	if (result == 1) {

		printf("game restart");
		start();

	}

	else {

		play = FALSE;
		printf("game end");

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