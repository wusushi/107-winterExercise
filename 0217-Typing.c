#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//2015 ACM-ICPC Taiwan Online Programming Contest  --  Promblem C-Typing

int MyStrstr(char temp[], char copy[], int Ncpy) {
	int i, j, n = 0, same = 0;
	for (i = 0;i < strlen(temp);i++) {
		same = 0;
		if (temp[i] == copy[same]) {
			for (j = 0;j < strlen(copy);j++) {
				if (temp[i + j] != copy[same + j]) {
					break;
				}
			}
			if (j == strlen(copy)) {
				n++;
			}
		}
	}
	return n;
}

void dataTyping(char strs[][10000], char strscpy[][100], int n) {
	int i;
	int seconds[n];
	char *temp;
	for (i = 0;i < n;i++) {
		seconds[i] = 0;
		seconds[i] = strlen(*(strs + i)) - MyStrstr(*(strs + i),*(strscpy + i), 10000) * (strlen(*(strscpy + i)) - 1);
		printf("%d\n", seconds[i]);
	}
}

int main() {
	int i, sum, n;
	int bottles[9];
	scanf("%d", &n);
	char strs[n][10000];
	char strscpy[n][100];
	for (i = 0;i < n;i++) {
		scanf("%s %s", &strs[i] ,&strscpy[i]);
	}
	dataTyping(strs, strscpy, n);
	return 0;
}
