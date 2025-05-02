static void clear(unsigned char* FREQ) {//모든 배열 0으로 초기화 
	for (int c = 0; c < 1000000; ++c) FREQ[c] = 0;
}

static int count(unsigned char* BITMAP, int y, int x) {// x,y가 0~6000 사이가 아니면 -1 return --
	if ((0 <= y && y <= 5999) == 0) return -1;
	if ((0 <= x && x <= 5999) == 0) return -1;

	unsigned char mask = 0x80 >> (x & 0x7); // x를 8로 나눈 나머지 만큼 128을 shift(2^(7-x%8))
	y = y * (6000 / 8); // 750
	x = x / 8;
	if ((BITMAP[y + x] & mask) == mask) return 1;//mask와 같은 값이면 1
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
static void rev_process3(unsigned char* FREQ) {
	for (int y = 0; y < 1000; ++y) {
		for (int x = 0; x < 1000; ++x) {
			FREQ[y * 1000 + x] -= 76;
		}
	}
}

void test(unsigned char* BITMAP, unsigned char* FREQ){
    clear(FREQ);
	sample(BITMAP, FREQ);
	process1(FREQ);
	process2(FREQ);
	process3(FREQ);
}

void bit_packing(unsigned char* FREQ, unsigned char* COMP, int freq_count){
	
}


void comp(unsigned char* FREQ, unsigned char* COMP){
	rev_process3(FREQ);

}
void decomp(unsigned char* COMP, unsigned char* FREQ){}
