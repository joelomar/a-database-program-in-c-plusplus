#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

int progStart();
int writeData();
int readFunction();
int searchName();

string name;
string lastName;
string email;
string inpName;
int idRec;
string nameRec;
string lastnameRec;
string emailRec;
string result;


int main() {
   
   srand(time(0));
   progStart();


	return 0;
}



//----------------START PROGRAM------------------// 

int progStart() {
     
   cout << "\nData Programm Options: Press a(Insert) b(View All) c(Search) \n";
   cin >> result;

   if (result=="a") {

        writeData(); 

    }if (result == "b") {
        
        readFunction();

   }if (result == "c") {
        
        searchName();

   }

}


//----------------OPEN AND WRITE TO DATABASE------------------//  

int writeData() {

     int id = rand() % 6000000 + 1000000;
     cout << "\nEnter your name lastname and email:" << endl;
     cin >> name >> lastName >> email;

     ofstream fileObj;
     fileObj.open("data_file.txt", ios::app);

     if (fileObj.is_open()) {

                 //--FOR DEBUGGING PURPOSE cout << "Database file is open" << endl;
                 cout << "\nThank You! your data is submited" << endl;
                 fileObj << id << ' ' << name << ' ' << lastName << ' ' << email << endl;


      }else {

        cout << "Error open Database file" << endl;
      }

      fileObj.close();
      progStart();

}


//----------------RREADING FROM DATABASE-----YOU can use the costructor for less code and will automaticly use the deconstructor-------------//

int readFunction() {

      ifstream fileReader;
      fileReader.open("data_file.txt");
      cout << "\nData list: \n \n";
      cout << "\nID: \t  Name: \t Lastname: \t email:" << endl;

      while (fileReader >> idRec >> nameRec >> lastnameRec >> emailRec) {

                 cout << idRec << ' ' << nameRec << ' ' << lastnameRec << ' ' << emailRec << endl;

      }

      fileReader.close();
      progStart();

 }


//----------------SEARCH FOR DATA-------------//

int searchName() {

    cout << "\nSearch for a user" << endl;
	cin >> inpName;

    ifstream searchObj;
    searchObj.open("data_file.txt");

      while (searchObj >> idRec >> nameRec >> lastnameRec >> emailRec) {

                 if (nameRec == inpName) {

                    cout << "\nYour Records: " << idRec << ' ' << nameRec << ' ' << lastnameRec << ' ' << emailRec << endl;

                 }

      }

      searchObj.close();
      progStart();

}