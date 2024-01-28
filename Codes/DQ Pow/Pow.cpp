int pow3(long long base, int index, int mod = 10) {
    long long r = 1;
    while (index != 0) {
        if (index & 1) r = (r * base) % mod;
        base = (base * base) % mod;
        index >>= 1;
    }
    return r;
}