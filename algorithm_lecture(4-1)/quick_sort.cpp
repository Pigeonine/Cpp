#include <chrono>
#include <iostream>
#include <random>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;


int partition(int* arr, const int& p, const int& r)
{
    int x = arr[r], i = p - 1,j,temp;
    for(j = p; j < r; j++)
    {
        if(arr[j] <= x)
        {
            i++;
            temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    temp = arr[i+1]; arr[i+1] = arr[j]; arr[j] = temp;
    return i+1;
}

void qsort_last(int* arr, const int& p, const int& r)
{
    if(p < r)
    {
        int q = partition(arr, p, r);
        qsort_last(arr, p, q - 1);
        qsort_last(arr, q + 1, r);
    }
}

void qsort_rand(int* arr, const int& p, const int& r)
{
    if(p < r)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(p, r);
        int i = dis(gen),temp;
        temp = arr[i]; arr[i] = arr[p]; arr[p] = temp;
        int q = partition(arr, p, r);
        qsort_rand(arr, p, q - 1); qsort_rand(arr, q+1, r);
    }
}



int* quick_sort_rand_piv(int* arr, int n) {
    // implement your algorithm
    int* sorted = new int[n];
    for (size_t i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }
    qsort_rand(sorted, 0, n-1);
    return sorted;
}

int* quick_sort_last_piv(int* arr, int n) {
    // implement your algorithm
    int* sorted = new int[n];
    for (size_t i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }
    qsort_last(sorted, 0, n-1);
    return sorted;
}

int m;
int main() {
    fastio;
    cin >> m;
    int *arr = new int[m];
    for(int i = 0; i < m; i++) cin >> arr[i];

    int *sorted = quick_sort_rand_piv(arr, m);
    for(int i = 0; i < m; i++) cout << sorted[i] << "\n";

} 
