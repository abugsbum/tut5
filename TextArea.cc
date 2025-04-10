#include "TextArea.h"
using namespace std;

TextArea::TextArea(int  x,int y, int width,int  height,const string& id, const string& label,const RGB& fill,const RGB& border):id(id),fill(fill),border(border),text(label){
  rect.height = height;
  rect.width = width;
  rect.x = x;
  rect.y = y;
}
TextArea::TextArea(Rectangle rect, const string& id, const string& label,const RGB& fill,const RGB& border):text(label),rect(rect),id(id),fill(fill),border(border){}







void TextArea::draw(Display *display,Window& win,GC& gc, int x, int y){
  XSetForeground(display, gc, border.getColour());
  XFillRectangle(display, win, gc,x,y, rect.width, rect.height);
  XFontStruct* font = XLoadQueryFont(display, "fixed");
    
  XSetFont(display, gc, font->fid);

    
  XSetForeground(display, gc, fill.getColour());
  
    
  int x_pos = x + 1;  
  int y_pos = y + font->ascent + 1;
  

  for (int i = 0; i < text.length(); i++) {
    
      //need to find width and height so you know how much to move forward and down by 
      int char_height = font->ascent + font->descent;
      int char_width = XTextWidth(font,&text[i], 1);
      //if a char is about to leave the panel set the x coordinate back to the start and move the y coordinate down(increase y) by one char 
      if (x_pos + char_width > x + rect.width - 1) {
          x_pos = x + 1;  
          y_pos += char_height; 

        }
      //if char is about to cross the bottom of the panel stop drawing chars 
      if (y_pos + 1 > y + rect.height - 1) {
        break;
      } 
      
      XDrawString(display, win, gc, x_pos, y_pos,&text[i], 1);
      //move up my one char 
      x_pos += char_width;
    }

    
  XFreeFont(display, font);


}


bool TextArea::overlaps(TextArea* textarea)const{return rect.overlaps(textarea->rect);}


void TextArea::print() const{
  cout<<"TextArea id:    "<<id<<endl;
  cout<<"Position: "<<rect.x<<", "<<rect.y<<endl;
  cout<<"Size:     "<<rect.width<<", "<<rect.height<<endl;
  cout<<"Text:  "<<text<<endl;
}

string TextArea::getId()const{return id;}








