#include <iostream>
#include <string>
#include <vector>

// Базовий клас Passport
class Passport {
protected:
    std::string fullName;
    std::string idNumber;
    std::string nationality;

public:
    // Конструктор класу Passport
    Passport(const std::string& name, const std::string& id, const std::string& nation)
        : fullName(name), idNumber(id), nationality(nation) {}

    // Метод для виведення інформації про паспорт
    void displayInfo() const {
        std::cout << "Full Name: " << fullName << "\nID Number: " << idNumber
            << "\nNationality: " << nationality << std::endl;
    }
};

// Похідний клас ForeignPassport, успадковує від класу Passport
class ForeignPassport : public Passport {
private:
    std::string passportNumber;
    std::vector<std::string> visas;

public:
    // Конструктор класу ForeignPassport
    ForeignPassport(const std::string& name, const std::string& id, const std::string& nation,
        const std::string& passportNum, const std::vector<std::string>& visaList)
        : Passport(name, id, nation), passportNumber(passportNum), visas(visaList) {}

    // Метод для виведення інформації про закордонний паспорт, розширює метод базового класу
    void displayInfo() const {
        Passport::displayInfo();  // Виклик методу базового класу
        std::cout << "Passport Number: " << passportNumber << "\nVisas:\n";
        for (const auto& visa : visas) {
            std::cout << "- " << visa << "\n";
        }
    }
};

int main() {
    // Створення об'єкта класу Passport
    Passport ukrainianPassport("John Doe", "123456789", "Ukrainian");

    // Виведення інформації про паспорт
    std::cout << "Ukrainian Passport Information:\n";
    ukrainianPassport.displayInfo();
    std::cout << "\n";

    // Створення об'єкта класу ForeignPassport
    ForeignPassport foreignPassport("Jane Smith", "987654321", "Canadian",
        "AB123456", { "USA", "UK", "France" });

    // Виведення інформації про закордонний паспорт
    std::cout << "Foreign Passport Information:\n";
    foreignPassport.displayInfo();

    return 0;
}
