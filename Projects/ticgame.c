#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//printf("\e[1;1H\e[2J");//By using this regex terminal screen can be cleared in 0.000001 sec
#define max(a,b) a>b?a:b
#define min(a,b) a>b?b:a
char mat[9];
int turn = 0, comp_turn = 0, a=0, b=0;
void reset(){
    for(int i=0;i<9;i++){
        mat[i] = 49+i;//as ascii of 1 is 49 and 9 is 57
    }
    turn = 0;//again make player 1 as first
}
void display(){
    printf(" %c | %c | %c",mat[0],mat[1],mat[2]);
    printf("\n-----------\n");
    printf(" %c | %c | %c",mat[3],mat[4],mat[5]);
    printf("\n-----------\n");
    printf(" %c | %c | %c",mat[6],mat[7],mat[8]);
}
int win(){
    char winner = 't';
    if((mat[0]==mat[1]&&mat[1]==mat[2])||(mat[0]==mat[3]&&mat[3]==mat[6])) { //1st row && 1st col
        winner = mat[0];
    }
    else if((mat[0]==mat[4]&&mat[4]==mat[8])||(mat[2]==mat[4]&&mat[4]==mat[6])|| //2 disgonals
    (mat[3]==mat[4]&&mat[4]==mat[5])||(mat[1]==mat[4]&&mat[4]==mat[7])){ //2nd row && 2nd col
        winner  = mat[4];
    }
    else if((mat[6]==mat[7]&&mat[7]==mat[8])||(mat[2]==mat[5]&&mat[5]==mat[8])){ //3rd row && 3rd col
        winner = mat[8];
    }
    if(winner == 'X') return -10;
    else if(winner == 'O') return 10;
    return 0;
}
int isMovesLeft(){
    for(int i=0;i<9;i++){
        if(mat[i]==49+i) return 1;
    }
    return 0;
}
int minimax(int depth, bool isMax) {
    int score = win();
    if (score == 10)// If Maximizer has won the game return his/her evaluated score
        return score;
    if (score == -10)// If Minimizer has won the game return his/her evaluated score
        return score;
    if (isMovesLeft()==false)// If there are no more moves and no winner then it is a tie
        return 0;
    if (isMax)// If this maximizer's move
    {
        int best = -1000;
        for (int i = 0; i<9; i++) {// Traverse all cells
            if (mat[i]==49+i) {// Check if cell is empty
                mat[i] = 'O';// Make the move
                // Call minimax recursively and choose the maximum value
                best = max( best, minimax(depth+1, !isMax) );
                mat[i]=49+i;// Undo the move
            }
        }
        return best;
    } else {// If this minimizer's move
        int best = 1000;
        for (int i = 0; i<9; i++) {// Traverse all cells
            if (mat[i]==49+i) {// Check if cell is empty
                mat[i] = 'X';// Make the move
                // Call minimax recursively and choose the maximum value
                best = min( best, minimax(depth+1, !isMax) );
                mat[i]=49+i;// Undo the move
            }
        }
        return best;
    }
}
int findBestMove() {
    int bestVal = -1000;
    int bestMove;
    for (int i = 0; i<9; i++) {// Traverse all cells, evaluate minimax function for all empty cells. And return the cell with optimal value.
        if (mat[i]==49+i) {// Check if cell is empty
            mat[i] = 'O';// Make the move
            int moveVal = minimax(0, false);// compute evaluation function for this move.
            mat[i] = 49+i;// Undo the move
            // If the value of the current move is more than the best value, then update best
            if (moveVal > bestVal) {
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }
    return bestMove+1;
}
void play(){
    int x;
    if(turn == 0){ //Player 1 turn
        printf("Enter the number in cell to play your turn : ");
        s:
        while(scanf("%d",&x)<10){
            if(x<10) break;
            printf("Enter a valid position..\nEnter the number in cell to play your turn : ");
        }
        while((mat[x-1]=='X'||mat[x-1]=='O')){
            printf("Position already taken\nEnter the number in cell to play your turn : ");
            goto s;
        }
        mat[x-1] = 'X';
    } else { // Player 2 turn
        if(comp_turn == 1) x = findBestMove(); //if comp_turn then this
        else { //else manually
            printf("Enter the number in cell to play your turn : ");
            w:
            while(scanf("%d",&x)<10){
                if(x<10) break;
                printf("Enter a valid position..\nEnter the number in cell to play your turn : ");
            }
            while((mat[x-1]=='X'||mat[x-1]=='O')){
                printf("Position already taken\nEnter the number in cell to play your turn : ");
                goto w;
            }
        }
        mat[x-1] = 'O';
    } 
    return;
}
void turn_change(){
    if(turn == 0) turn = 1;
    else turn = 0;
}
void startGame(){
    while(1) {
        printf("\e[1;1H\e[2J--------TIC-TAC-TOE--------\n");
        printf("Player1 - X    Player2 - O\n");
        printf("Won : %d        Won : %d\n",a,b);
        display();
        if(turn == 0) printf("\nPlayer 1 turn\n");//printing whose turn
        else printf("\nPlayer 2 turn\n");
        play();//play the turn
        int winner = win();//if anyone won
        if(winner == -10) {
            printf("\e[1;1H\e[2J--------TIC-TAC-TOE--------\n");
            display();
            printf("\nPlayer 1 won!!\n");
            a++;
            break;
        } else if(winner == 10){
            printf("\e[1;1H\e[2J--------TIC-TAC-TOE--------\n");
            display();
            printf("\nPlayer 2 won!!\n");
            b++;
            break;
        }
        if(!isMovesLeft()) {//if the array is full
            printf("DRAW..\n");
            break;
        }
        turn_change();//change turn
    }
    return;
}
int main(){
    int choice=1;
    printf("\e[1;1H\e[2J--------TIC-TAC-TOE--------\nPress 1 to play with Computer\nPress 2 to play with player 2\n");
    scanf("%d",&comp_turn);
    while(choice == 1){
        reset();
        display();
        startGame();
        printf("Press 1 to play another game : ");
        scanf("%d",&choice);
    }
    return 0;
}
