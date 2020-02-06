#include <iostream>
#include <fstream>


using namespace std;

class Tag{
    protected:
        string name;
        string inner_text;
        string to_hex(int v){
            if ( v < 0 )
                v = 0;
            if ( v > 255 )
                v = 255;
            char chex[3];
            sprintf(chex, "%X", v);
            string result = chex;
            return result;

        }
    public:
        Tag(string n ) { name = n; }
        void set_text(string text) { inner_text = text; }
        string open() { return "<" + name + ">"; }
        string close() { return "</" + name + ">"; }


};

class Html : public Tag{
    public:
        Html() : Tag("html") {}

};

class Head : public Tag{
    public:
        Head() : Tag("head") {}

};

class Body : public Tag{
    public:
        Body() : Tag("body") {}
        string setImage() {
            return "<" + name + " style = \"background-image: url(https://images.unsplash.com/photo-1500964757637-c85e8a162699?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=1978&q=80)\"" + ">";

        }
};


class Header : public Tag{
    private:
        string color;
    public:
    Header(int size) : Tag("h" + to_string(size)) {} 
    void set_color(int r, int g, int b){
        color = "#" + to_hex(r) + to_hex(g) + to_hex(b);
    }
    string get_color() { return color; } 
    string get_outerhtml(){
        return "<" + name + " style=\"color:" + color +"\">" + inner_text + close();

    }

 };

 class Title : public Tag{
    public:
        Title () : Tag("title") {}     
        string setName(){
            return inner_text;

        }  
 };

 
class Page{
    private:
        Html html;
        Head head;
        Body body;
        Title title;
        string filename;
        string contents;

        string add_line(string text){
            return text + "\n";
        }
    public:
        Page(string fn) : filename(fn) {}
        void create(Header line1, Header line2, Title line){
            contents = "";
            contents += add_line(html.open());
            contents += add_line(head.open());
            contents += add_line(title.open());
            contents += add_line(line.setName());
            contents += add_line(title.close());
            contents += add_line(head.close());
            contents += add_line(body.setImage());
            contents += add_line(line1.get_outerhtml());
            contents += add_line(line2.get_outerhtml());
            contents += add_line(body.close());
            contents += add_line(html.close());
            
            ofstream fout;
            fout.open(filename);
            if(fout.is_open()){
                fout << contents << endl;
            }

            fout.close();
        }


};

int main(){
    
    Page page("/home/stu/rayala/public_html/cs2020lab3.html");

    Header line1(1); //h1 tag
    line1.set_color(209, 24, 24);
    line1.set_text("hello inheritance");
    
    Header line2(3);  //h3 tag
    line2.set_color(30, 27, 231);
    line2.set_text("This is line 2");

    Title line;
    line.set_text("Lab 3");

    page.create(line1, line2, line);



    return 0;
}
