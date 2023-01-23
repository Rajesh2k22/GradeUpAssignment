#include<bits/stdc++.h>
using namespace std;

void printIntroMenu();
void printMainMenu();
void login();
void createAccount();
void deposite(int &, string &);
void Balance(int &, string &);
void withdraw(int & , string &);



char menuInput; // global Varible for taking menuinput.

map<pair<int, string>, int >  authenticationChecker; // Map data structure for the authenticationChecker
vector<int> accountBalance; // store the Balance of All Account Holder.


//function for Print the Menu List:-
void printIntroMenu(){

    cout<<"Please select an option from the menu below:-\n";
    cout<<"Press Key 'l' For LOGIN\n";
    cout<<"Press Key 'c' For CREATE ACCOUNT\n";
    cout<<"Press Key 'q' For QUITE\n";

}

// Print the Main Menu List
void printMainMenu(){

    cout<<"Please select an option from the menu below:-\n";
    cout<<"Press Key 'd' For Deposit Money\n";
    cout<<"Press Key 'w' For Withdraw Money\n";
    cout<<"Press Key 'r' For Request Balance\n";
    cout<<"Press Key 'q' For QUITE\n";
}

// deposite function helps to deposite the Amount(>0) in specific Account.   
void deposite(int  & id, string & password){


     cout<<"Amount to be deposite $ ";

     int amount=0;

     cin>>amount;

     cout<<endl;

     if(amount>0){

        int index= authenticationChecker[{id, password}];

        accountBalance[index]+=amount;

     }else{

        cout<<"Amount should not be less than or Equal to zero.\n";

       


     }


}

// Balance function for checking the Balance in specific Account.

void Balance(int  & id, string & password){


      cout<<"Balance in your Account $ ";

      int index= authenticationChecker[{id, password}];

      cout<<accountBalance[index]<<endl;

}

// withdraw function for withdraw the money from account.

void withdraw(int & id, string & password){


    cout<<"Amount to be withdraw $ ";

     

     int amount=0;

     cin>>amount;
     
     int index= authenticationChecker[{id, password}];

     if(amount>0 and accountBalance[index] >= amount){

        accountBalance[index]-=amount;

     }else if(accountBalance[index] <amount){

        
      cout<<"Account Balance is less than Withdraw Money \n";

      

     }else{

        cout<<"Amount should not be less than or Equal to zero.\n";

        withdraw(id, password);


     }
}

// AccountWork function handle all the work related to user request.
void AcountWork(int & id, string & password){

    while(true){

        printMainMenu();

        cin>>menuInput;

        switch(menuInput)
    {
       
        case 'd': 
            deposite(id, password);
            break;
        case 'w':
            withdraw(id, password);
            break;
        case 'r':
            Balance(id, password);
            break;
        case 'q':
            return ;
           

        default:
            cout<<"INVALID INPUT";
            break;
            

    }


    }
}

// login() function for the login in the existing Account.

void login(){

    int id;
    string password;

    cout<<"Please Enter the user Id:- ";
    cin>>id;
    cout<<endl;
    cout<<"Please Enter the password:- ";
    cin>>password;
    cout<<endl;

    if(authenticationChecker.count({id, password})){

        cout<<"Access Granted!\n";
        AcountWork(id, password);


    }else{

        cout<<"******** LOGIN FAILED! ********\n";
        printIntroMenu();

    }





}

// createAccount() function for creating the valid account on ATM.

void createAccount(){

    int id;
    string password;

    cout<<"Please Enter the user Id:- ";
    cin>>id;
    cout<<endl;
    cout<<"Please Enter the password:- ";
    cin>>password;
    cout<<endl;

    if(authenticationChecker.count({id, password})==0){
        accountBalance.push_back(0);
      int index= accountBalance.size()-1;

      authenticationChecker[{id, password}]=index;
    }else{
        cout<<"Already Account is Exist..\n";
        return;
    }

    cout<<"Thank You! Your account has been created!..\n";

    AcountWork(id, password);


}

// This is first function which is called when our Program start.
// And take the Action on the basis on User Request.

void start(){

   
   while(true)
   {
       
       printIntroMenu(); // call for display Menu option.

       cin>>menuInput; // take the input from user.

       switch(menuInput)
       {
       
        case 'l': 
            login();
            break;
        case 'c':
            createAccount();
            break;
        case 'q':
            exit(0);
            break;

        default:
            cout<<"INVALID INPUT";
            break;
            

       }

       
   }




}


int main(){

    cout<<"Hi Welcome to Rajesh ATM Machine !..\n";
     start();
     cout<<"Thanku to using Rajesh ATM Machine...";
     return 0;
}
