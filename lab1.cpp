#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    float a, b, c;
    
    cout << "Enter the value 'a':";
    cin >> a;
    cout << "Enter the value 'b'";
    cin >> b;
    cout << "Enter the value 'c'";
    cin >> c;
    
    double angle = acos  ((pow(a, 2)+pow(b, 2)- pow(c, 2)) / (2 * a * b));
    
    cout << "The angle betweenb sides a and b is " << angle << " radians" << endl;
    
    return 0;
}
