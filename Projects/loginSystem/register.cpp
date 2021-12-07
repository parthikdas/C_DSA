// If everything goes right do a email verification that @gmail.com is there or not
// Correct signup if only admin is there then no issue but if 2 or more user is there then segmentation
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;
// LL i could have used but then update would be hard but deletion would be easy
struct data {
    int id;
    string name, email, password;
};
int n=0; // number of users
struct data *arr;
fstream file;
void initialize() { // This function will be called when program is runned
    file.open("data.txt",ios::in);
    if(file.is_open()) {
        arr = (struct data*) malloc((n+1) * sizeof(struct data)); // 1 is for admin
        // Now count number of users and feed data
        string s;
        while(getline(file, s)) {
            stringstream stream(s);
            stream >> arr[n].id >> arr[n].name >> arr[n].email >> arr[n].password;
            n++;
            arr = (struct data*) realloc(arr, (n+1) * sizeof(struct data)); // increasing size
        }
        file.close();      
    } else {
        cout<<"File can't be found!!";
    }
}
void over() { //  This function will be called when program ends
    file.open("data.txt",ios::out);
    if(file.is_open()) {
        for(int i = 0 ; i < n ; i++) {
            file << arr[i].id <<" "<< arr[i].name <<" "<< arr[i].email << " " << arr[i].password << endl;
        }
        file.close();
    } else {
        cout<<"File can't be found!!";
    }
    cout<<"\nBye Bye\n";
    exit(1);
}
int existingUser(string &email, string &password) { // Function to check existing user and returns id else -1, -2 for wrong password
    for(int i = 0 ; i < n ; i++) {
        if(arr[i].email == email) {
            if(arr[i].password == password) return arr[i].id;
            else return -2;
        }
    }
    return -1;
}
string newPassword() {
    string pass1, pass2;
    cout<<"Enter new password : ";
    cin>>pass1;
    cout<<"Confirm password : ";
    cin>>pass2;
    if(pass1 == pass2) { // both matched
        return pass1;
    }
    cout<<"Passwords not matched\n";
    return newPassword();
}
void login();
void signup() { // Function for sign up
    cout<<"\e[1;1H\e[2JSign up Here\n";
    arr = (struct data*) realloc(arr, (n+1) * sizeof(struct data)); // increasing size
    arr[n].id = n;
    cout<<"Enter name : ";
    cin>>arr[n].name;
    cout<<"Enter email : ";
    cin>>arr[n].email;
    arr[n].password = newPassword();
    n++;
    cout<<"Account created!!\nPlease login.\n";
    login();
}
void login() { // Function for login
    cout<<"\e[1;1H\e[2JLogin Here\n";
    string email, password;
    cout<<"Enter email : ";
    cin>>email;
    here : 
    cout<<"Enter password : ";
    cin>>password;
    int index = existingUser(email, password);
    if(index == 0) { // admin
        here4:
        int ch;
        cout<<"\nEnter 1 to show all users\nEnter 2 to delete a user\nEnter 3 to exit\n";
        cin>>ch;
        if(ch == 1) { // Show all users
            cout<<"\nDetails of all users : \n";
            cout<<"Id Name\t     Email\t    Password\n";
            if(n > 1) {
                for(int i=1;i<n;i++) {
                    cout<<setw(3)<<left<< setfill(' ')<<arr[i].id<<setw(10)<<left<< setfill(' ')<<arr[i].name<<setw(15)<<left<< setfill(' ')<<arr[i].email<<arr[i].password<<endl;
                }
            } else cout<<"Currently no users!!\n\n";
        } else if(ch == 2) { // Delete a user
            int delInd;
            cout<<"Enter the id of user you want to delete : ";
            cin>>delInd;
            if(!delInd) cout<<"Can't delete admin account\n";
            else {
                n--; // reducing the size
                for(int i = delInd; i < n; i++) {
                    arr[i] = arr[i+1];
                }
                arr = (struct data*) realloc(arr, n * sizeof(struct data)); // releasing the memory
            }
        } else if(ch == 3) over();
        goto here4;
    } else if(index > 0) { // normal user
        here1:
        int ch;
        cout<<"\nEnter 1 to show account details\nEnter 2 to update details\nEnter 3 to exit\n";
        cin>>ch;
        if(ch == 1) { // display details
            cout<<"\nId : "<<arr[index].id<<"\nName : "<<arr[index].name<<"\nEmail : "<<arr[index].email<<"\nPassword : "<<arr[index].password<<endl;
        } else if(ch == 2) {
            int userch;
            string str;
            cout<<"\nEnter 1 to update name\nEnter 2 to update email\nEnter 3 to update password\n";
            cin>>userch;
            if(userch == 1) { // update name
                cout<<"Enter new name : ";
                cin>>str;
                arr[index].name = str;
            } else if(userch == 2) { // update email
                cout<<"Enter new email : ";
                cin>>str;
                arr[index].email = str;
            } else if(userch == 3) { // update password
                here2:
                cout<<"Enter old password : ";
                cin>>str;
                if(arr[index].password == str) {
                    arr[index].password = newPassword();
                } else {
                    cout<<"Old password not matched..\n";
                    goto here2;
                }
            }
            cout<<"Update Successful\n";
        } else if(ch == 3) over();
        goto here1;
    } else if(index == -2) { // update details
        cout<<"\nWrong Password\n";
        goto here;
    } else if(index == -1) { // new record
        int ch;
        cout<<"\nAccount not found!!\n";
        cout<<"Enter 1 for sign up\nEnter 2 to exit\n";
        cin>>ch;
        if(ch == 1) signup();
        else over();
    }
}
int main(){
    initialize();
    int ch;
    cout<<"\e[1;1H\e[2JWelcome to my logging system\nEnter 1 for login\nEnter 2 for signup\nPress 3 to exit\n"; // using regex to clear screen
    cin>>ch;
    if(ch == 1) login();
    else if(ch == 2) signup();
    over();
    return 0;
}