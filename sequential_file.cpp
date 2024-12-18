#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rno;
    string name;
};

void create() {
    ofstream fout("stud1.txt");
    int n;
    cout << "Enter number of records: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Student s;
        cout << "Enter roll number and name: ";
        cin >> s.rno >> s.name;
        fout << s.rno << "\t" << s.name << endl;
    }
}

void display() {
    ifstream fin("stud1.txt");
    Student s;
    while (fin >> s.rno >> s.name) 
        cout << s.rno << "\t" << s.name << endl;
}

void search() {
    ifstream fin("stud1.txt");
    int key, found = 0;
    cout << "Enter roll number to search: ";
    cin >> key;
    Student s;
    while (fin >> s.rno >> s.name) {
        if (s.rno == key) {
            cout << "Record found: " << s.rno << "\t" << s.name << endl;
            found = 1;
            break;
        }
    }
    if (!found) cout << "Record not found." << endl;
}

void delete_rec() {
    ifstream fin("stud1.txt");
    ofstream fout("temp.txt");
    int key, found = 0;
    cout << "Enter roll number to delete: ";
    cin >> key;
    Student s;
    while (fin >> s.rno >> s.name) {
        if (s.rno != key) fout << s.rno << "\t" << s.name << endl;
        else found = 1;
    }
    fin.close();
    fout.close();
    if (found) {
        remove("stud1.txt");
        rename("temp.txt", "stud1.txt");
        cout << "Record deleted successfully." << endl;
    } else {
        cout << "Record not found." << endl;
    }
}

void update_rec() {
    ifstream fin("stud1.txt");
    ofstream fout("temp.txt");
    int key, found = 0;
    cout << "Enter roll number to update: ";
    cin >> key;
    Student s;
    while (fin >> s.rno >> s.name) {
        if (s.rno == key) {
            cout << "Enter new roll number and name: ";
            cin >> s.rno >> s.name;
            found = 1;
        }
        fout << s.rno << "\t" << s.name << endl;
    }
    fin.close();
    fout.close();
    if (found) {
        remove("stud1.txt");
        rename("temp.txt", "stud1.txt");
        cout << "Record updated successfully." << endl;
    } else {
        cout << "Record not found." << endl;
    }
}

int main() {
    int ch;
    do {
        cout << "\n1.Create\n2.Display\n3.Search\n4.Delete Record\n5.Update\n6.Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: delete_rec(); break;
            case 5: update_rec(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (ch != 6);
    return 0;
}
