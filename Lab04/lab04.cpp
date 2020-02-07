#include <iostream>
#include <fstream>

using namespace std;

class Tag
{
    protected:
        string name;
        string inner_text;

        string to_hex(int n)
        {
            char chex[3];
            
            if (n > 255) 
                n = 255;
            if (n < 0)
                n = 0;

            sprintf(chex, "%X", n);
            string result = chex;
            return result;
        }
    public:
        Tag(string n) : name(n) {}
        void set_text(string text) 
        {
            inner_text = text;
        }
        // make the open function virtual
       virtual string open() { return "<" + name + ">"; }
        string close() { return "</" + name + ">"; }
        string get_text() { return inner_text; }
};

class Html : public Tag
{
    public:
        Html() : Tag("html") {}
};

class Head : public Tag
{
    public: 
        Head() : Tag("head") {}
};

class Body : public Tag
{
    private:
        string background;
    public:
        Body() : Tag("body") {}

};

class Anchor : public Tag
{
    private:
        string href;
    public:
        Anchor(string h, string where) : href(h), Tag("a") 
        {
            inner_text = where;
        }
      
        // create an overriding open() function that builds an <a> tag as below
        // remember to escape double quotes. See Header class below
        // <a href="some URL address here">
        //
        string open(){
            return "<" + name + " href = \"" + href + "\"" + ">";

        }
};

class Header : public Tag
{
    private:
        string color;
    public:
        Header(int size) : Tag("h" + to_string(size)) { color = "#000000"; }
        void set_color(int r, int g, int b)
        {
            color = "#" + to_hex(r) + to_hex(g) + to_hex(b);
        }
        string get_color() { return color; }
        string as_outerhtml() { return "<" + name + " style=\"color:" + color + "\">" + inner_text + close(); }
        string open() { return "<" + name + " style=\"color:" + color + "\">"; }
};

class Page
{
    private:
        string filename;
        Tag *lines[100];
        int linecount = 0;
        Html html;
        Head head;
        Body body;
        string contents;
        void add_line(string text)
        {
            contents += text + "\n";
        }
    public:
        Page(string fn) : filename(fn) 
        {
            linecount = 0;
        }

        ~Page()
        {
            for (int i = 0; i < linecount; i++)
            {
                delete lines[i];
            }
        }

        // this function adds to the collection of Tag objects
        void add(Tag * tag)
        {
            lines[linecount] = tag;
            linecount++;
        }

        string create()
        {
            contents = "";
            add_line(html.open());
            add_line(head.open());
            add_line(head.close());
            add_line(body.open());
            // this loop takes advantage of polymorphism, particularly the open() call
            // which will call the overriding open() if one exists, or the parent (Tag)
            for (int i = 0; i < linecount; i++)
            {
                add_line(lines[i]->open());         // this function will use overriding or base open() calls
                add_line(lines[i]->get_text());
                add_line(lines[i]->close());
            }
            add_line(body.close());
            add_line(html.close());

            ofstream fout;
            fout.open(filename);
            if (fout.is_open())
            {
                fout << contents << endl;
            }
            fout.close();
        } 
};

int main()
{
    Page page("/home/stu/rayala/public_html/cs2020lab4.html");
    Header * h;
    Anchor * a;

    string tag = "";
    string text = "";
    string name = "";   

    cout << "What tag? ";
    getline(cin, tag);
    while (tag != "exit")
    {
        if (tag == "h1")
        {
            cout << "Enter content: ";
            getline(cin, text);

            // create an h1 tag and add to page
            h = new Header(1);
            h->set_text(text);
            page.add(h);
        }
        else if (tag == "h2")
        {
            cout << "Enter content: ";
            getline(cin, text);

            // create an h2 tag and add to page
            h = new Header(2);
            h->set_text(text);
            page.add(h);
        }
        else if (tag == "a")
        {
            // create an a tag and add to page
            cout << "Enter website address: ";
            getline(cin, text);
            
            cout << "Enter name of website: ";
            getline(cin, name);
            
            a = new Anchor(text, name);
            page.add(a);
        }

        cout << "What tag? ";
        getline(cin, tag);
    }
    h = NULL;

    page.create();

    return 0;
}
