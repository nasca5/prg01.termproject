# include <stdio.h>
# include <Windows.h>
# include <conio.h>
# include <stdbool.h>
# include <time.h>

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



typedef struct {
	
	int x;
	int y;
	bool exist;

} STONE ;

typedef struct {

	int x;

} USER;

int set = 100;
int score;
int life;
int result;

bool play = TRUE;

STONE stone[WIDTH];
USER user;

void start() {
	
	int score = 0;
	int life = 3;

	for (int i = 0; i < WIDTH; i++) {

		stone[i].exist = FALSE;
		user.x = WIDTH / 2;

	}

}

void make_stone() {

}

void move_stone() {

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

		Sleep(set);
		system("cls");

	}

	return 0;

}