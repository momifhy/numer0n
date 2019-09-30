#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

const int NUM = 4;

class Number{
    private:
        int left;
        int center;
        int right;
    public:
        Number(){
            init();
        }
        void init(){
            left = center = right = 1;
        }

        int get_left(){
            return left;
        }
        int get_center(){
            return center;
        }
        int get_right(){
            return right;
        }

        void zero_zero(int i){
            switch (i){
                case 0:
                    break;
                case 1:
                case 2:
                case 3:
                    left = center = right = 0;
                    break;
                default:
                    std::cout << "error: function zero_zero receive " << i << "\n";
                    exit(-1);
            }
        }

        void zero_one(int i){
            switch (i){
                case 0:
                    break;
                case 1:
                    left = 0;
                    break;
                case 2:
                    center = 0;
                    break;
                case 3:
                    right = 0;
                    break;
                default:
                    std::cout << "error: function zero_one receive " << i << "\n";
                    exit(-1);
            }
        }

        void zero_two(int i){
            switch (i){
                case 0:
                    break;
                case 1:
                    left = 0;
                    break;
                case 2:
                    center = 0;
                    break;
                case 3:
                    right = 0;
                    break;
                default:
                    std::cout << "error: function zero_two receive " << i << "\n";
                    exit(-1);
            }
        }

        void zero_three(int i){
            switch (i){
                case 0:
                    left = center = right = 0;
                    break;
                case 1:
                    left = 0;
                    break;
                case 2:
                    center = 0;
                    break;
                case 3:
                    right = 0;
                    break;
                default:
                    std::cout << "error: function zero_three receive " << i << "\n";
                    exit(-1);
            }
        }

        void one_zero(int i){
            switch(i){
                case 0:
                    break;
                case 1:
                    center = right = 0;
                    break;
                case 2:
                    right = left = 0;
                    break;
                case 3:
                    left = center = 0;
                    break;
                default:
                    std::cout << "error: function one_zero receive " << i << "\n";
                    exit(-1);
            }
        }

        void one_one(int i){
            switch(i){
                case 0:
                case 1:
                case 2:
                case 3:
                    break;
                default:
                    std::cout << "error: function one_one receive " << i << "\n";
                    exit(-1);
            }
        }

        void one_two(int i){
            switch(i){
                case 0:
                    left = center = right = 0;
                    break;
                case 1:
                case 2:
                case 3:
                    break;
                default:
                    std::cout << "error: function one_two receive " << i << "\n";
                    exit(-1);
            }
        }

        void two_zero(int i){
            switch(i){
                case 0:
                    break;
                case 1:
                    center = right = 0;
                    break;
                case 2:
                    right = left = 0;
                    break;
                case 3:
                    left = center = 0;
                    break;
                default:
                    std::cout << "error: function two_zero receive " << i << "\n";
                    exit(-1);
            }
        }
};

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

int make_prediction(Number num[10]){
    // string place[3] = {"left", "center", "right"};
    int prediction;
    int past[3];
    srand(time(NULL));
    for(int i=0; i<NUM-1; i++){
        int n;
        n = rand() % 10;
        bool select = true;
        if(/*!num[n].place[i]*/ (i==0&&num[n].get_left()==0) || (i==1&&num[n].get_center()==0) || (i==2&&num[n].get_right()==0)){
            select = false;
        }else{
            for(int j=0; j<i; j++){
                if(n == past[j]){
                    select = false;
                    break;
                }
            }
        }
        if(select){
            prediction += n*(int)pow(10, NUM-i-2);
            past[i] = n;
        }else{
            i--;
            continue;
        }
    }
    return prediction;
}

int check_cover(int num, int array[], int count){
    for(int i=0; i<count; i++){
        if(num == array[count]){
            return 1;
        }
    }
    return 0;
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

void do_zero_zero(Number num[10], int prediction){
    for(int i=0; i<10; i++){
        if(i == prediction/100){
            num[i].zero_zero(1);
        }else if(i == prediction/10%10){
            num[i].zero_zero(2);
        }else if(i == prediction%10){
            num[i].zero_zero(3);
        }else{
            num[i].zero_zero(0);
        }
    }
}
void do_zero_one(Number num[10], int prediction){
    for(int i=0; i<10; i++){
        if(i == prediction/100){
            num[i].zero_one(1);
        }else if(i == prediction/10%10){
            num[i].zero_one(2);
        }else if(i == prediction%10){
            num[i].zero_one(3);
        }else{
            num[i].zero_one(0);
        }
    }
}
void do_zero_two(Number num[10], int prediction){
    for(int i=0; i<10; i++){
        if(i == prediction/100){
            num[i].zero_two(1);
        }else if(i == prediction/10%10){
            num[i].zero_two(2);
        }else if(i == prediction%10){
            num[i].zero_two(3);
        }else{
            num[i].zero_two(0);
        }
    }
}
void do_zero_three(Number num[10], int prediction){
    for(int i=0; i<10; i++){
        if(i == prediction/100){
            num[i].zero_three(1);
        }else if(i == prediction/10%10){
            num[i].zero_three(2);
        }else if(i == prediction%10){
            num[i].zero_three(3);
        }else{
            num[i].zero_three(0);
        }
    }
}
void do_one_zero(Number num[10], int prediction){
    for(int i=0; i<10; i++){
        if(i == prediction/100){
            num[i].one_zero(1);
        }else if(i == prediction/10%10){
            num[i].one_zero(2);
        }else if(i == prediction%10){
            num[i].one_zero(3);
        }else{
            num[i].one_zero(0);
        }
    }
}
void do_one_one(Number num[10], int prediction){
    for(int i=0; i<10; i++){
        if(i == prediction/100){
            num[i].one_one(1);
        }else if(i == prediction/10%10){
            num[i].one_one(2);
        }else if(i == prediction%10){
            num[i].one_one(3);
        }else{
            num[i].one_one(0);
        }
    }
}
void do_one_two(Number num[10], int prediction){
    for(int i=0; i<10; i++){
        if(i == prediction/100){
            num[i].one_two(1);
        }else if(i == prediction/10%10){
            num[i].one_two(2);
        }else if(i == prediction%10){
            num[i].one_two(3);
        }else{
            num[i].one_two(0);
        }
    }
}
void do_two_zero(Number num[10], int prediction){
    for(int i=0; i<10; i++){
        if(i == prediction/100){
            num[i].two_zero(1);
        }else if(i == prediction/10%10){
            num[i].two_zero(2);
        }else if(i == prediction%10){
            num[i].two_zero(3);
        }else{
            num[i].two_zero(0);
        }
    }
}

void do_process(Number num[10], int prediction, int eat, int bite){
    if(eat == 0){
        if(bite == 0){
            do_zero_zero(num, prediction);
        }else if(bite == 1){
            do_zero_one(num, prediction);
        }else if(bite == 2){
            do_zero_two(num, prediction);
        }else if(bite == 3){
            do_zero_three(num, prediction);
        }else{
            std::cout << "error: function do_process recieve " << bite << " as bite in eat == 0 pane\n";
        }
    }else if(eat == 1){
        if(bite == 0){
            do_one_zero(num, prediction);
        }else if(bite == 1){
            do_one_one(num, prediction);
        }else if(bite == 2){
            do_one_two(num, prediction);
        }else{
            std::cout << "error: function do_process recieve " << bite << " as bite in eat == 1 pane\n";
        }
    }else if(eat == 2){
        if(bite == 0){
            do_two_zero(num, prediction);
        }else{
            std::cout << "error: function do_process recieve " << bite << " as bite in eat == 2 pane\n";
        }
    }else{
        std::cout << "error: function do_process recieve " << eat << " as eat\n";
    }
}

int main(void){
    Number num[10];
    int past[720];
    int try_count = 0;
    int ans = make_num();

    std::cout << "ans:" << ans << "\n";

    for(int i=0; i<720; i++){
        int eat = 0;
        int bite = 0;
        int prediction = make_prediction(num);
        std::cout << prediction << "\n";
        if(check_cover(prediction, past, try_count) || judge(ans, prediction, &eat, &bite)){
            i--;
            continue;
        }
        try_count++;
        if(eat == NUM-1){
            std::cout << "correct! congratulations!\n" << "this ai's score is " << try_count << " hands\n";
            return 0;
        }else{
            std::cout << eat << " EATS " << bite << " BITES\n";
            do_process(num, prediction, eat, bite);
            past[try_count] = prediction;
        }
    }

}
