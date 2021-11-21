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
void start() {
	
	set = 100;
	score = 0;
	life = 3;

	for (int i = 0; i < WIDTH; i++) {

		stone[i].exist = FALSE;
		user.x = WIDTH / 2;

	}

}

//돌 생성
void make_stone() {
	
	for (int i = 0; i < WIDTH; i++) {

		if (!stone[i].exist) {
			
			stone[i].x = rand() % WIDTH;
			stone[i].y = (HEIGHT -1);
			stone[i].exist = TRUE;

		}

	}

}

//돌 움직이는 함수
void move_stone() {

	for (int i = 0; i < WIDTH; i++) {

		if (stone[i].exist) {

			stone[i].y--;

		}

	}

}

//바닥에 닿은 돌 사라지는 함수
void remove_stone() {

}

//이로운 효과 생성하는 함수
void make_good() {

}

//해로운 효과 생성하는 함수
void make_bad() {

}

//유저 움직이는 함수
void move_user() {

}

//화면 출력 함수
void display() {

}

//조건 충족시 종료시키는 함수
bool reset_game() {

	if (life == 0 || score == 10) {
		
		if (life == 0)
			printf("목숨이 0개입니다.\n");

		else
			printf("점수가 10점이 되었습니다! 축하드립니다!\n");
		
		return TRUE;

	}

	return FALSE;
	
}

//게임 재시작 여부를 묻고 처리하는 함수
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