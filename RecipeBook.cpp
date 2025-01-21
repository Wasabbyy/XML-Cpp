#include "RecipeBook.h"
#include <iostream>
#include <string>
#include <vector>

using namespace tinyxml2;

bool RecipeBook::loadFromFile(const std::string& fileName) {
    return doc.LoadFile(fileName.c_str()) == XML_SUCCESS;
}

std::vector<std::string> RecipeBook::getRecipesByCategory(const std::string& category) {
    std::vector<std::string> recipes;
    XMLElement* root = doc.RootElement();
    if (!root) return recipes;

    XMLElement* recipe = root->FirstChildElement("Recipe");
    while (recipe) {
        XMLElement* categoryElem = recipe->FirstChildElement("Category");
        if (categoryElem && categoryElem->GetText() == category) {
            XMLElement* titleElem = recipe->FirstChildElement("Title");
            if (titleElem) recipes.push_back(titleElem->GetText());
        }
        recipe = recipe->NextSiblingElement("Recipe");
    }
    return recipes;
}

void RecipeBook::displayRecipeDetails(const std::string& recipeTitle) {
    XMLElement* root = doc.RootElement();
    if (!root) return;

    XMLElement* recipe = root->FirstChildElement("Recipe");
    while (recipe) {
        XMLElement* titleElem = recipe->FirstChildElement("Title");
        if (titleElem && titleElem->GetText() == recipeTitle) {
            std::cout << "Recipe Details:\n";
            std::cout << "Title: " << recipeTitle << "\n";

            XMLElement* ingredientsElem = recipe->FirstChildElement("Ingredients");
            if (ingredientsElem) {
                std::cout << "Ingredients:\n";
                XMLElement* ingredient = ingredientsElem->FirstChildElement("Ingredient");
                while (ingredient) {
                    XMLElement* name = ingredient->FirstChildElement("Name");
                    XMLElement* quantity = ingredient->FirstChildElement("Quantity");
                    if (name && quantity) {
                        std::cout << "- " << name->GetText() << " (" << quantity->GetText() << " " << quantity->Attribute("unit") << ")\n";
                    }
                    ingredient = ingredient->NextSiblingElement("Ingredient");
                }
            }

            XMLElement* instructionsElem = recipe->FirstChildElement("Instructions");
            if (instructionsElem) {
                std::cout << "Instructions:\n";
                XMLElement* step = instructionsElem->FirstChildElement("Step");
                while (step) {
                    std::cout << "- " << step->GetText() << "\n";
                    step = step->NextSiblingElement("Step");
                }
            }
            return;
        }
        recipe = recipe->NextSiblingElement("Recipe");
    }
    std::cout << "Recipe not found!\n";
}