#include <iostream>
#include <string>
#include <vector>

// ������� ���� Passport
class Passport {
protected:
    std::string fullName;
    std::string idNumber;
    std::string nationality;

public:
    // ����������� ����� Passport
    Passport(const std::string& name, const std::string& id, const std::string& nation)
        : fullName(name), idNumber(id), nationality(nation) {}

    // ����� ��� ��������� ���������� ��� �������
    void displayInfo() const {
        std::cout << "Full Name: " << fullName << "\nID Number: " << idNumber
            << "\nNationality: " << nationality << std::endl;
    }
};

// �������� ���� ForeignPassport, ��������� �� ����� Passport
class ForeignPassport : public Passport {
private:
    std::string passportNumber;
    std::vector<std::string> visas;

public:
    // ����������� ����� ForeignPassport
    ForeignPassport(const std::string& name, const std::string& id, const std::string& nation,
        const std::string& passportNum, const std::vector<std::string>& visaList)
        : Passport(name, id, nation), passportNumber(passportNum), visas(visaList) {}

    // ����� ��� ��������� ���������� ��� ����������� �������, �������� ����� �������� �����
    void displayInfo() const {
        Passport::displayInfo();  // ������ ������ �������� �����
        std::cout << "Passport Number: " << passportNumber << "\nVisas:\n";
        for (const auto& visa : visas) {
            std::cout << "- " << visa << "\n";
        }
    }
};

int main() {
    // ��������� ��'���� ����� Passport
    Passport ukrainianPassport("John Doe", "123456789", "Ukrainian");

    // ��������� ���������� ��� �������
    std::cout << "Ukrainian Passport Information:\n";
    ukrainianPassport.displayInfo();
    std::cout << "\n";

    // ��������� ��'���� ����� ForeignPassport
    ForeignPassport foreignPassport("Jane Smith", "987654321", "Canadian",
        "AB123456", { "USA", "UK", "France" });

    // ��������� ���������� ��� ����������� �������
    std::cout << "Foreign Passport Information:\n";
    foreignPassport.displayInfo();

    return 0;
}
