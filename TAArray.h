
#ifndef TAArray_H
#define TAArray_H

#define MAX_ARR 64

#include "TextArea.h"

class TAArray
{
  public:
    TAArray();
    ~TAArray();

    bool add(TextArea*);
    bool add(TextArea*, int index);
    
    TextArea* get(const string& name)const;
    TextArea* get(int index)const;

    TextArea* remove(const string& name);
    TextArea* remove(int index);


    bool isFull()const{return size == MAX_ARR;}
    int getSize()const {return size;}
    void print()const ;
    

  private:
    TextArea** elements;
    int size;
   
};

#endif
