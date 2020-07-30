#include <iostream>

using namespace std;

class game {
    public:
        char Board[9] = {'-','-','-',
                    '-','-','-',
                    '-','-','-'};
    char current_player ='X';
    bool win = false;
    bool run = true;
    int index;
    bool row_winner;
    bool column_winner;
    bool diagonal_winner;

    void display_Board(){
        cout << Board[0] << '|' << Board[1] << '|' << Board[2] << endl;
        cout << Board[3] << '|' << Board[4] << '|' << Board[5] << endl;
        cout << Board[6] << '|' << Board[7] << '|' << Board[8] << endl;
        

    }

    void check_for_winner(){
        check_win();
        check_Tie();
    }
    void check_win(){
        row_winner = check_rows();
        column_winner = check_column();
        diagonal_winner = check_Diagonals();

        if(row_winner){
            run = false;
            cout << current_player << " won" << endl;
        }
        else if(column_winner){
            run = false;
            cout << current_player << " won" << endl;
        }
        else if(diagonal_winner){
            run = false;
            cout << current_player << " won" << endl;
        }


    }
    void check_Tie(){

        if(Board[0] != '-' && Board[1] != '-' && Board[2] != '-' && Board[3] != '-' && Board[4] != '-' && Board[5] != '-'
         && Board[6] != '-' && Board[7] != '-' && Board[8] != '-'){
            run = false;
            cout << "It is a Tie..." << endl;
         }

    }
    bool check_rows(){
        if (Board[0] == current_player && Board[1] == current_player && Board[2] == current_player){
            run = false;
            win = true;
        }
        else if (Board[3] == current_player && Board[4] == current_player && Board[5] == current_player) {
            run = false;
            win = true;
        }
        else if(Board[6] == current_player && Board[7] == current_player && Board[8] == current_player){
            run = false;
            win  = true;
        }
        return win;
    }
    bool check_column(){
        if (Board[0] == current_player && Board[3] == current_player && Board[6] == current_player){
            run = false;
            win = true;
        }
        else if(Board[1] == current_player && Board[4] == current_player && Board[7] == current_player){
            run = false;
            win = true;
        }
        else if(Board[2] == current_player && Board[5] == current_player && Board[8] == current_player){
            run = false;
            win  = true;
        }
        return win;
    }
    bool check_Diagonals(){
        if (Board[0] == current_player && Board[4] == current_player && Board[8] == current_player){
            run = false;
            win = true;
        }
        else if(Board[2] == current_player && Board[4] == current_player && Board[6] == current_player){
            run = false;
            win = true;
        }
        return win;
    }
    void flip_player(){
        if (current_player == 'X'){
            current_player = 'O';
        }
        else if(current_player == 'O'){
            current_player = 'X';
        }
    }


};

void playgame() {

    game Game;

    while (Game.run) {
            cout << "current Player is: " << Game.current_player << endl;
            cout << "Enter your position from 1-9: ";
            cin >> Game.index;
            if (Game.Board[Game.index-1] == '-'){
                Game.Board[Game.index-1] = Game.current_player;
                Game.display_Board();
                Game.check_for_winner();
                Game.flip_player();
            }
            else
            {
                cout <<  "It is already filled....." << endl;
            }
            

        }
    }






int main(){
    game Game;
    char yes_or_no;
    bool start = true;
    while (start){
        cout << "want to play?";
        cin  >> yes_or_no;
        if (yes_or_no == 'y'){
            Game.display_Board();
            playgame();
        }else if(yes_or_no == 'n'){
            start = false;
        }

    }
    return 0;
}