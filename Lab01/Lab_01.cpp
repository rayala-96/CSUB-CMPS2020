#include <iostream>



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
           
            //Keeping track of the count on all requirements needed    
           
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

        //Function to compare the allowed symbols in the entered password

        bool find_char(string allowed, char c){
            bool val = false;
            for ( int i = 0; i < allowed.length(); i++ ){
                if(allowed[i] == c ){
                    val = true;
                }
            }
            
           return val;
        }

        // Check to see if all requirements are met

        bool lengthMet(){
            bool length = false;
            
            if( lengthCount < minLength)
                length = true;
            
            return length;

        }
        bool lowerMet(){
            bool lower = false;
            if( lower_count < minLower )
                lower = true;
        
            return lower;
        }
        bool  upperMet(){
            bool upper = false;
            if ( upper_count < minUpper )
                upper = true;
            
            return upper;
        }
        bool symbolMet(){
            bool symbol = false;
            if ( symbol_count < minSymbols )
                symbol = true;

            return symbol;
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

        //Extra Credit
        //Show messages like "not enough upper case" or "too short"
   if(pv.lengthMet())
      cout << "length count not met\n";

   
   if(pv.lowerMet())
      cout << "Lower case letters count not met\n";

   
   if(pv.upperMet())
        cout << "Upper case letters count not met\n";

   if(pv.symbolMet())
       cout << "Symbols count not met\n";
   
    
    

  return 0;
}
