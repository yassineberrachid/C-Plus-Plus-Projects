#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"

// This is the shape array, to be dynamically allocated
Shape** shapesArray;

// The number of shapes in the database, to be incremented 
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;


void ErrorMessage(int number){
    if(number==0){
        cout<<"Error: invalid command"<<endl;
        return;
    }
    else if(number==1){
        cout<<"Error: invalid argument"<< endl;
        return;
    }
    
    else if(number==2){
        cout<<"Error: invalid shape name"<< endl;
        return;
    }

    else if(number==3){
        cout<<"Error: shape exists " <<endl;
        return;
    }

    else if(number==4){
        cout<<"Error: shape not found"<<endl;
        return;
    }

    else if(number==5){
        cout<<"Error: invalid shape type"<<endl;
        return;
    }

    else if(number==6){
        cout<<"Error: invalid value"<<endl;
        return;
    }

    else if(number==7){
        cout<<"Error: too many arguments"<<endl;
        return;
    }

    else if(number==8){
        cout<<"Error: too few arguments"<<endl;
        return;
    }
    else if(number==9){
        cout<<"Error: shape array is full"<<endl;
        return;
    }


}


bool checkNameValid(string name){

    for(int i=0;i<7;i++){
        if (name==keyWordsList[i]){
            return false;
        }
    }

    for(int i=0;i<4;i++){
        if(name==shapeTypesList[i]){
            return false;
        }
    }
    return true;
}

bool shapeNameExists(string name){
    for(int i=0; i<max_shapes;i++){
        if(shapesArray[i]==NULL){
            continue;
        }
        else{
            if((*shapesArray[i]).getName()==name){
                return true;
            }
        }
    }
    return false;
}


bool checkTypeValid(string type){
    for(int i=0;i<4;i++){
        if(type==shapeTypesList[i]){
            return true;
        }
    }

    return false;
}


bool checkLoc(int loc){
    if(loc>=0){
        return true;
    }
    else{
        return false;
    }

}
// linestream>> ws

bool checkSize(int sizeX,int sizeY, string command){
    
    if(command=="circle"){
        if(sizeX==sizeY){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if(sizeX>=0 && sizeY>=0){
            return true;
        }
        else{
            return false;
        }
    }
    
}

bool checkValue(int value){
    
    if(value>=0){
        return true;
    }
    else{
        return false;
    }
}

bool checkAngle(int angle){
    if(angle>=0 && angle<=360){
        return true;
    }
    else{
        return false;
    }
}



int main() {
    shapesArray=NULL;
    string line;
    string command;
    cout << "> ";         // Prompt for input
    getline(cin, line); 
    

    while ( !cin.eof () ) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        
        stringstream lineStream (line);
        
        //Check for linestream not eof
        
        if(lineStream.peek()==EOF){
            ErrorMessage(0);
            cout << "> ";         // Prompt for input
            getline(cin, line);
            continue;
        }
        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;
        if(command!="maxShapes" && command!="create" && command!="move" && command!="rotate" && command!="draw" && command!="delete"){ // invalid command case
            ErrorMessage(0);
            lineStream.clear();
            cout << "> ";         // Prompt for input
            getline(cin, line); 
            continue;
        }
        
               // Get a line from standard input
            if(command=="maxShapes"){

                int value;
                lineStream >> value;
                
                if(lineStream.fail() && lineStream.eof()) // check for too few arguments
                {
                    ErrorMessage(8);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line); 
                    continue;
                    
                }
                
                
                if(lineStream.fail()){
                    ErrorMessage(1);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line); 
                    continue;
                }
                int test=lineStream.peek();
                if(test!='\t' && test!=' ' && test!=EOF){ // Check for invalid argument
                    
                    ErrorMessage(1);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line); 
                    continue;
                }
                
                
                
                if(shapeCount<0){ // Check for invalid value
                    ErrorMessage(6);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                 // Too many arguments
                string tooMany;
                tooMany="";
                lineStream>>tooMany;
                if(tooMany!=""){
                    ErrorMessage(7);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                                
                if(shapesArray!=NULL){
                    for(int a=0;a<shapeCount;a++){ // Checks if the array is empty,and if it's not it deletes all the elements in the array
                        delete shapesArray[a];

                    }

                    //delete[] shapesArray;
                    shapesArray=nullptr;
                }

                max_shapes=value;
                shapesArray=new Shape*[max_shapes];
                cout<<"New database: max shapes is "<<max_shapes<<endl;
                shapeCount=0;
                

            }

            else if(command=="create"){
                string name,type;
                int loc1,loc2,size1,size2;
                lineStream>>name;
                if(lineStream.fail() && lineStream.eof()) // check for too few arguments
                {
                    ErrorMessage(8);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(checkNameValid(name)==false){ // Invalid shape name
                    ErrorMessage(2);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(shapeNameExists(name)==true){ 
                    cout<<"Error: shape "<<name<<" exists"<<endl;
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                lineStream>>type;
                
                if(lineStream.fail() && lineStream.eof()) // check for too few arguments
                {
                    ErrorMessage(8);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(checkTypeValid(type)==false){
                    ErrorMessage(5);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                lineStream>>loc1;
                
                if(lineStream.fail() && lineStream.eof()) // check for too few arguments
                {
                    ErrorMessage(8);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                
                if(lineStream.fail()){
                    ErrorMessage(1);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                int test=lineStream.peek();
                if(test!='\t' && test!=' ' && test!=EOF){ // Check for invalid argument
                    
                    ErrorMessage(1);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                

                
                if(checkLoc(loc1)==false){ // Check for invalid value;
                    ErrorMessage(6);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                lineStream>>loc2;
                
               if(lineStream.fail() && lineStream.eof()) // check for too few arguments
                {
                    ErrorMessage(8);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(lineStream.fail()){ // Invalid argument
                    ErrorMessage(1);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                test=lineStream.peek();
                if(test!='\t' && test!=' ' && test!=EOF){ // Check for invalid argument
                    
                    ErrorMessage(1);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }

                
                if(checkLoc(loc2)==false){ // Check for invalid value;
                    ErrorMessage(6);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                lineStream>>size1;
                
                if(lineStream.fail() && lineStream.eof()) // check for too few arguments
                {
                    ErrorMessage(8);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(lineStream.fail()){
                    ErrorMessage(1);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                test=lineStream.peek();
                if(test!='\t' && test!=' ' && test!=EOF){ // Check for invalid argument
                    
                    ErrorMessage(1);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }

                
                if(size1<0){ // Invalid value;
                    ErrorMessage(6);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                lineStream>> size2;
                
                if(lineStream.fail() && lineStream.eof()) // check for too few arguments
                {
                    ErrorMessage(8);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(lineStream.fail()){
                    ErrorMessage(1);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                test=lineStream.peek();
                if(test!='\t' && test!=' ' && test!=EOF){ // Check for invalid argument
                    
                    ErrorMessage(1);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
              
             
                if(size2<0){ // Invalid value;
                    ErrorMessage(6);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(type=="circle" && size1!=size2){
                    ErrorMessage(6);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                string tooMany;
                tooMany="";
                lineStream>>tooMany;
                if(tooMany!=""){
                    ErrorMessage(7);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(shapeCount==max_shapes){
                    ErrorMessage(9);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(shapeCount<=max_shapes){
                    
                     shapesArray[shapeCount]= new Shape(name,type,loc1,loc2,size1,size2); 
                    (*shapesArray[shapeCount]).setName(name);
                    (*shapesArray[shapeCount]).setType(type);
                    (*shapesArray[shapeCount]).setXlocation(loc1);
                    (*shapesArray[shapeCount]).setYlocation(loc2);
                    (*shapesArray[shapeCount]).setXsize(size1);
                    (*shapesArray[shapeCount]).setYsize(size2);
                    cout<<"Created "<<name<<": "<< type<< " "<< loc1<<" "<<loc2<< " "<< size1<< " "<< size2<<endl;
                    shapeCount++;
                }
                
                
                
                

            }

            else if(command=="move"){
                int xLoc, yLoc;
                string name;
                lineStream>>name;
                
                if(lineStream.fail() && lineStream.eof()) // check for too few arguments
                {
                    ErrorMessage(8);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(name=="all" || name=="maxShapes" || name=="create" || name=="move" || name=="rotate" || name=="draw" ||name=="delete" || name=="circle" || name=="ellipse" || name=="rectangle" || name=="triangle"){
                    ErrorMessage(2);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
               }
                
                if(shapeNameExists(name)==false){ // Not found
                    cout<<"Error: "<<"shape "<< name<< " not found"<<endl;
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                     
                        
                lineStream>>xLoc;
                
                if(lineStream.fail() && lineStream.eof()) // check for too few arguments
                {
                    ErrorMessage(8);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(lineStream.fail()){
                    ErrorMessage(1);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                int test=lineStream.peek();
                if(test!='\t' && test!=' ' && test!=EOF){ // Check for invalid argument
                    
                    ErrorMessage(1);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(checkLoc(xLoc)==false){ // Check for invalid value;
                    ErrorMessage(6);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
               
                  
                        
                lineStream>>yLoc;
                
                if(lineStream.fail() && lineStream.eof()) // check for too few arguments
                {
                    ErrorMessage(8);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(lineStream.fail()){
                    ErrorMessage(1);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                test=lineStream.peek();
                if(test!='\t' && test!=' ' && test!=EOF){ // Check for invalid argument
                    
                    ErrorMessage(1);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(checkLoc(yLoc)==false){ // Check for invalid value;
                    ErrorMessage(6);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                string tooMany;
                tooMany="";
                lineStream>>tooMany;
                if(tooMany!=""){
                    ErrorMessage(7);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                for(int i=0;i<max_shapes;i++){
                                        
                    if(shapesArray[i]==NULL){
                        continue;
                    }
                    if((*shapesArray[i]).getName()==name){
                        (*shapesArray[i]).setXlocation(xLoc);
                        (*shapesArray[i]).setYlocation(yLoc);
                        cout<<"Moved "<<name<<" to "<<xLoc<<" "<<yLoc<<endl;
                    }
                }
                
                            
                
                
  
            }
            
            
            else if(command=="rotate"){
                int angle;
                string name;
                lineStream>>name;
                if(lineStream.fail() && lineStream.eof()) // check for too few arguments
                {
                    ErrorMessage(8);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(name=="all" || name=="maxShapes" || name=="create" || name=="move" || name=="rotate" || name=="draw" ||name=="delete" || name=="circle" || name=="ellipse" || name=="rectangle" || name=="triangle"){
                  ErrorMessage(2);
                  lineStream.clear();
                  cout << "> ";         // Prompt for input
                  getline(cin, line);
                  continue;
               }
                
                if(shapeNameExists(name)==false){ // Not found
                    cout<<"Error: "<<"shape "<< name<< " not found"<<endl;
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                
                lineStream>>angle;
                
                if(lineStream.fail() && lineStream.eof()) // check for too few arguments
                {
                    ErrorMessage(8);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                
                
                if(lineStream.fail()){
                    ErrorMessage(1);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                int test=lineStream.peek();
                if(test!='\t' && test!=' ' && test!=EOF){ // Check for invalid argument
                    
                    ErrorMessage(1);
                    lineStream.clear();        
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(checkAngle(angle)==false){
                    ErrorMessage(6);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                string tooMany;
                tooMany="";
                lineStream>>tooMany;
                if(tooMany!=""){
                    ErrorMessage(7);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                for(int i=0;i<max_shapes;i++){
                                        
                    if(shapesArray[i]==NULL){
                        continue;
                    }
                    if((*shapesArray[i]).getName()==name){
                        (*shapesArray[i]).setRotate(angle);
                        cout<<"Rotated "<<name<<" by "<<angle<<" degrees"<<endl;
                    }
                }
                
                
            }
            
            else if(command=="draw"){
                
                string argument;
                lineStream>>argument;
                
                if(lineStream.fail() && lineStream.eof()) // check for too few arguments
                {
                    ErrorMessage(8);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                if(argument=="maxShapes" || argument=="create" || argument=="move" || argument=="rotate" || argument=="draw" ||argument=="delete" || argument=="circle" || argument=="ellipse" || argument=="rectangle" || argument=="triangle"){
                    ErrorMessage(2);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
               }
                
                if(shapeNameExists(argument)==false && argument!="all"){
                    cout<<"Error: shape "<<argument<<" not found"<<endl;
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                    
                }
                
                string tooMany;
                tooMany="";
                lineStream>>tooMany;
                if(tooMany!=""){
                    ErrorMessage(7);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                   if(argument!="all"){
                                    
                                
          
                    for(int i=0;i<max_shapes;i++){


                        if(shapesArray[i]==NULL){
                            continue;
                        }
                        if((*shapesArray[i]).getName()==argument){
                            cout<<"Drew "<< argument<< ": "<<(*shapesArray[i]).getType()<<" "<< (*shapesArray[i]).getXlocation()<<" "<<(*shapesArray[i]).getYlocation()<< " "<<(*shapesArray[i]).getXsize()<<" "<< (*shapesArray[i]).getYsize()<<endl;

                        }
                    }
                }

                else if(argument=="all"){
                    cout<<"Drew all shapes"<<endl;
                    for(int i=0;i<max_shapes;i++){
                        if(shapesArray[i]==NULL){
                            continue;
                        }
                        cout<<(*shapesArray[i]).getName()<<": "<<(*shapesArray[i]).getType()<<" "<< (*shapesArray[i]).getXlocation()<<" "<< (*shapesArray[i]).getYlocation()<< " "<< (*shapesArray[i]).getXsize()<<" "<<(*shapesArray[i]).getYsize()<<endl;

                    }

                }
             
            }
            
            else if(command=="delete"){
                string argument;
                lineStream>>argument;
                
                if(lineStream.fail() && lineStream.eof()) // check for too few arguments
                {
                    ErrorMessage(8);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(argument=="maxShapes" || argument=="create" || argument=="move" || argument=="rotate" || argument=="draw" ||argument=="delete" || argument=="circle" || argument=="ellipse" || argument=="rectangle" || argument=="triangle"){
                    ErrorMessage(2);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
               }
                
                if(shapeNameExists(argument)==false && argument!="all"){
                    cout<<"Error: shape "<<argument<<" not found"<<endl;
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                    
                }
                
                string tooMany;
                tooMany="";
                lineStream>>tooMany;
                if(tooMany!=""){
                    ErrorMessage(7);
                    lineStream.clear();
                    cout << "> ";         // Prompt for input
                    getline(cin, line);
                    continue;
                }
                
                if(argument!="all"){
                    for(int i=0; i<max_shapes;i++){
                        if(shapesArray[i]==NULL){
                            continue;
                        }
                        if((*shapesArray[i]).getName()==argument){
                            cout<<"Deleted shape "<< argument<<endl;
                            delete shapesArray[i];
                            shapesArray[i] = NULL;
                        }
                    }

                    
                }
                if(argument=="all"){
                    cout<<"Deleted: all shapes"<<endl;
                    for(int i=0; i<max_shapes;i++){
                        if(shapesArray[i]==NULL){
                            continue;
                        }
                        else{
                            delete shapesArray[i];
                            shapesArray[i]= NULL;
                            //shapeCount=0;

                        }

                    }
                    shapeCount=0;

                }
              
                
                //cout << "> ";         // Prompt for input
                //getline(cin, line);
 

            




            }
            
            lineStream.clear();
            cout << "> ";         // Prompt for input
            getline(cin, line);



            


                




            


            




        
        
        
        

        //if(command==)


        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
        
        
        
        
        // Once the command has been processed, prompt for the
        // next comman
        
        
    }
 
    
    return 0;
}


