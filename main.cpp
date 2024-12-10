#include <iostream>
#include <string>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>

using namespace std;

//struct for list
struct CoffeeCustomer {
    //sets data types for cu
    string name;
    string drinkOrder;
    CoffeeCustomer * next;
    //constructor to set with name and drink order
    CoffeeCustomer(string n, string d) : name(n), drinkOrder(d), next(nullptr) {}
};
//linked list class for coffee booth
class CoffeeQueue{
    private:
    //first customer in que
        CoffeeCustomer* head;
        //last customer in que
        CoffeeCustomer* tail;
    public:
    //constructor set empty que
        CoffeeQueue() : head(nullptr), tail(nullptr) {}
        //destructor frees up memory
        ~CoffeeQueue() {
            while (head) {
                dequeue();
            }
        }
        //add new customer to end of queue
        void enqueue(string name, string drink){
            CoffeeCustomer* newCustomer = new CoffeeCustomer(name, drink);
            if (!tail){
                head = tail = newCustomer;
            } else {
                tail->next = newCustomer;
                tail = newCustomer;
            }
        }
//removes customer at front of queue
        void dequeue(){
            if (!head) return;
            CoffeeCustomer* temp = head;
            head = head->next;
            if(!head) tail = nullptr;
            delete temp;
        }
//prints the queue of coffee customers
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
//struct for muffin booth customers
struct MuffinCustomer {
    string name;
    string muffinType;
};
//struct for bracelet booth customers
struct BraceletCustomer{
    string name;
    string bracelet_color;
};
//struct for custom booth customers
struct CustomBoothCustomer{
    string name;
    string customItem;
};
//generate random customer data
string getRandomName(const string names[], int size) {
    return names[rand() % size];
}

string getRandomDrink(const string drinks[], int size) {
    return drinks[rand() % size];
}

string getRandomMuffin(const string muffins[], int size) {
    return muffins[rand() % size];
}

string getRandomBracelet(const string bracelets[], int size) {
    return bracelets[rand() % size];
}

string getRandomCustomItem(const string items[], int size) {
    return items[rand() % size];
}


int main(){
    srand(time(0));
    //create data
    const string names[] = {"Gaby" , "Lilly", "Kalani", "David", "Jayden"};
    const string drinks[] = {"Chai", "Latte", "Matcha", "Espresso", "Mocha"};
    const string muffins[] = {"Choclate", "Banana", "Blueberry", "Vanilla", "Confetti"};
    const string bracelets[]= {"Pink", "Brown", "Green", "Yellow", "Blue"};
    const string custom_items[] = {"Shirt", "Skirt", "Dress", "Pants", "Hat"};
    //coffee booth set
    CoffeeQueue coffeeBooth;
    for (int i = 0; i< 3; ++i){
        coffeeBooth.enqueue(getRandomName(names, 5), getRandomDrink(drinks, 5));
    }
// differengt booth setup
    deque<MuffinCustomer> muffinBooth;
    deque<BraceletCustomer> braceletBooth;
    deque<CustomBoothCustomer> customBooth;

    for(int round = 1; round <= 10; ++round){
        cout << "Round" << round << endl;

        if(!coffeeBooth.isEmpty()){
            cout << "Serving coffee customer: " << endl;
            coffeeBooth.printQueue();
            coffeeBooth.dequeue();
        } else {
            cout << "No coffee customer to serve" << endl;
        }
        if (rand() % 2 == 0) {
            coffeeBooth.enqueue(getRandomName(names, 5), getRandomDrink(drinks, 5));
        }

        if (!muffinBooth.empty()){
            cout << "Serving muffin customer" << endl;
            cout << muffinBooth.front().name << " buys " << muffinBooth.front().muffinType << " muffin" << endl;
            muffinBooth.pop_front();
        } else {
            cout << "No muffin customer to serve" << endl;
        }
        if (rand() % 2 == 0) {
            muffinBooth.push_back({getRandomName(names, 5), getRandomMuffin(muffins, 4)});
        }

        if(!braceletBooth.empty()){
            cout << "Serving bracelet customer" << endl;
            auto customer = braceletBooth.back();
            cout << customer.name << " buys " << customer.bracelet_color << " bracelet" << endl;
            braceletBooth.pop_back();
        } else {
            cout << "No bracelet customer to serve" << endl;
        }
        if (rand() % 2 == 0) {
            braceletBooth.push_back({getRandomName(names, 5), getRandomBracelet(bracelets, 4)});
        }


        if (!customBooth.empty()){
            cout << "Serving custom customer" << endl;
            cout << customBooth.front().name << "buys" << customBooth.front().customItem << endl;
            customBooth.pop_front();
        } else {
            cout << "No custom customer to serve" << endl;
        }
        if (rand() % 2 == 0) {
            customBooth.push_back({getRandomName(names, 5), getRandomCustomItem(custom_items, 3)});
        }

        cout << endl;
    }

    return 0;
}