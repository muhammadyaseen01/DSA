#include <iostream>
using namespace std;
// QUESTION#01: subtract product and sum of digits (product - sum)

int main(){

    int n, product = 1, sum =0;
    cout << "enter the number: ";
    cin>>n;
    while(n!=0){
        int digit = n%10; //234 ka 10 se modulus --> 4   , 23%10-->3,   2%10-->2
        product = product * digit;
        sum = sum + digit;

        n = n/10;
    }
    int answer = product - sum;
    cout << answer;
    
}
