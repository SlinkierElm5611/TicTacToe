#include <iostream>//Used to be able to output or input information
#include <chrono>//Used to be able to use the sleep command at the end of program so it doesnt close instantly
#include "board.h"//imports the header file containing the board class
using namespace std;//means that the program will use the functions from the std "department" as you like to say
int main(){//Driver code
    int location;
    board game;//Creates an object for the board class
    bool moveallowed;
    bool colour=false;
    while(!game.EndGameChecker()){//Checks if the game has ended, and the game runs while its not over
        colour = !colour;
        moveallowed= false;
        for(int i=0; i<3; i++){//Prints the board out to the terminal
            for(int j=0; j<3; j++){
                cout<<" | ";
                if(game.spaceisoccupied[i][j]){
                    if(game.colourofoccupiedspace[i][j]){
                        cout<<"X";
                    }else{
                        cout<<"O";
                    }
                }else{
                    cout<<"-";
                }
            }
            cout<<" | "<<endl;
        }
        if(colour){//Checks who's turn it is
            cout<<"It is X's turn"<<endl;
        }else{
            cout<<"It is O's turn"<<endl;
        }
        while(!moveallowed){//This runs the actual turn and makes sure the input is correct
            cout<<"Enter the location you wish to take"<<endl;
            cin>>location;
            if(location/10>=3||location/10<0||location%10>=3||location%10<0){
                moveallowed=false;
                cout<<"Out of Bounds!!!!"<<endl;
            }else if(game.boardlocationchecker(location)){
                moveallowed= true;
            }else{
                cout<<"There is already something there"<<endl;
                moveallowed=false;
            }
        }
        game.boardUpdator(location, colour);//calls the function to update the board
    }
    for(int i=0; i<3; i++){//just to print the board one last time on the endgame condition
        for(int j=0; j<3; j++){
            cout<<" | ";
            if(game.spaceisoccupied[i][j]){
                if(game.colourofoccupiedspace[i][j]){
                    cout<<"X";
                }else{
                    cout<<"O";
                }
            }else{
                cout<<"-";
            }
        }
        cout<<" | "<<endl;
    }
    if(colour){//prints who the winner is
        cout<<"X is the winner"<<endl;
    }else{
        cout<<"O is the winner";
    }
    _sleep(10000);//Waits 10 seconds before completing the stack/closing the program
}