// COMSC-210 | Lab 23 | Jed Aficial 
// github link: https://github.com/jaficial/210-lab-23

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main_menu(){
    int choice;

    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl; 
    cout << "Choice --> ";
    cin >> choice;

    if ((choice < 1) || (choice > 4)){
        cout << "Invalid Choice" << endl;
    }
 
    return choice;
}

// parameters for goat: (name, age, color)
// function takes in the names array and the colors array
// WORKS
void add_goat(list <Goat> &trip, string name[], string color[]){
    int temp_age = rand() % MAX_AGE;
    int temp_name = rand() % SZ_NAMES;
    int temp_color = rand() % SZ_COLORS;
    
    Goat temp(name[temp_name], temp_age, color[temp_color]);
    trip.push_back(temp);
}

// WORKS
void display_trip(list <Goat> trip){
    int iter = 1;
    for (auto val : trip){
        cout << "\t" << "[" << iter << "] " << val.get_name() << " (" << val.get_age() << ", " << val.get_color() << ")" << endl;
        iter++;    
    }
}

// WORKS
int select_goat(list <Goat> trip){
    int selection;
    display_trip(trip);
    cout << "Select which goat you'd like to delete: ";
    cin >> selection;
    return selection;
}

// WORKS
void delete_goat(list <Goat> &trip){
    int temp_selection = select_goat(trip);
    auto iter = trip.begin();
    for (int i = 0; i < temp_selection - 1; i++){ // temp_selection - 1 because displaying the trip begins with 1 representing index 0 of the list
        iter++;
    }
    trip.erase(iter);
}
// when adding a goat, use random info from names, colors, and random age between 0 and MAX_AGE
// when deleting a goat, display the trip, which will then allow the user to select which goat to delete

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];

    int i = 0;
    while (fin >> names[i++]); // while loop inserts all the names from the names.txt file into an array "names"
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]); // while loop inserts all possible colors from the colors.txt file into an array "colors"
    fin1.close();

    list<Goat> trip; // list of Goat objects is created

   // WORKS: GM3K1 ENGINE THAT WILL LOOP THE MENU
    bool menu = true;
    while (menu){
        int temp_menu_choice;
        cout << endl;
        temp_menu_choice = main_menu();
        
        // WORKING: Choice 4 
        if (temp_menu_choice == 4){
            menu = false;
        }
        
        // WORKING: Choice 1
        if (temp_menu_choice == 1){
            add_goat(trip, names, colors);
        }

        // WORKING: Choice 2
        else if (temp_menu_choice == 2){
            delete_goat(trip);
        }

        // WORKING: Choice 3
        else if (temp_menu_choice == 3){
            display_trip(trip);
        }
    }

    return 0;
}

