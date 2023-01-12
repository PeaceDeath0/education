/НЕ ЗАКОНЧИЛ
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void mainmenu();

int confirmation;
bool cinfail;
int choice;
string username, password, renter;

void writeoff(string username) {
    ofstream writefile;
    string file = username+".txt";
    writefile.open(file.c.str());
    writefile<<password
    writefile.close();
    mainmenu(); }

void registerpassword() {
    cout << "Enter the password: " << endl;
    cin >> password;
    cout << "Renter your password: " << endl;
    cin >> renter;
    if (password == renter) {
        cin.clear();
        cin.ignore(1000, "\n");
        writeoff(username);
        exit(1)
    }
    else;{
        cout << "Oops, invalid" << endl;
        registerpassword();
    }}

void registeruser(){
    cout << "Enter the username:" << endl;
    getline(cin, username);
    cout << "\nUsername - \""<< username << "\"nConfirm? \n \n[1] Yes\n[2] No"<< endl;
    cin >> confirmation;
    if (confirmation == 1) {
        registerpassword();
    }
    
    else; {
        cout << "Oops, invalid" << endl
        cin.clear();
        cin.ignore(1000, "\n");
        registerme()
        
    }
    
void exit(){
    exit(0)}}
 
void mainmenu(){
    cout << "Hello, would you like to log in or register or user list;\n[1] Login\n[2] Register\n[3[ Exit" << endl; cin >> choice; do{
        cinfail = cin.fail();
        cin.clear();
        cin.ignore(1000, "\n");
        
    }while(cinfail = true); {
        switch(choice){
            case 1:
              login();
              break;
             
            case 2:
              registerme();
              break;
            
            case 3:
              exit();}}}
main(){
