#include <chrono>
#include <iostream>
#include <random>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

void max_heapify(int* arr, const int& n, const int& i)
{
    long long l,r;
    int temp, largest = i;
    l = 2 * i; r = l + 1;
    if(l <= n)
        if(arr[l] > arr[i]) largest = l;
    
    if(r <= n)
        if(arr[r] > arr[largest]) largest = r;

    if(largest != i)
    {
        temp = arr[i]; arr[i] = arr[largest]; arr[largest] = temp;
        max_heapify(arr, n, largest);
    }   
}

void build_max_heap(int*arr, const int& n)
{
    int i;
    for(i = n/2; i >= 1; i--)
        max_heapify(arr, n, i);
}

int* heap_sort(int* arr, int n) {
    int* sorted = new int[n+1];
    int i,temp;
    for (i = 1; i <= n; i++) {
        sorted[i] = arr[i-1];
    }
    build_max_heap(sorted, n);
    for(i = n; i >= 2; i--)
    {
        temp = sorted[i]; sorted[i] = sorted[1]; sorted[1] = temp;
        max_heapify(sorted, --n, 1);
    }
    // implement your algorithm

    return sorted+1;
}

int m;
int main() {
    fastio;
    cin >> m;
    int *arr = new int[m];
    for(int i = 0; i < m; i++) cin >> arr[i];

    int *sorted = heap_sort(arr, m);
    for(int i = 0; i < m; i++) cout << sorted[i] << "\n";

} 
