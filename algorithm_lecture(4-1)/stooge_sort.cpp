#include <chrono>
#include <iostream>
#include <random>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

void ssort(int* arr, int p, int r)
{
    if(arr[p] > arr[r]) 
    {
        int temp = arr[r]; arr[r] = arr[p]; arr[p] = temp;
    }
    if( p + 1 < r)
    {
        int k = (r-p+1)/3;
        ssort(arr,p,r-k);
        ssort(arr,p+k,r);
        ssort(arr,p,r-k);
    }
}

int* stooge_sort(int* arr, int n) {
    int* sorted = new int[n];
    for (size_t i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }
    // implement your algorithm
    ssort(sorted, 0,n-1);

    return sorted;
}

int m;
int main() {
    fastio;
    cin >> m;
    int *arr = new int[m];
    for(int i = 0; i < m; i++) cin >> arr[i];

    int *sorted = stooge_sort(arr, m);
    for(int i = 0; i < m; i++) cout << sorted[i] << "\n";

} 
