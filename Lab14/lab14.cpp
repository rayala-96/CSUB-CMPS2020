#include<iostream>
#include<cstdlib>
#include<chrono>
#include<ctime>

using namespace std;

void fill_array_random( int array[], int size, int lbounds, int ubounds);
void fill_array_inc( int array[], int size);
void fill_array_dec( int array[], int size);
void bubble_sort( int array[], int size);
void insertion_sort( int array[], int size);
void show_array( int array[], int size);

const int ARRAYSIZE = 100000;

int main(){
    
    srand(time(NULL));


    int random[ARRAYSIZE], increasing[ARRAYSIZE], decreasing[ARRAYSIZE];
    int insertRand[ARRAYSIZE],insertInc[ARRAYSIZE], insertDec[ARRAYSIZE]; 

    cout <<"\tBubble Sort\n";
    cout << "---------------------------\n";   

    cout << "Bubble sort (Random) took ";
    fill_array_random(random, ARRAYSIZE, 1000,1000000);

    auto start = chrono::steady_clock::now();
    bubble_sort(random, ARRAYSIZE);
    auto end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() << endl;

    cout << "Bubble sort (Increasing) took ";
    fill_array_inc(increasing, ARRAYSIZE);

    start = chrono::steady_clock::now();
    bubble_sort(increasing, ARRAYSIZE);
    end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() << endl;
    
    cout << "Bubble sort (Decreasing) took ";
    fill_array_dec(decreasing, ARRAYSIZE);

    start = chrono::steady_clock::now();
    bubble_sort(decreasing, ARRAYSIZE);
    end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() << endl << endl;
    
    cout <<"\tInsertion Sort\n";
    cout << "-------------------------------\n";   
    
    cout << "Insertion sort (Random) took ";
    fill_array_random(insertRand, ARRAYSIZE, 1000,1000000);

    start = chrono::steady_clock::now();
    bubble_sort(insertRand, ARRAYSIZE);
    end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() << endl;

    cout << "Insertion sort (Increasing) took ";
    fill_array_inc(insertInc, ARRAYSIZE);

    start = chrono::steady_clock::now();
    bubble_sort(insertInc, ARRAYSIZE);
    end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() << endl;
    
    cout << "Insertion sort (Decreasing) took ";
    fill_array_dec(insertDec, ARRAYSIZE);

    start = chrono::steady_clock::now();
    bubble_sort(insertDec, ARRAYSIZE);
    end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() << endl;




    return 0;
}

void fill_array_random(int array[], int size, int lbounds, int ubounds){
    for ( int i = 0; i < size; i++){
        int num = (rand() % (ubounds-lbounds)) + lbounds;
        array[i] = num;
    }


}

void fill_array_inc( int array[], int size){
    int num = 1;

    for( int i = 0; i < size; i++){
        array[i] = num;
        num++;

    }


}

void fill_array_dec( int array[], int size){
    int num = size;
    
    for( int i = 0; i < size; i++ ){
            array[i] = num;
            num--; 
    }
    

}
void bubble_sort( int array[], int size ){
    int temp;
    for ( int i = 0; i < size; i++){
        for( int j = i + 1; j < size; j++){
            if( array[i] > array[j] ){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            } 
        }
    }


}
void insertion_sort(int array[], int size){
    int temp, gap;

    for(int i = 1; i < size - 1; i++){
        temp = array[i];
        gap = i;

        while( gap > 0 && array[gap - 1] > temp){
            array[gap] = array[gap - 1];
            gap--;


        }
        array[gap] = temp;

    }  

}

