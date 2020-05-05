#include <iostream>

using namespace std;


struct JobNode{
    string name;
    JobNode *next;

};

class Queue{
    private:
        JobNode *head;

        JobNode *create(){
            JobNode *newnode;

            try{
                newnode = new JobNode;
            }
            catch (bad_alloc)
            {
                newnode = NULL;
            }

            return newnode;
        }
        void deallocate(){
            JobNode *copy;
            copy = head;

            while( copy != NULL ){
                head = head->next;
                delete copy;
                copy = head;


            }    
        }

    public:
        bool enqueue(string name){
            bool success = false;
            JobNode *newnode = create();
            newnode->name = name;


            if( head == NULL){ 

                head = newnode;
                newnode->next = NULL;               

                success = true;

            }
            else{
                newnode->next = head;
                head = newnode;

                success = true;             

            }

            return success;
        }




        string dequeue(){
            string temp;
            JobNode *last, *secondLast, *copy;
            last = head;

            if( head == NULL )
                temp = "";

            else
            {   
                if ( head->next == NULL ){
                        temp = head->name;
                        delete head;
                        head = NULL;
                    }
                else{
                while( last->next != NULL ){
                    last = last->next;


                }

                temp = last->name;
                secondLast = head;
                while( secondLast->next != last ){
                    
                    secondLast = secondLast->next;

                }
                secondLast->next = NULL;
                delete last;
                 }
             }
            return temp;



        }

        friend void show(Queue &Q);

        ~Queue() {
            deallocate();

            head = NULL;

        }


};

void show(Queue &Q){
    JobNode *copy;
    JobNode *store;
    copy = Q.head;


    while( copy != NULL){
        store = copy->next;
        cout << copy->name << " ";
        copy = store;

    }
}





int main() {
    Queue spooler;

    // simulate a printer spooler
    spooler.enqueue("Comm100 Paper.docx");
    spooler.enqueue("Fwd: Direct Deposit");
    spooler.enqueue("document(1).doc");
    spooler.enqueue("lab9.cpp");

    cout << "Pending jobs: " << endl;
    // show function to show all jobs
    show(spooler);

    cout << endl;

    // simulate the printer completing 

    string oldest;


    do{
        oldest = spooler.dequeue();
        if ( oldest != ""){
            cout << "Printing..." << endl;
            cout << oldest << " printed" << endl;

            cout << endl << "Pending jobs:" << endl;        
            show(spooler);
        }


    }while(oldest != "" );

    cout << "No jobs" << endl;

    return 0;
}  
