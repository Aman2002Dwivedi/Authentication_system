#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
using namespace std;

// Functions Declarations 

void login() ;
void registration();
void forgot_password();
void change_password();
void user_menu();
void user_view_profile();
void user_edit_profile();
void user_delete_profile();
void user_logout();
void main_menu();
void admin_menu();
void admin_view_users();
void admin_delete_users();
void admin_add_users();
void admin_edit_users();
void admin_logout();

// Global Variables 

string username , password , password2 , email , phone , address , city , state , country ,pincode, admin_username , admin_password;

//  Create an Array of structure  to store user data 

struct user 
{
    string username ;
    string password;
    string email;
    string phone ;
    string address;
    string city ;
    string state ;
    string country;
    string pincode ;
}user[100];

// function for drawing a  line 

void drawLine(int n , char symbol)
{
    for(int i=0;i<n;i++)
    {
        cout<<symbol;
    }
    cout<<endl;
}
int i = 0 ;
// Function for user registration

void registration()
{
    system("cls");
    drawLine(80 , '-');
    cout<<"\t\t\t Registration "<<endl;
    drawLine(80 , '-');
    cout<<"Enter Username: ";
    cin>>username;
    user[i].username = username;

    cout<<"Enter Password: ";
    cin>>password;
    user[i].password = password;

    cout<<"Enter Email: ";
    cin>>email;
    user[i].email = email;

    cout<<"Enter Phone: ";
    cin>>phone;
    user[i].phone = phone;

    cout<<"Enter Address: ";
    cin>>address;
    user[i].address = address;

    cout<<"Enter City: ";
    cin>>city;
    user[i].city = city ;

    cout<<"Enter State: ";
    cin>>state ;
    user[i].state = state ;

    cout<<"Enter Country: ";
    cin>>country;
    user[i].country = country ;

    cout<<"Enter Pincode: ";
    cin>>pincode;
    user[i].pincode = pincode;

    cout<<endl;
    cout<<"Registration Successful! "<<endl;
    cout<<endl;
    
    i++;

    cout<<endl;
    getch();
    main_menu();
}

// Function for Login 

void login()
{
    system("cls");
    drawLine(80 , '-');
    cout<<"\t\t\t Login "<<endl;
    drawLine(80 , '-');
    cout<<endl;
    cout<<"Enter Username: ";
    cin>>username;
    cout<<"Enter Password: ";
    cin>>password;
    cout<<endl;

    if(username == "admin" && password == "admin")
    {
        cout<<"Login Successful!"<<endl;
        cout<<endl;
        cout<<"Welcome Admin!"<<endl;
        cout<<endl;
        cout<<"Press any key to continue....";
        cout<<endl;
        getch();
        admin_menu();
    }
    int j =0 ;
    for(j=0;j<i;j++)
    {
        if(username == user[j].username && password == user[j].password)
        {
            cout<<"Welcome "<<username<<"!"<<endl;
            cout<<"Login Successful!"<<endl;
            cout<<endl;
            cout<<"Press any key to continue......";
            getch();
            user_menu();
        }
    }
    if(j > i)
    {
        cout<<"Login Failed!"<<endl;
        cout<<endl;
        cout<<"Press any key to continue.....";
        getch();
        login();
    }
}

// Function for Forget Password

void forgot_password()
{
    system("cls");
    drawLine(80 , '-');
    cout<<"\t\tForgot Password "<<endl;
    drawLine(80,'-');

    cout<<"Enter Username: ";
    cin>>username;
    cout<<"Enter Email: ";
    cin>>email;
    cout<<endl;

    for(int j=0;j<i;j++)
    {
        if(username == user[j].username && email == user[j].email)
        {
            cout<<"Enter New Password: ";
            cin>>password;
            cout<<"Confirm Password: ";
            cin>>password2;

            if(password == password2)
            {
                user[j].password = password;
                cout<<"Password Changed Successfully!"<<endl;
                cout<<endl;
                cout<<"Press any key to continue....";
                getch();
                login();
            }
            else 
            {
                cout<<"Password does bot match!"<<endl;
                cout<<endl;
                cout<<"Press any key to continue....";
                getch();
                forgot_password();
            }
            
        }
        else 
        {
            cout<<"Username or Email is incorrect!"<<endl;
            cout<<endl;
            cout<<"Press any key to continue....";
            getch();
            forgot_password();
        }
    }
}

void change_password()
{
    system("cls");
    drawLine(80 , '-');
    cout<<"\t\t\t Change Password "<<endl;
    drawLine(80 , '-');

    cout<<"Enter Username: ";
    cin>>username;
    cout<<"Enter Password: ";
    cin>>password;
    cout<<endl;

    for(int j=0;j<i;j++)
    {
        if(username == user[i].username && password == user[i].password)
        {
            cout<<"Enter New Password: ";
            cin>>password;
            cout<<"Confirm Password: ";
            cin>>password2;

            if(password == password2)
            {
                user[j].password = password2;
                cout<<"Password Changed Successfully!"<<endl;
                cout<<endl;
                cout<<"Press any key to continue....";
                getch();
                login();
            }
            else
            {
                cout<<"Password does not match!"<<endl;
                cout<<endl;
                cout<<"Press any key to continue....";
                getch();
                change_password();
            }
        }
    }
}

void user_menu()
{
    int choice ;
    system("cls");
    drawLine(80 , '-');
    cout<<"\t\t\t User Menu "<<endl;
    drawLine(80 , '-');
    cout<<endl;
    while(1)
    {
        cout<<"1. View Profile "<<endl;
        cout<<"2. Edit Profile"<<endl;
        cout<<"3. Delete Profile"<<endl;
        cout<<"4. Logout"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<endl;
        cout <<"Enter your choice: ";
        cin>>choice;

        switch (choice)
        {
            case 1:
                user_view_profile();
                break;
            case 2:
                user_edit_profile();
                break;
            case 3:
                user_delete_profile();
                break;
            case 4:
                user_logout();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout<<"Invalid Choice!"<<endl;
                cout<<endl;
                cout<<"Press any key to continue....";
                getch();
        }
    }

}


void user_view_profile()
{
    system("cls");
    drawLine(80 , '-');
    cout<<"\t\t View Profile "<<endl;
    drawLine(80 , '-');
    cout<<endl;
    int j = 0 ;
    for(j=0;j<i;j++)
    {
        if(username == user[j].username && password == user[j].password)
        {
            cout<<"Username: "<<user[j].username<<endl;
            cout<<"Password: "<<user[j].password<<endl;
            cout<<"Email: "<<user[j].email<<endl;
            cout<<"Phone: "<<user[j].phone<<endl;
            cout<<"Address: "<<user[j].address<<endl;
            cout<<"City: "<<user[j].city<<endl;
            cout<<"State: "<<user[j].state<<endl;
            cout<<"Country: "<<user[j].country<<endl;
            cout<<"Pincode: "<<user[j].pincode<<endl;
        }
    }
    if(j > i)
    {
        cout<<"User not Available!"<<endl;
    }
    cout<<endl;
    cout<<"Press any key to continue...."<<endl;
    getch();
    user_menu();
}

void user_edit_profile()
{
    system("cls");
    drawLine(80 , '-');
    cout<<"\t\t\t Edit Profile "<<endl;
    drawLine(80 , '-');
    cout<<endl;

    cout<<"Enter Email: ";
    cin>>email;
    cout<<endl;
    cout<<"Enter Phone: ";
    cin>>phone;
    cout<<endl;
    cout<<"Enter address: ";
    cin>>address;
    cout<<endl;
    cout<<"Enter City: ";
    cin>>city;
    cout<<endl;
    cout<<"Enter State: ";
    cin>>state;
    cout<<endl;
    cout<<"Enter Country: ";
    cin>>country;
    cout<<endl;
    cout<<"Enter Pincode: ";
    cin>>pincode;
    cout<<endl;

    cout<<"Enter the username and password to confirm: "<<endl;
    cout<<"Username: ";
    cin>>username;
    cout<<"Password: ";
    cin>>password2;
    cout<<endl;

    for(int j=0;j<=i;j++)
    {
        if(username == user[j].username && password == user[j].password)
        {
            user[j].email = email ;
            user[j].phone = phone ;
            user[j].address = address;
            user[j].city = city ;
            user[j].state = state ;
            user[j].country = country ;
            user[j].pincode = pincode ;
            cout<<endl;
            cout<<"Profile Updated Successfully!"<<endl;
            cout<<endl;
            cout<<"Press any key to continue....";
            getch();
            user_menu();
        }
        else
        {
            cout<<"Invalid Username or Password!";
            cout<<endl;
            cout<<"Press any key to continue....";
            getch();
            user_edit_profile();
        }
    }
}

void user_logout()
{
    system("cls");
    drawLine(80 , '-');
    cout<<"\t\t Logout "<<endl;
    drawLine(80 , '-');

    char logout;
    cout<<"Are you sure to logout? (y/n):";
    cin>>logout;
    if(logout == 'y' or logout == 'Y')
    {
        main_menu();
    }
    else
    {
        user_menu();
    }

}

void user_delete_profile()
{
    system("cls");
    drawLine(80 , '-');
    cout<<"\t\t Delete Profile "<<endl;
    drawLine(80 , '-');

    char delete_profile ;
    cout<<"Are you sure you want to delete your profile? (y/n) : ";
    cin>>delete_profile;
    cout<<endl;
    if(delete_profile == 'y' || delete_profile == 'Y')
    {
        for(int j=0;j<=i;j++)
        {
            if(username == user[j].username)
            {
                for(int k=j;k<=i;k++)
                {
                    user[k] = user[k+1];
                }
                i--;
                cout<<"Profile Deleted Successfully!"<<endl;
                cout<<endl;
                cout<<"Press any key to continue....";
                getch();
                main_menu();
            }
            else 
            {
                cout<<"User not found!"<<endl;
                cout<<endl;
                cout<<"Press any key to continue....";
                getch();
                user_menu();
            }
        }
    }
    else 
    {
        user_menu();
    }
}

void admin_menu()
{
    int choice ;
    system("cls");
    drawLine(80 , '-');
    cout<<"\t\t Admin Menu "<<endl;
    drawLine(80 , '-');

    while(1)
    {
        cout<<"1. View All Users"<<endl;
        cout<<"2. Delete User"<<endl;
        cout<<"3. Add User"<<endl;
        cout<<"4. Edit User"<<endl;
        cout<<"5. Logout"<<endl;
        cout<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl;
    
        switch(choice)
        {
            case 1:
                admin_view_users();
                break;
            case 2:
                admin_delete_users();
                break;
            case 3:
                admin_add_users();
                break;
            case 4:
                admin_edit_users();
                break;
            case 5:
                admin_logout();
                break;
            default :
                cout<<"Invalid Choice!"<<endl;
                cout<<endl;
                cout<<"Press any key to continue...."<<endl;
                getch();       
        }
    }
}

void admin_view_users()
{
    system("cls");
    drawLine(80 , '-');
    cout<<"\t\t All Users available in the database "<<endl;
    drawLine(80 , '-');
    if(i == 0)
    {
        cout<<"No users available in the database!"<<endl;
        cout<<endl;
        cout<<"Press any key to continue....";
        getch();
        admin_menu();
    }
    for(int j=0;j<i;j++)
    {
        cout<<user[j].username<<setw(20)<<user[j].password<<setw(20)<<user[j].email<<setw(20)<<user[j].phone<<setw(20)<<user[j].address<<setw(20)<<user[j].city<<setw(20)<<user[j].state<<setw(20)<<user[j].country<<setw(20)<<user[j].pincode<<endl;
    }
    cout<<endl;
    cout<<"Press any key to continue....";
    getch();
    admin_menu();
}

void admin_delete_users()
{
    system("cls");
    drawLine(80 , '-');
    cout<<"\t\t Delete User "<<endl;
    drawLine(80 , '-');
    cout<<endl;

    cout<<"Enter the username of the user you want to delete: ";
    cin>>username;
    cout<<endl;

    for(int j=0;j<=i;j++)
    {
        if(username == user[j].username)
        {
            for(int k=j;k<=i;k++)
            {
                user[k] = user[k+1];
            }
            i--;
            cout<<"User Deleted Successfully!"<<endl;
            cout<<endl;
            cout<<"Press any key to continue....";
            getch();
            admin_menu();
        }
        else 
        {
            cout<<"User not found!"<<endl;
            cout<<endl;
            cout<<"Press any key to continue....";
            getch();
            admin_delete_users();
        }
    }
}

void admin_logout()
{
    system("cls");
    drawLine(80 , '-');
    cout<<"\t\t Logout "<<endl;
    drawLine(80 , '-');

    char logout;
    cout<<"Are you sure you want to logout? (y/n): ";
    cin>>logout;
    cout<<endl;
    if(logout == 'y' || logout == 'Y')
    {
        main_menu();
    }
    else
    {
        admin_menu();
    }
}

void admin_edit_users()
{
    system("cls");
    drawLine(80 , '-');
    cout<<"\t\t Edit User "<<endl;
    drawLine(80 , '-');
    cout<<endl;

    cout<<"Enter the username of the user you want to edit: ";
    cin>>username;
    cout<<endl;

    for(int j=0;j<i;j++)
    {
        if(username == user[j].username)
        {
            cout<<"Enter the new Email: ";
            cin>>email;
            cout<<endl;
            cout<<"Enter the new Phone: ";
            cin>>phone;
            cout<<endl;
            cout<<"Enter the new address: ";
            cin>>address;
            cout<<endl;
            cout<<"Enter the new City: ";
            cin>>city;
            cout<<endl;
            cout<<"Enter the new State: ";
            cin>>state;
            cout<<endl;
            cout<<"Enter the new Country: ";
            cin>>country;
            cout<<endl;
            cout<<"Enter the new Pincode: ";
            cin>>pincode;
            cout<<endl;

            user[j].email = email ;
            user[j].phone = phone ;
            user[j].address = address;
            user[j].city = city ;
            user[j].state = state ;
            user[j].country = country ;
            user[j].pincode = pincode ;
            cout<<endl;

            cout<<"User Edited Successfully!"<<endl;
            cout<<endl;
            cout<<"Press any key to continue....";
            getch();
            admin_menu();
        }
        else 
        {
            cout<<"User not found!"<<endl;
            cout<<endl;
            int add;
            cout<<"Do you want to add a new user? (y/n): ";
            cin>>add;
            cout<<endl;
            if(add == 'y' || add == 'Y')
            {
                admin_add_users();
            }
            else
            {
                admin_menu();
            }
        }
    }
}

void admin_add_users()
{
    system("cls");
    drawLine(80 , '-');
    cout<<"\t\t Add New User "<<endl;
    drawLine(80 , '-');
    cout<<endl;

    cout<<"Enter the username: ";
    cin>>username;
    cout<<endl;

    cout<<"Enter the password: ";
    cin>>password;
    cout<<endl;

    cout<<"Enter the Email: ";
    cin>>email;
    cout<<endl;
    cout<<"Enter the Phone: ";
    cin>>phone;
    cout<<endl;
    cout<<"Enter the address: ";
    cin>>address;
    cout<<endl;
    cout<<"Enter the City: ";
    cin>>city;
    cout<<endl;
    cout<<"Enter the State: ";
    cin>>state;
    cout<<endl;
    cout<<"Enter the Country: ";
    cin>>country;
    cout<<endl;
    cout<<"Enter the Pincode: ";
    cin>>pincode;
    cout<<endl;

    
    
    user[i].username = username;
    user[i].password = password;
    user[i].email = email ;
    user[i].phone = phone ;
    user[i].address = address;
    user[i].city = city ;
    user[i].state = state ;
    user[i].country = country ;
    user[i].pincode = pincode ;

    cout<<"User Added Successfully! "<<endl;
    cout<<endl;
    i++;
    system("pause");
    admin_menu();
}

void main_menu()
{
    int choice ;
    while(1)
    {
        system("cls");
        drawLine(80,'-');
        cout<<"\t\t Welcome to Login System "<<endl;
        drawLine(80 , '-');
        cout<<endl;
        cout<<"1. Login"<<endl;
        cout<<"2. Registration"<<endl;
        cout<<"3. Forgot Password"<<endl;
        cout<<"4. Change Password"<<endl;
        cout<<"5. Exit"<<endl;

        cout<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                login();
                break;
            case 2:
                registration();
                break;
            case 3:
                forgot_password();
                break;
            case 4:
                change_password();
                break;
            case 5:
                exit(0);
                break;

            default :
                cout<<"Invalid Choice!"<<endl;
                cout<<endl;
                cout<<"Press any key to continue....";
                getch();
        }
    }
}

int main()
{
    main_menu();
    return 0;
}