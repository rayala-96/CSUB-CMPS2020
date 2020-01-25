#include <iostream>

using namespace std;

class Door{
    string password;
    bool locked;
    int fails;
    bool disabled;

    public: 
        Door(string pwd){
            password = pwd;
            fails = 0;
            locked = true;
            disabled = false;

        }
        void enter(string input){
            if( input == "331409" ){
                locked = false;
                disabled = false;

            }
            else{
             if( !disabled ){
                if ( input == password ){
                    locked = false;
                    fails = 0;

                

                }
                else{
                    locked = true;
                    fails++;
                    if( fails ==3 ){
                        disabled = true;

                    }


                }    





                }
        }
        }
        bool is_disabled(){
            return disabled;
        }
        bool unlocked(){
            return !locked;
        }
       



};

int main() {
    Door door("2325");
    string input;

    while(true){
        cout << " : ";
        cin >> input;

        door.enter(input);

        if( door.is_disabled()){
            cout << "Door is disabled \n";

        }
        else{
            if(door.unlocked()){

                cout << "Door is opened \n";

    
            }
            else{
                cout << "Door is locked \n";
            }






      }
    }





    return 0;
}
