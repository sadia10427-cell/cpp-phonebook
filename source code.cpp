#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;

class PhoneBook{
	
private:
	string Name, PhNo , Address;

public:
	PhoneBook():Name(""), PhNo(""), Address(""){	}

setName(string name){
	Name = name;
}	
setPhNo(string phNo){
	PhNo = phNo;
}	
setAddress(string address){
	Address = address;
}


string getName(){
	return Name ;
}	
	
string getPhNo(){
	return PhNo ;
}	

string getAddress(){
	return Address ;
}		

};
addNo(PhoneBook ph){
system("cls");
string name, phNo , address;

cout<<"\tEnter The Name Of User : ";
cin>>name;
ph.setName(name);	

cout<<"\tEnter The PhoneNo Of User : ";
cin>>phNo;
ph.setPhNo(phNo);	

cout<<"\tEnter The Address Of User : ";
cin>>address;
ph.setAddress(address);	

ofstream outfile("PhoneBook.txt",ios::app);
if(!outfile){
	cout<<"\tError : File Can't Open! "<< endl;
}
else{
	outfile<<"\t"<<ph.getName()<<" : "<<ph.getPhNo()<<" : "<<ph.getAddress()<<endl<<endl;
}
outfile.close();
cout<<"\tPhone Number Added To Phone Book ! ";
Sleep(3000);	
}

searchNo(){
system("cls");
string name;
cout<<"\t Enter The Name Of User : ";
cin>>name;

ifstream infile("PhoneBook.txt");
if(!infile){
	cout<<"\tError : File Can't Open !"<<endl;
}
else{
string line;
bool found= false;
while(getline(infile,line)){
	stringstream ss;
	ss<<line;
string userName , userPhNo , userAddress;
char delimiter;
ss>>userName>>delimiter>>userPhNo>>delimiter>>userAddress;

if(name== userName){
	found= true;
	cout<<"\t"<<userName<<"\t"<<userPhNo<<"\t"<<userAddress<<"\n";
}
}
if(!found){
	cout<<"\tUser Not Found In The Phone Book! "<<endl;
}
}
infile.close();
Sleep(3000);	
	
}
int main(){
	
PhoneBook ph;

bool exit= false;
while (!exit){
system("cls");
int val;
cout<<"\tWelcome To Phone Book Management System"<<endl;
cout<<"\t****************************************"<<endl;
cout<<"\t1. Add Number"<<endl;
cout<<"\t2. Search Number"<<endl;
cout<<"\t3. Exit"<<endl;
cout<<"\tEnter Your Choice: ";
cin>>val;
if(val==1){
	addNo(ph);
}

else if(val==2){
	searchNo();
}

else if(val==3){
system("cls");
exit=true;
cout<<"\t You Exit The System!"<<endl;

Sleep(3000);
}
}



}








