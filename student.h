// Name:         Daniel Humphrey, Nicholas Knoch
// Program:      CSC 275 Program 3
// Due Date:     02/19/17
// Compiler:     GNU GCC

//Interface

class Student{
    public:
        friend istream& operator >>(istream&,Student&);                         //Overloaded input operator
        friend ostream& operator <<(ostream& out, const Student& rhs);          //Overloaded output operator
        Student();                                                              //Default constructor
        Student(string, string, int);                                           //Constructor
        void newClass();                                                        //Function to create a new class for a particular student
        void delClass(int);                                                     //Function to delete a class from a particular student
        void reset();                                                           //Function to reset a particular student's data to empty
        void operator =(const Student&);                                        //Overloaded assignment operator
        ~Student();                                                             //Destructor
    private:
        string lname;                                                           //Last name of student
        string fname;                                                           //First name of student
        int nclasses;                                                           //Number of classes for a student
        string* classList;                                                      //List of all the classes for a student

};
