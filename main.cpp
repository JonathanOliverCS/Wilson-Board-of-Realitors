#include <fstream>
#include <iostream>
#include <string>

using namespace std;


// =============================
// ADD A PERSON
// =============================

void AddName()
{
    ofstream file("people.txt", ios::app);

    if (!file)
    {
        cout << "Error opening file.\n";
        return;
    }

    string name;
    int debt;
    int houseNetWorth;
    string notes;

    cin.ignore();

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter debt: ";
    cin >> debt;

    cout << "Enter house net worth: ";
    cin >> houseNetWorth;

    cin.ignore();

    cout << "Enter notes: ";
    getline(cin, notes);

    // Save the person
    file << name << endl;
    file << debt << endl;
    file << houseNetWorth << endl;
    file << notes << endl;

    file.close();

    cout << "Person added.\n";
}


// =============================
// EDIT A PERSON
// =============================

void editFile()
{
    string searchName;

    cin.ignore();

    cout << "Enter the name you want to edit: ";
    getline(cin, searchName);

    ifstream file("people.txt");

    if (!file)
    {
        cout << "Error opening file.\n";
        return;
    }

    // Temporary file for the edited information
    ofstream temp("temp.txt");

    string name;
    string debt;
    string houseNetWorth;
    string notes;

    bool found = false;

    while (getline(file, name))
    {
        getline(file, debt);
        getline(file, houseNetWorth);
        getline(file, notes);

        // Check if this is the person we want
        if (name == searchName)
        {
            found = true;

            cout << "\nPerson found:\n";
            cout << "1. Name: " << name << endl;
            cout << "2. Debt: " << debt << endl;
            cout << "3. House Net Worth: " << houseNetWorth << endl;
            cout << "4. Notes: " << notes << endl;

            int input2;

            cout << "\nWhich line do you want to edit? ";
            cin >> input2;

            switch (input2)
            {
                case 1:
                    cout << "Enter new name: ";
                    cin.ignore();
                    getline(cin, name);
                    break;

                case 2:
                    cout << "Enter new debt: ";
                    cin >> debt;
                    break;

                case 3:
                    cout << "Enter new house net worth: ";
                    cin >> houseNetWorth;
                    break;

                case 4:
                    cout << "Enter new notes: ";
                    cin.ignore();
                    getline(cin, notes);
                    break;

                default:
                    cout << "Invalid choice.\n";
                    file.close();
                    temp.close();
                    return;
            }
        }

        // Write the person, edited or not, to temp.txt
        temp << name << endl;
        temp << debt << endl;
        temp << houseNetWorth << endl;
        temp << notes << endl;
    }

    file.close();
    temp.close();

    if (!found)
    {
        cout << "Person not found.\n";
        remove("temp.txt");
        return;
    }

    // Replace the old file with the new one
    remove("people.txt");
    rename("temp.txt", "people.txt");

    cout << "Person successfully edited.\n";
}


// =============================
// SEARCH / PRINT INFORMATION
// =============================

void printInfo()
{
    int input2;

    cout << endl;
    cout << "====================" << endl;
    cout << "1. Search for a person" << endl;
    cout << "2. Print a person by location" << endl;
    cout << "3. Print all names" << endl;
    cout << "Enter choice: ";

    cin >> input2;

    switch (input2)
    {
        // -------------------------
        // SEARCH BY NAME
        // -------------------------

        case 1:
        {
            string searchName;

            cin.ignore();

            cout << "Enter the name you want information about: ";
            getline(cin, searchName);

            ifstream file("people.txt");

            if (!file)
            {
                cout << "Error opening file.\n";
                return;
            }

            string name;
            string debt;
            string houseNetWorth;
            string notes;

            bool found = false;

            while (getline(file, name))
            {
                getline(file, debt);
                getline(file, houseNetWorth);
                getline(file, notes);

                if (name == searchName)
                {
                    cout << "\nName: " << name << endl;
                    cout << "Debt: " << debt << endl;
                    cout << "House Net Worth: "
                         << houseNetWorth << endl;
                    cout << "Notes: " << notes << endl;

                    found = true;
                    break;
                }
            }

            file.close();

            if (!found)
            {
                cout << "Person not found." << endl;
            }

            break;
        }


        // -------------------------
        // PRINT PERSON BY LOCATION
        // -------------------------

        case 2:
        {
            int location;

            cout << "Enter person number: ";
            cin >> location;

            ifstream file("people.txt");

            if (!file)
            {
                cout << "Error opening file.\n";
                return;
            }

            string name;
            string debt;
            string houseNetWorth;
            string notes;

            int currentPerson = 1;
            bool found = false;

            while (getline(file, name))
            {
                getline(file, debt);
                getline(file, houseNetWorth);
                getline(file, notes);

                if (currentPerson == location)
                {
                    cout << "\nName: " << name << endl;
                    cout << "Debt: " << debt << endl;
                    cout << "House Net Worth: " << houseNetWorth << endl;
                    cout << "Notes: " << notes << endl;

                    found = true;
                    break;
                }

                currentPerson++;
            }

            file.close();

            if (!found)
            {
                cout << "Person not found." << endl;
            }

            break;
        }


        // -------------------------
        // PRINT ALL NAMES
        // -------------------------

        case 3:
        {
            ifstream file("people.txt");

            if (!file)
            {
                cout << "Error opening file.\n";
                return;
            }

            string name;
            string debt;
            string houseNetWorth;
            string notes;

            int currentPerson = 1;

            cout << "\nPeople:\n";

            while (getline(file, name))
            {
                getline(file, debt);
                getline(file, houseNetWorth);
                getline(file, notes);

                cout << currentPerson << ". " << name << endl;

                currentPerson++;
            }

            file.close();

            break;
        }


        default:
            cout << "Invalid choice.\n";
    }
}


// =============================
// MAIN
// =============================

int main()
{
    int input = 0;

    while (input != 4)
    {
        cout << endl;
        cout << "====================" << endl;
        cout << "1. Add a person" << endl;
        cout << "2. Edit someone" << endl;
        cout << "3. Get information" << endl;
        cout << "4. Quit" << endl;
        cout << "====================" << endl;

        cout << "Enter choice: ";
        cin >> input;

        switch (input)
        {
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
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
