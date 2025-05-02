#include <stdio.h>
#include <string.h>
#include <time.h>

#define TC (1)

extern void test(unsigned char* BITMAP, unsigned char* FREQ);
extern void comp(unsigned char* FREQ, unsigned char* COMP);
extern void decomp(unsigned char* COMP, unsigned char* FREQ);

static unsigned int random(void) {// 랜덤 값 생성 
	static unsigned long long seed = 70;
	return ((unsigned int)((seed = seed * 25214903917ULL + 11ULL) >> 16));
}

static void clear(unsigned char* FREQ) {//모든 배열 0으로 초기화 
	for (int c = 0; c < 1000000; ++c) FREQ[c] = 0;
}

static int count(unsigned char* BITMAP, int y, int x) {// x,y가 0~6000 사이가 아니면 -1 return --
	if ((0 <= y && y <= 5999) == 0) return -1;
	if ((0 <= x && x <= 5999) == 0) return -1;

	unsigned char mask = 0x80 >> (x & 0x7); // x를 8로 나눈 나머지 만큼 128을 shift(2^(7-x%8))
	y = y * (6000 / 8); // 750
	x = x / 8;
	if ((BITMAP[y + x] & mask) == mask) return 1;//mask와 동일한 비트 가질 경우(1/2)
	else return 0;
}

static void add(unsigned char* FREQ, int y, int x) {
	if ((0 <= y && y <= 5999) == 0) return;
	if ((0 <= x && x <= 5999) == 0) return;
	y = y / 6 * 1000;
	x = x / 6;
	FREQ[y + x]++;
}

static void sample(unsigned char* BITMAP, unsigned char* FREQ) {//count 맞을경우 add 진행
	for (int y = 0; y < 6000; ++y) {
		for (int x = 0; x < 6000; ++x) {
			if (count(BITMAP, y, x) == 1) add(FREQ, y, x);
		}
	}
}

static void process1(unsigned char* FREQ) {// 
	for (int y = 0; y < 1000; ++y) {
		for (int x = 0; x < 500; ++x) {
			unsigned char tmp = FREQ[y * 1000 + x];
			FREQ[y * 1000 + x] = FREQ[y * 1000 + (999 - x)];
			FREQ[y * 1000 + (999 - x)] = tmp;
		}
	}
}

static void process2(unsigned char* FREQ) {
	for (int y = 0; y < 500; ++y) {
		for (int x = 0; x < 1000; ++x) {
			unsigned char tmp = FREQ[y * 1000 + x];
			FREQ[y * 1000 + x] = FREQ[(999 - y) * 1000 + x];
			FREQ[(999 - y) * 1000 + x] = tmp;
		}
	}
}

static void process3(unsigned char* FREQ) {
	for (int y = 0; y < 1000; ++y) {
		for (int x = 0; x < 1000; ++x) {
			FREQ[y * 1000 + x] += 'J';
		}
	}
}


static void build(unsigned char* BITMAP, unsigned char* FREQ) {
	clear(FREQ);
	sample(BITMAP, FREQ);
	process1(FREQ);
	process2(FREQ);
	process3(FREQ);
}

int main() {
	static unsigned char BITMAP[4500000];
	static unsigned char FREQ1[4500000];
	static unsigned char FREQ2[4500000];
	static unsigned char FREQ3[4500000];
	static unsigned char COMP1[4500000];
	static unsigned char COMP2[4500000];

	int SCORE = 30000000 * TC;
	for (int tc = 0; tc < TC; ++tc) {
		for (int c = 0; c < 4500000; ++c) BITMAP[c] = random();
		build(BITMAP, FREQ1);
		time_t begin = clock();
		test(BITMAP, FREQ2);
		for(int i = 0; i < 1000000; ++i) printf("%d\n", FREQ1[i]);
		comp(FREQ2, COMP1);
		memcpy(COMP2, COMP1, 700000);
		decomp(COMP2, FREQ3);
		SCORE += ((clock() - begin) / (CLOCKS_PER_SEC / 1000));

		if (memcmp(FREQ1, FREQ2, 1000000) == 0) SCORE -= 20000000;
		if (memcmp(FREQ1, FREQ3, 1000000) == 0) SCORE -= 10000000;
	}
	printf("SCORE :: %d\n", SCORE);
	return 0;
}
