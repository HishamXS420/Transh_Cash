#include <iostream>
#include <conio.h>
#include <time.h>
#include <cstring>
#include <bits/stdc++.h>
 
using namespace std;
 
int getPin();
int Main_Menu();
int Search(string m);
int Menu1();
int OTP();
int select();
int trxID();
int put;
string getTime();
 
class TransCash
{
 
private:
    string mobile;
    string name;
    int pin;
    float balance = 0;
    int cnt = 0;
 
public:
    pair<int, string> his[100];
    tuple<float, float, string> hist[100];
     friend void insertFile();
        friend void getFile();
    void setData(string m, string n, int p, float bal)
    {
        mobile = m;
        name = n;
        pin = p;
        balance = bal;
       
 
      
    }
      
    string getMobile()
    {
        return (mobile);
    }
    int match(string m, int p)
    {
        if (m == mobile && p == pin)
        {
            return 1;
        }
        else
            return 0;
    }
    void Update();
    void Remove();
    void Send_Money();
    void Cash_In();
    void Cash_Out();
    void Pay_Bill();
    void Check_Balance();
    void History();
};
 
TransCash mc[1000];
int total = -1;
 
 
void getFile()
        {
            ifstream outputFile("exampl.txt", ios::app);
            if (outputFile.is_open())
            {
                for (int i = 0;; i++)
                {
                    if (outputFile.eof() == 1)
                        break;
                    string n, m;
                    int p;
                    float b;
                    // Add data to the next line
                    outputFile >> n >> m >> p >> b;
                    mc[i].setData(n,m, p, b);
                    total++;
                    // Close the file
                    outputFile.close();
                    n.clear();
                    m.clear();
                    p = 0;
                    b = 0;
                }
 
                outputFile.close();
            }
            // if() break;
        }
 
        void insertFile()
        {
            for (int i = 0; i <= total; i++)
            {
                ofstream Out("exampl.txt", ios::app);
 
                if (Out.is_open())
                {
                    Out << mc[i].name << " " << mc[i].mobile << " " << mc[i].pin << " " << mc[i].balance << " "
                        << "\n";
                }
            }
            // Out.close();
        }
void TransCash ::Update()
{
    system("cls");
 
   // cout << "\n\t \t \t \t \tUpdate" << endl << endl << endl;
    string n;
    int p;
    char x[100],ch;
    int a, b, c, d, e,s,f;
    cin.ignore();
    cout << "\t \t \t \t \t Update" << endl
         << endl
         << endl;
    cout << "\t \t \t \t \t Old Name :" << name << endl;
    cout << "\t \t \t \t \t Enter New Name : ";
    cin.getline(x, 100);
    cout << "\t \t \t \t \t Old PIN(enter to ignore): ";
    ch =getch();
    if(ch!=13){
        a = getPin();
    cout << endl;
    if (a != 1)
        do
        {
            cout << "\t \t \t \t \t Enter New PIN : ";
       
            c = getPin();
           cout << endl;
            if (c != a)
            {
                cout << "\t \t \t \t \t Confirm New Pin : ";
                p = getPin();
                cout << endl;
                if(c!=p){
                    cout << endl;
                    cout << "\t \t \t \t \t Pin Doesn't match. Enter Again";
                    cout << endl;
                }
            }
            else
            {
                cout << "\t \t \t \t \t You've already used this PIN. Please enter a new PIN.";
            }
        } while (c!= p);
    }
    
         s = OTP();
         cout << endl;
            cout << "\t \t \t \t \tmyCash OTP: " << s << endl;
            cout << "\t \t \t \t \tEnter OTP: ";
            cin >> f;
            if (f == s){
                 mc[put].setData(mobile, n, p, balance);
                 cout << endl;
        cout << "\t \t \t \t \tMember updated succesfully" << endl;
            }
            else
                cout << "\t \t \t \t \tInvalid OTP....";
 
    cout << endl;
 
   
}
void TransCash ::Remove()
{
    cout << "\n\t \t \t \t \tRemove" << endl << endl << endl;
    int p, s;
    do
    {
        cout << "\t \t \t \t \tEnter PIN: ";
        p = getPin();
        if (p != pin)
            cout << "\t \t \t \t \tInvalid PIN." << endl;
    } while (p != pin);
    
    
    int x = OTP();
    cout << endl;
    cout << "\t \t \t \t \tmyCash OTP: "<<x<<endl;
 
    cout << "\t \t \t \t \tEnter OTP: ";
    cin >> s;
    if (x == s) {
        cout << "\t \t \t \t \tRemove is succesful" << endl;
        mc[0].setData(" ", " ", 0,0.0);
    }
    else
        cout << "\t \t \t \t \tInvalid OTP...." << endl;
    
    
    cout << "\t \t \t \t \tPress any key go to main menu....." << endl;
    getch();
    system("cls");
 
    Menu1();
}
void TransCash ::Send_Money()
{
    cout << "\n\t \t \t \t \tSend Money" << endl << endl << endl;
    float b = 0;
    int a;
    string m;
    char s;
    cout << "\t \t \t \t \tEnter Destination no. (11-digit): ";
    cin >> m;
    int d = Search(m);
    if (m.length() == 11 && mc[d].mobile == m)
    {
        cout << "\t \t \t \t \tEnter Amount: ";
        cin >> b;
    }
    else
    {
        cout << "\t \t \t \t \tInvalid Mobile Number" << endl;
        goto c;
    }
    if (b <= balance)
    {
 
        cout << "\t \t \t \t \tSending " << b << " to " << m << endl;
       
        
        cout << "\t \t \t \t \tAre you sure(Y/N)? ";
        cin >> s;
        int x;
        if (s == 'Y')
 
        {
        m:
             mc[d].balance = mc[d].balance + b; 
            x = OTP();
             
            cout << "\t \t \t \t \tTransCash OTP: " << x << endl;
            clock_t start = clock();
            cout << "\t \t \t \t \tEnter OTP: ";
            cin >> a;
             clock_t end = clock();
             if (((end - start) / 1000) > 120)
            {
                cout << "\t \t \t \t \tOTP time has expired" << endl;
                goto m;
            }
            if (a == x){
                balance = balance - b;
                cout << "\t \t \t \t \tSend Money is Successful" << endl;
 
                his[cnt] = make_pair(trxID(), "Send Money");
                hist[cnt] = make_tuple(b, balance, getTime());
                cnt++;
            }
            else
                goto m;
        }
        else
            goto c;
    }
    else
        cout << "\t \t \t \t \tInsufficient Fund" << endl;
c:
 
    cout << "\t \t \t \t \tPress any key go to main menu....." << endl;
    getch();
    system("cls");
 
    select();
}
void TransCash ::Cash_In()
{
    cout << "\n\t \t \t \t \tCash In" << endl << endl << endl;
    float b;
    char s;
    cout << "\t \t \t \t \tEnter Amount: ";
    cin >> b;
    cout << "\t \t \t \t \tCash-in " << b << " tk" << endl;
    ;
   
    cout << "\t \t \t \t \tAre you sure(Y/N)? ";
    cin >> s;
    if (s == 'Y' || s == 'y')
    {
         balance = balance + b;
        his[cnt] = make_pair(trxID(), "Cash-in");
        hist[cnt] = make_tuple(b, balance, getTime());
        cnt++; 
          cout << "\t \t \t \t \tCash_in is Successful" << endl;
    }
      
    else
        goto c;
 
c:
    cout << "\t \t \t \t \tPress any key go to main menu....." << endl;
    getch();
    system("cls");
 
    select();
}
void TransCash ::Cash_Out()
{
    cout << "\n\t \t \t \t \tCash Out" << endl << endl << endl;
    float b;
    int a;
    int x;
    char s;
    cout << "\t \t \t \t \tEnter Amount: ";
    cin >> b;
    cout << "\t \t \t \t \tCash_out " << b << " tk" <<  endl;
 
    if (balance >= b)
    {
        cout << "\t \t \t \t \tAre you sure(Y/N)? ";
        cin >> s;
        if (s == 'Y')
        {
           
        g:
            x = OTP();
          
            cout << "\t \t \t \t \tTransCash OTP: " << x << endl;
              clock_t start = clock();
            cout << "\t \t \t \t \tEnter OTP: ";
            cin >> a;
             clock_t end = clock();
             if (((end - start) / 1000) > 120)
            {
                cout << "OTP time has expired" << endl;
                goto g;
            }
            if (a == x)
            {
                 balance = balance - b;
                cout << "\t \t \t \t \tCash-out is Successful" << endl;
                his[cnt] = make_pair(trxID(), "Cash Out");
                hist[cnt] = make_tuple(b, balance, getTime());
                cnt++;
            }
            else
                goto g;
        }
    }
    else
    {
        cout << "\t \t \t \t \tInsufficient Fund" << endl;
    }
    cout << "\t \t \t \t \tPress any key go to main menu....." << endl;
    getch();
    system("cls");
 
    select();
}
void TransCash ::Pay_Bill()
{
    cout << "\n\t \t \t \t \tPay Bill" << endl << endl << endl;
    int a, tk, x, f;
    char d;
    string s;
    cout << "\t \t \t \t \tEnter Bill Type (Gas/Electricity/Water/Internet-1/2/3/4):";
    cin >> a;
    if (a == 1)
        s = "Gas Bill";
    else if (a == 2)
        s = "Electricity Bill";
    else if (a == 3)
        s = "Water Bill";
    else
        s = "Internet Bill";
 
    cout << "\t \t \t \t \tYour " << s << " :" ;
    cin >> tk;
 
    if (tk <= balance)
    {
        cout << "\t \t \t \t \tAre you sure(Y/N)? ";
        cin >> d;
        if (d == 'Y')
        {
      otp:      
            x = OTP();
            
 
            cout << "\t \t \t \t \tTransCash OTP: " << x << endl;
            clock_t start = clock();
            
            cout << "\t \t \t \t \tEnter OTP: ";
            cin >> f;
             clock_t end = clock();
             if (((end - start) / 1000) > 120)
            {
                cout << "OTP time has expired" << endl;
                goto otp;
            }
            if (f == x){
            balance = balance - tk;
                cout << "\t \t \t \t \tBill payment is Successful" << endl;
                 his[cnt] = make_pair(trxID(), s);
                hist[cnt] = make_tuple(tk, balance, getTime());
                cnt++;
            }
            else
                cout << "\t \t \t \t \tInvalid OTP....";
        }
    }
    else
        cout << "\t \t \t \t \tInsufficient balance..." << endl;
    cout << "\t \t \t \t \tPress any key go to main menu....." << endl;
    getch();
    system("cls");
 
    select();
}
void TransCash ::Check_Balance()
{
    cout << "\n\t \t \t \t \tCheck Balance" << endl << endl << endl;
    cout << "\t \t \t \t \tBalance: " << balance << " tk" << endl;
 
    cout << "\t \t \t \t \tPress any key go to main menu....." << endl;
    getch();
    system("cls");
 
    select();
}
void TransCash ::History()
{
     cout << "\n\t \t \t \t \tHistory" << endl << endl << endl;
    cout << left << setw(20) << "\t \t \t \t \t TransCash ID  " << setw(20) << "Description" << setw(10) << "Amount" << setw(10) << "Balance"
         << "Date & Time" << endl;
    for (int i = 0; i < cnt; i++)
    {
        cout <<"\t \t \t \t \t "<< left << setw(20) << his[i].first << setw(20) << his[i].second;
        cout << fixed << setprecision(2) << setw(10) << get<0>(hist[i]) << setw(10) << get<1>(hist[i]) << get<2>(hist[i]) << endl;
    }
 
    cout << "\t \t \t \t \t Press any key go to TransCash Menu" << endl;
    getch();
    system("cls");
    select();
}
 
int Menu1()
{
    int op;
 
    cout << "\t \t \t \t \t Welcome to TransCash" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\tPress Any Key To Proceed" << endl;
    getch();
    system("cls");
    cout << "\t \t \t \t \t\tTransCash Login" << endl;
    cout << endl;
    cout << "\t \t \t \t \t 1. Login" << endl;
    cout << "\t \t \t \t \t 2. Register" << endl;
    cout << "\t \t \t \t \t 3. Exit" << endl;
    cout << endl;
    cout << "\t \t \t \t \t Enter Your Option : ";
 
    cin >> op;
    return (op);
}
 
int Search(string m)
{
    int i, pos = -1;
    for (i = 0; i <= total;   i++)
        if (mc[i].getMobile() == m)
            pos = i;
    return (pos);
}
 
int getPin()
{
    string pass = "\t \t \t \t \t ";
    char ch;
    ch = getch();
    while (ch != 13)
    {
        if (ch != 8)
        {
            pass.push_back(ch);
            cout << "*";
            ch = getch();
        }
        else
        {
            if (!pass.empty())
            {
                pass.pop_back();
                cout << "\b \b"; // \b = backspace character
            }
            ch = getch();
        }
    }
    return (stoi(pass));
}
 
void Register()
{
    system("cls");
    string m;
    char n[100];
    int c, p, q;
    int x, o;
 
    cout << "\n\t \t \t \t \t Register" << endl;
    cout << endl;
     do
    {
    cout << "\n\t \t \t \t \t Enter your Mobile No. (11-digits) : ";
    cin >> m;
      if (m.length() != 11)
            cout << "\n\t \t \t \t \tMobile number must be 11 digits" << endl;
    } while (m.length() != 11);
    
 
    cin.ignore();
    q = Search(m);
    if (q < 0)
    {
        cout << "\t \t \t \t \t Enter your Name : ";
        cin.getline(n, 100);
        do
        {
            cout << "\t \t \t \t \t Enter your PIN (in 5 digit): ";
            p = getPin();
            cout << endl;
            cout << "\t \t \t \t \t Confirm your PIN : ";
            c = getPin();
            cout << endl;
            if (c != p)
                cout << "\t \t \t \t \t PINs are not same, Please try Again"<<endl;
        } while (c != p);
    otp:
        x = OTP();
       
 
        cout << "\n\t \t \t \t \t Your TransCash OTP: " << x << endl;
         clock_t start = clock();
        cout << "\t \t \t \t \t Enter your OTP: ";
        cin >> o;
         clock_t end = clock();
         if (((end - start) / 1000) > 120)
        {
            cout << "\t \t \t \t \t OTP time has expired" << endl;
            goto otp;
        }
        if (x == o)
        {
            total++;
            mc[total].setData(m, n, p,0.0);
            cout << endl;
            cout << "\t \t \t \t \t Registration Successful" << endl;
        }
        else
            cout << "\t \t \t \t \t Invalid OTP detected" << endl;
    }
    else
        cout << "\t \t \t \t \t Sorry, Member already exists..." << endl;
 
    cout << endl;
    cout << "\t \t \t \t \t Press Any Key to go to the Main Menu" << endl;
    getch();
    system("cls");
}
 
int Login()
{
    system("cls");
    cout << endl
         << "\t \t \t \t \tLogin" << endl;
    cout << endl;
    int p;
    string m;
    cout << endl
         << "\t \t \t \t \tEnter Mobile Number : ";
    cin >> m;
    cout << endl
         << "\t \t \t \t \tEnter PIN : ";
 
    p = getPin();
    cout << endl;
    int e = Search(m);
    put = e;
    int c = mc[e].match(m, p);
    if (c == 1)
    {
        cout << "\t \t \t \t \tLogin Successful" << endl;
        cout << endl;
        cout << "\t \t \t \t \tPress Any key to go to TransCash Main Menu" << endl;
        getch();
        system("cls");
        select();
        return e;
    }
    else
    {
        cout << endl;
        cout << "\t \t \t \t \tInvalid Login Detected!" << endl;
    }
return 0;
    getch();
    system("cls");
}
 
int select()
{
    int n = Main_Menu();
    if(n == 0 || n>= 10){
               cout << "\t \t \t \t \tInvalid Option" << endl<< endl;
        ;
        cout << "\t \t \t \t \tPress any key go to TransCash Menu" << endl;
        getch();
        system("cls");
        select();
    }
    else{
        switch (n)
    {
    case 1:
        mc[put].Update();
        break;
    case 2:
        mc[put].Remove();
        break;
    case 3:
        mc[put].Send_Money();
        break;
    case 4:
        mc[put].Cash_In();
        break;
    case 5:
        mc[put].Cash_Out();
        break;
    case 6:
        mc[put].Pay_Bill();
        break;
    case 7:
        mc[put].Check_Balance();
        break;
    case 8:
        mc[put].History();
        break;
    case 9:
        system("cls");
       
        return 0;
    }
    }
    
   
    return 0;
}
 
int trxID()
{
    srand(time(0));
    int x = +rand();
    return x;
}
 
string getTime()
{
 
    time_t now = time(0);
    char *dt = ctime(&now);
    return string(dt);
}
 
int OTP()
{srand(time(0));
    int x = 1000 + rand() % 9000;
    return x;
}
int Main_Menu()
{
    // You WERE HERE
    cout << "\t \t \t \t \t TransCash Main Menu" << endl;
    cout << endl;
    cout << "\t \t \t \t \t 1. Update Me" << endl;
    cout << "\t \t \t \t \t 2. Remove Me" << endl;
    cout << "\t \t \t \t \t 3. Send Money" << endl;
    cout << "\t \t \t \t \t 4. Cash-in" << endl;
    cout << "\t \t \t \t \t 5. Cash-out" << endl;
    cout << "\t \t \t \t \t 6. Pay Bill" << endl;
    cout << "\t \t \t \t \t 7. Check Balance" << endl;
    cout << "\t \t \t \t \t 8. History" << endl;
    cout << "\t \t \t \t \t 9. Logout" << endl;
 
 
    cout << "\t \t \t \t \t Enter Your Option : ";
    int s;
    cin >> s;
    system("cls");
    return s;
}
int main()
{
    int op;
 
    for (;;)
    {
        op = Menu1();
       
        if (op == 3)
            break;
        switch (op)
        {
        case 1:
            Login();
            break;
        case 2:
            Register();
            break;
        }
    }
    return 0;
}
 
/*
01644409903
Hisham
55555
 
01655554444
Tonmoy
66666
 */