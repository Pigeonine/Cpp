#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    string fir, sec, thi; cin >> fir >> sec >> thi;
    int res;
    if(fir != "Fizz" && fir != "Buzz" && fir != "FizzBuzz")
        res = stoi(fir) + 3;
    else if(sec != "Fizz" && sec != "Buzz" && sec != "FizzBuzz")
        res = stoi(sec) + 2;
    else if(thi != "Fizz" && thi != "Buzz" && thi != "FizzBuzz")
        res = stoi(thi) + 1;
    
    if(res % 15 == 0) cout << "FizzBuzz";
    else if(res % 5 == 0) cout << "Buzz";
    else if(res % 3 == 0) cout << "Fizz";
    else cout << res;
}