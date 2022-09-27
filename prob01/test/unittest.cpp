#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(Restaurant, OutputFormat) {
  std::string unittest_output =
      "Please input meal cost: Please input tip "
      "percentage: \nRestaurant Bill\n====================\n"
      "Subtotal: $34.00\nTaxes: $2.55\nTip: $5.10\n"
      "====================\nTotal: $41.65\n";
  ASSERT_EXECIO_EQ("main", "34 15", unittest_output);
}

TEST(Restaurant, MealCost) {
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    // randomly generate a meal cost between 0 and $50
    double meal_cost = (((double)rand() / RAND_MAX) * pow(10, rand() % 5));
    // make sure the randomly generated double only has 2 decimal places
    meal_cost -= fmod(meal_cost, 0.01);
    double taxes = meal_cost * 0.075;
    // randomly generate a tip between 0 and 15.00
    double total = meal_cost + taxes + meal_cost * 15 / 100;
    std::string unittest_output =
        "Please input meal cost: Please input tip "
        "percentage: \nRestaurant Bill\n====================\n"
        "Subtotal: $" +
        to_string_double(meal_cost) + "\nTaxes: $" + to_string_double(taxes) +
        "\nTip: $" + to_string_double(meal_cost * 15 / 100) +
        "\n"
        "====================\nTotal: $" +
        to_string_double(total) + "\n";
    std::string input = to_string_double(meal_cost) + " 15";
    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

TEST(Restaurant, Taxes) {
  for (int i = 0; i < 10; i++) {
    // randomly generate a meal cost between 0 and $50
    double meal_cost = 25.65;
    // make sure the randomly generated double only has 2 decimal places
    double taxes = meal_cost * 0.075;
    double total = meal_cost + taxes + meal_cost * 15 / 100;
    std::string taxes_string = "Taxes: $" + to_string_double(taxes);
    std::string unittest_output =
        "Please input meal cost: Please input tip "
        "percentage: \nRestaurant Bill\n====================\n"
        "Subtotal: $25.65\nTaxes: $";
    unittest_output += to_string_double(taxes) + "\nTip: $" +
                       to_string_double(meal_cost * 15 / 100) + "\n" +
                       "====================\nTotal: $" +
                       to_string_double(total) + "\n";
    std::string input = to_string_double(meal_cost) + " 15";
    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

TEST(Restaurant, Tip) {
  for (int i = 0; i < 10; i++) {
    double meal_cost = 30.20;
    double taxes = meal_cost * 0.075;
    // randomly generate a tip between 0 and 15.00
    double tip = (rand() % 10 + 6) / RAND_MAX;
    tip -= fmod(tip, 0.01);
    double total = meal_cost + taxes + meal_cost * tip / 100;
    std::string unittest_output =
        "Please input meal cost: Please input tip "
        "percentage: \nRestaurant Bill\n====================\n"
        "Subtotal: $30.20\nTaxes: $";
    unittest_output += to_string_double(taxes) + "\nTip: $" +
                       to_string_double(meal_cost * tip / 100) + "\n" +
                       "====================\nTotal: $" +
                       to_string_double(total) + "\n";
    std::string input =
        to_string_double(meal_cost) + " " + to_string_double(tip);
    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

TEST(Restaurant, Total) {
  for (int i = 0; i < 10; i++) {
    // randomly generate a meal cost between 0 and $50
    double meal_cost = (((double)rand() / RAND_MAX) * pow(10, rand() % 5));
    // make sure the randomly generated double only has 2 decimal places
    meal_cost -= fmod(meal_cost, 0.01);
    double taxes = meal_cost * 0.075;
    // randomly generate a tip between 0 and 15.00
    double tip = (rand() % 10 + 6) / RAND_MAX;
    double total = meal_cost + taxes + meal_cost * tip / 100;
    std::string unittest_output =
        "Please input meal cost: Please input tip "
        "percentage: \nRestaurant Bill\n====================\n"
        "Subtotal: $" +
        to_string_double(meal_cost) + "\nTaxes: $" + to_string_double(taxes) +
        "\nTip: $" + to_string_double(meal_cost * tip / 100) +
        "\n"
        "====================\nTotal: $" +
        to_string_double(total) + "\n";
    std::string input =
        to_string_double(meal_cost) + " " + to_string_double(tip);
    ASSERT_EXECIO_EQ("main", input, unittest_output);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
