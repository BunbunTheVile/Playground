#include "dice.hpp"
#include "normalDistribution.hpp"
#include "exactDiceDistribution.hpp"
#include "improvedDiceDistribution.hpp"
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double binomialCoefficient(int n, int k) {
    //return factorial(n) / (factorial(n - k) * factorial(k));
    // Let's not use factorials, but instead let's optimize this a bit and use doubles that are finally cast back to long long
    // for example: n over k = 50!/(30! * 20!) can instead be calculated as (50*49*...*31)/(20*19*...*1) after simplification
    // To avoid very large numbers (and thus loss of precision), let's switch between multiplying and dividing
    
    k = (n-k) < k ? n-k : k;

    double total = 1;
    for (int i = 0; i < k; i++) {
        total = total * (n - i) / (k - i);
    }
    return total;
}

double permutations(int sum, int number, int sides) {
    // Calculates the possible permutations of dice rolls that add up to a given sum
    // The formula that is used was taken from Luca M on this here forum post:
    // https://math.stackexchange.com/questions/794981/how-many-permutations-of-die-rolls-add-up-to-a-fixed-total
    // k = sum, n = number, replace 6 in the formula with sides
    
    double total = 0;
    int imax = (sum - number) / sides;
    for (int i = 0; i <= imax; i++) {
        int sign = i % 2 == 0 ? 1 : -1;
        double bc1 = binomialCoefficient(number, i);
        double bc2 = binomialCoefficient(sum - sides*i - 1, sum - sides*i - number);
        total += sign * bc1 * bc2;
    }
    return total;
}


// TODO!!!
int main() {    
    cout << fixed;
    cout << setprecision(15);
    
    //20d6
    double possibilities = pow(6, 20);
    int minRoll = 20;
    double total = 0;
    for (int i = minRoll; i <= 120; i++) {
        double probability = permutations(i, 20, 6) / possibilities;
        cout << i << "\t" << probability << endl;
        total += probability;
    }
    cout << "\n\nTotal is: " << total << endl;
    
}