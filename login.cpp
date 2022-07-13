#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void resgistration();
void forgot();

int main(){
    int c;
    cout<<"\t\t---------------------------------------------------\n\n\n";
    cout<<"\t\t        Welcome TO Login Page                       \n\n\n";
    cout<<"\t\t_________________ Menu ________________\n\n";
    cout<<"\t\t||-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_||\n";
    cout<<"\t\t||  Press 1 to Login                  ||\n";    
    cout<<"\t\t||  Press 2 to Register               ||\n";
    cout<<"\t\t||  Press 3 to reset your password    ||\n";
    cout<<"\t\t||  Press 4 to Exit                   ||\n";
    cout<<"\t\t||                                    ||\n";
    cout<<"\t\t||-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_||\n";
    cout<<"\n\t\t       Please Enter your choice : ";
    cin>>c;
    cout<<endl;
    
    switch (c){
        case 1:
           login();
           break;
        case 2:
            resgistration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout<<"thank you";
            break;
        default :
            system("cls");
            cout<<"\n\t\t please choose from the below given options."<<endl;
            main();
    }
return 0;
}
void login(){
    int c;
    string userid, password,id,pass;
    system("cls");
    cout<<"\t\t Pleasr Enter Your Password :"<<endl;
    cout<<"\t\t UserName :";
    cin>>userid;
    cout<<"\t\t PassWord :";
    cin>>password;

    ifstream input("record.txt");
    while(input>>id>>pass){
        if(id==userid && pass==password)
        {
            c=1;
            system("cls");
        }
    }
    input.close();

    if(c==1){
        cout<<userid<<"\n\t\tYour Login is successfull thanks for loggin in!\n";
    }
    else{
        cout<<"\n\t\t Login Error \n PLease check your username and password\n";
        main();
    }
}


void resgistration(){
    string ruserid,rpassword,rid,rpass;
    system("cls");
    cout<<"\t\t Enter the username : ";
    cin>>ruserid;
    cout<<"\t\t Enter the password : ";
    cin>>rpassword;

    ofstream f1("record.txt", ios::app);
    f1<<ruserid<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\t\t Registration succesfull ! \n";
    main();
}


void forgot(){
   int option;
   system("cls");
   cout<<"\t\t You Can Find Your Password\n\n";
   cout<<"\t\tPress 1 to search your id by username"<<endl;
   cout<<"\t\tPress 2 to go back to main menu"<<endl;
   cout<<"\t\t Enter Your choice"<<endl;
   cin>>option;
   switch(option){
    case 1:{
        int count =0;
        string suserid,sid,spass;
        cout<<"\n\t\tEnter the username :";
        cin>>suserid;

        ifstream f2("record.txt");
        while(f2>>sid>>spass){
            if(sid==suserid){
                count=1;
            }
        }
        f2.close();
        if(count==1){
            cout<<"\n\t\tYour account is found"<<endl;
            cout<<"\n\t\tYour password is :"<<spass;
            main();
       }
       break;
    }
    case 2:{
        main();
    }
    default:
    cout<<"\t\t Wrong choice"<<endl;
    forgot();
   }
}

