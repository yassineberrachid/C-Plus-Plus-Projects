//
//  playMove.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

// update the functions turn, validmove,gameover,wincode

#include "globals.h"
#include "GameState.h"
#include <iostream>

void playMove(GameState& game_state) {
 
        
        if(game_state.get_turn()==true){ // If it's X turn

            if(game_state.get_gameBoard(game_state.get_selectedRow(),game_state.get_selectedColumn())==0){

                game_state.set_moveValid(true);

                game_state.set_gameBoard(game_state.get_selectedRow(),game_state.get_selectedColumn(),X);


                if(game_state.get_gameBoard(2,0)==1 && game_state.get_gameBoard(1,1)==1 && game_state.get_gameBoard(0,2)==1 ){
                    game_state.set_winCode(8);
                    game_state.set_gameOver(true);
                    return;
                }

                else if(game_state.get_gameBoard(0,0)==1 && game_state.get_gameBoard(1,1)==1 && game_state.get_gameBoard(2,2)==1 ){
                    game_state.set_winCode(7);
                    game_state.set_gameOver(true);
                    return;
                    
                }

                else if(game_state.get_gameBoard(0,2)==1 && game_state.get_gameBoard(1,2)==1 && game_state.get_gameBoard(2,2)==1 ){
                    game_state.set_winCode(6);
                    game_state.set_gameOver(true);
                    return;
                }

                else if(game_state.get_gameBoard(0,1)==1 && game_state.get_gameBoard(1,1)==1 && game_state.get_gameBoard(2,1)==1 ){
                    game_state.set_winCode(5);
                    game_state.set_gameOver(true);
                    return;
                }

                else if(game_state.get_gameBoard(0,0)==1 && game_state.get_gameBoard(1,0)==1 && game_state.get_gameBoard(2,0)==1 ){
                    game_state.set_winCode(4);
                    game_state.set_gameOver(true);
                    return;
                }
                
                else if(game_state.get_gameBoard(2,0)==1 && game_state.get_gameBoard(2,1)==1 && game_state.get_gameBoard(2,2)==1 ){
                    game_state.set_winCode(3);
                    game_state.set_gameOver(true);
                    return;
                }
                
                else if(game_state.get_gameBoard(1,0)==1 && game_state.get_gameBoard(1,1)==1 && game_state.get_gameBoard(1,2)==1 ){
                    game_state.set_winCode(2);
                    game_state.set_gameOver(true);
                    return;
                }

                else if(game_state.get_gameBoard(0,0)==1 && game_state.get_gameBoard(0,1)==1 && game_state.get_gameBoard(0,2)==1 ){
                    game_state.set_winCode(1);
                    game_state.set_gameOver(true);
                    return;
                }

                else if(game_state.get_gameBoard(0,0)!=0 && game_state.get_gameBoard(0,1)!=0 && game_state.get_gameBoard(0,2)!=0 && game_state.get_gameBoard(1,0)!=0 && game_state.get_gameBoard(1,1)!=0 && game_state.get_gameBoard(1,2)!=0 && game_state.get_gameBoard(2,0)!=0 && game_state.get_gameBoard(2,1)!=0 && game_state.get_gameBoard(2,2)!=0){
                    game_state.set_winCode(0);
                    game_state.set_gameOver(true);
                }
        

                else{ // No winner and no draw, the game continues, we change turns

                        game_state.set_winCode(0);
                        game_state.set_gameOver(false);
                        game_state.set_turn(false);
                        return;


                 }
    
            }
            else{

                game_state.set_moveValid(false);
                game_state.set_turn(true);
                game_state.set_gameOver(false);
                return;

            }

        }
        
        else if(game_state.get_turn()==false){ // If it's O turn

            if(game_state.get_gameBoard(game_state.get_selectedRow(),game_state.get_selectedColumn())==0){

                game_state.set_moveValid(true);

                game_state.set_gameBoard(game_state.get_selectedRow(),game_state.get_selectedColumn(),O);

                if(game_state.get_gameBoard(2,0)==-1 && game_state.get_gameBoard(1,1)==-1 && game_state.get_gameBoard(0,2)==-1 ){
                    game_state.set_winCode(8);
                    game_state.set_gameOver(true);
                    return;
                }

                else if(game_state.get_gameBoard(0,0)==-1 && game_state.get_gameBoard(1,1)==-1 && game_state.get_gameBoard(2,2)==-1 ){
                    game_state.set_winCode(7);
                    game_state.set_gameOver(true);
                    return;
                }

                else if(game_state.get_gameBoard(0,2)==-1 && game_state.get_gameBoard(1,2)==-1 && game_state.get_gameBoard(2,2)==-1 ){
                    game_state.set_winCode(6);
                    game_state.set_gameOver(true);
                    return;
                }

                else if(game_state.get_gameBoard(0,1)==-1 && game_state.get_gameBoard(1,1)==-1 && game_state.get_gameBoard(2,1)==-1 ){
                    game_state.set_winCode(5);
                    game_state.set_gameOver(true);
                    return;
                }

                else if(game_state.get_gameBoard(0,0)==-1 && game_state.get_gameBoard(1,0)==-1 && game_state.get_gameBoard(2,0)==-1 ){
                    game_state.set_winCode(4);
                    game_state.set_gameOver(true);
                    return;
                }

                else if(game_state.get_gameBoard(2,0)==-1 && game_state.get_gameBoard(2,1)==-1 && game_state.get_gameBoard(2,2)==-1 ){
                    game_state.set_winCode(3);
                    game_state.set_gameOver(true);
                    return;
                }

                else if(game_state.get_gameBoard(1,0)==-1 && game_state.get_gameBoard(1,1)==-1 && game_state.get_gameBoard(1,2)==-1 ){
                    game_state.set_winCode(2);
                    game_state.set_gameOver(true);
                    return;
                }

                else if(game_state.get_gameBoard(0,0)==-1 && game_state.get_gameBoard(0,1)==-1 && game_state.get_gameBoard(0,2)==-1 ){
                    game_state.set_winCode(1);
                    game_state.set_gameOver(true);
                    return;
                }

                else if(game_state.get_gameBoard(0,0)!=0 && game_state.get_gameBoard(0,1)!=0 && game_state.get_gameBoard(0,2)!=0 && game_state.get_gameBoard(1,0)!=0 && game_state.get_gameBoard(1,1)!=0 && game_state.get_gameBoard(1,2)!=0 && game_state.get_gameBoard(2,0)!=0 && game_state.get_gameBoard(2,1)!=0 && game_state.get_gameBoard(2,2)!=0){
                    game_state.set_winCode(0);
                    game_state.set_gameOver(true);
                }
                
                else{ // No winner and no draw, the game continues, we change turns

                        game_state.set_winCode(0);
                        game_state.set_gameOver(false);
                        game_state.set_turn(true);
                        return;
                    }


            }

            else{

                game_state.set_moveValid(false);
                game_state.set_turn(false);
                game_state.set_gameOver(false);
                return;

            }
        












        }

}

