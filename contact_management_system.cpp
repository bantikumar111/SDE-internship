#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Contact {
    string name, phone, email;
};

vector<Contact> contacts;

// Load contacts from file
void loadContacts() {
    contacts.clear();
    ifstream file("contacts.txt");
    Contact c;
    while (file >> c.name >> c.phone >> c.email) {
        contacts.push_back(c);
    }
    file.close();
}

// Save contacts to file
void saveContacts() {
    ofstream file("contacts.txt");
    for (auto& c : contacts) {
        file << c.name << " " << c.phone << " " << c.email << endl;
    }
    file.close();
}

// Add contact
void addContact() {
    Contact c;
    cout << "Enter Name: ";
    cin >> c.name;
    cout << "Enter Phone: ";
    cin >> c.phone;
    cout << "Enter Email: ";
    cin >> c.email;
    contacts.push_back(c);
    saveContacts();
    cout << "Contact added.\n";
}

// View all contacts
void viewContacts() {
    int i = 1;
    for (auto& c : contacts) {
        cout << i++ << ". Name: " << c.name << ", Phone: " << c.phone << ", Email: " << c.email << endl;
    }
}

// Edit contact
void editContact() {
    viewContacts();
    int index;
    cout << "Enter contact number to edit: ";
    cin >> index;
    if (index > 0 && index <= contacts.size()) {
        cout << "Enter new Name: ";
        cin >> contacts[index - 1].name;
        cout << "Enter new Phone: ";
        cin >> contacts[index - 1].phone;
        cout << "Enter new Email: ";
        cin >> contacts[index - 1].email;
        saveContacts();
        cout << "Contact updated.\n";
    } else {
        cout << "Invalid index.\n";
    }
}

// Delete contact
void deleteContact() {
    viewContacts();
    int index;
    cout << "Enter contact number to delete: ";
    cin >> index;
    if (index > 0 && index <= contacts.size()) {
        contacts.erase(contacts.begin() + index - 1);
        saveContacts();
        cout << "Contact deleted.\n";
    } else {
        cout << "Invalid index.\n";
    }
}

int main() {
    loadContacts();
    int choice;
    do {
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n2. View Contacts\n3. Edit Contact\n4. Delete Contact\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: editContact(); break;
            case 4: deleteContact(); break;
            case 5: cout << "Exiting..."; break;
            default: cout << "Invalid option!\n";
        }
    } while (choice != 5);
    return 0;
}
