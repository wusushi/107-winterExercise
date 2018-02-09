#include <stdio.h>
#include <stdlib.h>
//2015 ACM-ICPC Taiwan Online Programming Contest  --  Promblem A-Horns

void dataSpilt(int horn[], int beast[], int n) {
	int i;
	for (i = 0;i < n;i++) {
		printf("%d %d\n", beast[i] - (horn[i]-beast[i]), horn[i]-beast[i]);
	}
}

void dataTest(int n) {
	int i, j, k;
	int horn[n], beast[n];
	for (i = 0;i < n;i++) {
		do {
			scanf("%d %d", &horn[i], &beast[i]);
		} while (horn[i] > 300||horn[i] < 1||horn[i] < beast[i]||horn[i] > 2*beast[i]);
	}
	printf("\n\n");
	dataSpilt(horn,beast,n);
}

int main() {
	int n;
	do {
		scanf("%d", &n);
	} while (n > 25);
	dataTest(n);
	return 0;
}
