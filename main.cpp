#include <iostream>
#include <string>
#include <vector>
#include "RecipeBook.h"
#include "MealPlan.h"
#include "Core.h"

int main() {
    RecipeBook recipeBook;
    MealPlan mealPlan;
    Core core;

    if (!recipeBook.loadFromFile("recept.xml")) {
        std::cerr << "Failed to load recipes!\n";
        return -1;
    }

    if (!mealPlan.loadFromFile("recept.xml")) {
        std::cerr << "Failed to load meal plan!\n";
        return -1;
    }

    while (true) {
        std::cout<<"\nWelcome to my lovely CookBook and your Food list for next week :333 !!\n" << std::endl;
        core.displayMainMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                core.browseRecipesByCategory(recipeBook);
                break;
            case 2:
               core.mealPlanning(mealPlan, recipeBook);
                break;
            case 3:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
