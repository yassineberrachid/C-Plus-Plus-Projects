//
//  parser.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"
#include "ShapeNode.h"
#include "GroupNode.h"
#include "ShapeList.h"
#include "GroupList.h"

// This is a pointer to the groups list
// The list itseld must be allocated
GroupList* gList;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here

bool checkNameValid(string name) {
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (name == keyWordsList[i]) {
            return false;
        }
    }

    for (int i = 0; i < NUM_TYPES; i++) {
        if (name == shapeTypesList[i]) {
            return false;
        }
    }
    return true;


}

void ErrorPrinting(int code, string name) {
    if (code == 0) {
        cout << "error: invalid name" << endl;
    } else if (code == 1) {
        cout << "error: name " << name << " exists" << endl;
    }
    else if (code == 2) {
        cout << "error: shape " << name << " not found" << endl;
    }

    else if (code == 3) {
        cout << "error: group " << name << " not found" << endl;
    }
}

GroupNode* findGroup(string name) {
    GroupNode* ptr1;
    ptr1 = gList->getHead();

    while (ptr1 != NULL) {
        if (ptr1->getName() == name) {
            return ptr1;
        } 
        
        
        else {
            ShapeList* ptr2;
            ptr2 = ptr1->getShapeList();
            
            
            ShapeNode* ptr3;
            ptr3 = ptr2->getHead();
            
            
            if (ptr3 == NULL) {
                ptr1 = ptr1->getNext();
                continue;
            }

            while (ptr3 != NULL) {
                if (ptr3->getShape()->getName() == name) {
                    return ptr1;
                } else {
                    ptr3 = ptr3->getNext();
                }
            }

        }

        ptr1 = ptr1->getNext();


    }
    return nullptr;

}

int checkExists(string name, string type) {
    GroupNode* ptr1;
    ptr1 = gList->getHead();

    while (ptr1 != NULL) {
        if (ptr1->getName() == name) {
            if (type == "all") {
                return 1;
            } else if (type == "group" || type == "shape") {
                return 4;
            }
        } else {
            ShapeList* ptr2;
            ptr2 = ptr1->getShapeList();
            ShapeNode* ptr3;
            ptr3 = ptr2->getHead();
            if (ptr3 == NULL) {
                ptr1 = ptr1->getNext();
                continue;
            }

            while (ptr3 != NULL) {
                if (ptr3->getShape()->getName() == name) {
                    
                    
                    if (type == "all") return 1;
                    else if (type == "shape") return 2;
                } else {
                    ptr3 = ptr3->getNext();
                }
            }
            ptr1 = ptr1->getNext();
        }


    }
    if (type == "all") return 0;
    else if (type == "shape") return 3;
    else if (type == "group") return 5;


}

void shapeCommand(stringstream &lineStream, GroupNode* pool) {
    string shapeName;
    string type;
    string line;
    int xloc, yloc, xsize, ysize;
    lineStream >> shapeName >> type >> xloc >> yloc >> xsize>>ysize;
    if (checkNameValid(shapeName) == false) {
        ErrorPrinting(0, "");
        return;
    }
    else if (checkExists(shapeName, "all") == 1) {
        ErrorPrinting(1, shapeName);
        return;
    }

    Shape* myShape = new Shape(shapeName, type, xloc, yloc, xsize, ysize);
    ShapeNode* ptr1 = new ShapeNode();
    ptr1->setShape(myShape);
    pool->getShapeList()->insert(ptr1);
    myShape->draw();



}

void groupCommand(stringstream &lineStream, GroupList* &gList) {

    string groupName;
    lineStream>>groupName;
    if (checkNameValid(groupName) == false) {
        ErrorPrinting(0, "");
        return;
    }
    else if (checkExists(groupName, "all") == 1) {
        ErrorPrinting(1, groupName);
        return;
    }

    GroupNode* mygroup = new GroupNode(groupName);
    gList->insert(mygroup);
    cout << groupName << ": group" << endl;

}

void drawCommand(GroupList* &gList) {
    cout << "drawing:" << endl;
    gList->print();
}

void moveCommand(stringstream &lineStream) {
    string name1, name2;
    lineStream >> name1 >> name2;

    if(checkNameValid(name1) == false)
    {
        ErrorPrinting(0, "");
        return;
    }
    
    if(checkNameValid(name2) == false)
    {
        ErrorPrinting(0, "");
        return;
    }
    
    if (checkExists(name1, "shape") == 2) {
        if (checkExists(name2, "group") == 4) {
            GroupNode* shapeGroup = findGroup(name1);
            
            
            GroupNode* destinationGroup = findGroup(name2);
            
            ShapeNode* deletedShape = shapeGroup->getShapeList()->remove(name1);
            
            destinationGroup->getShapeList()->insert(deletedShape);
            cout << "moved " << name1 << " to " << name2 << endl;

        } else {
            ErrorPrinting(3, name2);
        }
    } else {
        ErrorPrinting(2, name1);
    }
}

void deleteCommand(stringstream &lineStream, GroupList* &gList) {
    string name;
    lineStream>>name;
    if (checkNameValid(name) == false) {
        ErrorPrinting(0, "");
        return;
    }
    // check for if its not a shape or a group name return
    if (checkExists(name, "shape") == 2) { // FIX THIS
        GroupNode* ptr1 = findGroup(name);


        ShapeNode* ptr2 = ptr1->getShapeList()->getHead();
        ShapeNode* ptr3 = NULL;

        while (ptr2 != NULL) {
            if (ptr2->getShape()->getName() == name) {
                break;
            }

            ptr3 = ptr2;
            ptr2 = ptr2->getNext();
        }

        if (ptr2 == ptr1->getShapeList()->getHead()) {
            ptr1->getShapeList()->setHead(ptr2->getNext());


                    delete ptr2->getShape();

            ptr2->setShape(nullptr);
            delete ptr2;
                ptr2 = nullptr;
            
            
            cout << name << ": deleted" << endl;

        } else {
            ptr3->setNext(ptr2->getNext());
            delete ptr2->getShape();
            
            ptr2->setShape(nullptr);
            
            delete ptr2;
            
                ptr2 = nullptr;
            cout << name << ": deleted" << endl; 
        }
    }

    
    else if (checkExists(name, "group") == 4) {

        GroupNode* groupNode = gList->getHead();
        GroupNode* lateGroupNode = NULL;

        while (groupNode != NULL) {
            if (groupNode->getName() == name) break;

            lateGroupNode = groupNode;
            groupNode = groupNode->getNext();
        }

        lateGroupNode->setNext(groupNode->getNext());

        if (groupNode->getShapeList()->getHead() == NULL) 
        {
            delete groupNode;
            cout << name << ": deleted" << endl;
        } 
        else {
            ShapeNode* s = groupNode->getShapeList()->getHead();

            while (s != NULL) {
                string Nname, Ytype;
                int xLoc, yLoc, xSize, ySize;
                Nname = s->getShape()->getName();
                Ytype = s->getShape()->getType();
                xLoc = s->getShape()->getXlocation();
                yLoc = s->getShape()->getYlocation();
                xSize = s->getShape()->getXsize();
                ySize = s->getShape()->getYsize();

                    Shape* shapeSS = new Shape(Nname, Ytype, xLoc, yLoc, xSize, ySize);
                ShapeNode* shapeNodeS = new ShapeNode();
                shapeNodeS->setShape(shapeSS);
                gList->getHead()->getShapeList()->insert(shapeNodeS);

                s = s->getNext();
            }

            ShapeNode* tunisia = groupNode->getShapeList()->getHead();
            ShapeNode* latetunisia = NULL;

            while (tunisia != NULL) {
                latetunisia = tunisia->getNext();
                delete tunisia->getShape();
                
                
                
                tunisia->setShape(nullptr);
                    delete tunisia;
                    tunisia = latetunisia;
            }

            groupNode->getShapeList()->setHead(NULL);
            lateGroupNode->setNext(groupNode->getNext());
            
                delete groupNode;
            cout << name << ": deleted" << endl;

        }

    }
    
    else if (checkExists(name, "shape") == 3) {
        ErrorPrinting(2, name);
        return;
    }

    
    return;

    //else if(checkExists(name,))
}

int main() {

    // Create the groups list
    gList = new GroupList();

    // Create the poo group and add it to the group list
    GroupNode* poolGroup = new GroupNode(keyWordsList[NUM_KEYWORDS - 1]);
    gList->insert(poolGroup);

    string line;
    string command;

    cout << "> "; // Prompt for input
    getline(cin, line); // Get a line from standard input

    while (!cin.eof()) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream(line);

        if (lineStream.peek() == EOF) {
            cout << "> "; // Prompt for input
            getline(cin, line);
            continue;
        }

        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        if (command == "shape") {
            shapeCommand(lineStream, poolGroup);
        }

        if (command == "group") {
            groupCommand(lineStream, gList);
        }

        if (command == "draw") {
            drawCommand(gList);
        }

        if (command == "move") {
            moveCommand(lineStream);
        }

        if (command == "delete") {
            deleteCommand(lineStream, gList);
        }

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here

        // Once the command has been processed, prompt for the
        // next command
        //lineStream.clear();
        cout << "> "; // Prompt for input
        getline(cin, line);


    } // End input loop until EOF.

    return 0;
}

