#include <iostream>
#include <iomanip>

using namespace std;

int main(){
   //initializing an array which will store f[k] as the value of fk for k=0 to k=26 
   double f[27];
    
    //probability that a configuration has payoff>=0 is 1
    f[0]=1;

    //loop for finding the values of f[k] where 0<=k<=26
    for(int k=1; k<=26; k++){
        f[k]=f[k-1]*((double)(26-k+1)/(double)(26+k));
    }

    //initializing array to store the probabilities where p[k]=probability that payoff=k
    double p[27];
    p[26]=f[26];

    //variable which stores the maximum probability
    double max_prob=0;
    //variable which stores the payoff for which probability is maximum
    int max_payoff;
    
    //loop for finding the values of p[k] where 0<=k<=26
    for(int k=0; k<=26; k++){
    if(k<26){
         p[k]=f[k]-f[k+1];  
    }
    else{
        p[k]=f[k];
    }
    cout<<" P(payoff ="<<k<<") = " <<p[k]<<endl;

    if(p[k]>max_prob){
        max_prob=p[k];
        max_payoff=k;
       }
    }

    //question 2.9
    cout<<"Most likely (one with the highest probability) payoff= "<<max_payoff<<endl;

    //question 2.10
    double expected_payoff=0;

    for(int k=0; k<=26; k++){
        expected_payoff+=(p[k]*k);
    }
    cout<<fixed<<setprecision(2);
    cout<<"Expected pay-off Of the game= "<<expected_payoff<<endl;
}