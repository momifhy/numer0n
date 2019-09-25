#include <iostream>

class Number{
    private:
        double first;
        double second;
        double third;
    public:
        Number(){
            init();
        }
        void init(){
            first = second = third = 100/30;
        }

        void zero_zero(int i, int rest){
            switch (i){
                case 0:
                    if(first != 0) first = 100/rest/3;
                    if(second != 0) second = 100/rest/3;
                    if(third != 0) third = 100/rest/3;
                    break;
                case 1:
                case 2:
                case 3: 
                    first = second = third = 0;
                    break;
                default: 
                    std::cout << "error: function zero_zero receive " << i << "\n";
                    exit(-1);
            }
        }

        void zero_one(int i, int rest){
            switch (i){
                case 0:

            }
        }
        // void this_eat(int i){
        //     switch (i){
        //     case 0:
        //         first += 100/3;
        //         break;
        //     case 1:
        //         second += 100/3;
        //         break;
        //     case 2:
        //         third += 100/3;
        //         break;
        //     default:
        //         std::cout << "error: function this_eat receive " << i << "\n";
        //         exit(-1);
        //     }
        // }

        // void this_bite(int i){
        //     switch (i){
        //     case 0:
        //         second += 50/3;
        //         third += 50/3;
        //         break;
        //     case 1:
        //         first += 50/3;
        //         third += 50/3;
        //         break;
        //     case 2:
        //         second += 50/3;
        //         first += 50/3;
        //         break;
        //     default:
        //         std::cout << "error: function this_bite receive " << i << "\n";
        //         exit(-1);
        //     }
        // }

        // void other_eat(int i){
        //     switch (i){
        //     case 0:
        //     case 1:
        //     case 2:
        //         first = second = third = 0;
        //         break;
        //     default:
        //         std::cout << "error: function other_eat receive " << i << "\n";
        //         exit(-1);
        //     }
        // }
};

int main(void){
    Number num[10];
    int exclution[7]  = {0};
    int exclution_num = 0;
}