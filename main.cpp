#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


// How many characters each field gets
const int NAME_SIZE = 30;
const int ADDRESS_SIZE = 50;
const int AGE_SIZE = 3;
const int ID_SIZE = 10;


// Total size of one person
const int RECORD_SIZE = NAME_SIZE + ADDRESS_SIZE + AGE_SIZE + ID_SIZE;

// Add a person
void AddName() {

    string first;
    string last;
    string address;

    int age;
    int id;


    cout << "First name: ";
    cin >> first;

    cout << "Last name: ";
    cin >> last;

    cin.ignore();

    cout << "Address: ";
    getline(cin, address);

    cout << "Age: ";
    cin >> age;

    cout << "ID: ";
    cin >> id;


    string name = first + " " + last;


    // Open at the end of the file
    ofstream file("people.txt", ios::app);

    if (!file) {
        cout << "Could not open file." << endl;
        return;
    }


    // Make sure each field has exactly the correct size

    file << left << setw(NAME_SIZE) << name.substr(0, NAME_SIZE);

    file << left << setw(ADDRESS_SIZE) << address.substr(0, ADDRESS_SIZE);

    file << right << setw(AGE_SIZE) << age;

    file << left << setw(ID_SIZE) << id;


    file << endl;

    file.close();

    cout << endl;
    cout << "Person added!" << endl;
}


// Print one person
void printPerson(int recordNumber) {

    ifstream file("people.txt");

    if (!file) {
        cout << "Could not open file.\n";
        return;
    }


    // Move to the beginning of the requested record
    file.seekg(recordNumber * (RECORD_SIZE + 1));


    char name[NAME_SIZE + 1];
    char address[ADDRESS_SIZE + 1];
    char age[AGE_SIZE + 1];
    char id[ID_SIZE + 1];


    file.read(name, NAME_SIZE);
    file.read(address, ADDRESS_SIZE);
    file.read(age, AGE_SIZE);
    file.read(id, ID_SIZE);


    name[NAME_SIZE] = '\0';
    address[ADDRESS_SIZE] = '\0';
    age[AGE_SIZE] = '\0';
    id[ID_SIZE] = '\0';

    cout << endl;
    cout << "--------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Age: " << age << endl;
    cout << "ID: " << id << endl;
    cout << "--------------------" << endl;


    file.close();
}


// Edit a person's information
void editFile() {

    int recordNumber;

    cout << "Enter person number: ";
    cin >> recordNumber;


    // Convert from person #1 to record 0
    recordNumber--;


    fstream file("people.txt", ios::in | ios::out);

    if (!file) {
        cout << "Could not open file.\n";
        return;
    }


    // Find the beginning of the person's record
    file.seekg(recordNumber * (RECORD_SIZE + 1));


    char name[NAME_SIZE + 1];
    char address[ADDRESS_SIZE + 1];
    char age[AGE_SIZE + 1];
    char id[ID_SIZE + 1];


    file.read(name, NAME_SIZE);
    file.read(address, ADDRESS_SIZE);
    file.read(age, AGE_SIZE);
    file.read(id, ID_SIZE);


    name[NAME_SIZE] = '\0';
    address[ADDRESS_SIZE] = '\0';
    age[AGE_SIZE] = '\0';
    id[ID_SIZE] = '\0';

    cout << endl;
    cout << "Person found:" << endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Age: " << age << endl;
    cout << "ID: " << id << endl;


    int choice;


    cout << endl;
    cout << "What do you want to edit?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Address" << endl;
    cout << "3. Age" << endl;
    cout << "4. ID" << endl;
    cout << "Choice: ";

    cin >> choice;


    // Calculate where this record starts
    int recordStart =
        recordNumber * (RECORD_SIZE + 1);


    switch (choice) {

        case 1:
        {
            string newName;

            cin.ignore();

            cout << "New name: ";
            getline(cin, newName);

            // Go to the name section
            file.seekp(recordStart);

            file << left << setw(NAME_SIZE)
                 << newName.substr(0, NAME_SIZE);

            break;
        }


        case 2:
        {
            string newAddress;

            cin.ignore();

            cout << "New address: ";
            getline(cin, newAddress);

            // Name comes first, so skip NAME_SIZE
            file.seekp(recordStart + NAME_SIZE);

            file << left << setw(ADDRESS_SIZE)
                 << newAddress.substr(0, ADDRESS_SIZE);

            break;
        }


        case 3:
        {
            int newAge;

            cout << "New age: ";
            cin >> newAge;

            // Name + address come first
            file.seekp(recordStart +
                       NAME_SIZE +
                       ADDRESS_SIZE);

            file << right << setw(AGE_SIZE)
                 << newAge;

            break;
        }


        case 4:
        {
            int newID;

            cout << "New ID: ";
            cin >> newID;

            // Skip name, address and age
            file.seekp(recordStart +
                       NAME_SIZE +
                       ADDRESS_SIZE +
                       AGE_SIZE);

            file << left << setw(ID_SIZE)
                 << newID;

            break;
        }


        default:
            cout << "Invalid choice.\n";
            file.close();
            return;
    }


    file.close();

    cout << "\nPerson updated!\n";
}


// Print all people
void printInfo() {

    ifstream file("people.txt");

    if (!file) {
        cout << "Could not open file.\n";
        return;
    }


    int personNumber = 1;


    while (file.peek() != EOF) {

        char name[NAME_SIZE + 1];
        char address[ADDRESS_SIZE + 1];
        char age[AGE_SIZE + 1];
        char id[ID_SIZE + 1];


        file.read(name, NAME_SIZE);
        file.read(address, ADDRESS_SIZE);
        file.read(age, AGE_SIZE);
        file.read(id, ID_SIZE);


        if (!file) {
            break;
        }


        name[NAME_SIZE] = '\0';
        address[ADDRESS_SIZE] = '\0';
        age[AGE_SIZE] = '\0';
        id[ID_SIZE] = '\0';


        cout << endl;
        cout << "Person #" << personNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;


        file.get(); // skip newline


        personNumber++;
    }


    file.close();
}


// Main
int main() {

    int input = 0;


    while (input != 5) {

        cout << endl;
        cout << "Press 1 to add a person:" << endl;
        cout << "Press 2 to edit someone:" << endl;
        cout << "Press 3 to get information:" << endl;
        cout << "Press 4 to remove someone:" << endl;
        cout << "Press 5 to save and quit:" << endl;


        cin >> input;


        switch (input) {

            case 1:
                AddName();
                break;


            case 2:
                editFile();
                break;


            case 3:
                printInfo();
                break;


            case 4:
                cout << "Remove isn't implemented yet.\n";
                break;


            case 5:
                cout << "Saving and quitting...\n";
                break;


            default:
                cout << "Invalid choice.\n";
        }
    }


    return 0;
}
