
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

template <typename T>
T getInput(const std::string &strQuery);

std::string getUername();
std::string getPassword();
void saveUser(const std::string &username, const std::string &password);

void login();
void registerUser();
void mainMenu();

int main()
{
    mainMenu();
}

template <typename T>//Создадим функцию, чтобы возвращать целые числа и другите типы переменных. Если ввести неверные данные, то будет просить повторить попытку ввода
T getInput(const std::string &strQuery)
{
    std::cout << strQuery << "\n> ";
    T out = T();

    while (!(std::cin >> out)) {
        std::cin.clear();
        std::cin.ignore(std::numericLimits <std::streamsize>::max(), '\n');
        std::cout << "Error!" "\n";
        std::cout << strQuery << "\n> ";
    }

    return out;
}

std::string getPassword()
{
    std::string password1 = getInput <std::string> ("Please enter your password.");
    std::string password2 = getInput <std::string> ("Please re-enter your password.");

    while (password1 != password2) and strlen(str)<4 or strlen(str)>12 {
        std::cout << "Error! Passwords do not match." "\n";
        password1 = getInput <std::string>("Please enter your password.");
        password2 = getInput <std::string>("Please re-enter your password.");
    }

    return password1;
}

std::string getUsername()
{
    std::string username = getInput <std::string>("Please enter a username.");
    std::cout << "Username: \"" << username << "\"\n";

    while (getInput <int>("Confirm? [0|1]") != 1) {
        username = get_Input <std::string>("Please enter a username.");
        std::cout << "Username: \"" << username << "\"\n";
    }

    return username;
}

void login()
{
    std::cout << "You are being logged in!" "\n";
}

void mainMenu()
{
    int choice = get_input <int>(
        "Hello, Would you like to log in or register?" "\n"
        "[1] Login" "\n"
        "[2] Register" "\n"
        "[3] User list" "\n"
        "[4] Exit");

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        register_user();
        break;
    }
}

void register_user()
{
    std::string username = getUsername();
    std::string password = getPassword();
    saveUser(username, password);
}

void saveUser(const std::string &username, const std::string &password)
{
    std::string filename = username + ".txt";
    std::ofstream file(filename);
    file << password << "\n";
}
