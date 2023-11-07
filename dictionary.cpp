#include <map>
#include <fstream>
#include <iostream>
#include <locale>


void AddWord( std::map<std::string, std::string>& dictionary ) {

    std::string word, translition;
    std::cout << "Enter a word in English: ";
    std::cin >> word;

    if ( dictionary.count( word ) > 0) {

        std::cout << "Such a word is already in the dictionary!" << std::endl;

    } else {

        std::cout << "Enter a word in Russian: ";
        std::cin >> translition;
        dictionary[word] = translition;
        std::cout << "The word \"" << word << "\" has been successfully added to the dictionary" << std::endl;
    }

}

void findTranslition( const std::map<std::string, std::string>& dictionary ) {
    std::string word;
    std::cout << "Enter a word in English: ";
    std::cin >> word;

    if (dictionary.count( word ) > 0) {

        std::cout << "Translation of the word\"" << word << "\" into Russian: " << dictionary.at(word) << std::endl;

    } else {
        std::cout << "Word \"" << word << "\" is not found in dictionary" << std::endl;
    }
}

void saveDictionary(const std::map<std::string, std::string>& dictionary) {
    std::ofstream file("dictionary.txt");

    if (file.is_open()) {
        for (const auto& pair : dictionary) {

            file << pair.first << "-" << pair.second << std::endl;

        }

        std::cout << "The dictionary has been successfully saved to a file dictionary.txt" << std::endl;

    } else {

        std::cout << "Failed to save file" << std::endl;

    }
}

int main()
{
    std::map <std::string, std::string>dictionary;
    int choice;
    setlocale(LC_ALL, "Russian");

    while (true) {

        std::cout << "Select an action" << std::endl;
        std::cout << "1. Add a word and translation" << std::endl;
        std::cout << "2. Find a word-translation" << std::endl;
        std::cout << "3. Save dictionary to file" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Your choice" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1:
            AddWord(dictionary);
            break;
        case 2:
            findTranslition(dictionary);
            break;
        case 3:
            saveDictionary(dictionary);
            break;
        case 4:
            return 0;
        default:
            std::cout << "Error choice. Try again!" << std::endl;
        }
        std::cout << std::endl;
    } 
 
}
