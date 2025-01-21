#ifndef CORE_H
#define CORE_H

#include <string>
#include <vector>
#include "RecipeBook.h"
#include "MealPlan.h"

class Core {
public:
    void displayMainMenu();
    void browseRecipesByCategory(RecipeBook& recipeBook);
    void mealPlanning(MealPlan& mealPlan, RecipeBook& recipeBook);
    void getValidatedInput();
};

#endif
