# GradeUpAssignment
Hello, MySelf Rajesh Kumar Gupta, I have created a ATM Machine .

 Language Used : CPP
 
 
 functionality :  create a Account,
                  login in Existing Account,
                  Deposite the Money from the Account,
                  Withdraw the Money from the Account,
                  Check Balance of the Account.
                  
                  
   Global Varibles :
     
     char menuInput  // global Varible for taking menuinput.
     map<pair<int, string>, int >  authenticationChecker // Map data structure for the authenticationChecker
     vector<int> accountBalance  // // store the Balance of All Account Holder.
     
   functions Declaration : 
                          
      void printIntroMenu(); // function for Print the Menu List:-
      void printMainMenu();  //  Print the Main Menu List
      void login();          // login() function for the login in the existing Account. 
      void createAccount();  // createAccount() function for creating the valid account on ATM.
      void deposite(int &, string &); // deposite function helps to deposite the Amount(>0) in specific Account.   
      void Balance(int &, string &);  // Balance function for checking the Balance in specific Account.
      void withdraw(int & , string &); // withdraw function for withdraw the money from account.
      void AcountWork(int &, string &); // AccountWork function handle all the work related to user request.
      void start(); // This is first function which is called when our Program start and take the Action on the basis on User Request.
      
      
    
    
                  
                  

                
                
