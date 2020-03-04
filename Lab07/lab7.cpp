#include<iostream>

using namespace std;

template <class T>
class Collection{

   private:
        T* data;
        int max;
    public:
        Collection(int size, T initial_value){
            max = size; 
            data = new T[max];

            for( int i = 0; i < max; i++){
                data[i] = initial_value;
            }


        }

        int count(T value){
            int valueCount = 0;

            for( int i = 0; i < max; i++){
                if( data[i] == value )
                    valueCount++;

            }


            return valueCount;
        }


        bool contains(T value){
            bool doesContain = false;

            for( int i = 0; i < max; i++){
                if( data[i] == value)
                    doesContain = true;


            }

            return doesContain;

        }   

        T& operator[](int index){
            for(int i = 0; i < max; i++){
                if( i == index )
                    return data[i];


            }
        }

        void showArray() {
                for ( int i = 0; i < max; i++){

                    cout << data[i] << endl;

                }

            }


        T at(int index);

        ~Collection() { delete []data; };

};

template<class T> 
T Collection<T>::at(int index){
   if( index >= max )
          throw out_of_range("index exceeds collection size");

   return data[index];
}



int main(){
    Collection <int> info(10,0);
    Collection <string> str(5, "hello");
    int numContain = 21;
    string strContain = "Josh";



    int count = info.count(0);
    int stringCount = str.count("hello");


    info[4] = 21;
    str[3] = "Ive Changed";


    cout << "Integer appears in the data: " << count << " times\n";
    cout << "String appears: " << stringCount << " Times\n"; 


    if(info.contains(numContain))
        cout << numContain <<" appears in the data\n";

    else{
        cout << numContain << " does not appear in Data\n";    


     }

    if(str.contains(strContain))
        cout << strContain <<" appears in the data\n";

    else{
        cout << strContain << " does not appear in Data\n";    


    }

    
    int element = info.at(20);

    


    return 0;
}
