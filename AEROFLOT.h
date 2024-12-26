#ifndef AEROFLOT_H
#define AEROFLOT_H

#include <iostream>
#include <string>

// Класс AEROFLOT, описывающий рейсы
class AEROFLOT {
private:
    std::string destination; // Название пункта назначения
    int flightNumber;        // Номер рейса
    std::string planeType;   // Тип самолета

public:
    // Конструктор по умолчанию
    AEROFLOT();
    
    // Конструктор с параметрами
    AEROFLOT(const std::string& dest, int flightNum, const std::string& type);
    
    // Конструктор копирования
    AEROFLOT(const AEROFLOT& other);

    // Деструктор
    ~AEROFLOT();

    // Методы установки значений
    void setDestination(const std::string& dest);  // Установить пункт назначения
    void setFlightNumber(int flightNum);           // Установить номер рейса
    void setPlaneType(const std::string& type);    // Установить тип самолета

    // Методы получения значений
    std::string getDestination() const;           // Получить пункт назначения
    int getFlightNumber() const;                  // Получить номер рейса
    std::string getPlaneType() const;             // Получить тип самолета

    // Перегрузка операторов ввода и вывода
    friend std::ostream& operator<<(std::ostream& os, const AEROFLOT& obj); // Вывод объекта
    friend std::istream& operator>>(std::istream& is, AEROFLOT& obj);       // Ввод объекта
};

#endif // AEROFLOT_H
