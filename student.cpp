// Name:         Daniel Humphrey, Nicholas Knoch
// Program:      CSC 275 Program 3
// Due Date:     02/19/17
// Compiler:     GNU GCC

//Implementation

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This is an overloaded input >> operator for type Student.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
istream& operator >>(istream& in, Student& rhs){
    in>>rhs.lname>>rhs.fname>>rhs.nclasses;
    rhs.classList = new string[rhs.nclasses];
    for (int j=0; j<rhs.nclasses;j++){
        in>>rhs.classList[j];
    }
    return in;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This is an overloaded output << operator for type Student.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ostream& operator <<(ostream& out, const Student& rhs){

    out << rhs.lname<< ", " << rhs.fname << ", # of classes: "<< rhs.nclasses<<" Classes are: ";
    for (int j=0; j<rhs.nclasses;j++){
        out <<j<<": "<<rhs.classList[j]<<" ";
    }
    return out;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This is an overloaded assignment operator for type Student.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Student::operator =(const Student &rhs){
    string* temp = new string[rhs.nclasses];    //create new dynamic array with size same as rhs array
    for(int i=0; i<rhs.nclasses; i++){          //fills new array with what is in the rhs array
        temp[i] = rhs.classList[i];
    }
    classList = NULL;                           //empty out the rhs array
    classList = temp;                           //set
    delete [] temp;
    nclasses = rhs.nclasses;
    fname = rhs.fname;
    lname = rhs.lname;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This is the default constructor for our class Student.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Student::Student() : lname("Smith"), fname("John"), nclasses(1) {
    classList = new string[1];
    for (int j=0; j<nclasses;j++){
        classList[j]="default";                 //default all classes in the classList to "default".
    }
}

Student::Student(string lastname, string firstname , int numclasses):lname(lastname), fname(firstname), nclasses(numclasses){
    classList = new string[numclasses];
    for (int j=0; j<numclasses;j++){
        classList[j]="default";
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This the destructor for our class Student, to free up the memory we allocated for the dynamic array.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Student::~Student(){
    classList=NULL;
    delete [] classList;
    cout<<"Destructor use!"<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This is a function to add a new Student object to our dynamic array
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void addStudent(Student* &aarry, int &currSize){
    Student*  temp = new Student[currSize+1];           //make a new temp array that is 1 larger than the original
    for (int i=0; i<currSize; i++){                     //loop to save all the data from the original array to the new one
        temp[i]=aarry[i];
    }
    delete [] aarry;                                    //delete original array
    aarry=temp;
    temp=NULL;
    currSize=currSize+1;
    cout<<"Input the new student: "<<endl;
    cin>>aarry[currSize-1];                             //input for the new Student
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This is a function to add a new class to a particular student.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Student::newClass(){
    string*  temp = new string[nclasses+1];             //make a new temp array that is 1 larger than the original
    for (int i=0; i<nclasses; i++){                     //loop to save all the data from the original classList array to the new one
        temp[i]=classList[i];
    }
    delete [] classList;                                //delete original classList array
    classList=temp;
    temp=NULL;
    nclasses=nclasses+1;
    cout<<"Name of New Class: "<<endl;
    cin>>classList[nclasses-1];                        //input for the new class to be added to the classList
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This is a function to delete a particular class from a particular student.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Student::delClass(int inx){
    cout<< inx<<"indx, numclass:"<<nclasses<<endl;
    if(inx<nclasses){
        for(int j=inx;j<(nclasses-1);j++){          //loop to assign each value above the index to the value below it and then
            cout<<j<<endl;                          //shrink the size of the array by 1, deleting the particular class
            classList[j]=classList[j+1];
        }
        nclasses--;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This is a function to reset a particular student's classList to empty.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Student::reset(){
    string* temp = new string[0];           //new empty array
    classList = NULL;                       //delete original
    classList = temp;
    delete [] temp;
    nclasses =0;
}
