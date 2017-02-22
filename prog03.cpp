// Name:         Daniel Humphrey, Nicholas Knoch
// Program:      CSC 275 Program 3
// Due Date:     02/19/17
// Compiler:     GNU GCC

//Main

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

#include "student.h"
#include "student.cpp"


int main() {
     bool isRunning = true;         //bool variable to use with our maintenance mode
    int sizet;                      //size of the dynamic Student array
    string choice;                  //variable to know what choice is selected in maintenance mode


    cout<<"Input the size of the database: "<<endl;
    cin>>sizet;         //input for size of the dynamic student array
    cout<<"Size is: " <<sizet<<endl;
    Student* arry;
    arry = new Student[sizet];                      //our dynamic array of type student

    int i = 0;
    while (!(i == sizet) ) {                    //loop for inputing the data
        cin >> arry[i];                         //input the data
        i++;
    }

    while (isRunning ==true){
        cout<<"You have entered the database maintenance mode. \nType help for a list of commands, thank you!"<<endl;       //maintenance mode after all the initial inputting is done
        cin >> choice;          //enter in your option
        if(choice == "quit"){
            cout<<"You have selected the quit function, thank you!"<<endl;
            delete [] arry;                                                            //use the destructor to free up the memory taken by the dynamic array
            isRunning= false;
        }
        else if(choice == "add"){
            cout<<"You have selected the add function, thank you!"<<endl;
            addStudent(arry,sizet);                                                     //call the addStudent function to add a student to the dynamic array
        }
        else if(choice == "list"){
            cout<<"You have selected the list function, thank you!"<<endl<<endl;
            for(int j=0; j<sizet; j++){                                               //choice "list" to print out the dynamic array
                cout<<"Student "<<j<<": "<<arry[j]<<endl;
            }
        }
        else if(choice == "copy"){                                                   //choice "copy" to copy the information of student m to student n
                int indexn,indexm;
                cout<<"You have selected the copy function, thank you!"<<endl;
                cin>>indexn>>indexm;            //input for selecting what student to copy from and to
                arry[indexn] = arry[indexm];
        }
        else if(choice == "delclass"){                                                  //choice "delclass" to delete a particular class from a particular student
            int index, indexofClass;
            cout<<"You have selected the delclass function, thank you!"<<endl;
            cin>>index>>indexofClass;           //input for what class and what student
            arry[index].delClass(indexofClass);     //call delCLass function to delete that class
        }
        else if(choice == "delete"){                                                //choice "delete" to completely remove a student from the dynamic array
            cout<<"You have selected the delete function, thank you!"<<endl;
            int index;
            cin>>index;         //index for which student to delete
            if(index<sizet){
                for(int j=index;j<(sizet-1);j++){       //loop to delete the index value in the array and move the other values accordingly
                    cout<<j<<endl;
                    arry[j]=arry[j+1];
                }
                sizet--;
            }
        }
        else if(choice == "reset"){                                                 //choice "reset" to empty out the classList of a particular student
            cout<<"You have selected the reset function, thank you!"<<endl;
            int index;
            cin>>index;     //index for which student to reset their classes
            arry[index].reset();
        }
        else if(choice == "newclass"){                                                //choice "newclass" to add a new class to a particular student
            int index;
            cout<<"You have selected the newclass function, thank you!"<<endl;
            cin>>index;              //index for which student you want to add a new class to
            arry[index].newClass();
        }
        else if(choice == "help"){                                                  //choice "help" to know your choice options
                cout<<"\nreset n - resets student n's classes to 0"<<endl;
                cout<<"list - print out the database"<<endl;
                cout<<"newclass n - adds a new class to student n"<<endl;
                cout<<"add - adds a student to the database"<<endl;
                cout<<"delclass n m - removes class m from student n"<<endl;
                cout<<"quit - to terminate the program"<<endl;
                cout<<"copy n m - to copy student m's information to student n"<<endl;
                cout<<"delete n - to remove student n from the database"<<endl<<endl;
        }
        else{
            cout<<"That is not a recognized command"<<endl;                         //if you type in an invalid choice
        }
    }    //end of while
return 0;
}           //end of main
