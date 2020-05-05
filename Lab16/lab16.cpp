#include<iostream>

bool is_max_heap(int data[], int count);
void heapify(int data[], int count);
void show_array(int data[], int size);
bool hasParent(int childIndex);
void swap(int *left , int *right);
void heapifyStructure( int arr[], int n, int parent);

const int SIZE = 1000;

using namespace std;

int main(){
    int userInput, inputCount, arrayIndex;
    arrayIndex = 0;
    int array[SIZE];
    do{

        cout << "Enter a Number: \n";
        cin >> userInput;
        if( userInput > 0){
        array[arrayIndex] = userInput;
        arrayIndex++;
        inputCount++; 
        heapify(array, inputCount);

        }

    }while(userInput != -1);


    if(is_max_heap(array,inputCount))
        cout << "Array is a verified max-heap\n";
    else
        cout << "Array is not verified as max-heap\n";

    show_array(array, inputCount);

    return 0;
}
void heapifyStructure( int arr[], int n, int parent){
    int index = parent;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    //Checking to see if child data are greater than parent data
    if(left < n && arr[left] > arr[index])
        index = left;
    if(right < n && arr[right] > arr[index])
        index = right;

    //Swapping the larger value    
    if(index != parent){
        swap(&arr[parent], &arr[index]);

        heapifyStructure(arr, n, index);
    }
}
void heapify(int data[], int count){
    //Starting at subtree of last item
    int parent = (count - 1) / 2;

    for( int i = parent; i >= 0; i--)
        heapifyStructure(data,count,i);


}
bool hasParent( int childIndex){
    int parentIndex;
    parentIndex = (childIndex - 1) / 2;

    return parentIndex >= 0;
}
bool is_max_heap( int data[], int count){
    bool result = false;
    int parent;
    int index = count - 1;
    int left = (parent * 2) + 1;
    int right = (parent * 2) + 2;
    parent = (index - 1) / 2;

    while (hasParent(index))
    {
        if(data[parent] > data[index])
            result = true;
            index--;
        
    }
    
    return result;
}
void swap(int *left, int *right){
    int temp;
    temp = *left;
    *left = *right;
    *right = temp;
}

void show_array( int data[], int size){
    for ( int i = 0; i < size; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}
