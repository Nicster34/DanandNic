// Name:         Daniel Humphrey
// Program:      CSC 275 Program 3
// Due Date:     02/19/17
// Compiler:     GNU GCC


//interface
class Student{

    public:
        friend istream& operator >>(istream&,Student&);
        friend ostream& operator <<(ostream& out, const Student& rhs);
        Student();
        Student(string, string, int);



    private:
        string lname;
        string fname;
        int nclasses;
        string* classList;



};
