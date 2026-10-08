#include <fstream>
#include <iostream>

using namespace std;

int AddName () {




}

int editFile () {

    // I want a search function the to print the next 4 lines of the file then ask which line to edit


    int input2;

    cout << "" << endl;

    cin << input2;

}

int printInfo () {
    int input2;

    cout << "Press 1 to " << endl;

    cin << input2;

    switch

}



int main() {
 
    ifstream file("people.txt");

    int location;
    int input;

    cout << "Press 1 to add a person:" << endl;
    cout << "Press 2 to edit someone:" << endl;
    cout << "Press 3 to get information:" << endl;

    while (input != 0) {
        cin >> input;

        switch (input) {
            case 1:
                int a = AddName();

                break;
            case 2:
                location = 2;
                break;
            default:
                location = 0;
        }
    }


    return 0;
}3