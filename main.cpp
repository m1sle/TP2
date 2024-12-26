#include "AEROFLOT.h"
#include "SentenceHandler.h"
#include <vector>
#include <algorithm>

// Вывод меню
void displayMenu() {
    std::cout << "1. Добавить рейс\n";
    std::cout << "2. Вывести рейсы по типу самолета\n";
    std::cout << "3. Обработать файл с предложениями\n";
    std::cout << "0. Выход\n";
}

int main() {
    std::vector<AEROFLOT> flights; // Вектор для хранения рейсов
    SentenceHandler handler; // Объект для работы с предложениями
    int choice; // Выбор пользователя

    do {
        displayMenu(); // Вывод меню
        std::cin >> choice; // Ввод выбора

        switch (choice) {
        case 1: {
            AEROFLOT flight;
            std::cin >> flight; // Ввод информации о рейсе
            flights.push_back(flight); // Добавление рейса в вектор
            // Сортировка рейсов по алфавиту
            std::sort(flights.begin(), flights.end(), [](const AEROFLOT& a, const AEROFLOT& b) {
                return a.getDestination() < b.getDestination();
            });
            break;
        }
        case 2: {
            std::string planeType;
            std::cout << "Введите тип самолета: ";
            std::cin >> planeType; // Ввод типа самолета

            bool found = false; // Флаг наличия рейсов
            for (const auto& flight : flights) {
                if (flight.getPlaneType() == planeType) { // Проверка совпадения типа самолета
                    std::cout << flight << "\n"; // Вывод рейса
                    found = true;
                }
            }

            if (!found) { // Если рейсов не найдено
                std::cout << "Рейсы с таким типом самолета не найдены.\n";
            }
            break;
        }
        case 3: {
            try {
                handler.readFromFile("input.txt"); // Чтение предложений из файла
                handler.reverseSentences(); // Реверсирование предложений
                handler.displaySentences(); // Вывод предложений
            } catch (const std::exception& e) { // Обработка исключений
                std::cerr << e.what() << "\n"; // Вывод сообщения об ошибке
            }
            break;
        }
        case 0:
            std::cout << "Выход из программы.\n"; // Завершение программы
            break;
        default:
            std::cout << "Некорректный выбор.\n"; // Сообщение о неверном выборе
            break;
        }
    } while (choice != 0); // Пока не выбран выход

    return 0;
}
