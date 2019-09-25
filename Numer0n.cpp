#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main(void){
    const int NUM = 4;
    string ans;
    int try_count = 0;
    srand(time(NULL));

    // 回答生成
    for(int i=0; i<NUM-1; i++){
        int n;
        n = rand() % 10;
        string s = to_string(n);
        bool select = true;
        for(int j=0; j<i; j++){
            if(ans[j] == s[0]){
                i--;
                select = false;
            }
        }
        if(select){
            ans += s;
        }else{
            continue;
        }
    }

    cout << ans;

    while (1){
        int eat = 0;
        int bite = 0;
        string prediction;
        cout << "please put your prediction\n";
        cin >> prediction;

        // 照合処理
        if(prediction.length() != NUM-1){
            cout << "put " << NUM-1 << " numbers\n";
            continue;
        }else{
            for(int i=0; i<NUM-1; i++){
                if(prediction[i] == ans[i]){
                    eat++;
                }else{
                    for(int j=0; j<NUM-1; j++){
                        if(prediction[i] == ans[j]){
                            bite++;
                        }
                    }
                }
            }
        }

        try_count++;
        if(eat == NUM-1){
            cout << "correct! congratulations!\n" << "your score is " << try_count << " hands\n";
            return 0;
        }else{
            cout << eat << " EATS " << bite << " BITES\n";
        }
    }
}