#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <random>

using namespace std;

// переворачивание
    string reverseString(string str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

// удаление гласных
    string removeVowels(string str) {
    string result = "";
    for (char c : str) {
        if (tolower(c) != 'у' && tolower(c) != 'е' && tolower(c) != 'ы' && tolower(c) != 'а' && tolower(c) != 'о' && tolower(c) != 'э' && tolower(c) != 'я' && tolower(c) != 'и' && tolower(c) != 'ю') {
            result += c;
        }
    }
    return result;
}

// удаление согласных
    string removeConsonants(string str) {
    string result = "";
    for (char c : str) {
        if (!isalpha(c) || tolower(c) == 'у' || tolower(c) == 'е' || tolower(c) == 'ы' || tolower(c) == 'а' || tolower(c) == 'о' || tolower(c) == 'э' || tolower(c) == 'я' || tolower(c) == 'и' || tolower(c) == 'ю') {
            result += c;
        }
    }
    return result;
}

// перемешивание
    string shuffleString(std::string str) {
    random_device rd;
    mt19937 g(rd());
    shuffle(str.begin(), str.end(), g);
    return str;
}

int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    string word;
    cout << "Введите слово: ";
    cin >> word;

    int choice;
    cout << "Выберите действие:\n";
    cout << "1. Слово выводится задом наперед.\n";
    cout << "2. Вывести слово без гласных.\n";
    cout << "3. Вывести слово без согласных.\n";
    cout << "4. Рандомно раскидывать буквы заданного слова.\n";
    cin >> choice;

    switch (choice) {
    case 1:
        word = reverseString(word);
        cout << "Результат: " << word << endl;
        break;
    case 2:
        word = removeVowels(word);
        cout << "Результат: " << word  << endl;
        break;
    case 3:
        word = removeConsonants(word);
        cout << "Результат: " << word << endl;
        break;
    case 4:
        word = shuffleString(word);
        cout << "Результат: " << word << endl;
        break;
    default:
        cout << "Некорректный выбор.\n";
    }

    return 0;
}