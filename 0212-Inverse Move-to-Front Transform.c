#include <stdio.h>
#include <stdlib.h>
//2015 ACM-ICPC Taiwan Online Programming Contest  --  Promblem B-Inverse Move-to-Front Transform

void dataPrint(char a[], int numbers[], int d) {
	int i, j = 0, k, post, max = 0, zero = 0, repeat = 0, reset = 0;
	while (j < d) {
		printf("\n");
		max = zero = repeat = reset = 0;
		for (i = (j + 1);i <= (j + numbers[j]);i++) {
			if (numbers[i] > max) {
				a[i] = 'a' + numbers[i];
				max = numbers[i];
			}
			else if ((reset - zero - repeat) == numbers[i]) {
				a[i] = 'a' - (reset - zero - repeat) + numbers[i];
			}
			else if ((reset - zero - repeat) < numbers[i]){
				a[i] = 'a' - (reset - zero - repeat) + numbers[i] + 1;
			}
			else {
				a[i] = a[i - 1 - numbers[i] - zero];
			}
			printf("%c", a[i]);
			if (numbers[i] == 0) {
				zero++;
			}
			for (k = (j + 1);k <= (reset + j);k++) {
				if (numbers[k] == numbers[i]) {
					repeat++;
					break;
				}
			}
			reset++;
		}
		j = i;
	}
}

void dataTest(int n) {
	int i = 0, d, j = n;
	int numbers[n*25];
	char strs[n*25];
	for (d = 0;d < (n * 25);d++) {
		strs[d] = '0';
	}
	while (n != 0) {
		do {
			scanf("%d", &numbers[i]);
		} while (numbers[i] > 100||numbers[i] < 1);
		strs[i] = 'A';
		for (j = 1;j <= numbers[i];j++) {
			scanf("%d", &numbers[i+j]);
		}
		i = i + j;
		n--;
	}
	printf("\n\n");
	dataPrint(strs,numbers,i);
}

int main() {
	int n;
	do {
		scanf("%d", &n);
	} while (n > 50);
	dataTest(n);
	return 0;
}
