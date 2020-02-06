#include <iostream>

using namespace std;

//Defined classes with setter and getter methods

class Student{
    string name, id;
    int acad_year;
    public:
        Student(string n, int y, string i ) : name(n), acad_year(y), id(i) {}
        Student(){}
     void setAll(string setname, int setYear, string setId){
        name = setname;
        acad_year = setYear;
        id = setId; 

     }
     string getName(){ return name; }
     string getId() { return id; }
     int getYear() { return acad_year; }

     string schoolYear(){
        string year;
        if( acad_year == 1 )
            year = "Freshman";
        else if( acad_year == 2)
            year = "Sophomore";
        else if ( acad_year == 3)
            year = "Junior";
        else if ( acad_year == 4)
            year = "Senior";

        return year;

     }
};



class Class{
    string courseid;
    int coursenum, units;
    public:

        void setClass(string setCourse, int setNum, int setUnits){
            courseid = setCourse;
            coursenum = setNum;
            units = setUnits;
        }
        
        string getCourse() { return courseid; }
        int getCoursenum() { return coursenum; }
        int getUnits() { return units; } 
};


class Registration{
    private:
        Student one;
        Class classes[10];
        int maxunits, currentUnits, classPosition;

    public:
        Registration(string name, int year, string id, int uni){
            maxunits = uni;
            currentUnits = 0;
            classPosition = 0;

            one.setAll(name,year,id);

        }
        bool addClass(string cid, int cnum, int units ){
           bool addedSuccessfully = false;
           currentUnits += units;


           if(currentUnits <= maxunits)
           {    
              
                 classes[classPosition].setClass( cid, cnum, units);
                 addedSuccessfully = true;
                 classPosition++;                              
        
           }
          
        
            return addedSuccessfully; 
        }

        friend void showAll(Registration* r);


};

//Showing Student Information

void showAll(Registration* r){

    
    cout << "\t Student Information \n";
    cout << "---------------------------------------------------------------\n";
    cout << " Student name: " << r->one.getName() << "\tID: " << r->one.getId() << "\tYear: ";
    cout << r->one.schoolYear() << endl << endl; 
    cout << "\t Classes\n";
    cout << "------------------------------------\n";
   
    for( int i = 0; i < r->classPosition; i++){ 
         
    
    cout << "Course: " << r->classes[i].getCourse() << " " << r->classes[i].getCoursenum();
    cout << "\tUnits: " << r->classes[i].getUnits() << endl;
  
       
    }
   
    cout << "-----------------------------------\n";
    cout << "Total Units:\t\t\t" << r->currentUnits << endl; 
    cout << "-----------------------------------\n";
}



//Functions used to display a menu


void displayMenu();
int choice();

int main() {

    string studentName, studentId;
    int academicYear;
    int maxUnitsAllowed; 

    cout << "Enter student name: \n";
    getline(cin, studentName);
    cout << "\n";

    cout << "Enter student id: \n";
    getline(cin,studentId);
   
    cout << "\n";

    cout << "Enter current Academic Year: \n";
    cin >> academicYear;

    cout << "\n";

    cout << "Enter max units for semester: \n";
    cin >> maxUnitsAllowed;
    cout << endl;

    Registration* reg = new Registration(studentName, academicYear, studentId, maxUnitsAllowed);
     
    int usrInput;
    do{
        displayMenu();
        usrInput = choice();

        switch(usrInput){
            case 1: {
                        string courseName;
                        int courseId, courseUnits;
                        
                        //Gathering class information
                        
                        cout << "Enter course name: \n";
                        cin.ignore();
                        getline(cin, courseName);
                        cout <<"\n";

                        cout << "Enter course id: \n";
                        cin >> courseId;

                        cout <<"\n";

                        cout << "Enter units of course: \n";
                        cin >> courseUnits;
                        cout <<"\n";
                        
                        //Adding class
                        
                        if(reg->addClass(courseName, courseId, courseUnits)){
                            cout << "Class added succesfully!! \n\n";


                        }
                        else{
                            cout << "Failed to add class!( Max units) \n\n";
                        
                            
                        }

                        break;

                    }
              
              case 2: {

                          system("clear");
                          showAll(reg);
                          cout << endl;
                          break;
    


                      }

        }

    }while(usrInput != 3);


    delete reg;

    return 0;
}



void displayMenu(){

    cout << "1. Add Class\n";
    cout << "2. View Student Information\n";
    cout << "3. Exit Program\n";


}

// Getting user input for Menu

int choice(){
    int choice;
    cin >> choice;
    cout <<"\n";

    return choice;
}
