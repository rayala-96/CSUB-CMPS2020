#include <iostream>
#include <typeinfo>

using namespace std;

//Tewmplate to calculate average and show the array

template<typename T>
double average(T array[], int size){
    double sum = 0;
    double average;

    for( int i = 0; i < size; i++){
        sum += array[i];


    }

    average = (sum * 1.0) / size;
    
    return average;
}

template<typename T>
void show(T array[], int size){
    
    if(*(typeid(T).name()) == 'i'){
        cout << "\tInteger Array \n";
        cout << "----------------------------------------\n" << "Values: ";
     }
    
    else if(*(typeid(T).name()) == 'd'){
        cout << "\tDouble Array \n";
        cout << "----------------------------------------\n" << "Values: ";
    }

    for( int i = 0; i < size; i++){
        cout << array[i] << " ";
    }

}


template<typename T>
void fillArray(T array[], int size){
    
    system("clear");
    
    if(*(typeid(T).name()) == 'i')
        cout << "\tEnter integer values \n" << "-------------------------------------\n"; 
    
    else if(*(typeid(T).name()) == 'd')
        cout << "\tEnter double values \n" << "--------------------------------------\n"; 
    
    else
        cout << "\tEnter string values \n" << "--------------------------------------\n"; 
  

    for(int i = 0; i < size; i++){
        cout << "Value " << i + 1 << " : "; 
        cin >> array[i];
    }


}



template<>
void show(string array[], int size){
    
    cout << "\n\n\n\tString Array \n" << "------------------------------\n"; 

    for ( int i = 0; i < size; i++){
        cout << array[i] << endl;

    }

    cout << endl;
}



int main(){
    int idata[10];
    double ddata[10];
    string sdata[10];
    
    

    fillArray(idata, 10);
    fillArray(ddata, 10);
    fillArray(sdata, 10);

    double _average = average(idata, 10);
    double average1 = average(ddata, 10);
    
    system("clear");

    show(idata, 10);
    cout << "\nAverage:  " << _average << endl << endl;
    
    show(ddata, 10);
    cout << "\nAverage: \t" << average1 << endl;

    show<string>(sdata, 10);
    
    return 0;
}
