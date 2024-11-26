#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <locale>

struct Автомобиль {
    std::string марка;
    std::string модель;
    int год;
    std::string цвет;
    float цена;

    // Метод для отображения информации об автомобиле
    void показатьИнформацию() const {
        std::cout << "Марка: " << марка
            << ", Модель: " << модель
            << ", Год: " << год
            << ", Цвет: " << цвет
            << ", Цена(в сутки): " << цена
            << std::endl;
    }
};

std::vector<Автомобиль> автомобили;

double balance = 0;
bool isActive = false;

int init() {
    автомобили.push_back({"Lada", "Vesta", 2015, "Белый", 2500 });
    автомобили.push_back({"Honda", "Civic", 2019, "Красный", 3500 });
    автомобили.push_back({"Ford", "Mustang", 2021, "Черный", 5000 });
    return 0;
}

int arenda() {
    std::cout << "Выберите авто, которое вы хотите арендовать (введите номер):" << std::endl;
    for (size_t i = 0; i < автомобили.size(); ++i) {
        const auto& авто = автомобили[i];
        std::cout << i << " - " << авто.марка << " " << авто.модель << " (Цена: " << авто.цена << ")" << std::endl;
    }

    int выбор1;
    std::cout << "Введите номер автомобиля: ";
    std::cin >> выбор1;

    // Проверка на корректность ввода
    if (выбор1 < 0 || выбор1 >= автомобили.size()) {
        std::cout << "Неверный номер автомобиля. Попробуйте еще раз." << std::endl;
        return -1; // Возвращаем ошибку
    }

    // Вывод информации о выбранном автомобиле
    const auto& выбранныйАвто = автомобили[выбор1];
    if (balance >= выбранныйАвто.цена) {
        std::cout << "Вы выбрали: " << выбранныйАвто.марка << " " << выбранныйАвто.модель
            << ". Цена аренды: " << выбранныйАвто.цена << std::endl;
        balance -= выбранныйАвто.цена;
    }
    else {
        std::cout << "У вас недостаточно средств! Пополните счет чтобы арендовать авто!" << std::endl;
    }
    

    return 0;
}

int info() {
    std::cout << "Выберите авто, которое вы хотите просмотреть (введите номер):" << std::endl;
    for (size_t i = 0; i < автомобили.size(); ++i) {
        const auto& авто = автомобили[i];
        std::cout << i << " - " << авто.марка << " " << авто.модель << std::endl;
    }

    int выбор2;
    std::cout << "Введите номер автомобиля: ";
    std::cin >> выбор2;

    // Проверка на корректность ввода
    if (выбор2 < 0 || выбор2 >= автомобили.size()) {
        std::cout << "Неверный номер автомобиля. Попробуйте еще раз." << std::endl;
        return -1; // Возвращаем ошибку
    }

    // Вывод информации о выбранном автомобиле
    const auto& выбранныйАвто = автомобили[выбор2];
    выбранныйАвто.показатьИнформацию();
    return 0;
}

int plusMoney() {
    double money;
    std::cout << "Введите сумму, которую хотите положить на счет: ";

    while (true) {
        std::cin >> money;

        // Проверка на корректность ввода
        if (std::cin.fail() || money < 0) { // Проверяем, является ли ввод числом и не отрицательным
            std::cout << "Ошибка: введите положительное число!" << std::endl;
            std::cin.clear(); // Сбрасываем состояние потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем некорректный ввод
            std::cout << "Введите сумму, которую хотите положить на счет: ";
        }
        else {
            break; // Ввод корректен, выходим из цикла
        }
    }

    balance += money; // Добавляем сумму к балансу
    std::cout << "Баланс обновлен. Текущий баланс: $" << balance << std::endl;

    system("cls");
    return 0;
}

int main() {
    setlocale(LC_ALL, "RU");

    if (isActive != true) {
        init();
        isActive = true;
    }
    system("cls");
    int command;
    while (true) {
        std::cout << "Добро пожаловать в Caromobile! Введите нужную команду чтобы арендовать авто (Баланс: " << balance << " рублей)" << std::endl;
        std::cout << "1 - Арендовать авто" << std::endl;
        std::cout << "2 - Информация о авто" << std::endl;
        std::cout << "3 - Пополнить баланс" << std::endl;
        std::cout << "4 - Админ-панель" << std::endl;
        std::cout << "5 - Выйти" << std::endl;
        std::cin >> command;
        switch (command)
        {
            default:
                break;

            case 1:
                arenda();
                break;

            case 2:
                info();
                break;

            case 3:
                plusMoney();
                break;

            case 4:
                std::string password = "cppIsTopChik";
                std::string input;
                std::cout << "Введи пароль: ";
                std::cin >> input;
                if (input != password) {
                    std::cout << "Неверный пароль" << std::endl;
                    break;
                }
                else {
                    std::string com;
                    while (true) {
                        std::cout << "Админ-Панель Caromobile" << std::endl;
                        std::cout << "create - Добавить машину" << std::endl;
                        std::cout << "exit - выйти" << std::endl;
                        std::cin >> com;
                        if (com == "create") {
                            std::string brandInput;
                            std::string modelInput;
                            int yearInput;
                            std::string colourInput;
                            float sellInput;

                            std::cout << "Введи название бренда: ";
                            std::cin >> brandInput;

                            std::cout << "Введи название модели: ";
                            std::cin >> modelInput;

                            std::cout << "Введи год производства: ";
                            std::cin >> yearInput;

                            std::cout << "Введи цвет авто: ";
                            std::cin >> colourInput;

                            std::cout << "Введи цену(в сутки): ";
                            std::cin >> sellInput;

                            автомобили.push_back({ brandInput, modelInput, yearInput, colourInput, sellInput });
                        }
                        else if (com == "exit") {
                            main();
                        }
                        else {
                            std::cout << "Неизвестная команда!" << std::endl;
                        }
                        
                    }
                }

        }
    }

	return 0;
}
