
#include <iostream>
using namespace std;


int main(){
/*
1).PRINT THIS PATTERN:
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
*/
    // int n, i = 1;
    // cout << "enter the number: ";
    // cin>>n;
    // while(i<=n){
    //     int j = 1;
    //     while(j<=n){
    //         cout << j;
    //         j+=1;
    //     }
    //     cout<< endl;
    //     i+=1;
    // }








/*
2).PRINT THIS PATTERN:
4 3 2 1
4 3 2 1
4 3 2 1
4 3 2 1
*/

//METHOD#01
    // int n, i = 1;
    // cout << "enter the number: ";
    // cin>>n;
    // while(i<=n){
    //     int j = n;
    //     while(j>=1){
    //         cout << j;
    //         j-=1;
    //     }
    //     cout<< endl;
    //     i+=1;
    // }
//METHOD#02

    // int n, i = 1;
    // cout << "enter the number: ";
    // cin>>n;
    // while(i<=n){
    //     int j = 1;
    //     while(n-j+1 !=0){//n-j+1 == 4-1+1==4,   4-2+1==3,  4-3+1==2,  4-4+1===1
    //         cout << n-j+1;
    //         j+=1;
    //     }
    //     cout<< endl;
    //     i+=1;
    // }





//3).PRINT THIS PATTERN:
/*
1 2 3
4 5 6 
7 8 9
*/
    // int n, i = 1;
    // int count = 1;
    // cout << "enter the number: ";
    // cin>>n;
    // while(i<=n){
    //     int j = 1;
    //     while(j<=n){
    //         cout << count <<" ";
    //         count +=1;
    //         j+=1;
    //     }
    //     cout<< endl;
    //     i+=1;
    // }



//4).PRINT THIS PATTERN:
/*
*
* *
* * *
* * * *
* * * * *
*/

    // int row = 1, num;
    // cout<<"enter the number: ";
    // cin>>num;
    // while(row<=num){//1 to num tk chalana h
    //     int col = 1;
    //     while(col<=row){
    //         cout<<'*';
    //         col +=1;
    //     }
    //     cout<<endl;
    //     row+=1;
    // }




//5).PRINT THIS PATTERN:
/*
        *
      * *
    * * *
  * * * *
* * * * *
*/

    // int row = 1, num;
    // cout<<"enter the number: ";
    // cin>>num;

    // while(row<=num){//1 to num tk chalana h
    //     int space = num - row;
    //     while(space){
    //         cout<< " ";
    //         space-=1;
    //     }


    //     //to print stars:
    //     int col = 1;
    //     while(col<=row){
    //         cout<<'*';
    //         col +=1;
    //     }
    //     cout<<endl;
    //     row+=1;
    // }





//6).PRINT THIS PATTERN:
/*
* * * * *
  * * * *
    * * *
      * *
        *
*/

    // int row = 1, num;
    // cout<<"enter the number: ";
    // cin>>num;

    // while(row<=num){//1 to num tk chalana h
    //     int space = row - 1;
    //     while(space){
    //         cout<< " ";
    //         space-=1;
    //     }


    //     //to print stars:
    //     int col = 1;
    //     while(col<=num - row + 1){//num -1 +1== num--->5,   num-2+1==num-1-->4,   num-3+1==num-2--->3
    //         cout<<'*';
    //         col +=1;
    //     }
    //     cout<<endl;
    //     row+=1;
    // }






//5).PRINT THIS PATTERN:
/*
        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *
*/

    int row = 1, num;
    cout<<"enter the number: ";
    cin>>num;

    while(row<=num){//1 to num tk chalana h

        //printing space:
        int space = num - row;
        while(space){
            cout<< " ";
            space-=1;
        }


        //to print 1st triangle:
        int col = 1;
        while(col<=row){
            cout<< '*';
            col +=1;
        }

        //to print 2nd triangle:
        int row1 = row -1;
        while(row1){
            cout<<'*';
            row1--;
        }


        cout<<endl;
        row+=1;
    }


    return 0;
}