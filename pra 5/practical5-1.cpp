#include <iostream>
using namespace std;

class Node {
public:
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
private:
    Node* head;

public:

    // Constructor
    Playlist() {
        head = NULL;
    }

    // Insert at beginning
    void insertBeginning(string song) {

        Node* newNode = new Node(song);

        if (head == NULL) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        cout << "Song inserted at beginning.\n";
    }

   
    void insertEnd(string song) {

        Node* newNode = new Node(song);

        if (head == NULL) {
            head = newNode;
            cout << "Song inserted at end.\n";
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;

        cout << "Song inserted at end.\n";
    }

    
    void insertAfter(string givenSong, string newSong) {

        Node* temp = head;

        while (temp != NULL && temp->song != givenSong) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Song not found.\n";
            return;
        }

        Node* newNode = new Node(newSong);

     
        newNode->prev = temp;
        newNode->next = temp->next;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }

    
        temp->next = newNode;

        cout << newSong << " inserted after "
             << givenSong << ".\n";
    }

    
    void deleteFirst() {

        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* temp = head;

        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        cout << "Deleted song: " << temp->song << endl;

        delete temp;
    }


    void countSongs() {

        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        cout << "Total songs = " << count << endl;
    }

    
    void display() {

        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* temp = head;

        cout << "Playlist: ";

        while (temp != NULL) {

            cout << temp->song;

            if (temp->next != NULL) {
                cout << " <-> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    Playlist p;

    int choice;
    string song;
    string givenSong;
    string newSong;

    do {

        cout << "\n========== MUSIC PLAYLIST ==========\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Song\n";
        cout << "4. Delete First Song\n";
        cout << "5. Count Songs\n";
        cout << "6. Display Playlist\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            cout << "Enter song name: ";
            cin >> song;

            p.insertBeginning(song);
            p.display();

            break;

        case 2:

            cout << "Enter song name: ";
            cin >> song;

            p.insertEnd(song);
            p.display();

            break;

        case 3:

            cout << "Enter existing song: ";
            cin >> givenSong;

            cout << "Enter new song: ";
            cin >> newSong;

            p.insertAfter(givenSong, newSong);
            p.display();

            break;

        case 4:

            p.deleteFirst();
            p.display();

            break;

        case 5:

            p.countSongs();

            break;

        case 6:

            p.display();

            break;

        case 7:

            cout << "Program ended.\n";

            break;

        default:

            cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}