#include <iostream>

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false; // If x is negative or ends with 0 (except 0 itself), it cannot be a palindrome
    }

    int reversed = 0;
    while (x > reversed) {
        reversed = reversed * 10 + x % 10; // Reversing the number
        x /= 10;
    }

    return x == reversed || x == reversed / 10; // If the length of x is odd, we need to divide reversed by 10 to check for equality
}

int main() {
    int x = 12321;
    if (isPalindrome(x)) {
        std::cout << x << " is a palindrome." << std::endl;
    } else {
        std::cout << x << " is not a palindrome." << std::endl;
    }

    return 0;
}
