#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Structure to store food recommendations
struct FoodItem {
    string name;
    string cuisine;
    string type;  // Breakfast, Lunch, Dinner
    string dietary; // Vegetarian, Vegan, None
};

// Function to load food data from file
void loadFoodData(vector<FoodItem>& foodList) {
    ifstream file("food_data.txt");
    if (!file) {
        cout << "No food data found. Using default options.\n";
        return;
    }

    FoodItem item;
    while (file >> item.name >> item.cuisine >> item.type >> item.dietary) {
        foodList.push_back(item);
    }
    file.close();
}

// Function to save food data
void saveFoodData(const vector<FoodItem>& foodList) {
    ofstream file("food_data.txt");
    for (const auto& item : foodList) {
        file << item.name << " " << item.cuisine << " " << item.type << " " << item.dietary << endl;
    }
    file.close();
}

// Function to get a recommendation
void getRecommendation(const vector<FoodItem>& foodList, string cuisine, string type, string dietary) {
    vector<FoodItem> filteredList;

    for (const auto& item : foodList) {
        if ((cuisine == "Any" || item.cuisine == cuisine) &&
            (type == "Any" || item.type == type) &&
            (dietary == "Any" || item.dietary == dietary)) {
            filteredList.push_back(item);
        }
    }

    if (filteredList.empty()) {
        cout << "No food recommendations match your criteria.\n";
    } else {
        srand(time(0));
        int index = rand() % filteredList.size();
        cout << "Recommended food: " << filteredList[index].name << " (" << filteredList[index].cuisine << " - " 
             << filteredList[index].type << ", " << filteredList[index].dietary << ")\n";
    }
}

// Function to add a new food item
void addFoodItem(vector<FoodItem>& foodList) {
    FoodItem item;
    cout << "Enter food name: ";
    cin >> item.name;
    cout << "Enter cuisine type (Italian, Mexican, Japanese, etc.): ";
    cin >> item.cuisine;
    cout << "Enter meal type (Breakfast, Lunch, Dinner): ";
    cin >> item.type;
    cout << "Enter dietary restriction (Vegetarian, Vegan, None): ";
    cin >> item.dietary;

    foodList.push_back(item);
    saveFoodData(foodList);
    cout << "Food item added successfully!\n";
}

int main() {
    vector<FoodItem> foodList;
    loadFoodData(foodList);

    int choice;
    do {
        cout << "\nFood Recommendation System\n";
        cout << "1. Get a Food Recommendation\n";
        cout << "2. Add a New Food Item\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 1) {
            string cuisine, type, dietary;
            cout << "Enter preferred cuisine (or 'Any' for no preference): ";
            cin >> cuisine;
            cout << "Enter meal type (Breakfast, Lunch, Dinner, or 'Any'): ";
            cin >> type;
            cout << "Enter dietary restriction (Vegetarian, Vegan, None, or 'Any'): ";
            cin >> dietary;
            getRecommendation(foodList, cuisine, type, dietary);
        } else if (choice == 2) {
            addFoodItem(foodList);
        } else if (choice == 3) {
            cout << "Exiting program...\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}

