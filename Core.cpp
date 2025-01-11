#include "Core.h"
#include <iostream>
#include <string>
#include <vector>
#include "RecipeBook.h"
#include "MealPlan.h"

void Core::displayMainMenu() {
    std::cout << "Main Menu:\n";
    std::cout << "1. Browse Recipes by Category (Breakfast, Lunch, Dinner)\n";
    std::cout << "2. Meal Planning\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
}

void Core::browseRecipesByCategory(RecipeBook& recipeBook) {
    std::cout << "Choose a category:\n";
    std::cout << "1. Breakfast\n";
    std::cout << "2. Lunch\n";
    std::cout << "3. Dinner\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    std::string category;
    switch (choice) {
        case 1: category = "Breakfast"; break;
        case 2: category = "Lunch"; break;
        case 3: category = "Dinner"; break;
        default:
            std::cout << "Invalid choice!\n";
            return;
    }

    std::vector<std::string> recipes = recipeBook.getRecipesByCategory(category);
    if (recipes.empty()) {
        std::cout << "No recipes found for " << category << ".\n";
        return;
    }

    std::cout << "Recipes for " << category << ":\n";
    for (size_t i = 0; i < recipes.size(); ++i) {
        std::cout << i + 1 << ". " << recipes[i] << "\n";
    }

    std::cout << "Enter the number of the recipe to view details: ";
    int recipeChoice;
    std::cin >> recipeChoice;

    if (recipeChoice > 0 && recipeChoice <= recipes.size()) {
        recipeBook.displayRecipeDetails(recipes[recipeChoice - 1]);
    } else {
        std::cout << "Invalid choice!\n";
    }
}

void Core::mealPlanning(MealPlan& mealPlan, RecipeBook& recipeBook) {
    mealPlan.displayMealPlan();
    std::cout << "Enter the date to view meals (e.g., 2024-12-02): ";
    std::string date;
    std::cin >> date;

    std::vector<std::string> meals = mealPlan.getMealsForDate(date);
    if (meals.empty()) {
        std::cout << "No meals found for " << date << ".\n";
        return;
    }

    std::cout << "Meals for " << date << ":\n";
    for (size_t i = 0; i < meals.size(); ++i) {
        std::cout << i + 1 << ". " << meals[i] << "\n";
    }

    std::cout << "Enter the number of the meal to view details: ";
    int mealChoice;
    std::cin >> mealChoice;

    if (mealChoice > 0 && mealChoice <= meals.size()) {
        recipeBook.displayRecipeDetails(meals[mealChoice - 1]);
    } else {
        std::cout << "Invalid choice!\n";
    }
}
