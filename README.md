Wilson Board of Realtors Record Management System
A C++ command-line application developed for the Wilson Board of
Realtors to help a staff member manage individual records using a
straightforward text-file-based system.
Overview
The program provides a menu-driven interface for adding, viewing, and
editing records. Information is stored locally in people.txt, making
it possible to access saved records again after the program closes.
Features
- Add records: Enter a person's name, address, age, and ID.
- View records: Display saved records in the console.
- Edit records: Update a record's name, address, age, or ID.
- File-based storage: Append records to and read records from
  people.txt.
- Fixed-width fields: Store each record using predefined field
  widths.
- Menu-driven interface: Choose available operations from a
  numbered menu.
Note: The menu includes a record-deletion option, but deletion has
not been implemented.

Built With
- C++
- File streams: ifstream, ofstream, and fstream
- Formatted output with iomanip
- String handling with string and getline
Record Format
Each record contains the following fields:
  Field       Allocated width
  Name          30 characters
  Address       50 characters
  Age            3 characters
  ID            10 characters
The program uses fixed-width fields and file-position operations to
locate and update records.
