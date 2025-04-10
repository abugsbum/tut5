#include "RGB.h"
#include "defs.h"
#include <X11/X.h>
#include <X11/Xlib.h>
#include "string"
#include "iostream"
using namespace std;


class TextArea {
  private:
    string id;
    string text;
    Rectangle rect;
    RGB fill, border;


  public:

    TextArea(int  x,int y, int width,int  height,const string& id, const string& label,const RGB& fill = RGB::BLACK(),const RGB& border = RGB::WHITE());
    TextArea(Rectangle rect, const string& id, const string& label,const RGB& fill = RGB::BLACK(),const RGB& border = RGB::WHITE());

    void draw(Display *display,Window& win,GC& gc, int x, int y);
    bool overlaps(TextArea* textarea)const;
    void print() const;

    string getId() const;

    Rectangle getRect() const{return rect;}
    void setText(const string& new_text){text = new_text;}

    void setHeight(int val){rect.height = val;}
    

};


