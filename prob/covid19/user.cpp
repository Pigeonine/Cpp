static const int MAX_SAMPLE = 50000000;
extern int covid_checkup(int n);
extern void culture(int n, int a, int b);
extern void clear(int n);
void test(void) {
	for (int i = 0; i < MAX_SAMPLE; i++)
		if (covid_checkup(i)) clear(i);
}
