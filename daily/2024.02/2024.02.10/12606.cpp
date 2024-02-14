#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)

using namespace std;

int main() {
    fastio;
    int n; cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++)
    {
        // 공백 분리할 문자열 선언
        string s;
        getline(cin, s);
        // 문자열을 스트림화
        stringstream ss(s);

        // 공백 분리 결과를 저장할 배열
        stack<string> st;

        string word;
        // 스트림을 한 줄씩 읽어, 공백 단위로 분리한 뒤, 결과 배열에 저장
        while (getline(ss, word, ' ')){
            st.push(word);
        }
        cout << "Case #" << i << ": ";
        while(!st.empty())
        {
            string temp = st.top();
            st.pop();
            cout << temp << ' ';
        }
        cout << "\n";
    }
    
}