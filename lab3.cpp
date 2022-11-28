#include <iostream>
#include <fstream>
#include <cmath>


double log(double a, double b)
{
    return log(b) / log(a);
}



int main()
{
    setlocale(LC_ALL, "en");

    std::ifstream f_input;
    std::ofstream f_output("R.txt");
    std::ofstream result("degree.txt");

    std::cout << "Welcome to the degree calculation program\n";
   
  
        double R;
        double a = 3;
        do
        {
            
            
            std::cout << "Enter the R value: ";
            std::cin >> R;

            f_output << R;
            f_output.close();

            f_input.open("R.txt");
            if (f_input.fail())
            {
                std::cout << "File opening error\n";
                return 1;
            }

            f_input >> R;
            f_input.close();

            result << "X = " << log(a, R);
            result.close();

            if (R <= 0)
            {
                std::cout << "Enter the positive R value\n";
            }

            
                std::cout << "x = " << log(a, R) << '\n' << "The result is recorded in stepen.txt\n";

        } while (R <= 0);

    return 0;
    
}
