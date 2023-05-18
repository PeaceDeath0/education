#include <iostream>
using namespace std;

int main() {
	float v, s, t;

	cout << "Enter the speed in m/s:";
	cin >> v;
	cout << "Enter the distance in km:";
	cin >> s;

	v = v * 60 / 1000;
	t = s / v; 
	cout << "travel time: " << t << " minute." << endl;

	return 0;
}
