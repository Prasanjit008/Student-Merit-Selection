#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

#define MAX_SEATS 60

struct Student {
    std::string name;
    int marks;
    
    // Comparator for sorting in ascending order of marks
    bool operator<(const Student& other) const {
        if (marks == other.marks) {
            return name < other.name; // Secondary sort by name if marks are the same
        }
        return marks < other.marks;
    }
};

class Stream {
private:
    std::multiset<Student> students; // Stores students in ascending order by default

public:
    void addStudent(const std::string& name, int marks) {
        students.insert({name, marks});
    }

    void displayMeritList(const std::string& streamName) const {
        std::cout << "\nMerit List for " << streamName << ":\n";
        int count = 0;
        for (const auto& student : students) {
            if (count >= MAX_SEATS) break; // Limit the output to MAX_SEATS
            std::cout << count + 1 << ". Name: " << student.name << ", Marks: " << student.marks << "\n";
            count++;
        }
    }
};

int main() {
    Stream scienceStream, commerceStream, artsStream;
    int choice;

    while (true) {
        std::cout << "\n--- Student Merit-Based Selection System ---\n";
        std::cout << "1. Apply for Science\n";
        std::cout << "2. Apply for Commerce\n";
        std::cout << "3. Apply for Arts\n";
        std::cout << "4. Display Merit Lists\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Exiting...\n";
            break;
        }

        std::string name;
        int marks;
        
        if (choice >= 1 && choice <= 3) {
            std::cout << "Enter student name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter marks: ";
            std::cin >> marks;
        }

        switch (choice) {
            case 1:
                scienceStream.addStudent(name, marks);
                std::cout << "Student added to Science stream.\n";
                break;
            case 2:
                commerceStream.addStudent(name, marks);
                std::cout << "Student added to Commerce stream.\n";
                break;
            case 3:
                artsStream.addStudent(name, marks);
                std::cout << "Student added to Arts stream.\n";
                break;
            case 4:
                scienceStream.displayMeritList("Science");
                commerceStream.displayMeritList("Commerce");
                artsStream.displayMeritList("Arts");
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
