// Name:         Daniel Humphrey & NIC KNOCH
// Program:      CSC 275 Program 3
// Due Date:     02/19/17
// Compiler:     GNU GCC





#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

#include "student.h"
#include "student.cpp"


//main
int main() {
     bool isRunning = true;
    int sizet;
    string choice;


    cout<<"Input the size of the database: "<<endl;
    cin>>sizet;
    cout<<"Size is: " <<sizet<<endl;
    Student* array;
    array = new Student[sizet];

    int i = 0;
            //loop for inputing the data
    while (!(i == sizet) ) {                    //i is counter of number of people
        cin >> array[i];            //input the data
        i++;
    }
    cout<<"You have entered the database maintenance mode. Type HELP for a list of commands, thank you!"<<endl;
    cout<<"Note: is case sensitive."<<endl;
    while (isRunning ==true){
        cin >> choice;
        if(choice == "quit"){
            cout<<"You have selected the quit function, thank you!"<<endl;
            isRunning= false;

        }
        else if(choice == "add"){
            cout<<"You have selected the add function, thank you!"<<endl;
        }
        else if(choice == "list"){
            cout<<"You have selected the list function, thank you!"<<endl;
            for(int j=0; j<sizet; j++){
                cout<<array[j]<<endl;
            }
        }
        else if(choice == "delclass"){
            cout<<"You have selected the delclass function, thank you!"<<endl;
        }
        else if(choice == "delete"){
            cout<<"You have selected the delete function, thank you!"<<endl;
        }
        else if(choice == "reset"){
            cout<<"You have selected the reset function, thank you!"<<endl;
        }
        else if(choice == "newclass"){
            cout<<"You have selected the newclass function, thank you!"<<endl;
        }
    }




return 0;
}
