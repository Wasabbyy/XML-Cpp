#include "Core.h"
#include <iostream>
#include <string>
#include <vector>
#include "RecipeBook.h"
#include "MealPlan.h"

void Core::displayMainMenu() {
    std::cout << "\nMain Menu:\n";
    std::cout << "\n1. Browse Recipes by Category (Breakfast, Lunch, Dinner)\n";
    std::cout << "\n2. Meal Planning\n";
    std::cout << "\n3. Exit\n";
    std::cout << "\nEnter your choice:\n ";
}

void Core::browseRecipesByCategory(RecipeBook& recipeBook) {
    std::cout << "\nChoose a category:\n";
    std::cout << "\n1. Breakfast\n";
    std::cout << "\n2. Lunch\n";
    std::cout << "\n3. Dinner\n";
    std::cout << "\nEnter your choice:\n";
    int choice;
    std::cin >> choice;

    std::string category;
    switch (choice) {
        case 1: category = "Breakfast"; break;
        case 2: category = "Lunch"; break;
        case 3: category = "Dinner"; break;
        default:
            std::cout << "\nInvalid choice!\n";
            return;
    }

    std::vector<std::string> recipes = recipeBook.getRecipesByCategory(category);
    if (recipes.empty()) {
        std::cout << "No recipes found for " << category << ".\n";
        return;
    }

    std::cout << "\nRecipes for " << category << ":\n";
    for (size_t i = 0; i < recipes.size(); ++i) {
        std::cout << i + 1 << ". " << recipes[i] << "\n";
    }

    std::cout << "\nEnter the number of the recipe to view details:\n ";
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
    std::cout << "\nEnter the date to view meals (e.g., 2024-12-02):\n";
    std::string date;
    std::cin >> date;

    std::vector<std::string> meals = mealPlan.getMealsForDate(date);
    if (meals.empty()) {
        std::cout << "\nNo meals found for " << date << ".\n";
        return;
    }

    std::cout << "\nMeals for " << date << ":\n";
    for (size_t i = 0; i < meals.size(); ++i) {
        std::cout << i + 1 << ". " << meals[i] << "\n";
    }

    std::cout << "\nEnter the number of the meal to view details:\n ";
    int mealChoice;
    std::cin >> mealChoice;

    if (mealChoice > 0 && mealChoice <= meals.size()) {
        recipeBook.displayRecipeDetails(meals[mealChoice - 1]);
    } else {
        std::cout << "\nInvalid choice!\n";
    }
}
