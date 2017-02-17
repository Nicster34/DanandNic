// Name:         Daniel Humphrey
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
    Student* arry;
    arry = new Student[sizet];

    int i = 0;
            //loop for inputing the data
    while (!(i == sizet) ) {                    //i is counter of number of people
        cin >> arry[i];            //input the data
        i++;
    }

    while (isRunning ==true){
        cout<<"You have entered the database maintenance mode. \nType help for a list of commands, thank you!"<<endl;
        cin >> choice;
        if(choice == "quit"){
            cout<<"You have selected the quit function, thank you!"<<endl;
            isRunning= false;

        }
        else if(choice == "add"){
            cout<<"You have selected the add function, thank you!"<<endl;
            addStudent(arry,sizet);
        }
        else if(choice == "list"){
            cout<<"You have selected the list function, thank you!"<<endl;
            for(int j=0; j<sizet; j++){
                cout<<arry[j]<<endl;
            }
        }
        else if(choice == "delclass"){
            int index, indexofClass;
            cout<<"You have selected the delclass function, thank you!"<<endl;
            cin>>index>>indexofClass;
            arry[index].delClass(indexofClass);
        }
        else if(choice == "delete"){
            cout<<"You have selected the delete function, thank you!"<<endl;
        }
        else if(choice == "reset"){
            cout<<"You have selected the reset function, thank you!"<<endl;
        }
        else if(choice == "newclass"){
            int index;
            cout<<"You have selected the newclass function, thank you!"<<endl;
            cin>>index;
            arry[index].newClass();
        }
        else if(choice == "help"){
                cout<<"reset - Resets to default"<<endl;
                cout<<"reset - Resets to default"<<endl;

        }
        else{
            cout<<"That is not a recognized command"<<endl;
        }
    }




return 0;
}
