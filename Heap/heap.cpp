#include <algorithm>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */

using namespace std;



// Define a structure for Creature with only name and capacity
struct Troops {
    string name;
    int capacity;

    //Default constructor
    Troops() : name(""), capacity(0) {}

    Troops(string n, int c) : name(n), capacity(c) {}
};

class Maxheap {
private:
    vector<Troops> myheap;

     // heapifying fomula
    void heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;


    if ( left < myheap.size() && myheap[left].capacity > myheap[largest].capacity){
        largest = left;
    }

    if ( right < myheap.size() && myheap[right].capacity > myheap[right].capacity){
        largest = right;
    }

    if (largest != i) {
        swap(myheap[i], myheap[largest]);  // Swap the index to maintain myheap
        heapify(largest); // Recursively heapify the affected subtree
    }
}


public:
    void displayTitle() {
    cout << R"(
  ______   __                      __                         ______
 /      \ |  \                    |  \                       /      \
|  $$$$$$\| $$  ______    _______ | $$____          ______  |  $$$$$$\
| $$   \$$| $$ |      \  /       \| $$    \        /      \ | $$_  \$$
| $$      | $$  \$$$$$$\|  $$$$$$$| $$$$$$$\      |  $$$$$$\| $$ \
| $$   __ | $$ /      $$ \$$    \ | $$  | $$      | $$  | $$| $$$$
| $$__/  \| $$|  $$$$$$$ _\$$$$$$\| $$  | $$      | $$__/ $$| $$
 \$$    $$| $$ \$$    $$|       $$| $$  | $$       \$$    $$| $$
 __$$$$__  \$$  \$$$$$$$ \$$$$$$$  \$$   \$$        \$$$$$$  \$$
|  \  |  \
| $$  | $$  ______    ______    ______    _______
| $$__| $$ /      \  |      \  /      \  /       \
| $$    $$|  $$$$$$\  \$$$$$$\|  $$$$$$\|  $$$$$$$
| $$$$$$$$| $$    $$ /      $$| $$  | $$ \$$    \
| $$  | $$| $$$$$$$$|  $$$$$$$| $$__/ $$ _\$$$$$$\
| $$  | $$ \$$     \ \$$    $$| $$    $$|       $$
 \$$   \$$  \$$$$$$$  \$$$$$$$| $$$$$$$  \$$$$$$$
                              | $$
                              | $$
                               \$$

    Welcome to the Clash of Heaps!
    )" << "\n";
}




     // Insert a creature into the myheap based on capacity
     void add(const Troops& c) {
        myheap.push_back(c);
        int i = myheap.size() - 1;

       // Fix the myheap property
       while(i > 0 && myheap[(i-1)/2].capacity < myheap[i].capacity){
            swap(myheap[i], myheap[(i -1) / 2]);
            i = (i - 1) / 2;
       }
    }

    // Function to get color based on troop capacity
    string getColor(int capacity) {
        if (capacity >= 20) return RED;        // High-capacity troops in Red
        if (capacity >= 5) return YELLOW;     // Mid-capacity troops in Yellow
        return GREEN;                          // Low-capacity troops in Green
    }

    // Display the myheap (list of Troops
    void displayHeap(){
    cout << "\n=========================\n";
    cout << "Heap of Troops (by Capacity):\n";
    cout << "=========================\n";
        for (const auto&c : myheap) {
            string color = getColor(c.capacity);
            cout << color << c.name << " (Capacity: " << c.capacity << ")" << RESET << "\n";
        }
         cout << "=========================\n";
    }

     // Remove the root (the strongest Troop)
    void removeRoot(){
        if (myheap.empty()) return;

        myheap[0] = myheap.back(); // Move the last element to the root
        myheap.pop_back(); // Remove the last element
        heapify(0); // Restore the heap property
    }

    void buildHeap(vector<Troops>& troops) {
        myheap = troops;
        for (int i = myheap.size() / 2 - 1; i >= 0; i --) {
            heapify(i);
        }
    }

    void simulateTraining(const string& troopName) {
    cout << "Training " << troopName << ": [";
    for (int i = 0; i < 10; ++i) {
        cout << "#";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(300));  // Simulates delay
    }
    cout << "] Done!\n";
}

};



int main() {
    Maxheap train;

    //Display Title
    train.displayTitle();

     // Example Troop with name and capacity
    Troops dragon("Dragon", 20);
    Troops wizard("Wizard", 4);
    Troops giant("Giant", 5);
    Troops archer("Archer", 1);
    Troops pekka("P.E.K.K.A", 25);




    // Insert creatures into the heap based on their capacity
    train.add(dragon);
    train.add(wizard);
    train.add(giant);
    train.add(archer);
    train.add(pekka);

    //simulate training
    train.simulateTraining("Dragon");
    train.simulateTraining("Wizard");
    train.simulateTraining("Giant");
    train.simulateTraining("Archer");
    train.simulateTraining("P.E.K.K.A");


    // Display the heap after insertions
    train.displayHeap();

     // Remove the strongest creature (root of the heap)
     cout << "\nRemoving the strongest Troops...\n";
     train.removeRoot();
     // Display the heap after removal
    train.displayHeap();

     // Heapify a random list of creatures
     vector<Troops> randomTroops = {wizard,dragon,pekka,giant,archer};
     train.buildHeap(randomTroops);


      // Display the heap after heapifying
    cout << "\nHeap after heapifying the list:\n";
    train.displayHeap();


    return 0;
}

