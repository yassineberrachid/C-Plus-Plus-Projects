//
//  GroupList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the GroupList class below
#include "GroupList.h"
#include "GroupNode.h"

GroupList::GroupList(){
    head=nullptr;
}

GroupList::~GroupList(){
   
    GroupNode* ptr1;
    GroupNode* ptr2;
    GroupNode* tptr;
    
   if(head->getNext()!=NULL){
        ptr1=head->getNext();
        if(ptr1->getNext()!=NULL){
            ptr2=ptr1->getNext();
            delete ptr1;
            ptr1=nullptr;
            ptr1=ptr2;
            
            
        }
        

    }
    
}

GroupNode* GroupList::getHead() const{
    return head;
}

void GroupList::setHead(GroupNode* ptr){
    
    head=ptr;
}

void GroupList::insert(GroupNode* s){
    if(head==NULL){
        head=s;
        s->setNext(NULL);
    }
    
    else{
        GroupNode* tptr=head;
        while(tptr->getNext()!=NULL){
            tptr=tptr->getNext();
        }
        tptr->setNext(s);
        s->setNext(NULL);
    }
}

GroupNode* GroupList::remove(string name){
    if(head==NULL){
        return nullptr;
    }
    
    
    GroupNode* ptr1=head;
    GroupNode* ptr2= ptr1->getNext();
    
    if (ptr1->getShapeList()->getHead()->getShape()->getName() == "name")
    {
        head = ptr1->getNext();
        return ptr1;
    }
    
    while(ptr2!=NULL){
        if(ptr2->getShapeList()->getHead()->getShape()->getName() == name)
        {
            ptr1->setNext(ptr2->getNext());
            
            return ptr2;
        }
        ptr1=ptr1->getNext();
        ptr2 = ptr2->getNext();
    }
    
    return nullptr;
}

void GroupList::print()const{
    GroupNode* tptr=head;
    while(tptr!=NULL){
        tptr->print();
        tptr=tptr->getNext();
    }
}
                                      




