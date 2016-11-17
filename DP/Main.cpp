#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
int n, coin[101], k, cache[10001] = {0,};
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}

	cache[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j >= coin[i]) {
				cache[j] += cache[j - coin[i]];
			}
		}
	}

	printf("%d",cache[k]);
}