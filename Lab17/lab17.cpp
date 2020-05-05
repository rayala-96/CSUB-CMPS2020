#include<iostream>
#include<string>
#include<cstring>

int find_item_linear(std::string items[], std::string item, int size);
void sort(std::string items[], int size);
int find_items_binary(std::string items[], std::string item, int size);
int find_matches(std::string items[], std::string pattern, int size, std::string matches[]);
void showArray(std::string items[], int size);
void displayMenu();
int choice();

using namespace std;

int main(){

    string matches[25];
    int userInput;
    string text[25] = { "winter", "radius", "arthritis", "sponge", "rotation", "brandy", "radium", "crank", "ginger", "ankle", "cooler", "cranium", "potato", "receipt", "keratin", "stool", "termite", "dynamite", "singing", "banker", "thrifty", "longer", "tattoo", "rations", "being"};

    sort(text, 25);

    cout << endl;



    do{
        displayMenu();
        userInput = choice();
        switch(userInput){
            case 1:{    
                        string word;
                        cout << "Enter word to search: \n";
                        cin >> word;
                        int index = find_item_linear(text, word, 25);
                        if(index > 0 )
                            cout << "Found: " << word << " at index: " << index << endl;
                        else
                            cout << word << " was not found\n";
                
                        break;
                    }
            

            case 2: {
                        string word;
                        cout << "Enter word to search: \n";
                        cin >> word;
                        int index = find_items_binary(text, word, 25);
                        if(index > 0)
                            cout << "Found: " << word << " at index: " << index << endl;
                        else
                            cout  << word << " was not found\n";

                        break;   
                    }

            case 3:{
                        string searchPattern;
                        cout << "Enter pattern to search for: \n";
                        cin >> searchPattern;
                        int count = find_matches(text, searchPattern, 25, matches);
                        if(count > 0){
                            cout << "Found: ";
                            for(int i = 0; i < count; i++)
                                cout << matches[i] << " ";
                            
                            cout << endl;
                        }
                        else
                            cout << "No matches were found\n";
                    
                        break;
                    }
     }
    }while ( userInput != 4);
        return 0;
}
int find_item_linear(std::string items[], std::string item, int size){
    for(int i = 0; i < size; i++){
        if(items[i] == item)
            return i;
        
    }

   return -1;
}
void sort(std::string items[], int size){
    int gap;
    string temp;

    for(int i = 1; i < size - 1; i++){
        temp = items[i];
        gap = i;

        while( gap > 0 && items[gap - 1] > temp){
            items[gap] = items[gap - 1];
            gap--;


        }
        items[gap] = temp; 

    }  


}
int find_items_binary(std::string items[], std::string item, int size){
    int low, high, mid;
    low = 0;
    high = size - 1;

    while(low <= high){
        mid = (low + high) / 2;
        if(item == items[mid])
           return mid;
        else if(item > items[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

  return -1;
}
int find_matches(std::string items[], std::string pattern,int size, std::string matches[]){
    int index = 0;
    int count = 0;
    for(int i = 0; i < size; i++){
        string word = items[i];
        string partial = pattern;
        size_t found = word.find(partial);
        if(found != string::npos){
            matches[index] = word;
            index++;
            count++;
        }
    }
    return count;
}

void displayMenu(){
    cout << "1- Search for a word using linear\n";
    cout << "2- Search for a word using binary\n";
    cout << "3- Search for a partial word\n";
    cout << "4- Exit Program\n";

}
int choice(){
    int choice;
    cin >> choice;
    
    return choice;
}
void showArray( std::string items[], int size){
    for(int i = 0; i < size; i++)
        cout << items[i] << " ";
}
