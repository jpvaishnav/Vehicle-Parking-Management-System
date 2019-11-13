#include<bits/stdc++.h>
//#include<conio.h>
//#include<process.h>
#include<fstream>
using namespace std;
//int count=0;
int login(){
  /* if(count==5){
      system("CLS");
      cout<<"Wrong attempt for 5 times \a \a "<<endl;
      exit(0);
   }
   count++;*/
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\n\n\n\t\t\t\t\tWelcome to Parking Management System (Creator: JP) \n\t\t\t\t\tLogin to continue";
   cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "b18cse017"){
      cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
      system("PAUSE");
      
   }else{
      cout << "\n\n\n\n\t\t\t\t\t\aAccess Aborted...Please Try Again!!\n";
      system("PAUSE");
      system("CLS");
      login();
   }
}
class location{
public:	
	int postelCode;
	string Region;
	int floor;
};
class parkingArea:public location{
public:     
     string name;
};
class vehicleModel{
public:	
	string brandName;
};
class vehicle:public vehicleModel{
public:    
    string vehicleNumber;
    double size;
};
class parkingSpot:public location{
public:    
    string slotId;
    double size;
};
class token{
public:
	string uniqueCode;
	double entryTime;
};
class Bill:public token{
public:
	double price;

};
int main(){
	int login();
	login();
	/*while(1) {
  system("CLS");
     cout << "\n\n\t\t ====== CAR PARKING RESERVATION SYSTEM ======";
     cout <<"\n\n                                          ";
     cout<<" \n\t\t\t======================";
     /*cout << "\n\n\t\t\t  1. Arrival of a Car";
     cout << "\n\n\t\t\t  2. Total no of cars Arrived";
     cout << "\n\n\t\t\t  3. Total parking charges of all cars with details";
     cout << "\n\n\t\t\t  4. Departure of the car";
     cout << "\n\n\t\t\t  5. Exit Program";
     cout<<" \n\t\t\t======================";
     cout << "\n\n";
     cout << "\n\n\t\t\t  1. Entry of vehicle";
     cout << "\n\n\t\t\t  2. Exit of vehicle";
     cout << "\n\n\t\t\t  3. Vehicles data at present";
     cout << "\n\n\t\t\t  4. All data";
     cout << "\n\n\t\t\t  5. Exit Program";
     cout << "\n\n\t\t\t  5. Exit Program";
     cout<<" \n\t\t\t======================";
     cout << "\t\t\t Select Your Choice ::";
     cin>>choice;
     switch(choice)
     {
      case 1 :
        {   
            char f;
            cout<<"\n\n\t\t==Do You Want to continue==y/n ";
            cin>>f;
            if(f=='y')
            {
            
        ofstream f1("parking3.dat",ios::binary|ios::out|ios::app);
                a.input();
                f1.write((char*)&a,sizeof(a));
        }
              break;
        }
       case 2 :
           {
            system("CLS");
         cout << "\n\n\t\t=== View the Records in the Parking Database ===";
           cout << "\n";
           ifstream infile("parking3.dat",ios::binary|ios::in);
           int d=1;
           while (infile.read((char *)&a,sizeof (a)))
       {
    system("CLS");
           cout << "\n";
           cout<<"\n\n\tThe Car position in parking lot : "<<d;
           d++;
           a.output();
           cout<<"\n";
           cout<<"\n\n\n";
           system("PAUSE");
           cout<<endl;
           }
       
           break;
           }
        case 4: 
       {
       
       delete_record();
       break;
  }
      case 3:
    {
        ifstream infile("parking3.dat",ios::binary|ios::in);
           while (infile.read((char *)&a,sizeof (a)))
       {
             cout << "\n";
       a.cal();
       a.output();
       cout<<"\n";
       cout<<endl;
       
          }
          break;
   }
      
      case 5: 
       {
        system("CLS");
        cout<<"\n\n\n\t\t\t \n\t\t\t ©Jay Prakash \n";
       exit(0);
        break;
      }
      default : 
       {
       cout<<"\n\n\t\t Invalid input";
      cout<<"\n\n\t\tPress Enter to continue";
    }
   }
getch();
}*/
}