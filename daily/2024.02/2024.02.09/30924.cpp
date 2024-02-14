#include <bits/stdc++.h>
using namespace std;

bool a_arrs[10001]{};
bool b_arrs[10001]{};
int main() {
    int resp;
    // 시드값을 얻기 위한 random_device 생성.
    std::random_device rd;

    // random_device 를 통해 난수 생성 엔진을 초기화 한다.
    std::mt19937 gen(rd());

    // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
    std::uniform_int_distribution<int> dis(1, 10000);


   
    for(int i=1; i <=9999; i++){
        // A가 a인지 물어보고 flush를 한다.
        // endl은 자동으로 flush도 해준다.
        int a = dis(gen);
        while(a_arrs[a]) a = dis(gen);
        std::cout << "? A " << a << std::endl;
        a_arrs[a] = true;

        // 채점기의 답변을 입력받는다.
        std::cin >> resp;

        if(resp == 1){
            // 답변이 "예"이므로 A의 값은 a이다.
            // B의 값도 알아내야 하는데, 이 부분은 직접 채워보자.
            int resp_b;
            int b;
            for(int j = 1; j <= 9998; j++)
            {
                b = dis(gen);
                while(b_arrs[b]) b = dis(gen);
                cout << "? B " << b << endl;
                b_arrs[b] = true;
                std::cin >> resp_b;
                if(resp_b == 1){break;}
            }
            std::cout << "! " << a + b;
            break;
        }
    }
}