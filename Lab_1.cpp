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


int main() {
  
    
    
    return 0;
}

// -----------------------------
// Core API — implement these
// -----------------------------

// Inserts a new (username, password) at the END of the list.
// If username already exists, do NOT insert a duplicate; return false.
// Otherwise insert and return true.
bool insertUser(User*& head, const string& username, const string& password) {
    
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
    // TODO: implement
    
    return 0;
}

// Prints usernames in order, separated by " -> " then " -> NULL".
// Example: alice -> bob -> charlie -> NULL
void printUsers(User* head) {
    // TODO: implement
    
}


