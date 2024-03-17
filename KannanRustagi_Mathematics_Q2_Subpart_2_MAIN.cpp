#include <iostream>

using namespace std;

int main(){
    int cnt_ways=0;
    //initializing the total payoff of all the configurations
    int total_payoff=0;
    //card_i represents the position of ith red card for i=1 to i=4
    //to prevent overcounting I have used 4 nested for loops such that card_i is placed only after all previous i-1 cards have been placed
    for(int card_1=1;card_1<=5; card_1++){
        for(int card_2=card_1+1; card_2<=6; card_2++){
            for(int card_3=card_2+1; card_3<=7; card_3++){
                for(int card_4=card_3+1; card_4<=8; card_4++){
                    //now after all the cards have been placed for a particular configuration, we need to calculate the maximum payoff possible
                    int pay=0;
                    int payoff=0;
                    cnt_ways++;
                    //iterating through all the cards
                    for(int m=1; m<=8; m++){
                        //whenever I counter a red card, I increase my pay by 1 else I have encountered a black card and I decrease it by 1
                        if(m==card_1|| m==card_2 || m==card_3 || m==card_4){
                            pay++;
                        }
                        else{
                            pay--;
                        }
                        //my payoff would be the maximum of my current pay and my previous maximum payoff 
                        payoff=max(pay, payoff);
                    }
                    total_payoff+=payoff;
                }
            }
        }
    }

    cout<<"Number of possible configurations: "<<cnt_ways<<endl;
    cout<<"Expected payoff: "<<double(total_payoff)/double(cnt_ways);
}