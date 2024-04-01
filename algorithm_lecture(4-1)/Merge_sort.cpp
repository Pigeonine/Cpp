#include <chrono>
#include <iostream>
#include <random>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int m;

int* merge_sort(int* arr, int n) {
    // implement your algorithm
    if(n == 1) return arr;
    int mid = (n-1)/2, *lsorted = new int[mid + 1], *rsorted = new int[n - mid - 1], i;
    for(i = 0; i <= mid; i++) lsorted[i] = arr[i];
    for(i = mid+1; i < n; i++) rsorted[i - mid - 1] = arr[i];
    merge_sort(lsorted, mid+1); merge_sort(rsorted, n - mid - 1);
    

}
int main() {
    fastio;
    cin >> m;
    cout << 0 << ' ' << (m-1)/2 << ' ' << m-1 << ' ' << (m-1)/2 + 1 << ' ' << m - 1 - (m-1)/2;
    //int* arrs = new int[m];
    //for(int i = 0; i < m; i++) cin >> arrs[i];

    //int* res = merge_sort(arrs, m);
    //for(int i = 0; i < m; i++) cout << res[i] << "\n";
}