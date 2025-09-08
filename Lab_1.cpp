#include <iostream>
using namespace std;


struct User {
    string username;
    string password; 
    User* next;
    
    User(string u, string p) {
        username = u;
        password = p;
        next = nullptr;
    }
};

bool insertUser(User*& head, const string& username, const string& password);
User* findUser(User* head, const string& username);
bool authenticate(User* head, const string& username, const string& password);
bool removeFront(User*& head);
bool removeByUsername(User*& head, const string& username);
void clearList(User*& head);
size_t size(User* head);
void printUsers(User* head);

int main() {
   User* head = nullptr;
    
   cout << "=== INSERT USERS ===\n";
    insertUser(head, "alice", "123");
    insertUser(head, "bob", "456");
    insertUser(head, "charlie", "789");

      
    printUsers(head);

    cout << "Size: " << size(head) << "\n";

    if(authenticate(head, "bob", "456")) {
          cout << "bob authenticated\n";
         
        } 
           else {
             cout << "authentication failed! Please try again.\n";
    }

    removeFront(head);
    printUsers(head);

    removeByUsername(head, "charlie");
    printUsers(head);

    cout << "Size: " << size(head) << "\n";

    clearList(head);
    printUsers(head);
    
    return 0;
}

// -----------------------------
// Core API — implement these
// -----------------------------

// Inserts a new (username, password) at the END of the list.
// If username already exists, do NOT insert a duplicate; return false.
// Otherwise insert and return true.
bool insertUser(User*& head, const string& username, const string& password) {  
    //RUNTIME: O(n)
    
     if(head == nullptr) {
         User* newHead = new User(username, password);
        return true;
     }

        User* current = head;

    while(current) {
            
           if(current->username == username) {
               return false;
          }

             if(current->next == nullptr) {
               current->next = new User(username, password);
                 return true;
         }
          current = current->next;
         
    }
 
    return false;
}

// Returns pointer to the node with matching username; otherwise nullptr.
User* findUser(User* head, const string& username) { 
    //RUNTIME: O(n)
    User* search = head;


        while(search != nullptr) {
           if(search->username == username) {
               return search;
           }
          search = search->next;
        }


   return nullptr;

}

// Returns true if (username, password) matches an existing node; false otherwise.
bool authenticate(User* head, const string& username, const string& password) {  
    //RUNTIME: O(n)
      User* current = head;

      while(current != nullptr) {
     if(current->username == username && current->password == password) {
       return true;
     }

     current = current->next;
   }

    return false;
}

// Deletes the FIRST node (head) and updates head. No-op if list is empty.
// Return true if a node was deleted, false otherwise.
bool removeFront(User*& head) {
     //RUNTIME: O(1)

    if (head == nullptr) {
        return false;
    }

     else if (head != nullptr) {
           User* temp = head;
           head = head->next;
            delete temp;

            return true;
     }

    return false;
}

// Deletes the node with matching username (first match only).
// Return true if a node was found & deleted; false if not found.
bool removeByUsername(User*& head, const string& username) {
      //RUNTIME: O(n)

    User* previous = head;
    User* current = head->next;

    if(head == nullptr) {
        return false;
    }
   
      if(head->username == username) {
        User* temp = head;
        head = head->next;
        delete temp;

        return true;

      }

      while (current != nullptr) {
        if(current->username == username) {
            previous->next = current->next;
            delete current;

            return true;
        }

       previous = current;
       current = current->next;
      }

    return false;
}

// Deletes ALL nodes and sets head=nullptr. 
void clearList(User*& head) {
      //RUNTIME: O(n)

    if (head == nullptr) {
        cout << "Everything is already gone. Nothing to delete \n";
    }

    while(head != nullptr) {
           User* temp = head;
           head = head->next;
           delete temp;
    }
    head = nullptr;

    cout << "All nodes were deleted. Yor list has been cleard.\n";
    
}

// Returns number of nodes.
size_t size(User* head) {
     //RUNTIME: O(n)

    size_t count = 0;

    User* current = head;

    while(current != nullptr) {
        count++;
        current = current->next;
    }
     return count;
    
    return 0;
}

// Prints usernames in order, separated by " -> " then " -> NULL".
// Example: alice -> bob -> charlie -> NULL
void printUsers(User* head) {
     //RUNTIME: O(n)
     
    User* current = head;
    
    cout << "Contents: \n";

    while(current != nullptr) {
        cout << current->username;

        if(current->next != nullptr) {
            cout << " -> ";
        }

        current = current->next;
    }
     cout << " -> NULL \n";
    
}


