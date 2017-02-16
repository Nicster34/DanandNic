// Name:         Daniel Humphrey
// Program:      CSC 275 Program 3
// Due Date:     02/19/17
// Compiler:     GNU GCC


//implementation

istream& operator >>(istream& in, Student& rhs){          //the overloaded >> operator to use with type credit
    in>>rhs.lname>>rhs.fname>>rhs.nclasses;
    for (int j=0; j<rhs.nclasses;j++)
    {
        in>>rhs.classList[j];
    }
    return in;
}



ostream& operator <<(ostream& out, const Student& rhs){           //the overloaded << operator to use with type credit

return out << rhs.lname<< ", " << rhs.fname << ", # of classes: "<< rhs.nclasses<<" Classes are: "<< *rhs.classList;
}


Student::Student() : lname("Smith"), fname("John"), nclasses(1) {
    classList = new string[1];
    for (int j=0; j<nclasses;j++)
    {
        classList[j]="default";
    }
}//, classList("BUS100")
Student::Student(string lastname, string firstname , int numclasses):lname(lastname), fname(firstname), nclasses(numclasses){
    classList = new string[numclasses];
    for (int j=0; j<numclasses;j++)
    {
        classList[j]="default";
    }
}
