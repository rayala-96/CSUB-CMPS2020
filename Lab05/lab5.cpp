#include <iostream>
#include <fstream>


using namespace std;

//Setting up exception Classes


class ConfigFileError : public exception{
    public:
        const char* what() const throw(){
            return "Configuration file is badly formed";

        }



};

class ConfigFileMissingKey : public ConfigFileError{
    public:
        const char* what() const throw(){
            return "Missing key";

        }



};

class ConfigFileBadKey : public ConfigFileError{
    public:
        const char* what() const throw(){
            return "Bad key specification";

        }



};

class ConfigFileMissingSeparator : public ConfigFileError{
    public:
        const char* what() const throw(){
            return "Missing separator";

        }



};

class ConfigFile{
    private:

        //Check if the key and value is separated by an equal sign

        bool contains_separator(string line, char sep = '='){
            bool containsSep = false;
            for ( int i = 0; i < line.length(); i++){
                if( line[i] == sep ){
                    containsSep = true;
                    break;
                }
            }
            return containsSep;
        }

        //Check if string follows C++ basic variable name

        bool is_name_valid(string name){
            bool check = false;
            int lineHolder = 0;

            if((name[lineHolder] <= 122 && name[lineHolder] >= 95) || (name[lineHolder] <= 90 && name[lineHolder] >= 65) || name[lineHolder] == (char)95)
                check = true;

            return check;
        }
        //Check to see if the string is a comment

        bool is_comment(string line){
            bool comment = false;
            int lineHolder = 0;

            if(line[lineHolder] == ';')
                comment = true;


            return comment;
        }

        // checks to see if the string is missing a key by checking the first character

        bool is_missing_key(string line){
            bool missingKey = false;
            int lineHolder = 0;

            if(line[lineHolder] == '=')
                missingKey = true;


            return missingKey;
        }


    public:

        //Opening up the file 

        bool load(string filename){
            string line;

            ifstream fin;
            fin.open("config.ini");

            if(fin.is_open()){
                while(!fin.eof()){
                    if(getline(fin,line)){
                        if(line != "" && !is_comment(line)){

                            if(!contains_separator(line))
                                throw ConfigFileMissingSeparator();


                            else if(!is_name_valid(line))
                                throw ConfigFileBadKey();


                            else if(is_missing_key(line))
                                throw ConfigFileMissingKey();





                        }



                    }




                }



            }






        return true;
        }


};
int main(){
    ConfigFile config;

    try{
        if (config.load("config.ini"))
            cout << "Config file verified" << endl;

    }

    catch (ConfigFileMissingKey &ex){
        cerr << ex.what() << endl;
    }

    catch (ConfigFileBadKey &ex){
        cerr << ex.what() << endl;
    }

    catch (ConfigFileMissingSeparator &ex){
        cerr << ex.what() << endl;
    }


    catch(...){

        cerr << "Error" << endl;
    }

    return 0;
}
