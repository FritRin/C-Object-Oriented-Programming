#include <iostream>

using namespace std;

const int arrSize = 20;
const int matrixRow = 10;
const int matrixCols = 4;

void inputArray(int*);
void doubleArray(int*, int*);
void copyAlphaBeta(int*, int*, int[][matrixCols]);
void printArray(int*);
void printMatrix(int[][matrixCols]);


int main(){
    int alpha[arrSize];
    int beta[arrSize];
    int matrix[matrixRow][matrixCols];

    inputArray(alpha);
    doubleArray(beta, alpha);
    copyAlphaBeta(alpha, beta, matrix);
    printArray(alpha);
    printArray(beta);
    printMatrix(matrix);

    return 0;
}

void inputArray(int alpha[]){

    cout << "Input 20 numbers: ";
    for(int i = 0; i < arrSize; i++){
        cin >> alpha[i];
    }
}

void doubleArray(int newArr[], int copyArr[]){
    
    for(int j = 0; j < 20; j++){
        newArr[j] = copyArr[j] * 2;
    }

}

void copyAlphaBeta(int alpha[], int beta[], int matrix[][matrixCols]){
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
}

void printArray(int array[]){
    
    for(int o = 0; o < arrSize; o++){
        cout << array[o] << " ";
        if((o + 1) % 15 == 0){
            cout << endl;
        }
    }
    cout << endl;
}

void printMatrix(int matrix[][matrixCols]){

    int count = 0;

    for(int p = 0; p < matrixRow; p++){
        for(int q = 0; q < matrixCols; q++){
            cout << matrix[p][q] << " ";
            count++;
            if((count + 1) % 15 == 0){
                cout << endl;
            }
        }
    }
    cout << endl;
}