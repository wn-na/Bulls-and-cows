#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define Random rand() % 10;
#define false 0
#define true 1

int setRandomNum(int *arr, int count);
int setMyNum(int *arr, int num, int count);
void showNum(int *arr, int count, int space);
int checkNum(int *arr, int *inputarr, int count, int *numCount);
void check(int *arr, int *inputarr, int count, int *strack, int *ball);
void clear(int, char); // s = slepp, p = pause

int main() {
	int ch;
	int random[10], num, myNum[10];
	int strack = 0, ball = 0, out = 0;
	int minTry = 0, tryTime = 0, maxTry = 0;
	int trycount = 0;
	int numCount = 10;
	char str[100];

	while (true) {
		
		while (true) {
		printf("=== Baseball Game ===\n");
		printf("1. Game Start\n"); 
		printf("2. Game Score\n");
		printf("3. Exit\n\n");

			printf("> ");
			scanf_s("%d", &ch);

			if (ch == 1 || ch == 2 || ch == 3) {
				break;
			} else {
				printf("Error. Please try again\n");
				clear(1,'s');
				continue;
			}
		}

		switch (ch) {
		case 1 :
			clear(0, 's');
			tryTime++;
			int number[10] = { 0,1,2,3,4,5,6,7,8,9 };
			numCount = 10;
			setRandomNum(random, 4);
			trycount = 0;
			while (true) {
				trycount++;
				ball = 0; strack = 0;

				printf("> ");
				showNum(number, numCount, true);
				while (true) {
					printf("> ");
					scanf("%s", str);
					if (strlen(str) != 4) {
						printf("Error. Please try again\n");
						continue;
					}
					else {
						num = atoi(str);
						if (num >= 0 && num < 10000) {
							setMyNum(myNum, num, 4);
							break;
						}
						else {
							printf("Error. Please try again\n");
							continue;
						}
					}
				}

				check(myNum, random, 4, &strack, &ball);

				if (ball != 0 || strack != 0 && strack != 4) {
					printf("[result] %d Strack / %d ball\n", strack, ball);
				} else if (strack == 4) {
					printf("[result] Congratulations!! Your Correct\n");

					if (maxTry == 0 && minTry == 0) maxTry = minTry = trycount;
					else if (trycount > maxTry) maxTry = trycount;
					else if (trycount < minTry) minTry = trycount;
					clear(0,'p');
					break;
				} else {
					printf("[result] Out!!!\n");
					checkNum(number, myNum, 4, &numCount);
				}
			}
			break;
		case 2:
			clear(0, 's');
			printf("=== Your Score ===\n");
			printf("Min Try Time = %d\n", minTry);
			printf("Max Try Time = %d\n", maxTry);
			printf("Try time = %d\n\n", tryTime);
			clear(0, 'p');
			break;
		case 3:
			clear(0, 's');
			printf("Good Bye~\n");
			return 0;
		}
	}
}

int setMyNum(int *arr, int num, int count) {
	for (int i = 0; i < count; i++, num /= 10) 
		arr[count - 1 - i] = num % 10;
	return arr;
}

int setRandomNum(int *arr, int count) {
	srand(time(NULL));
	for (int i = 0; i < count; i++) {
		int tmp = Random;
		for (int j = 0; j < i; j++) {
			if (tmp == arr[j]) {
				tmp = Random;
				j = -1;
			}
		}
		arr[i] = tmp;
	}
	return arr;
}

void showNum(int *arr, int count, int space) {
	if (space == true) for (int i = 0; i < count; i++) printf("%d ", arr[i]);
	else for (int i = 0; i < count; i++) printf("%d", arr[i]);
	printf("\n");
}

void check(int *arr, int *inputarr, int count, int *strack, int *ball) {
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (arr[j] == inputarr[i] && i != j) *ball = *ball + 1;
			else if (arr[j] == inputarr[i] && i == j) *strack = *strack + 1;
		}
	}
}

int checkNum(int *arr, int *inputarr, int count, int *numCount) {
	for (int j = 0; j < count; j++) {
		for (int i = 0; i < *numCount; i++) {
			if (inputarr[j] == arr[i]) {
				*numCount = *numCount - 1;
				for (int k = i; k < *numCount; k++)	arr[k] = arr[k + 1];
			}
		}
	}
	return arr;
}


void clear(int time, char type) {
	if(type == 's') Sleep(time * 1000);
	else if(type == 'p') system("pause");
	system("cls");
}
