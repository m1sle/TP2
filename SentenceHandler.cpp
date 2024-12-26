#include "SentenceHandler.h"
#include <sstream>

// Конструктор по умолчанию
SentenceHandler::SentenceHandler() : sentences(nullptr), count(0) {
    std::cout << "Вызван конструктор по умолчанию для SentenceHandler.\n"; // Сообщение о вызове конструктора
}

// Деструктор
SentenceHandler::~SentenceHandler() {
    delete[] sentences; // Освобождение памяти
    std::cout << "Вызван деструктор для SentenceHandler.\n"; // Сообщение о вызове деструктора
}

// Чтение предложений из файла
void SentenceHandler::readFromFile(const std::string& filename) {
    std::ifstream file(filename); // Открытие файла
    if (!file) { // Проверка успешности открытия
        throw std::runtime_error("Ошибка открытия файла."); // Исключение при ошибке
    }

    std::string line;
    count = 0;
    while (std::getline(file, line)) { // Подсчет строк в файле
        count++;
    }

    file.clear(); // Сброс состояния потока
    file.seekg(0, std::ios::beg); // Возврат указателя на начало файла

    sentences = new std::string[count]; // Выделение памяти для массива строк
    for (int i = 0; i < count; ++i) {
        std::getline(file, sentences[i]); // Чтение строк в массив
    }
    file.close(); // Закрытие файла
}

// Реверсирование порядка предложений
void SentenceHandler::reverseSentences() {
    for (int i = 0; i < count / 2; ++i) { // Меняем местами строки
        std::swap(sentences[i], sentences[count - i - 1]);
    }
}

// Вывод предложений на экран
void SentenceHandler::displaySentences() const {
    for (int i = 0; i < count; ++i) { // Перебор всех строк
        std::cout << sentences[i] << "\n"; // Вывод строки
    }
}
