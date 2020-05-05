#include <iostream>

using namespace std;

class RingBuffer{

    private:
        int size, head, tail;
        string *names;
 
        bool is_empty(){
           bool empty = false;
           if( head == -1 )
               empty = true;

           return empty;

        }

        bool is_full(){
            bool full = false;
            if( (head == 0 && tail == size - 1) || head == tail + 1 )
                full = true;

            return full;

        }
    public:
        //Initializing variables with overloaded constructor
        RingBuffer( int s ) : size(s) {
            names = new string[size];
            head = tail = -1;
            for ( int i = 0; i < size; i++ ){
                names[i] = " ";
            }
        }
        
        //Enque bool function
        bool enqueue( string name ){
            bool added = false;
            if( !is_full() ){
                if(head == -1 )
                    head = 0;

                tail = (tail + 1) % size;
                names[tail] = name;

                added = true;

            }

            return added;
    
        }
        //Dequeue Function
        string dequeue(){
            string name;
            if( is_empty() )
                name = "";
            if ( !is_empty() ){
                name = names[head];
            }

            if ( head == tail )
                head = tail = -1;
            else{
                head = (head + 1) % size;

            }
            return name;
        }
        
        friend void show( RingBuffer &rb);

        ~RingBuffer(){
            delete []names;

        }
};

//Showing Queue contents
void show( RingBuffer &rb ){
    
    int counter = rb.head;
     if ( rb.is_empty() )
         cout << "Queue is empty!\n";
     while ( counter != rb.tail ){
         counter = (counter + 1) % rb.size;    
     
     }
        cout << "[ " << rb.names[counter] << " ] " << endl;
    
 }

int main(){
    RingBuffer buffet(4);
    char action;
    string name = "";
    bool added;

    do{
        cout << "e - Enqueue" << endl;
        cout << "d - Dequeue" << endl;
        cout << "q - Quit" << endl;
        cout << "Action: ";

        cin >> action;

        if ( action == 'e' ){
            cout << "Name: ";
            cin >> name;
            if( buffet.enqueue(name) )
                cout << "Added " << name << endl;
        
        }

        else if( action == 'd' ){
            name = buffet.dequeue();
            if( name != "" )
                cout << "Dequeued " << name << endl;
            
        }

        show(buffet);

        cout << "--------------\n";

    }while( action != 'q');


    return 0;

}
