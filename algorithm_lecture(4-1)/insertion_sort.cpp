#include <chrono>
#include <iostream>
#include <random>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int m;

int* insertion_sort(int* arr, int n) {
    int* sorted = new int[n];
    for (size_t i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }
    int i, key, j;
    for(i = 1; i < n; i++)
    {
        key = sorted[i];
        j = i - 1;
        while(j >= 0 && sorted[j] > key)
        {
            sorted[j+1] = sorted[j];
            j = j-1;
        }
        sorted[j+1] = key;
    }
    return sorted;
}

int main() {
    fastio;
    cin >> m;
    int* arrs = new int[m];
    for(int i = 0; i < m; i++) cin >> arrs[i];

    int* res = insertion_sort(arrs, m);
    for(int i = 0; i < m; i++) cout << res[i] << "\n";
}