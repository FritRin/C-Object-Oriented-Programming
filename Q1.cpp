#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int Rows = 13;
const int Seats = 6;
const char seat_labels[Seats] = {'A', 'B', 'C', 'D', 'E', 'F'};

bool valid_type(char);
bool valid_row(char, int);
bool valid_seat(char);
int seat_number(char);
void welcome();
void seating(bool reserved_seats[Rows][Seats]);

int main(){

    char choice;
    bool seat_reserved[Rows][Seats] = {};

    welcome();
    seating(seat_reserved);

    cout << "Would you like to reserve a seat? Y/y (Yes), N/n (no): ";
    cin >> choice;
    if(choice == 'Y' || choice == 'y'){
        while(true){
            char ticket_type = 0;
            int row = 0;
            char seat = 0;
            bool seat_chosen = false;

            while(!seat_chosen){

                while(!valid_type(ticket_type)){
                cout << "Enter ticket type: F/f (first class), B/b (business class), E/e (economy class): ";
                cin >> ticket_type;   
                }

                do{
                    if(ticket_type == 'F' || ticket_type == 'f'){
                        cout << "Enter row number 1 - 2: ";
                        cin >> row;
                    }
                    if(ticket_type == 'B' || ticket_type == 'b'){
                        cout << "Enter row number 3 - 7: ";
                        cin >> row;
                    }
                    if(ticket_type == 'E' || ticket_type == 'e'){
                        cout << "Enter row number 8 - 13: ";
                        cin >> row;
                    }
                }while(!valid_row(ticket_type, row));

                while(!valid_seat(seat)){
                    cout << "Enter seat number (A - F): ";
                    cin >> seat;
                }

                if(seat_reserved[row-1][seat_number(seat)]){
                    cout << "*#*#*#*# This seat is occupied *#*#*#*#" << endl;
                    cout << "Make another selection" << endl;
                    seating(seat_reserved);
                    row = 0;
                    seat = 0;
                }
                else {
                    seat_chosen = true;
                    seat_reserved[row-1][seat_number(seat)] = true;
                    cout << "This seat is reserved for you." << endl;
                    seating(seat_reserved);
                    cout << endl;
                }
            }
            welcome();
            seating(seat_reserved);
            cout << "Reserve another seat? Y/y (Yes), N/n (No): ";
            cin >> choice;
            if(choice == 'N' || choice == 'n'){
                break;
            }
        } 
    }

    return 0;
}

bool valid_type(char ticket){
    char valid[6] = {'F', 'f', 'B', 'b', 'E', 'e'};

    for(int t=0; t < 6; t++){
        if(ticket == valid[t]){
            return true;
        }
    }
    return 0;
}

bool valid_row(char t, int r){
    if(t == 'F' || t == 'f'){
        if(r > 2 || r < 0){
            return false;
        } return true;
    } 

    if(t == 'B' || t == 'b'){
        if(r > 7 || r < 3){
            return false;
        }
        else return true;
    }

    if(t == 'E' || t == 'e'){
        if(r > 13 || r < 8){
            return false;
        } else return true;
    }
    return 0;
}

bool valid_seat(char seat){
    for(int t=0; t < 6; t++){
        if(seat == seat_labels[t]){
            return true;
        }
    }
    return 0;
}

int seat_number(char s){
    switch(s){
        case 'A':
            return 0;

        case 'B':
            return 1;
        
        case 'C':
            return 2;
        
        case 'D':
            return 3;

        case 'E':
            return 4;
        
        case 'F':
            return 5;
        
        default:
            return 0;
    }
}

void seating(bool reserved_seats[Rows][Seats]){

    cout << setw(Seats) << setfill(' ') << " ";
    for(int g = 0; g < Seats/2; g++){
        cout << setw(2) << seat_labels[g];
    }
    cout << " ";
    for(int h = 3; h < Seats; h++){
        cout << setw(2) << seat_labels[h];
    }
    cout << endl;

    for(int i = 0; i < Rows; i++){
        cout << "Row " << i + 1 << " ";
        if(i < 9){
            cout << " ";
        }
        for(int j = 0; j < 3; j++){
            if(reserved_seats[i][j]){
                cout << "X ";
            } else cout << "* "; 
        } 
        for(int k = 3; k < 6; k++){
            if(reserved_seats[i][k]){
                cout << right << setw(2) << " X";
            } else cout << right << setw(2) << " *"; 
        }
        cout << endl;
    }
    cout << "* -- available seat" << endl;
    cout << "X -- occupied seat" << endl;
    cout << endl;
    cout << "Rows 1 and 2 are for first class passengers." << endl;
    cout << "Rows 3 through 7 are for business class passengers." << endl;
    cout << "Rows 8 through 13 are for economy class passengers." << endl;
}

void welcome(){
    cout << "This program assigns seats for a commercial airplane." << endl;
    cout << "The current seat assignments are as follows." << endl;
}