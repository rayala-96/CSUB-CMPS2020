//
// Raymundo Ayala                       <-----------------------------------------------
// Final
// 2020-05-14

#include <iostream>

using namespace std;

class Animal
{
    protected:
        string type;    // represents animal type: "cat", "dog", etc
        int age;        // in months
    public:
        Animal() 
        {
            type = "";
            age = 0;
        }
        Animal(string t, int a)
        {
            type = t;
            age = a;
        }
        string get_type() { return type; }
        int get_age() { return age; }
};

class Rescue : public Animal
{
    private:
        string name;
    public:
        Rescue * next;
        Rescue() {}
        Rescue(string n, string t, int a) : name(n), next(NULL), Animal(t, a) {}
        string get_name() { return name; }
};

class RescueOps     // Rescue Operations
{
    private:
        int types;
        int count;
        Rescue *rescues[50];    // an array of head pointers

        bool is_new(string type)  // PART 1 <========
        {

            if(find_type(type) == NULL)
                return true;
            
            // calls find_type
            // returns true if find_type() returns NULL, and false otherwise

            return false;
        }

        Rescue * create(string n, string t, int a)
        {
            return new Rescue(n, t, a);
        }

        Rescue * find_type(string type) // PART 1 <=========
        {
            Rescue * firstnode = NULL;
            bool found = false;
            int i = 0;
            while(i < types && rescues[i] != NULL){
                if(rescues[i]->get_type() == type){
                    firstnode = rescues[i];
                    break;
                }
                i++;
            }
            


            // check -rescues- array if any collection of -type- has been started
            // returns the head pointer for the list of -type, if found
            // returns NULL if no list was found for -type-

            return firstnode;
        }
    public:
        RescueOps()
        {
            count = 0;
            types = 0;
            // set all heads to NULL
            for (int i = 0; i < 50; i++)
            {
                rescues[i] = NULL;
            }
        }

        ~RescueOps()
        {
            Rescue * ptr, * temp;
            // destroy all nodes in all lists
            for (int i = 0; i < types; i++)
            {
                ptr = rescues[i];

                while (ptr != NULL)
                {
                    temp = ptr;
                    ptr = ptr->next;
                    delete temp;
                }
            }
        }

        void add(string n, string t, int a)     // name, type, age  <== PART 1 ========
        {
            Rescue * node = create(n, t, a);

            count++;

            if(types == 0){
                rescues[types] = node;
                types++;

            }

            else{

                if(is_new(t)){
                    rescues[types] = node;
                    types++;

                }
                    
                
                else{
                    
                    Rescue *head = find_type(t);

                    
                    Rescue *hCopy = head;
                    if(head->next == NULL)
                        head->next = node;
                    else{
                            while(hCopy->next != NULL){
                                hCopy = hCopy->next;
                            }
                            hCopy->next = node;


                        }
                    
                }
            }
    

            // check if this rescue -t- is a new type, use is_new()
            // if it's a new type, then add a new entry into -rescues- array
            // this first node effectively becomes the head node

            // Otherwise, find the head node of the matching type using find_type()
            // then add the new node to the end of the list

        }

       Rescue * find_youngest(string t)  // PART 1 <=========
        {
               
            Rescue *temp = find_type(t);
            Rescue * youngest;
            int flag = 1;

            

            while(temp != NULL){
                if(flag == 1){
                    youngest = temp;
                    flag = 0;
                }
                else{  
                    if(youngest->get_age() > temp->get_age()){
                        youngest = temp;
                    }
                }

                 temp = temp->next;


            }

            // now find and return the youngest rescue in the list

            return youngest;

        }

        Rescue * find_oldest(string t)  // PART 2 <-------------------------------------------------------------
        {

            Rescue *temp = find_type(t);
            Rescue * oldest;
            int flag = 1;

            

            while(temp != NULL){
                if(flag == 1){
                    oldest = temp;
                    flag = 0;
                }
                else{  
                    if(oldest->get_age() < temp->get_age()){
                        oldest = temp;
                    }
                }

                 temp = temp->next;


            }

            return oldest;


        }

        int get(string t, Rescue list[])    // PART 2 <---------------------------------------------------------
        {
            int i = 0;
            
            Rescue *head = find_type(t);
            while (head != NULL){
                list[i] = *head;
                head = head->next;
                i++;
            }
        
                

            // Fill up the -list- array with all the nodes of type -t-            
            // this function returns the count, i, of rescues of -type- found
            

            return i;
        }

        int count_type(string t) // PART 1 <=======
        {
            
            int c = 0;
            Rescue *head = find_type(t);
            Rescue *hCopy = head;
            while(hCopy != NULL){
                c++;
                hCopy = hCopy->next;
            }
        
            
            // returns how many rescues exist of -type-
            // start with find_type() to find the head node
            
            return c;
        }
/*
        void show(string t)  // PART 1 <==== 
        {   
            
            Rescue *head = find_type(t);
            Rescue *hCopy = head;

            while(hCopy != NULL){
                cout << " Name: " << hCopy->get_name() << " Age: " << hCopy->get_age();

                hCopy = hCopy->next;
            }

        

            // go ahead and do cout's in this function
            // this is the dirty way, just so you can see
            // the contents of the collections
        }
*/
        // extra credit  <------------------------------------------------------------
        double average_age(string t)
        {
            int totalRescues = count_type(t);
            double ageSum = 0;
            Rescue *head = find_type(t);
            while(head != NULL){
                ageSum += head->get_age();
                head = head->next;
            }
            
            return totalRescues == 0 ? 0 : ageSum / totalRescues;
        }

};

// PART 2  <---------------------------------------------------------------------------
void sort(Rescue data[], int size)
{
    
    Rescue temp;
    int length = size;
    for(int i = 0; i <= length - 1; i++){
        for(int j = i + 1; j <= length - 1; j++){
            if(data[i].get_age() > data[j].get_age()){
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    // sort the data array by rescue's age (youngest to oldest)
    // do not use STL
}

// PART 2  <---------------------------------------------------------------------------
void show(Rescue data[], int size)
{

    int length = size;

    
    for(int i = 0; i < length; i++){
        int years = data[i].get_age() / 12;
        int months = data[i].get_age() % 12;
        cout << " Name: " << data[i].get_name() << " Age: " << years << " years, " << months << " months " << " | ";

    }
    // show the rescues in the data array
    // convert the age into years and months when displaying
    // something like "meow1 is 2 years, 2 months
    //
    // when this is done, delete the dirty show() function in the class and don't call it in main
}

int main()
{
    RescueOps ops;
    string input = "", type = "";

    do
    {
        cout << endl << endl;
        cout << "  -Raymundo Ayala- RESCUE MISSION" << endl;     // PART 1 <======== Put your actual name here
        cout << "  --------------------------" << endl;
        cout << "  You can enter 'cat' 'dog' or any other rescue type " << endl;
        cout << "  You can also type commands: 'stop', 'youngest', 'oldest', 'show' " << endl;
        cout << "  Additional commands: 'average' " << endl;  // EXTRA CREDIT   // <-----------------------------------------
        cout << "  Enter command or rescue type: ";
        cin >> input;

        if (input != "stop")
        {
            if (input == "youngest")
            {
                cout << endl;
                cout << "You have chosen to view the youngest, of what type? ";
                cin >> type;

                // The RescueOps object contains the collection of rescues
                // find and display the information for the youngest -type-
                Rescue * found = ops.find_youngest(type);

                cout << "The youngest " << type << " found was: ";

                // show details for the youngest 
                if (found != NULL)
                {
                    cout << "  " << found->get_name() << ", " << found->get_age() << " months " << endl;
                }
                else
                    cout << "No " << type << " rescues" << endl;
            }
            else if (input == "oldest")         // PART 2  <------------------------------------------------------------------
            {
                cout << endl;
                cout << "You have chosen to view the oldest, of what type? ";
                cin >> type;

                // The RescueOps object contains the collection of rescues
                // find and display the information for the oldest -type-
                Rescue * found = ops.find_oldest(type);

                cout << "The oldest " << type << " found was: ";

                // show details for the youngest 
                if (found != NULL)
                {
                    cout << "  " << found->get_name() << ", " << found->get_age() << " months " << endl;
                }
                else
                    cout << "No " << type << " rescues" << endl;
                // similar to youngest above, show oldest rescue 
            }
            else if (input == "average")     // EXTRA CREDIT  <------------------------------------------------------------
            {
                cout << endl;
                cout << "You have chosen to view the average, of what type? ";
                cin >> type;

                // The RescueOps object contains the collection of rescues
                // find and display the information for the oldest -type-
                double average = ops.average_age(type);

                // show details for the youngest 
                if (average != 0)
                {
                    cout << " Average of " << type << " age is: " << average << " months\n";
                }
                else
                    cout << "No type: " << type << " to find average\n";
            //   // similar to youngest above, but only show average age of rescues of user-inputed type
            // }
            // else if (input == "oldestall")   // EXTRA CREDIT  <------------------------------------------------------------
            // {
            //   // show the name and age of the oldest rescue, no matter what type
             }
            else if (input == "show")  // PART 2
            {
                string type;
                cout << endl;
                cout << "Show list of what type? ";
                cin >> type;

                // get count of rescues of -type-
                int count = ops.count_type(type);

                if (count == 0)
                    cout << "No " << type << " rescues" << endl;
                else
                {
                    Rescue *sorted = new Rescue[count];

                    // because it's difficult to sort a linked list, copy the list of rescues of -type-
                    // into the sorted array
                    ops.get(type, sorted);// <- PART 2 ---------------- Uncomment

                    // then sort it
                     sort(sorted, count);//          <- PART 2 ---------------- Uncomment

                    // then show it
                     show(sorted, count);//          <- PART 2 ---------------- Uncomment
                    //ops.show(type);  // PART 2 <-------------------- Get rid of this line that calls the dirty show
                    
                    delete [] sorted;
                }
            }
            else // at this point, assume -input- is a rescue type
            {
                string name, type;
                int age;

                type = input;
                // User input for new rescue
                cout << endl;
                cout << "Enter complete information for new " << input << " rescue: " << endl;
                cout << "Rescue's name: ";
                cin >> name;

                cout << "Rescue's age (in months): ";
                cin >> age;

                // add the newly entered rescue into the RescueOps object, by calling add()
                ops.add(name, type, age);
            }
        }
    } while (input != "stop");

    return 0;
}


