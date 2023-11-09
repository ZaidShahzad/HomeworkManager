#include <iostream>

int add(int number1, int number2) {
    return number1 + number2;
}

int main() {
    std::cout << "The Sum of 1 + 2 = " << add(1,2) << std::endl;
    return 0;
}
