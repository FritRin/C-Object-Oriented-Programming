#include <iostream>

using namespace std;

int* inputArray();
int* doubleArray(int*);
int* copyAlphaBeta(int*, int*);
void printArray(int*);

int main(){
    int* alpha;
    int* beta;
    int* matrix;

    alpha = {inputArray()};
    beta = {doubleArray(alpha)};
    matrix = {copyAlphaBeta(alpha, beta)};
    printArray(alpha);

    return 0;
}

int* inputArray(){
    int* alpha;
    int number;
    cout << "Input 20 numbers: ";
    for(int i = 0; i < 20; i++){
        cin >> number;
        alpha[i] = number;
    }
    return alpha;
}

int* doubleArray(int* beta){
    int* doubleAlpha;
    for(int j = 0; j < 20; j++){
        doubleAlpha[j] = beta[j] * 2;
    }
    return doubleAlpha;
}

int** copyAlphaBeta(int* alpha, int* beta){
    int** matrix;
    int a = 0;
    int b = 0;
    
    for(int k = 0; k < 5; k++){
        for(int l = 0; l < 4; l++){
            matrix[k][l] = alpha[a];
            a++;
        }
    }

    for(int m = 5; m < 10; m++){
        for(int n = 0; n < 4; n++){
            matrix[m][n] = beta[b];
            b++;
        }
    }
    return matrix;
}

void printArray(int array[]){
    
    for(int o = 0; o < 15; o++){
        cout << array[o] << " ";
    }
}