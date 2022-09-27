// Create a program that computes the customer's Restaraunt Bill.
// This program will ask for the user's meal cost(s) and tip percentage.
#include <iomanip>
#include <iostream>

int main() 
{
  double meal_cost, 
         tip_percentage,
         tip, subtotal, 
         tax, 
         total;
  
  // money format. 
  std::cout << std::fixed << std::setprecision(2);

  std::cout << "Please input meal cost: ";
  std::cin  >> meal_cost;

  std::cout << "Please input tip percentage: ";
  std::cin  >> tip_percentage;

  // Calculate user's Subtotal, Tax, Tip, and Total. 
  subtotal = meal_cost;
  tax = 0.075 * meal_cost;
  tip = (tip_percentage / 100) * meal_cost;
  total = subtotal + tax + tip;

  // Customer's Receipt Bill.
  std::cout << "\nRestaurant Bill";
  std::cout << "\n====================";
  std::cout << "\nSubtotal: $"  << subtotal; 
  std::cout << "\nTaxes: "      << std::setw(4) << "$" << tax; 
  std::cout << "\nTip:   "      << std::setw(4) << "$" << tip;
  std::cout << "\n====================";
  std::cout << "\nTotal: "      << std::setw(4) << "$" << total << "\n";

  return 0;
}
