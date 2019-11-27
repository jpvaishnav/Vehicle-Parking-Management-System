#include<bits/stdc++.h>
#include<conio.h>   //system("PAUSE") and system("CLS")   
#include<fstream>   //File handling.
#include<map> 

#include "Huffman.h"   //For huffman encoding
//#include<chrono>  //Chrono for time.
#include<ctime>    //time library
using namespace std;
//3 Maps for structural size small,medium and large
map<int,int> mapSmall;
map<int,int> mapMedium;
map<int,int> mapLarge;
//Map for count of a particular brand 
map<string,string> SerialNumber_to_Size;
map<string,int> _brand;// Stroring 
map<string,time_t> entry_time; //entrytime store.
map<string,int> vehicleEntryRecord;
string getSlotID(int _size_){
  string ans="";
  //search in the file if the slot available or not.
  //if not available...print sorry message and exit.
  //if available ...return the slot id
  //"A" for structural size 1 vehicle
   //"B" for structural size 2 vehicle
   //"C" for structural size 3 vehicle
  switch(_size_){
    //ans="A";
    case 1:{
      ans="A";
      for(int i=1;i<=100;i++){
        if(mapSmall[i]==0){
           mapSmall[i]=1;
           char ch='0'+i;
           ans+=ch;
           return ans;
        }
      }
      break;
    }
    case 2:{
      ans="B";
      for(int i=1;i<=100;i++){
        if(mapMedium[i]==0){
          mapMedium[i]=1;
          char ch='0'+i;
            ans+=ch;
            return ans;
        }
      }
      break;
    }
    case 3:{
      ans="C";
      for(int i=1;i<=100;i++){
        if(mapLarge[i]==0){
          mapLarge[i]=1;
          char ch='0'+i;
            ans+=ch;
            return ans;
        }
      }
      break;
    }
  }
  cout<<"\n\n\t\t Sorry , no slot available\n\n";
  exit(0);
}
//Number of trials , admin can try for password. Can be changed dynamically.
int trial=0;
//encoded string through huffman tree
string encodedstring[1];
//password taken as input by console.
string pass[1];
int login(){
  if(trial>=1){
        cout<<"\n\n\t\t\t unsuccessfull attempt"<<endl;
        exit(0);
        //Exiting the program after Unsuccessfull attempt.
  }
   pass[trial] ="";
   char ch;
   cout <<"\n\n\n\n\n\n\n\t\t\t\t\tWelcome to Parking Management System (Creator: JP) \n\t\t\t\t\tLogin to continue";
   cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
   //_getch() read input from console but it doesn't write that input on console.
   ch = _getch();
   while(ch != 13){//character 13 is Enter defined under ASCII table, Carriage return line feed.
      pass[trial].push_back(ch);
      //Printing * as console takes input. It secures the password.
      cout << '*';
      ch = _getch();
   }
   //calculatinf freq of each character of password.
   calcFreq(pass[trial],pass[trial].length());
   //Build the huffman tree.
   HuffmanCodes(pass[trial].length());
   //Get the encoded string.
   for(int i=0;i<pass[trial].length();i++){
        encodedstring[trial]+=codes[pass[trial][i]];
   }
   //Compare with encoded actual password.
   if(encodedstring[trial] == "001111000101110100010111011"){
      cout << "\n\n\n\n\t\t\t\t\t Welcome To the System \n\n";
      system("PAUSE");   //Press any key to continue...
   }else{
      trial++;
      cout << "\n\n\n\n\t\t\t\t\t\aWrong password...Please Try Again!!\n";
      system("PAUSE");
      system("CLS");   //Opening console with cleared previous lines.
      login();
   }
}
//vector of string containing all Vehicle Numbers entered in system.
vector<string> allvehiclenumbers;
//class with it's data members.
class vehicle{
public:    
    string vehicleNumber;
    double structuralSize;
    string brandName;
    int wheels;
};
//Array of class vehicle.
vehicle v[100];
//Count for entry
int vcount=0;
//Count for exit.
int exit_count=0;
//Token to be collected.
class token{
public:
  int uniqueID;
};
token _token[100];
//Bill to be generated.
class Bill:public token,public vehicle{
public:
  time_t exitTime;
  double price;
  double createAmount(time_t exitTime);
  void incrementBrandCounter();
};   
Bill bill[100];
//separate function for price calculating, could be changed according to need.
double calculatePrice(time_t e1,time_t e2){
  return difftime(e2,e1)*(0.0556);   //1 hour= 200Rs.
}
//Payment class which ensures all payment possibilities.
class Payment{
public:
    void getpayment(double moneyToBeCollected){
         cout<<"\n\n\t\t"<<"Press \n\t 1.Cash\n\t 2.e-payment"<<endl;
         int xy;
         cin>>xy;
         system("CLS");
         switch(xy){
          case 1:{
            cout<<"\n\n\t\tInsert cash below "<<endl;
            double temp_cash;
            cin>>temp_cash;
            if(abs(temp_cash-moneyToBeCollected)<=0.1){
              cout<<"\n\n\t\tPayment Successfull\n\n\t\t Visit again!"<<endl;
            }
            else if(temp_cash>moneyToBeCollected){
              cout<<"\n\n\t\t Collect the change : "<<temp_cash-moneyToBeCollected<<endl;
            }
            else{
              cout<<"\n\n\t\tInsufficient money, Kindly insert "<< abs(temp_cash-moneyToBeCollected)<<" more"<<endl;
              getpayment(abs(temp_cash-moneyToBeCollected));
            }
            break;
          }
          case 2:{
            //barcode printing.
            cout<<"\n\n\t\t Scan the barcode sticker and proceed \n\n\n"<<endl;

            cout<<"\t\t Thank You and Visit Again \n\n";
            break;
          }
          default:{
            cout<<"\n\n\t\t Kindly press one of the button";
            getpayment(moneyToBeCollected);
          }
         }
         system("PAUSE");
    }
};
Payment payment[100];





//Main section starts.
int main(){
  int login();
  login();
  //will execute after logged in.
  while(1) {
  system("CLS");
     cout << "\n\n\t\t ======  PARKING MANAGEMENT SYSTEM ======";
     cout <<"\n\n                                          ";
     
     cout << "\n\n\t\t\t  1. Entry of vehicle : Entry sensor ON";
     cout << "\n\n\t\t\t  2. Exit of vehicle : Exit sensor ON";
     cout << "\n\n\t\t\t  3. Open database ";
     cout << "\n\n\t\t\t  4. Exit Program ";
     cout << "\n\n\t\t\t  5. All time database ";
     cout<<"\n\n";
     cout<<  " \n\t\t====================================";
     cout << "\n\n\t\t\t Select Your Choice ::";
     int choice;
     cin>>choice;
     switch(choice)
     {
      case 1 :
        {   system("CLS");
              //Opening file to maintain vehicle data.
              ofstream fout;
              fout.open("data.dat", ios:: out | ios::app);
              //Taking essential attributes for class Vehicle.
              cout<<"\n\n\t\t\t Vehicle serial number from image sensor : ";
              cin>>v[vcount].vehicleNumber;
              fout<<"Vehicle serial number : "<<v[vcount].vehicleNumber<<endl;
              vehicleEntryRecord[v[vcount].vehicleNumber]=1;
              allvehiclenumbers.push_back(v[vcount].vehicleNumber);
              cout<<"\n\n\t\t\t Vehicle structural size from image sensor  1: Small size 2: Medium size 3: Large size \n\t\t\t Press integar value(1/2/3)  : ";
              cin>>v[vcount].structuralSize;
              fout<<"Structural size of vehicle : "<<v[vcount].structuralSize<<endl;
              cout<<"\n\n\t\t\t Vehicle brand name from sensor : ";
              cin>>v[vcount].brandName;
              fout<<"Brand name of vehicle : "<<v[vcount].brandName<<endl;
              cout<<"\n\n\t\t\t Type of vehicle : \n\n\t\t\t 2-wheel / 3-wheel / 4-wheel : ";
              cin>>v[vcount].wheels;
              fout<<"Wheels : "<<v[vcount].wheels<<endl;
          
              system("PAUSE");
              //Assigning slot 
              string ans=getSlotID(v[vcount].structuralSize);
              SerialNumber_to_Size[v[vcount].vehicleNumber]=ans;
              cout<<"\n\n\t\t\t Parking available at : ";
              cout<<ans<<endl;
              fout<<"Allotted parking slot : "<<ans<<endl;
              //Updating class token.
              _token[vcount].uniqueID=vcount;//System prints a token for user reference.
              cout<<"\n\n\t\t\t Collect the token\n";
              system("PAUSE");
              time(&entry_time[v[vcount].vehicleNumber]);
              //writing in file.
              fout<<"Entry time : "<<ctime(&entry_time[v[vcount].vehicleNumber])<<endl;
              cout<<"\n\n\t\t\t Vehicle Parked\n";
              system("PAUSE");
              _brand[v[vcount].brandName]++;
              //Maintaining all brand data.
              ofstream fbrand;
              fbrand.open("BrandData.dat", ios:: app | ios:: out);
              fbrand<<"Brand name : "<<v[vcount].brandName<<"   Current Count: "<<_brand[v[vcount].brandName]<<endl;
              vcount++;
              fout.close();
              fbrand.close();    
              break;
        }
    
           case 2 :{
              //scanning vehicle serial number from sensor.
              cout<<"\n\n\t\t\t Vehicle serial number from image sensor : \n";
              string s;
              int flag=0;
              cin>>s;
              //Checking if that vehicle serial number is right or wrong detected.
              string tempSlot=SerialNumber_to_Size[s];
              if(tempSlot[0]=='A'){
                  int t=tempSlot[1]-'0';
                  mapSmall[t]=0;
              }
              else if(tempSlot[0]=='B'){
                int t=tempSlot[1]-'0';
                mapMedium[t]=0;
              }
              else{
                  int t=tempSlot[1]-'0';
                  mapLarge[t]=0;
              }
              //checking for permitted vehicles.
              ifstream fsp;
              fsp.open("permitted.txt");
              string line;
              int permittedflag=0;
              while(fsp){
                  getline(fsp,line);
                  if(line==s){
                    cout<<"\n\t\t\t permitted vehicle. No need to pay"<<endl;
                    fsp.close();
                    permittedflag=1;
                    break;
                  }
              }
              if(permittedflag==1){
                break;
              }
              
              for(int i=0;i<allvehiclenumbers.size();i++){
                if(allvehiclenumbers[i]==s){
                  flag=1;
                   break;    
                }
              }
              if(!flag || vehicleEntryRecord[s]==0){
                cout<<"\n\t\t\tVehicle serial number not detected!"<<endl;
                break;
              }
              vehicleEntryRecord[s]=0;
              //updating bill class.
              bill[exit_count].vehicleNumber=s;
              time_t e1;
              time_t e2;
              e1=entry_time[s];
              time(&e2);
              //updating bill class.
              bill[exit_count].exitTime=e2;
              double money=calculatePrice(e1,e2);
              bill[exit_count].price=money;
              cout<<"\n\n\t\t\tAmount to be paid : "<<money<<endl;
              //Passing to payment class.
              payment[exit_count].getpayment(money);
              exit_count++;
            break;
           }
        case 3: 
       {   cout<<"\n\n\t\t\t Press any of them \n\t\t\t 1).Today's vehicle data\n\t\t\t 2).Bill data \n\t\t\t 3).Brand data \n\t\t\t 4).Net price "<<endl;
             int temp_var;
             cin>>temp_var;
             switch(temp_var){
              case 1: {
                for(int i=0;i<vcount;i++){
                    cout<<"\t\t\t vehicle number : "<<v[i].vehicleNumber  <<endl;
                    cout<<"\t\t\t structuralSize : "<<v[i].structuralSize  <<endl;
                    cout<<"\t\t\t Brand name : "<<v[i].brandName  <<endl;
                    cout<<"\t\t\t wheels : "<<v[i].wheels <<endl;
                    cout<<"\t\t\t Entry time: "<<ctime(&entry_time[v[i].vehicleNumber])<<endl;         
                }
                break;
              }
              case 2: {
                for(int i=0;i<exit_count;i++){
                    cout<<"\t\t\t Vehicle number : "<<bill[i].vehicleNumber<<endl;
                    cout<<"\t\t\t exitTime : "<<ctime(&bill[i].exitTime)  <<endl;
                    cout<<"\t\t\t Price : "<<  bill[i].price  <<endl;
                }
                break;
              }
              case 3: {
    
                for(int i=0;i<_brand.size();i++){
                    cout<<"\t\t\tBrand Name:"<<v[i].brandName<<"\tCount :"<<_brand[v[i].brandName]<<endl;
                }
                break;
              }
              case 4:{
                double sum=0;
                for(int i=0;i<exit_count;i++){
                      sum+=bill[i].price;
                }
                cout<<"\n\t\t\tNet income is : "<<sum<<endl;
                break;
              }
              default:{
                cout<<"\n\t\t\t Please select again "<<endl;
                break;
              }
             }
 
       break;
  }
   
      case 4: 
       {
        //exiting from the system at the end of the day.
        system("CLS");
        cout<<"\n\n\n\t\t\t Copyright Jay Prakash, T&C applied \n\t\t\t ";
       exit(0);
        break;
      }
      case 5:{   
                //writing all data for vehicles and brand.
                ifstream fin;
                fin.open("data.dat");
                string line;
                while(fin){
                  getline(fin,line);
                  cout<<line<<endl;
                }
                fin.close();
                cout<<"\n\n Brand data ::"<<endl;
                fin.open("BrandData.dat");
                while(fin){
                  getline(fin,line);
                  cout<<line<<endl;
                }
                fin.close();
                break;
      }
      default : 
       {
       cout<<"\n\n\t\t Invalid input";
      cout<<"\n\n\t\tPress Enter to continue";
    }
   }
getch();
}
}