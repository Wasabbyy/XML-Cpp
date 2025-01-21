#include "MealPlan.h"
#include <iostream>
#include <string>
#include <vector>

using namespace tinyxml2;

bool MealPlan::loadFromFile(const std::string& fileName) {
    return doc.LoadFile(fileName.c_str()) == XML_SUCCESS;
}

void MealPlan::displayMealPlan(std::vector<std::string>& indexedDays) {
    indexedDays.clear(); // Clear the vector to store fresh data.
    XMLElement* root = doc.RootElement();
    if (!root) return;

    XMLElement* mealPlan = root->FirstChildElement("MealPlan");
    if (!mealPlan) return;

    XMLElement* day = mealPlan->FirstChildElement("Day");
    int index = 1; // Start indexing from 1
    while (day) {
        const char* date = day->Attribute("date");
        if (date) {
            std::cout << index << ". Date: " << date << "\n";
            indexedDays.push_back(date);

            // Display meals for this date
            XMLElement* meal = day->FirstChildElement("Meal");
            while (meal) {
                std::cout << "   - " << meal->GetText() << "\n";
                meal = meal->NextSiblingElement("Meal");
            }
            ++index;
        }
        day = day->NextSiblingElement("Day");
    }
}


std::vector<std::string> MealPlan::getMealsForDate(const std::string& date) {
    std::vector<std::string> meals;
    XMLElement* root = doc.RootElement();
    if (!root) return meals;

    XMLElement* mealPlan = root->FirstChildElement("MealPlan");
    if (!mealPlan) return meals;

    XMLElement* day = mealPlan->FirstChildElement("Day");
    while (day) {
        if (std::string(day->Attribute("date")) == date) {
            XMLElement* meal = day->FirstChildElement("Meal");
            while (meal) {
                meals.push_back(meal->GetText());
                meal = meal->NextSiblingElement("Meal");
            }
            break;
        }
        day = day->NextSiblingElement("Day");
    }
    return meals;
}