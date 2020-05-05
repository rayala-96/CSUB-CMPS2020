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
void quickSort( int data[], int i, int h);
int partition(int array[], int i, int h);
void swap(int *left, int *right);

const int ARRAYSIZE = 10000;

int main(){
    
    srand(time(NULL));


    int random[ARRAYSIZE], increasing[ARRAYSIZE], decreasing[ARRAYSIZE];
    int insertRand[ARRAYSIZE],insertInc[ARRAYSIZE], insertDec[ARRAYSIZE];
    int qsRand[ARRAYSIZE], qsInc[ARRAYSIZE], qsDec[ARRAYSIZE]; 

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
    
    cout <<"\tQuick Sort\n";
    cout << "-------------------------------\n";   
    
    cout << "Quick sort (Random) took ";
    fill_array_random(qsRand, ARRAYSIZE, 10000,1000000);

    start = chrono::steady_clock::now();
    quickSort(qsRand,0,ARRAYSIZE - 1);
    end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() << endl;

    cout << "Quick sort (Increasing) took ";
    fill_array_inc(qsInc, ARRAYSIZE);

    start = chrono::steady_clock::now();
    quickSort(qsInc,0,ARRAYSIZE - 1);
    end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() << endl;
    
    cout << "Quick sort (Decreasing) took ";
    fill_array_dec(qsDec, ARRAYSIZE);

    start = chrono::steady_clock::now();
    quickSort(qsDec,0,ARRAYSIZE - 1);
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
void quickSort( int data[], int l, int h){
    if( l < h){
        int p = partition(data, l , h);
        quickSort(data, l, p - 1);
        quickSort(data, p + 1, h);
    }

}
int get_pivot_pos(int array[], int l, int h){
    int a = array[l];
    int b = array[(l+h)/2];
    int c = array[h];

    if(c < a)
        swap(&a, &c);
    if(b < a)
        swap(&b, &a);
    if(c < b)
        swap(&c, &b);
    
    swap(&c, &b);

    return array[h];
    


}

int partition(int array[], int l, int h){
    int pivot = get_pivot_pos(array, l, h);
    int i = l - 1;
    for( int j = l; j <= h - 1; j++){
        if(array[j] < pivot){
            i++;
            swap(&array[i], &array[j]);
        }

    }
    swap(&array[i + 1], &array[h]);

    return (i + 1);

}

void swap(int *left, int *right){
    int temp = *left;
    *left = *right;
    *right = temp;

} 

