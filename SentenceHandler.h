#ifndef SENTENCE_HANDLER_H
#define SENTENCE_HANDLER_H

#include <string>
#include <fstream>
#include <iostream>

// Класс для обработки предложений из файла
class SentenceHandler {
private:
    std::string* sentences; // Указатель на массив строк (предложения)
    int count;              // Количество предложений

public:
    SentenceHandler();      // Конструктор по умолчанию
    ~SentenceHandler();     // Деструктор

    void readFromFile(const std::string& filename); // Чтение предложений из файла
    void reverseSentences();                        // Реверсирование предложений
    void displaySentences() const;                 // Вывод предложений на экран
};

#endif // SENTENCE_HANDLER_H
