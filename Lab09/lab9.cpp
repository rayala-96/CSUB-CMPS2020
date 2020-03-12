#include <iostream>

using namespace std;

struct Location{
    string name;
    string address;
 
};

struct VisitNode{
    Location loc;
    VisitNode *next;


};

class Stack{
    private:
        VisitNode *head;

        VisitNode *create(){
            VisitNode *newnode;
            try{
                newnode = new VisitNode;

            }
            catch (bad_alloc){
                newnode = NULL;

            }
                
            return newnode;

        }

        void deallocate(){
            VisitNode *hCopy;
            hCopy = head;

            while( hCopy != NULL ){
                head = head->next;
                delete hCopy;
                hCopy = head;

                
            }


        }
    public:
        bool push(string name, string address){
            VisitNode *newnode = create();
            

            bool successful = false;
            newnode->loc.name = name;
            newnode->loc.address = address;

            if( head == NULL){
                newnode->next = head;
                head = newnode;
                //newnode->next = NULL;
                successful = true;

            }
            else{
                newnode->next = head;
                head = newnode;;



            }

            return successful;
            
        }
        
        string pop(){
            VisitNode *curr;
            string name;
            
            if( head != NULL){
                curr = head;
                name = curr->loc.name;
                head = head->next;
                delete curr;


            }
            return name;
        
        }
        friend void show(Stack &S);
       
        ~Stack(){
            deallocate();
            head = NULL;

        }


        
};

void show(Stack &S){
    VisitNode *copy;
    VisitNode *store;
    copy = S.head;
    
    while( copy != NULL ){
        store = copy->next;
        cout << copy->loc.name << " ";
        copy = store;

    } 


}

 
int main() {
    Stack browser;

    //Simulating browser history
    browser.push("Google", "https://google.com");
    browser.push("Amazon", "https://amazon.com");
    browser.push("LinkedIn", "https://LinkedIn.com");
    browser.push("Reddit", "https://reddit.com");

    show(browser);

    //Simulating clicking back button
    
    cout << endl;    
    string top = browser.pop();
    if (top != "")
          cout << endl << "Clicked back from " << top << endl;
    show(browser);

    cout << endl;    
    //Simulating clicking back button
    top = browser.pop();
    if (top != "" )
        cout << endl << "Clicked back from " << top << endl;
    show(browser);
    
    cout << endl;    
    //Simulating clicking back button
    top = browser.pop();
    if (top != "" )
        cout << endl << "Clicked back from " << top << endl;
    show(browser);

    cout << endl << endl;

    
    return 0;
}
