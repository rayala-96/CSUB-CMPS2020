#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

int calc_hash( string word );
int maxCollisions( int arr[], int size);
int hashKeyVal( int arr[], int size, int collisions);
void showArray( int arr[], int size);

const int HASH = 27;

int main(){
   
    ifstream textFile;
    int collisions[320] = {0};
    string word;

    int hashKey;
    

    textFile.open( "enable1.txt" );

    if(textFile){
        while(!textFile.eof()){
            getline(textFile, word);
            hashKey = calc_hash(word);
            for ( int i = 1; i < 320; i++ ){
                if( hashKey == i )
                    collisions[i]++;
            }       
        }
    
    }
    else{
        cerr << "Error Opening File\n";
    }

    int hashValue, numCollisions;
 
    numCollisions = maxCollisions( collisions, 320 );
    hashValue = hashKeyVal( collisions, 320, numCollisions);   

    showArray( collisions, 320 );

    cout << "Hash Value with greatest collisions: " << hashValue << endl;
    cout << "Largest number of collisions: " << numCollisions << endl;
    
    textFile.close();

    return 0;
}

int calc_hash( string word ){
    int hashKey = 0;
    int letters = 97;
    char hashArray[HASH];

   //Filling array with the alphabet 
    for ( int i = 1; i < HASH; i++ ){
        if( letters <= 122 ){
          hashArray[i] = (char)letters;
          letters++;
        }


    }

    //Looping through word and creating hashkey

    for( int i = 0; i < word.length(); i++ ){
        for( int j = 1; j < HASH; j++){
            if( word[i] == hashArray[j] )
                hashKey += j;

        }

    }

    return hashKey;
}

int maxCollisions( int arr[], int size ){
    int result = 0;

    for( int i = 1; i < size; i++ ){
        if ( arr[i] > result )
            result = arr[i];

    }
    return result;
}
int hashKeyVal( int arr[], int size,  int collisions ){
    int hashVal = 0;

    for( int i = 1; i < size; i++ ){
        if( collisions == arr[i] )
            hashVal = i;

    }

    return hashVal;
}

void showArray( int arr[], int size ){
    for( int i = 1; i < size; i++ ){
        cout << "Index: " << i << "\tCollisions: " << arr[i] << endl;
    }
}


