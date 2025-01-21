#include "Core.h"
#include "RecipeBook.h"
#include "MealPlan.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>

void Core::displayMainMenu() {
    std::cout << "\nMain Menu:\n";
    std::cout << "1. Browse Recipes by Category (Breakfast, Lunch, Dinner)\n";
    std::cout << "2. Meal Planning\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
}

void Core::browseRecipesByCategory(RecipeBook& recipeBook) {
    std::cout << "\nChoose a category:\n";
    std::cout << "1. Breakfast\n";
    std::cout << "2. Lunch\n";
    std::cout << "3. Dinner\n";
    std::cout << "Enter your choice: ";
    int choice = getValidatedInput();

    std::string category;
    switch (choice) {
        case 1: category = "Breakfast"; break;
        case 2: category = "Lunch"; break;
        case 3: category = "Dinner"; break;
        default:
            std::cout << "Invalid choice!\n";
            return;
    }

    auto recipes = recipeBook.getRecipesByCategory(category);
    if (recipes.empty()) {
        std::cout << "No recipes found for " << category << ".\n";
        return;
    }

    std::cout << "\nRecipes for " << category << ":\n";
    for (size_t i = 0; i < recipes.size(); ++i) {
        std::cout << i + 1 << ". " << recipes[i] << "\n";
    }

    std::cout << "Enter the number of the recipe to view details: ";
    int recipeChoice = getValidatedInput();

    if (recipeChoice > 0 && recipeChoice <= recipes.size()) {
        recipeBook.displayRecipeDetails(recipes[recipeChoice - 1]);
    } else {
        std::cout << "Invalid choice!\n";
    }
}

void Core::mealPlanning(MealPlan& mealPlan, RecipeBook& recipeBook) {
    std::vector<std::string> indexedDays;
    mealPlan.displayMealPlan(indexedDays);

    if (indexedDays.empty()) {
        std::cout << "No days available in the meal plan.\n";
        return;
    }

    std::cout << "\nEnter the number of a day you want to list: ";
    int dateChoice = getValidatedInput();

    if (dateChoice < 1 || dateChoice > indexedDays.size()) {
        std::cout << "Invalid choice!\n";
        return;
    }

    std::string selectedDate = indexedDays[dateChoice - 1];
    auto meals = mealPlan.getMealsForDate(selectedDate);

    if (meals.empty()) {
        std::cout << "\nNo meals found for " << selectedDate << ".\n";
        return;
    }

    std::cout << "\nMeals for " << selectedDate << ":\n";
    for (size_t i = 0; i < meals.size(); ++i) {
        std::cout << i + 1 << ". " << meals[i] << "\n";
    }

    std::cout << "\nEnter the number of the meal to view details: ";
    int mealChoice = getValidatedInput();

    if (mealChoice > 0 && mealChoice <= meals.size()) {
        recipeBook.displayRecipeDetails(meals[mealChoice - 1]);
    } else {
        std::cout << "\nInvalid choice!\n";
    }
}

int Core::getValidatedInput() {
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number: ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}