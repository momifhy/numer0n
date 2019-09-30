#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

const int NUM = 4;

unsigned int get_digit(int num){
    return log10(num)+1;
}

unsigned int make_num(){
    int num = 0;
    int past[3];
    srand(time(NULL));
    for(int i=0; i<NUM-1; i++){
        int n;
        n = rand() % 10;
        std::cout << i << n << "\n";
        bool select = true;
        for(int j=0; j<i; j++){
            if(n == past[j]){
                select = false;
                break;
            }
        }
        if(select){
            num += n*(int)pow(10, NUM-i-2);
            past[i] = n;
        }else{
            i--;
            continue;
        }
    }
    return num;
}

int judge(const int ans, const int prediction, int *eat, int *bite){
    if(get_digit(prediction)!=NUM-1 && get_digit(prediction)!=NUM-2){
        std::cout << "put " << NUM-1 << " numbers\n";
        return 1;
    }else{
        for(int i=0; i<NUM-1; i++){
            if(prediction/(int)pow(10, i)%10 == ans/(int)pow(10, i)%10){
                (*eat)++;
            }else{
                for(int j=0; j<NUM-1; j++){
                    if(prediction/(int)pow(10, i)%10 == ans/(int)pow(10, j)%10){
                        (*bite)++;
                    }
                }
            }
        }
    }
    return 0;
}

int main(void){
    int ans = make_num();
    int try_count = 0;

    std::cout << ans << "\n";

    while(1){
        int eat = 0;
        int bite = 0;
        int prediction;
        std::cout << "please put your prediction\n";
        std::cin >> prediction;
        if(judge(ans, prediction, &eat, &bite)){continue;}
        try_count++;
        if(eat == NUM-1){
            std::cout << "correct! congratulations!\n" << "your score is " << try_count << " hands\n";
            return 0;
        }else{
            std::cout << eat << " EATS " << bite << " BITES\n";
        }
    }
}
