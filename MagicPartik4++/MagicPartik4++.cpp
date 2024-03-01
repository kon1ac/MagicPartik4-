#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

string reverse(string word) {
    reverse(word.begin(), word.end());
    return word;
}

string removeVowels(string word) {
    string vowels = "aeiouAEIOU";
    for (int i = 0; i < word.length(); i++) {
        if (vowels.find(word[i]) != string::npos) {
            word.erase(i, 1);
            i--;
        }
    }
    return word;
}

string removeConsonants(string word) {
    string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    for (int i = 0; i < word.length(); i++) {
        if (consonants.find(word[i]) != string::npos) {
            word.erase(i, 1);
            i--;
        }
    }
    return word;
}

string shuffle(string word) {
    srand(time(0));
    random_shuffle(word.begin(), word.end());
    return word;
}

int main() {
    SetConsoleCP(1251);
    setlocale(0, "Russian");
    string word;
    int choice;

    cout << "Введите слово: ";
    cin >> word;

    while (true) {
        cout << "Выберите действие:\n";
        cout << "1. Вывести слово задом наперед\n";
        cout << "2. Вывести слово без гласных\n";
        cout << "3. Вывести слово без согласных\n";
        cout << "4. Рандомно раскидывать буквы заданного слова\n";
        cout << "Выбор: ";
        cin >> choice;

        string result;

        switch (choice) {
        case 1:
            result = reverse(word);
            break;
        case 2:
            result = removeVowels(word);
            break;
        case 3:
            result = removeConsonants(word);
            break;
        case 4:
            result = shuffle(word);
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз.\n";
            continue;
        }

        cout << "Результат: " << result << "\n";

        char continueChoice;
        cout << "Желаете продолжить? (y/n): ";
        cin >> continueChoice;

        if (continueChoice != 'y' && continueChoice != 'Y')
            break;
    }

    return 0;
}
