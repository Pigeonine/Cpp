#include <stdio.h>
#include <time.h>

static unsigned char dummy[2560];
static unsigned char KEY[200];
static unsigned char dummy2[2560];
static unsigned int seed = 3;
static unsigned char dummy3[2560];
extern void test(unsigned char key[200]);

int rand() {
	seed = seed * 214011 + 2531011;
	return (seed >> 16) & 0x7FFF;
}

int count;
int check(unsigned char key[200]) {
	count++;
	int equal = 0, pos = 0;
	for (register int i = 0; i < 200; i++) {//같은 위치 같은 값일때 pos++
		if (key[i] == KEY[i]) {
			pos += 1;
		}
	}
	for (register int i = 0; i < 200; i++) {
		for (register int j = 0; j < 200; j++) {//같은+다른 위치 같은 값이면 equal++
			if (key[i] == KEY[j]) {
				equal += 1;
			}
		}
	}
	return pos * 256 + equal;
}

void makeKey() {
	unsigned int pool[256] = { 0 };
	int idx;
	for (register int i = 0; i < 200; i++) {
		KEY[i] = 0;
	}
	for (register int i = 0; i < 200; i++) {
		idx = rand() % 255;
		while (pool[idx] != 0) {
			idx = rand() % 255;
		}
		KEY[i] = idx + 1; // 1~255 값중 랜덤 배정해서 key에 할당
		pool[idx] = 1;
		// printf("%d %d\n", KEY[i], i);
	}
}
int main() {
	int PENALTY = 0;
	for (register int i = 0; i < 50; i++) {
		count = 0;
		unsigned char key[200] = { 0 };
		makeKey();
		clock_t t0 = clock();
		test(key);
		PENALTY += (clock() - t0) / (CLOCKS_PER_SEC / 1000);
		for (register int j = 0; j < 200; j++) {
			if (key[j] != KEY[j]) {
				PENALTY += 10000;
				printf("penalty!!!!!!! %d %d %d\n", j , key[j], KEY[j]);
			}
		}
	}
	printf("PENALTY: %d\n", PENALTY);
	return 1;
}
