#include <iostream>
using namespace std;

int main() {

// ========================WHILE LOOP=============================

    // int n, i =1;
    // cout << "enter the no: ";
    // cin>>n;
    // while(i<=n){
    //     cout << i << " ";
    //     // i = i + 1;
    //     i+=1;
    // }


    // sum of n natural no's:

    // int i=1,n,sum=0;
    // cout << "enter the number: ";
    // cin>> n;
    // while(i<=n){
    //     sum = sum + i;
    //     i +=1;
    // }
    // cout << sum;



    // Sum of even no's:

    // int i=2,n,sum=0;
    // cout << "enter the number: ";
    // cin>> n;
    // while(i<=n){
    //     sum += i;
    //     i+=2;
    // }
    // cout << sum;

    //printing the pattern:

    // int i = 1, n;

    // cout << "enter the number(rows): ";
    // cin>> n;

    // while(i<=n){
    //     int j = 1;
    //     while(j<=n){
    //         cout << '*';
    //         j+=1;
    //     }
    //     cout<<endl;
    //     i+=1;
    // }




// ========================FOR LOOP=============================

for (int i = 1;i<=15 ;i+=2){
    cout << i <<endl;
    if(i&1){//to check odd or even  last bit 1==odd ,  last bit 0 ==even (i&1 zero hoga to continue work)
        continue;
    }
    i+=1;

}
    
//MULTIPLE VARIABLES:

// for(int a =1,b=5; a<=5 && b>=1 ; a++,b--){
//     cout <<"success"<<endl;
// }


// CONTINUE STATEMENT:


// for(int i=0;i<=5;i++){
//     cout << "hi"<< endl;
//     cout << "hello"<< endl;
//     continue;
//     cout << "world"<< endl;

// }



    return 0;
}

