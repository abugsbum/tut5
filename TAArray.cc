#include "TAArray.h"

#include <iostream>
using namespace std;

TAArray::TAArray(){
    size = 0;
    elements = new TextArea*[MAX_ARR];
}

TAArray::~TAArray(){
    for(int i = 0; i < size; i++){
        delete elements[i];
    }
    delete[] elements;
}

bool TAArray::add(TextArea* s, int index){
    if (size >= MAX_ARR){return false;}

    if((index < 0) || (index > size)){return false;}

    for (int i = size; i >= index ; --i){
        elements[i] = elements[i-1];
        }    
    elements[index] = s;
    ++size;
    return true;
    
}
bool TAArray::add(TextArea* s){
    if (size >= MAX_ARR)return false;
    elements[size] = s;
    ++size;
    return true;
}

TextArea* TAArray::get(const string& id)const{
    for (int i = 0; i < size; ++i){
        if (elements[i]->getId() == id ){
            return elements[i];
        }
    }
    return nullptr;
}

TextArea* TAArray::get(int index)const{
    if (index < 0 || index >= size) return nullptr;
    return elements[index];
}

TextArea* TAArray::remove(const string& number){
    
    int index = 0;
    //we want to find the index of the element to remove
    while (elements[index]->getId() != number && index < size){
        ++index;
    }

    return remove(index);

}

TextArea* TAArray::remove(int index){

    //did we fall off the end of the TextArea?
    if (index<0 || index >=size) return nullptr;

    //we have found what we wanted to remove,
    //assign the output value
    TextArea *stu = elements[index];

    //copy everything after index left one position
    while (index < size - 1){
        elements[index] = elements[index + 1];
        ++index;
    }
    --size;
    return stu;

}


void TAArray::print()const
{
  cout << endl << endl << "TextAreas:" << endl;
  for (int i=0; i<size; ++i)
    elements[i]->print();

  cout << endl;
}

