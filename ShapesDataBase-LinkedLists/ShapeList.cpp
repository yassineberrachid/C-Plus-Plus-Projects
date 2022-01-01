#include "Shape.h"
#include "ShapeList.h"

ShapeList::ShapeList(){
    head=nullptr;
}

ShapeList::~ShapeList(){
    ShapeNode* tptr;
    while(head!=NULL){
        tptr=head;
        head=tptr->getNext();
        delete tptr;
    }
    
}

ShapeNode* ShapeList::getHead()const{
    return head;
}

void ShapeList::setHead(ShapeNode* ptr){
    head=ptr; 
}

ShapeNode* ShapeList::find(string name) const{
    ShapeNode* tptr=head;
    while(tptr!=NULL){
        if(tptr->getShape()->getName()==name){
            break;
        }
        tptr=tptr->getNext();
    }
    return tptr;
}

void ShapeList::insert(ShapeNode* s){
    if(head==NULL){
        head=s;
        s->setNext(NULL);
    }
    
    else{
        ShapeNode* tptr=head;
        while(tptr->getNext()!=NULL){
            tptr=tptr->getNext();
        }
        tptr->setNext(s);
        s->setNext(NULL);
    }
}

ShapeNode* ShapeList::remove(string name){
    
    if(head==NULL){
        return nullptr;
    }
    
    
    ShapeNode* ptr1=head;
    ShapeNode* ptr2= ptr1->getNext();
    
    if (ptr1->getShape()->getName() == name)
    {
        head = ptr1->getNext();
        return ptr1;
    }
    
    while(ptr2!=NULL){
        if(ptr2->getShape()->getName()==name)
        {
            ptr1->setNext(ptr2->getNext());
            
            return ptr2;
        }
        ptr1=ptr1->getNext();
        ptr2 = ptr2->getNext();
    }
    
    return nullptr;
    
}

void ShapeList::print()const{
    ShapeNode* tptr=head;
    while(tptr!=NULL){
        tptr->print();
        tptr=tptr->getNext();
    }
}


