#pragma once 
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Phone  
{  
private:  
   char* name;  
   int homeNumber;  
   int workNumber;  
   int mobileNumber;  
   char* job;  
   static Phone* contacts;
   static int size;
     

public:  
   Phone();  
   Phone(const char* n, int hn, int wn, int mn, const char* j); 
   Phone(const Phone& p);  
   void PrintPhone() const; 

   char* getName(); 
   int getHomeNumber() const;  
   int getWorkNumber() const;  
   int getMobileNumber() const;  
   char* getJob(); 

   void setName(const char*);  
   void setHomeNumber(int);  
   void setWorkNumber(int);  
   void setMobileNumber(int);  
   void setJob(const char*);

   void show() const;
   void save(ofstream& fout) const;
   void load(ifstream& fin);

   static void addContact(const Phone& c);  
   static void deleteContact();
   static void searchByName(const char* n);  
   static void showAllContacts();  
   static void saveToFile(const string& file);  
   static void loadFromFile(const string& file);  
   ~Phone();  
};
   
