#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H
class board {
public://this is where the public functions and variables go
    bool spaceisoccupied[3][3];//Creates a 2-d boolean array which checks if the spot is taken
    bool colourofoccupiedspace[3][3];//Creates a 2-d boolean array which tells the whether the occupant of the space is X or O
    board(){//Constructor function for class board
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                spaceisoccupied[i][j]=false;//Sets all positions as empty
            }
        }
    }
    bool boardlocationchecker(int location){//Function that returns true if its empty or false if its taken
        return !spaceisoccupied[location % 10][location / 10];
    }
    void boardUpdator(int location, bool colour){//Function that does not return anything and updates the board with the new position
        spaceisoccupied[location%10][location/10]=true;
        colourofoccupiedspace[location%10][location/10]=colour;
    }
    bool EndGameChecker(){//Checks if there is an endgame condition fufilled, there are 8 possible endgames btw, it returns true if the game is over, false if it isn't over
        if(spaceisoccupied[0][0]&&spaceisoccupied[0][1]&&spaceisoccupied[0][2]){
            if(colourofoccupiedspace[0][0]==colourofoccupiedspace[0][1]&&colourofoccupiedspace[0][1]==colourofoccupiedspace[0][2]){
                return true;
            }
        }
        if(spaceisoccupied[0][0]&&spaceisoccupied[1][0]&&spaceisoccupied[2][0]){
            if(colourofoccupiedspace[0][0]==colourofoccupiedspace[1][0]&&colourofoccupiedspace[1][0]==colourofoccupiedspace[2][0]){
                return true;
            }
        }
        if(spaceisoccupied[0][0]&&spaceisoccupied[1][1]&&spaceisoccupied[2][2]){
            if(colourofoccupiedspace[0][0]==colourofoccupiedspace[1][1]&&colourofoccupiedspace[1][1]==colourofoccupiedspace[2][1]){
                return true;
            }
        }
        if(spaceisoccupied[0][2]&&spaceisoccupied[1][2]&&spaceisoccupied[2][2]){
            if(colourofoccupiedspace[0][2]==colourofoccupiedspace[1][2]&&colourofoccupiedspace[1][2]==colourofoccupiedspace[2][2]){
                return true;
            }
        }
        if(spaceisoccupied[0][1]&&spaceisoccupied[1][1]&&spaceisoccupied[2][1]){
            if(colourofoccupiedspace[0][1]==colourofoccupiedspace[1][1]&&colourofoccupiedspace[1][1]==colourofoccupiedspace[2][1]){
                return true;
            }
        }
        if(spaceisoccupied[0][2]&&spaceisoccupied[1][1]&&spaceisoccupied[2][0]){
            if(colourofoccupiedspace[0][2]==colourofoccupiedspace[1][1]&&colourofoccupiedspace[1][1]==colourofoccupiedspace[2][0]){
                return true;
            }
        }
        if(spaceisoccupied[1][0]&&spaceisoccupied[1][1]&&spaceisoccupied[1][2]){
            if(colourofoccupiedspace[1][0]==colourofoccupiedspace[1][1]&&colourofoccupiedspace[1][1]==colourofoccupiedspace[1][2]){
                return true;
            }
        }
        if(spaceisoccupied[2][0]&&spaceisoccupied[2][1]&&spaceisoccupied[2][2]){
            if(colourofoccupiedspace[2][0]==colourofoccupiedspace[2][1]&&colourofoccupiedspace[2][1]==colourofoccupiedspace[2][2]){
                return true;
            }
        }
        return false;
    }
};
#endif //TICTACTOE_BOARD_H
