#include <iostream>
#include <string>

class Student {
protected:
    std::string name;
    int age;
    double averageGrade;

public:
    Student(const std::string& n, int a, double avg) : name(n), age(a), averageGrade(avg) {}

    void displayInfo() const {
        std::cout << "Name: " << name << "\nAge: " << age << "\nAverage Grade: " << averageGrade << std::endl;
    }
};

class Aspirant : public Student {
private:
    std::string thesisTopic;

public:
    Aspirant(const std::string& n, int a, double avg, const std::string& topic)
        : Student(n, a, avg), thesisTopic(topic) {}

    // Remove the 'override' keyword
    void displayInfo() const {
        Student::displayInfo();
        std::cout << "Thesis Topic: " << thesisTopic << std::endl;
    }
};

int main() {
    Student student("John Doe", 20, 85.5);
    std::cout << "Student Information:\n";
    student.displayInfo();
    std::cout << "\n";

    Aspirant aspirant("Jane Smith", 25, 88.0, "Research on Artificial Intelligence");
    std::cout << "Aspirant Information:\n";
    aspirant.displayInfo();

    return 0;
}
