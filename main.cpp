#include <iostream>
#include <string>

using namespace std;

struct CoffeeCustomer {
    string name;
    string drink_order;
    CoffeeCustomer * next;

    CoffeeCustomer(string n, string d) : name(n), drinkOrder(d), next(nullptr) {}
};

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

        bool isEmpty(){
            return head == nullptr;
        }
};

struct MuffinCustomer {
    string name;
    string muffin_type;
};

struct BraceletCustomer{
    string name;
    string bracelet_color;
};

struct CustomBoothCustomer{
    string name;
    string custome_item;
};

int main(){
    const string names[] = {"Gaby" , "Lilly", "Kalani", "David", "Jayden"};
    const string drinks[] = {"Chai", "Latte", "Matcha", "Espresso", "Mocha"};
    const string muffins[] = {"Choclate", "Banana", "Blueberry", "Vanilla", "Confetti"};
    const string bracelets[]= {"Pink", "Brown", "Green", "Yellow", "Blue"};
    const string custom_items[] = {"Shirt", "Skirt", "Dress", "Pants", "Hat"};

    CoffeeQueue coffeeBooth;
    for (int i = 0; i){
        coffeeBooth.enqueue(getRandomName(names, 5), getRandomDrink(drink, 5));
    }

    deque<MuffinCustomer> muffinBooth;
    deque<BraceletCustomer> braceletBooth;
    deque<CustomBoothCustomer> customBooth;

    for(int round = 1; round <= 10; ++round){
        cout << "Round" << round << endl;

        if(!coffeeBooh.isEmpty()){
            cout << "Serving coffee customer: " << endl;
            coffeeBooth.printQueue();
            coffeeBooth.dequeue();
        } else {
            cout << "No customer to serve" << endl;
        }

        if (!muffinBooth.empty()){
            cout << "Serving muffin customer" << endl;
            cout << 
        }

        if(!braceletBooth.empty()){

        }

        if (!customBooth.empty()){

        }
    }

    return 0;
}