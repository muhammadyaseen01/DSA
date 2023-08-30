// #include<iostream>
// using namespace std;

// int power(int a,int b){   //2^3---> 2 * 2 * 2
//     int ans = 1;
//     for (int i = 1; i <= b; i++ ){
//         ans = ans * a;  //1 * 2 =2,   2 * 2=4,   4 * 2=8
//     }
//     cout<< ans<<endl;
// }

// int main(){

//     int a,b,n;
//     // cout<< " enter a: ";
//     // cin>>a;
//     // cout << "enter b: ";
//     // cin>>b;
//     cout<<"enter how many number you to power them: ";
//     cin>>n;
//     for (int i = 1;i<=n;i++){
//         cout<< "enter a: ";
//         cin>>a;
//         cout << "enter b: ";
//         cin>>b;
//         power(a,b);
//     }
//     return 0;
// }




// #include <iostream>
// using namespace std;

// int update(int a){
//     a-=5;
//     return a; // a ki copy banai or usse change krdia lakin jab func end hoya wo wo copy bhi khatam
// }

// int main(){
//     int a = 15;
//     update(a);
//     cout<<a<<endl;
// }


#include <iostream>
using namespace std;

int update(int a){
    int ans = a * a;
    return ans;
}

int main(){
    int a = 12;
    a = update(a);//jo function return kr rha wo a me save hogyi to a change hogya ab main me hi
    cout << a << endl;
}