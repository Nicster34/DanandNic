// Name:         Daniel Humphrey
// Program:      CSC 275 Program 3
// Due Date:     02/19/17
// Compiler:     GNU GCC


//implementation

istream& operator >>(istream& in, Student& rhs){          //the overloaded >> operator to use with type credit
    in>>rhs.lname>>rhs.fname>>rhs.nclasses;
    rhs.classList = new string[rhs.nclasses];
    for (int j=0; j<rhs.nclasses;j++){
        in>>rhs.classList[j];
    }
    return in;
}



ostream& operator <<(ostream& out, const Student& rhs){           //the overloaded << operator to use with type credit

    out << rhs.lname<< ", " << rhs.fname << ", # of classes: "<< rhs.nclasses<<" Classes are: ";
    for (int j=0; j<rhs.nclasses;j++){
        out <<rhs.classList[j]<<" ";
    }
    return out;
}


Student::Student() : lname("Smith"), fname("John"), nclasses(1) {
    classList = new string[1];
    for (int j=0; j<nclasses;j++){
        classList[j]="default";
    }
}//, classList("BUS100")
Student::Student(string lastname, string firstname , int numclasses):lname(lastname), fname(firstname), nclasses(numclasses){
    classList = new string[numclasses];
    for (int j=0; j<numclasses;j++){
        classList[j]="default";
    }
}

void addStudent(Student* &aarry, int &currSize){
    Student*  temp = new Student[currSize+1];
    for (int i=0; i<currSize; i++){
        temp[i]=aarry[i];
    }
    delete [] aarry;
    aarry=temp;
    temp=NULL;
    currSize=currSize+1;
    cin>>aarry[currSize-1];


}
void Student::newClass(){
    string*  temp = new string[nclasses+1];
    for (int i=0; i<nclasses; i++){
        temp[i]=classList[i];
    }
    delete [] classList;
    classList=temp;
    temp=NULL;
    nclasses=nclasses+1;
    cout<<"Name of New Class: "<<endl;
    cin>>classList[nclasses-1];


}

void Student::delClass(int inx){
    if(inx<nclasses){
        for(int j=nclasses;j>inx;j--){
            classList[j]=classList[j-1];
        }
    }
    nclasses--;
}
