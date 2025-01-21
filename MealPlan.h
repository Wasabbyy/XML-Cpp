#ifndef MEAL_PLAN_H
#define MEAL_PLAN_H

#include <string>
#include <vector>
#include "tinyxml2.h"

class MealPlan {
public:
    bool loadFromFile(const std::string& fileName);
   void displayMealPlan(std::vector<std::string>& indexedDays);

    std::vector<std::string> getMealsForDate(const std::string& date);
    std::vector<std::string> getDays();

private:
    tinyxml2::XMLDocument doc;
};

#endif
