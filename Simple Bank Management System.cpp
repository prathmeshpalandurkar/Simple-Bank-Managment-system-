// This is the code for Simple Bank Management system 


#include<iostream>
#include<vector>
using namespace std ;
class BankAccount {
    private :
      string name ;
      int account_num ;
      double balance ;


     public :
     BankAccount (string n , int acn , double bal ){
        name = n ;
        account_num = acn ;
        balance = bal ;
     }
       
       string getName(){
        return name ;

       }
       int getAccountNum (){
        return account_num;
       }
       double getBalance(){
        return balance ;
       }
       void deposit(double amount ){
           balance = balance +amount ;
           
       }
        void withdraw(double amount){
            if(balance >=amount){
                balance = balance - amount ;
                cout<<"\t\tWithdraw Sucessfully..."<<endl ;
            } else {
                cout<<"\t\tInsufficient Balance..."<<endl;
            }
        }
};
    class BankManagement {
        private :
        vector<BankAccount>accounts;    
        public : 
           void AddAccount (string name , int account_num , double balance ){
               accounts.push_back (BankAccount(name , account_num, balance ));
           }
           void showAllAccounts(){
               cout<<"\t\t All Account Holders "<<endl ;
               for(int i =0 ;i<accounts.size();i++){
               cout<<"Name : "<<accounts[i].getName()<<"\tAccount Number :"<<accounts[i].getAccountNum()<<"\tBalance :"<<accounts[i].getBalance()<<endl;
               }
           }
           
           void searchAccount(int account){
               cout<<"\t\t Account Holder "<<endl ;
               for(int i =0 ; i<accounts.size();i++){
               if (accounts[i].getAccountNum()==account){
               cout<<"Name : "<<accounts[i].getName()<<"\tAccount Number :"<<accounts[i].getAccountNum()<<"\tBalance :"<<accounts[i].getBalance()<<endl;
                   }
               }
           }
           BankAccount* findAccount(int accountNum){
               for(int i =0 ;i<accounts.size();i++){
                   if(accounts[i].getAccountNum()==accountNum){
                       return &accounts[i];
                   }
               }
           }
  };
        
        int  main(){
        BankManagement  bank ;
        int choice ;
        char op ;
        
        do {
            // system("cls");
             cout<<"\t\t ::----------- Bank Management System ------------::"<<endl ;
        cout<<"\t\t\tMain  Menu"<<endl;
        cout<<"\t\t 1. Create New Account"<<endl ;
        cout<<"\t\t 2. Show All Account"<<endl ;
        cout<<"\t\t 3. Search Account"<<endl ;
        cout<<"\t\t 4. Deposit Money"<<endl ;
        cout<<"\t\t 5. Withdraw Money"<<endl ;
        cout<<"\t\t 6. Exit"<<endl ;
        cout<<"\t\t---------------------------------"<<endl ;
        cout<<"\t\t Enter Your Choice :"<<endl ;
        cin>>choice ;
        switch(choice){
            case 1 : {
                string name ;
                int account_num ;
                double balance ;
                cout<<"\t\t Enter Name :";
                cin>>name ;
                cout<<"\t\t Enter Account Number :";
                cin>>account_num ;
                cout<<"\t\t Enter Initial Balance : ";
                cin>>balance ;
                bank.AddAccount(name,account_num , balance);
                cout<<"\t\t Account Created successfully..... :)";
                break ;
            }
            case 2  :{
                bank.showAllAccounts();
                break;
        }
            case 3 : {
                 int accountNum ;
                 cout<<"Enter Account Number :";
                 cin>>accountNum;
                 bank.searchAccount(accountNum);
                 break ;
             }
             
             case 4 : {
                 int accountNum;
                 double amount ;
                 cout<<"\t\t To Deposit Money Enter Account Number  : ";
                 cin>>accountNum ;
                 BankAccount*account = bank.findAccount(accountNum);
                 if(account != NULL){
                     cout<<"\t\tEnter Amount to Deposit :";
                     cin>>amount ;
                     account->deposit(amount);
                     cout<<"\t\t"<<amount<<"Deposit Successfully ..."<<endl;
                 }
                 else{
                     cout<<"\t\tAccount Not Found..."<<endl;
                 }
                 
                 break ;
                 
             }
                case 5 :{
                    int accountNum ;
                    double amount ;
                    cout<<"\t\t To withdraw Money Enter Account Number :";
                    cin>>accountNum;
                    BankAccount *account = bank.findAccount(accountNum);
                    if(account !=NULL){
                        cout<<"\t\tEnter Amount to withdraw :";
                        cin>>amount;
                        account->withdraw(amount);
                        
                    }
                    else{
                        cout<<"\t\tAccount Not Found ..."<<endl;
                    }
                    
                }
             
               break ;
               
               case 6 :{
                   exit(1);
                   break ;
               }
        }
        
        cout<<"\t\t\n\t Type ('Y'/ 'y') to Continue or Exit  ??\t";
        cin>>op ;
        }while (op =='y'|| op =='Y');
       
       
       
    }
    


