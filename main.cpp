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
        std::cout << "\nWelcome to My Lovely CookBook and Your Food List for Next Week!\n";
        core.displayMainMenu();
        int choice = core.getValidatedInput();

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
}
