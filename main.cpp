#include <iostream>
#include <string>

using namespace std;

struct CoffeeCustomer {
    string name;
    string drink_order;
    CoffeeCustomer * next;
}

class CoffeeQueue{
    private:
        CoffeeCustomer* head;
        CoffeeCustomer* tail;
    public:
        void enqueue(){
            CoffeeCustomer* newCustomer = new CoffeeCustomer(name, drink);
            if (!tail){
                head = tail = newCustomer;
            } else {
                tail->next = newCustomer;
                tail = newCustomer;
            }
        }

        void dequeue(){
            if (!head) return;
            CoffeeCustomer* temp = head;
            head = head->next;
            if(!head) tail = nullptr;
            delete temp;
        }

        void printQueue(){
            CoffeeCustomer* current = head;
            while (current){
                cout << current->name << " ordered " << current->drinkOrder << endl;
                current = current -> next;
            }
        }
};

int main(){

    return 0;
}