#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

class Calculator{
    private:
        int choice;
    
    public:
        //Default Constructor
        Calculator() : choice(0){displayMenu();}

        //Function for Handling and Performing the Arithmetic Operations
        void OperationHandler(){
            if(choice == 1){
                int counter;
                cout << "ENTER TOTAL NUMBERS TO PERFORM ADDITION: "; cin >> counter;
                int sum = 0, num;
                for(int i =0; i < counter; i++){
                    cout << "Enter Number " << i+1 << ": "; cin >> num;
                    sum += num;
                }
                cout << "AFTER PERFORMING ADDITION..." << endl << "SUM: " << sum << endl;
            }else if(choice == 2){
                int num, difference;
                cout << "ENTER FIRST NUMBER: "; cin >> difference;
                cout << "ENTER SECOND NUMBER: "; cin >> num;
                difference -= num;
                cout << "AFTER PERFORMING SUBTRACTION..." << endl << "DIFFERENCE: " << difference << endl;
            }else if(choice == 3){
                int counter;
                cout << "ENTER TOTAL NUMBERS TO PERFORM MULTIPLICATION: "; cin >> counter;
                int product = 1, num;
                for(int i =0; i < counter; i++){
                    cout << "Enter Number " << i+1 << ": "; cin >> num;
                    product *= num;
                }
                cout << "AFTER PERFORMING MULTIPLIATION..." << endl << "PRODUCT: " << product << endl;
            }else if(choice == 4){
                float num, quotient;
                cout << "ENTER FIRST NUMBER: "; cin >> quotient;
                cout << "ENTER SECOND NUMBER: "; cin >> num;
                quotient /= num;
                cout << "AFTER PERFORMING DIVISION..." << endl << "QUOTIENT: " << quotient << endl;
            }else if(choice == 5){
                int num, mod;
                cout << "ENTER FIRST NUMBER: "; cin >> mod;
                cout << "ENTER SECOND NUMBER: "; cin >> num;
                mod %= num;
                cout << "AFTER PERFORMING DIVISION..." << endl << "REMAINDER: " << mod << endl;
            }
            int again;
            cout << "DO YOU WANT TO PERFORM MORE OPERATIONS:\n1-YES\n2-NO\nENTER CHOICE: "; cin >> again;
            if(again == 1){
                displayMenu();
            }else{
                cout << "EXITING...";
                exit(0);                
            }

        }

        //Function to display the many for operations to the user
        void displayMenu(){
            cout << "SIMPLE CALCULATOR" << endl;
            cout << "1- ADDITION" << endl;
            cout << "2- SUBTRACTION" << endl;
            cout << "3- MULTIPLICATION" << endl;
            cout << "4- DIVISION" << endl;
            cout << "5- MOD (FINDING REMAINDER)" << endl;
            cout << "0- EXIT" << endl;
            cout << "ENTER CHOICE: "; cin >> choice;
            if(choice == 0){
                cout << "EXITING...";
                exit(0);
            }
            while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5){
                cout << "INVALID CHOICE... ENTER AGAIN: "; cin >> choice;
            }
            OperationHandler();
        }
};

int main(){
    Calculator calculator;
}