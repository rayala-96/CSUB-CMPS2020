#include <iostream>

using namespace std;

struct StateInfo{
    string abbv;
    string name;
    int population;
    StateInfo *next;



};

void show(StateInfo *ptr){
    StateInfo *curr;
    curr = ptr;

    while( curr != NULL ){
    
        cout << curr->abbv << curr->name << " ( population "<< curr->population << " ) " << endl;
        curr = curr->next;
    }
         
    
    
}

int totalpop(StateInfo *ptr){
    int calculatedTotal = 0;
        StateInfo *curr;
        curr = ptr;
        while(curr != NULL){
            calculatedTotal += curr->population;
            curr = curr->next;

        }

    
    return calculatedTotal;



}


int main() {
	
    //Instantiating new structures

    StateInfo *head;
    StateInfo *state1 = new StateInfo;

    state1->abbv = "CA-";
    state1->name = "California";
    state1->population = 39400000;
    

    StateInfo *state2 = new StateInfo;
    StateInfo *state3 = new StateInfo;

    state2->abbv = "OR-";
    state2->name = "Oregon";
    state2->population = 4300000;

    state3->abbv = "WA-";
    state3->name = "Washington";
    state3->population = 7800000;

    
    
    head = state1;
    state1->next = state2;
    state2->next = state3;
    
    system("clear");
    cout << "\t Original \n";
    cout << "-----------------------------------------\n"; 
    show(head);
    int popTotal = totalpop(head); 

    cout << "Total population: " << popTotal << endl;
    
    cout << "\n\tRearranged \n";
    cout << "-----------------------------------------\n";

    head = state3;
    state3->next = state2;
    state2->next = state1;
    state1->next = NULL;    

    show(head);
    cout << endl;    

    delete state1,state2,state3;
    return 0;
}
