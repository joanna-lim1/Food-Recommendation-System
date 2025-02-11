# Food Recommendation System (C++)

## Overview
The **Food Recommendation System** is a **C++ command-line application** that suggests meals based on **cuisine type, dietary restrictions, and meal preferences**. Users can also add new food items dynamically, with data stored in `food_data.txt` for future use.

## Features
- Get personalized **food recommendations** based on cuisine, meal type, and dietary restrictions.  
- Supports **cuisine preferences** (Italian, Mexican, Japanese, etc.).  
- Includes **meal type selection** (Breakfast, Lunch, Dinner).  
- Considers **dietary restrictions** (Vegan, Vegetarian, None).  
- Stores food data persistently for future use.  

---

## Folder Structure
```
Food-Recommendation-System/
│-- src/
│   ├── main.cpp      # Main C++ source code
│-- food_data.txt     # Stores food recommendations (auto-generated)
│-- README.md         # Documentation
│-- .gitignore        # Ignores food_data.txt file
```

---

## Installation & Usage

### 1. Clone the Repository
```sh
git clone https://github.com/joanna-lim1/Food-Recommendation-System.git
cd Food-Recommendation-System
```

### 2. Compile the Program
```sh
g++ -std=c++11 src/main.cpp -o food_recommend
```

### 3. Run the Program
```sh
./food_recommend
```

### 4. Program Menu
When you run the program, you will see this menu:
```
Food Recommendation System
1. Get a Food Recommendation
2. Add a New Food Item
3. Exit
Enter your choice: 
```
- **Option 1:** Get a food recommendation based on your input.
- **Option 2:** Add a new food item to the database.
- **Option 3:** Exit the program.

---

## Technologies Used
- **C++** for logic and program flow.
- **File Handling (File I/O)** to store and retrieve food data.
- **Object-Oriented Programming (OOP)** for structuring food information.
- **Randomization** for selecting food recommendations.
- **Git & GitHub** for version control and collaboration.

---


## Author
Joanna Lim  
GitHub: [github.com/joanna-lim1](https://github.com/joanna-lim1)  
LinkedIn: [linkedin.com/in/joanna-lim-4793112a6](https://linkedin.com/in/joanna-lim-4793112a6)  

Happy Coding and Enjoy Your Food Recommendations.

