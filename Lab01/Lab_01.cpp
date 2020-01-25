#include <iostream>

//Program Checks user entered password

using namespace std;

class PasswordValidator{
    int minLength, minLower, minUpper, minSymbols, lengthCount, lower_count, upper_count, symbol_count;
    string allowedSymbols;
    public:
        PasswordValidator( int length, int lower, int upper, int symbol, string symbols){
            minLength = length;
            minLower = lower;
            minUpper = upper;
            minSymbols = symbol;
            allowedSymbols = symbols;

        }
        bool check(string input){
            bool passwordVal = false;
            lengthCount = 0;
            lower_count = 0;
            upper_count = 0;
            symbol_count = 0;
            
            lengthCount = input.length();
                for(int i = 0; i < input.length(); i++){
                    if(isupper(input[i])){
                        upper_count++;
                       

                    }
                    if(islower(input[i])){
                        lower_count++;
                        
        
                    }
                    if(find_char(allowedSymbols, input[i])){
                        symbol_count++;
                    }
                              
                    
                    
                }
                if( lengthCount >= minLength && lower_count >= minLower && upper_count >= minUpper && symbol_count >= minSymbols)
                    passwordVal = true;
            
             

            return passwordVal;


        }

        bool find_char(string allowed, char c){
            bool val = false;
            for ( int i = 0; i < allowed.length(); i++ ){
                if(allowed[i] == c ){
                    val = true;
                }
            }
            
           return val;
        }
        void missingRequirements(){
            if( lengthCount < minLength)
                cout << "Password not long enough\n";
            if( lower_count < minLower )
                cout << "Password does not have enough lower case letters\n";
            if ( upper_count < minUpper )
                cout << "Password does not have enough Upper case letters\n";
            if ( symbol_count < minSymbols )
                cout << "Password does not have enough symbols\n";


        }
   
};

int main() {


  PasswordValidator pv(8, 2, 2, 1, "$%&^(#!");

  string input;

  cout << "Enter password to test: ";
  cin >> input;


  if(pv.check(input))
      cout << input << " satisfies all requirements" << endl;
  else 
      cout << input << " is not strong enough" << endl;

   pv.missingRequirements();
    // EXTRA CREDIT
    // Show messages like "not enough upper case " or "too short"

  return 0;
}
