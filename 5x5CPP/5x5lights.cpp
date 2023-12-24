#include <iostream>
#include <stdlib.h>
using namespace std;
const int ROWS = 5;
const int COLS = 5;

bool count_lights(int (*game_board)[COLS], int light_amt); // returns 1 if amt of lights == to amt counted, used for testing purposes to ensure proper board creation
int generate_game_board(int (*game_board)[COLS]); //returns number of lights turned "on" aka ints flipped to 1
void print_board(int (*game_board)[COLS]); 
void turn_off_lights(int (*game_board)[COLS], int i, int j); //turns 1 to 0 and then flips surronding neighbors to 1
int check_win(int (*game_board)[COLS]); // if complete return 0 otherwise return 1 if 1 is found, return 2 if error
void random_play(int (*game_board)[COLS]);


int main(){
    int game_board[ROWS][COLS] = {{0,0,0,0,0},
                                  {0,0,0,0,0},
                                  {0,0,0,0,0},
                                  {0,0,0,0,0},
                                  {0,0,0,0,0}};
    int lights = generate_game_board(game_board);
    // print_board(game_board);
    // turn_off_lights(game_board,3,3);
    // print_board(game_board);
    // turn_off_lights(game_board,2,2);
    // cout<<endl;
    // print_board(game_board);
    random_play(game_board);
    // count_lights(game_board,lights);
    // TODO
    // Allow for coordinates to be "flipped" turning off "0" the picked coordinate and turning on "1" the surronding lights if they are not already on
    // Create functions to randomly do this 
    // Create function to check if board is clear aka all "0s"
    // Time the random function for how long it takes to complete
    // 
    return  0;
}

bool count_lights(int (*game_board)[COLS], int light_amt){
    // Utilized for veryfing correct # of lights are being lit up
    if(game_board == NULL){
        return false;
    }
    int count = 0;
    for(int i = 0; i < COLS; i++){
        for(int j = 0; j < ROWS; j++){
            if(game_board[i][j] == 1){
                count++;
            }
        }
    }
    // cout << count << endl;
    // cout << light_amt << endl;
    return count == light_amt;
}

int check_win(int (*game_board)[COLS]){
    if(game_board == NULL){
        return 2; //error
    }
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(game_board[i][j] == 1){
                return 1;// not won
            }
        }
        cout << endl;
    }
    return 0;//success, board is cleared
}

int generate_game_board(int (*game_board)[COLS]){
    if(game_board == NULL){
        return 1;
    }
    srand (time(NULL));
    // Deciding on amount of lights to have on
    int light_amt = rand() % 10 + 5;
    int lights = light_amt;
    int i = 0;
    int j = 0;
    while(light_amt > 0){
        int light_square = rand() % 2;
        int i = rand() % 5;
        int j = rand() % 5;
        // cout << light_amt << endl;
        if(light_square && game_board[i][j] != 1){
            game_board[i][j] = 1;
            light_amt--;
        }
        
        if(i == ROWS && j == COLS){
            i = 0;
            j = 0;
        }
    }
    print_board(game_board);
    cout<< endl;
    // cout << lights << endl;
    return lights;
}

void turn_off_lights(int (*game_board)[COLS], int i, int j){
    game_board[i][j] = 1 - game_board[i][j];
    game_board[i+1][j] = 1 - game_board[i+1][j];
    game_board[i-1][j] = 1 - game_board[i-1][j];
    game_board[i][j+1] = 1 - game_board[i][j+1];
    game_board[i][j-1] = 1 - game_board[i][j-1];
}

void print_board(int (*game_board)[COLS]){
    //printing board
    if(game_board == NULL){
        return;
    }
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            cout << game_board[i][j] << " ";
        }
        cout << endl;
    }
}

void random_play(int (*game_board)[COLS]){
    srand (time(NULL));
    // Deciding on amount of lights to have on
    int i = rand() % 5;
    int j = rand() % 5;
    while(check_win(game_board) != 0){
        int i = rand() % 5;
        int j = rand() % 5;
        turn_off_lights(game_board, i, j);
        print_board(game_board);
        // cout<<endl;
    }
    return;
}
