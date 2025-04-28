#include <iostream>
#include <list>

using namespace std;

list<int> numbers;

void deleteValues(list<int>&, int, int);
void printList(const list<int>&);

int main(){
    int x = 0;
    int y = 0;

    for(int i = 0; i < 10; i++){
        numbers.push_back(i+1);
    }   

    while(x == 0 || y == 0){
        cout << "Please input two numbers: ";
        cin >> x;
        cin >> y;
        if(x > 10 || y > 10){
            cout << "Invalid input, please try again." << endl;
            x = 0;
            y = 0;
        }
    }

    cout << "Initial linked list: " << endl;
    printList(numbers);

    deleteValues(numbers, x, y);

    cout << "Linked list after deletion." << endl;
    printList(numbers);
}

void deleteValues(list<int>& l, int x, int y){
    auto pos = l.begin();
    
    for(int i = 0; i < y; i++){
        if(pos == l.end()){
            cout << "List out of bounds.";
            break;
        }
        pos++;
    }

    for(int j = 0; j < x; j++){
        if(pos == l.end()) break;
        pos = l.erase(pos);
    }
}

void printList(const list<int>& l){
    for(auto pos = l.begin(); pos != l.end(); pos++){
        int i = *pos;
        cout << i << " -> ";
    }
    cout << "null" << endl;
}

