#include "AEROFLOT.h"

// Конструктор по умолчанию
AEROFLOT::AEROFLOT() : destination(""), flightNumber(0), planeType("") {
    std::cout << "Вызван конструктор по умолчанию для AEROFLOT.\n"; // Сообщение о вызове конструктора
}

// Конструктор с параметрами
AEROFLOT::AEROFLOT(const std::string& dest, int flightNum, const std::string& type)
    : destination(dest), flightNumber(flightNum), planeType(type) {
    std::cout << "Вызван конструктор с параметрами для AEROFLOT.\n"; // Сообщение о вызове конструктора
}

// Конструктор копирования
AEROFLOT::AEROFLOT(const AEROFLOT& other)
    : destination(other.destination), flightNumber(other.flightNumber), planeType(other.planeType) {
    std::cout << "Вызван конструктор копирования для AEROFLOT.\n"; // Сообщение о вызове конструктора копирования
}

// Деструктор
AEROFLOT::~AEROFLOT() {
    std::cout << "Вызван деструктор для AEROFLOT.\n"; // Сообщение о вызове деструктора
}

// Установить пункт назначения
void AEROFLOT::setDestination(const std::string& dest) { 
    destination = dest; 
}

// Установить номер рейса
void AEROFLOT::setFlightNumber(int flightNum) { 
    flightNumber = flightNum; 
}

// Установить тип самолета
void AEROFLOT::setPlaneType(const std::string& type) { 
    planeType = type; 
}

// Получить пункт назначения
std::string AEROFLOT::getDestination() const { 
    return destination; 
}

// Получить номер рейса
int AEROFLOT::getFlightNumber() const { 
    return flightNumber; 
}

// Получить тип самолета
std::string AEROFLOT::getPlaneType() const { 
    return planeType; 
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const AEROFLOT& obj) {
    os << "Пункт назначения: " << obj.destination
       << ", Номер рейса: " << obj.flightNumber
       << ", Тип самолета: " << obj.planeType;
    return os; // Возвращаем поток для цепочки операций
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& is, AEROFLOT& obj) {
    std::cout << "Введите пункт назначения: "; 
    is >> obj.destination; // Ввод пункта назначения
    std::cout << "Введите номер рейса: "; 
    is >> obj.flightNumber; // Ввод номера рейса
    std::cout << "Введите тип самолета: "; 
    is >> obj.planeType; // Ввод типа самолета
    return is; // Возвращаем поток для цепочки операций
}
