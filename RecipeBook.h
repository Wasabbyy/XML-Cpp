#ifndef RECIPE_BOOK_H
#define RECIPE_BOOK_H

#include <string>
#include <vector>
#include "tinyxml2.h"

class RecipeBook {
public:
    bool loadFromFile(const std::string& fileName);
    std::vector<std::string> getRecipesByCategory(const std::string& category);
    void displayRecipeDetails(const std::string& recipeTitle);

private:
    tinyxml2::XMLDocument doc;
};

#endif
