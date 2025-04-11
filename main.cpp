//Main program
  
#include <iostream>
#include <string>
#include <iomanip>
#include "roman.h" 

using namespace std; 

//Top level functions prototype to be implemented
romanType add(romanType, romanType);
romanType add(romanType, int);
void printTimesTable(romanType, romanType);

int main()
{

    //test the constructors
    romanType roman1;  //default constructor
    romanType roman2 = romanType("XXIV"); //String Constructor
    romanType roman3 = romanType(33); //Integer Constructor

    //test the results from the constructors
    cout << endl << "Print the roman representation of the values" << endl;
    roman1.printRoman();
    cout << endl;
    roman2.printRoman();
    cout << endl;
    roman3.printRoman();
    cout << endl;
    
    //Add the rest of the tests to get the outputs as in the example output
    
    //Test the no parameter constructor
    cout << "\nDefault romanType constructor with no parameter" << endl;
    romanType def;
    cout << "Default romanType variable as Roman = ";
    def.printRoman();
    cout << endl;
    cout << "Default romanType variable as number = ";
    def.printPositiveInteger();
    cout << endl;
        
    //Test change the romanType value and representation
    cout << "\nSetting the default romanType value to 44" << endl;
    def.setRoman(44);
    cout << "Default romanType variable as Roman = ";
    def.printRoman();
    cout << endl;
    cout << "Default romanType varaible as value = ";
    def.printPositiveInteger();
            
    //Check the string constructor for romanType
    cout << "\nGet roman and value from the string constructor" << endl;
    cout << "String constructor romanType variable as Roman = ";
    roman2.printRoman();
    cout << endl;
    cout << "String constructor romanType variable as value = ";
    roman2.printPositiveInteger();
    cout << endl;

    //Check the value constructor for romanType
    cout << "\nGet roman and value from the integer constructor" << endl;
    cout << "Number constructor romanType variable as Roman = ";
    roman3.printRoman();
    cout << endl;
    cout << "Number constructor romanType variable as value = ";
    roman3.printPositiveInteger();
    cout << endl;
                    
    //Check the increment and decrement operations
    cout << "Increment and Decrement on romanTypes" << endl;
    cout << "Increment class method on a romanType before ";
    roman3.printRoman();
    roman3.inc();
    cout << " After call to class method inc ";
    roman3.printRoman();
    cout << endl;
    
    cout << "\nDecrement class method on a romanType before ";
    roman3.printRoman();
    roman3.dec();
    cout << " After call to class method dec ";
    roman3.printRoman();

    //use the top level add function to add two romanTypes
    cout << "\nAdd using function method on romanTypes" << endl;
    cout << "add two romanType using top level function XXIV plus XXXIII = ";
    romanType sum = add(roman2, roman3);
    sum.printRoman();

    //use the overloaded add methods using an integer and a romanType as param
    cout << "Add using overloaded function method on romanTypes and integer" << endl;
    cout << "Add romanType and integer using top level function XXIV plus 12 = ";
    romanType sum2 = add(roman2, 12);
    sum2.printRoman();
    cout << endl;

    //check the class method for the add function with romanType
    cout << "Using class method for addition of romanTypes XXIV plus XXXIII Result = ";
    roman2.add(roman3);
    roman2.printRoman();
    cout << endl;
    
    //check add integer class method to a romanType
    cout << "Using overloaded class method for addition of romanType and integer LVII plus 12 Result = ";
    romanType roman4 = romanType("LVII");
    roman4.add(12);
    roman4.printRoman();
    cout << endl;
        
    //check the times table using romanTypes
    cout << "Roman Times Table base 6 12 times" << endl;
    printTimesTable(6, 12);
}

romanType add(romanType t, romanType s){
    int sum = t.getValue() + s.getValue();
    return romanType(sum);
}

romanType add(romanType r, int n){
    int sum = n + r.getValue();
    return romanType(sum);
} 

void printTimesTable(romanType base, romanType multiplier){
    int mult = multiplier.getValue();

    for(int i = 1; i < 13; i++){
        romanType numb(i);
        int product = i * mult;
        romanType result(product);
        cout << setw(4) << numb.getRoman() 
        << setw(4) << " * " 
        << setw(4) << multiplier.getRoman() 
        << setw(4) << " = " 
        << setw(10) << result.getRoman() << endl;
    }
}