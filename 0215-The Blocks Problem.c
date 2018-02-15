#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*UVa Online Judge	--	Problem Set Volumes(101) -- The Blocks Problem*/
/*Learn how to pass by reference(two-dimensional array) to subroutine*/


int Commands (char a[]) {
	char commandActing[2][10] = {"move", "pile"};
	char commandPosition[2][10] = {"onto", "over"};
	int i, j, n;
	for (i = 0;i < 2;i++) {
		for (j = 0;j < 2;j++) {
			if (strstr(a,commandActing[i])&&strstr(a,commandPosition[j])) {
				n = i * 2 + j;
				i = 10;
				break;
			}
		}
	}
	if (i == 2&&j == 2) {
		n = -1;
	}
	return n;
}

int blocksA (char a[]) {
	int i, A;
	for (i = 0;i < strlen(a);i++) {
		if (a[i] == '\0') {
			break;
		}
		if (a[i] >= '0'&&a[i] <= '9') {
			if (a[i + 1] >= '0'&&a[i + 1] <= '9') {
				A = (a[i] - 48) * 10 + (a[i + 1] - 48);
			}
			else {
				A = a[i] - 48;
			}
			break;
		}
	}
	return A;
}

int blocksB (char a[]) {
	int i, B;
	for (i = 0;i < strlen(a);i++) {
		if (a[i] == '\0') {
			break;
		}
	}
	if (a[i - 2] >= '0'&&a[i - 2] <= '9') {
		B = (a[i - 2] - 48) * 10 + (a[i - 1] - 48);
	}
	else {
		B = a[i - 1] - 48;
	}
	return B;
}

int position (int a, int *blocks, int n, int n1) {
	int x, y, k = 0;
	for (x = 0;x < n;x++) {
		for (y = 0;y < n;y++) {
			if (*blocks != a) {
				blocks++;
				k++;
			}
			else {
				x = n + 20;
				break;
			}
		}
	}
	return k;
}

void blocksPiling (int A, int B, int *blocks, int n, int n1, int y) {
	int x;
	for (x = 0;x < n;x++) {
		if (*(blocks + A + x) != -1) {
			*(blocks + B + (y++)) = *(blocks + A + x);
			*(blocks + A + x) = -1;
		}
		else {
			break;
		}
	}
}

void blocksMoving (int A, int *blocks, int n, int n1) {
	int x, y;
	for (x = 1;x < n;x++) {
		if (*(blocks + A + x) == -1) {
			break;
		}
		else {
			for (y = 0;y < n;y++) {
				if (*(blocks + *(blocks + A + x) * n + y) == -1) {
					*(blocks + *(blocks + A + x) * n + y) = *(blocks + A + x);
					break;
				}
			}
			*(blocks + A + x) = -1;
		}
	}
}

void robotCommand(char a[], int *blocks, int n, int n1) {
	int i = Commands(a);
	int A = position(blocksA(a),&blocks[0], n, n);
	int B = position(blocksB(a),&blocks[0], n, n);
	int x, y, k = 0;
	for (x = 1;x < n;x++) {
		if (((A - x * n) < n)&&((B - x * n) < n)) {
			i = 10;
			break;
		}
		else if (((A - x * n) < n)||((B - x * n) < n)) {
			break;
		}
	}
	if (A == B) {
		i = 10;
	}
	switch (i) {
		case 0:
			blocksMoving(A,&blocks[0], n, n);
			blocksMoving(B,&blocks[0], n, n);
			for (x = 1;x < n;x++) {
				if (*(blocks + B + x) == -1) {
					*(blocks + B + x) = *(blocks + A);
					break;
				}
			}
			*(blocks + A) = -1;
			break;
		case 1:
			blocksMoving(A,&blocks[0], n, n);
			for (x = 1;x < n;x++) {
				if (*(blocks + B + x) == -1) {
					*(blocks + B + x) = *(blocks + A);
					break;
				}
			}
			*(blocks + A) = -1;
			break;
		case 2:
			blocksMoving(B,&blocks[0], n, n);
			blocksPiling(A, B, &blocks[0], n, n, 1);
			break;
		case 3:
			for (y = 0;y < n;y++) {
				if (*(blocks + B + y) == -1) {
					break;
				}
			}
			blocksPiling(A, B, &blocks[0], n, n, y);
			break;
		default:
			break;
	}
}

void blocksShow(int *blocks, int n, int nn) {
	int i, j;
	for (i = 0;i < n;i++) {
		printf("%d:", i);
		for (j = 0;j < n;j++) {
			if (*blocks != -1) {
				printf(" %d", *blocks);
			}
			blocks++;
		}
		printf("\n");
	}
}

int main() {
	int i, j, n;
	char a[20];
	do {
		scanf("%d", &n);
	} while (n >= 25||n < 1);
	
	int blocks[n][n];
	for (i = 0;i < n;i++) {
		blocks[i][0] = i;
	}
	for (i = 0;i < n;i++) {
		for (j = 1;j < n;j++) {
			blocks[i][j] = -1;
		}
	}
	do {
		gets(a);
		robotCommand(a,&blocks[0][0],n,n);
	} while (strcmp(a,"quit") != 0);
	blocksShow(&blocks[0][0],n,n);
	return 0;
}
