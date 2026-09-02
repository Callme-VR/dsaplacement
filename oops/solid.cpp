#include <iostream>
#include <string>

using namespace std;

// 1. Domain / Entity Model: Holds user data
class User {
public:
    string name;
    string email;

    User(string name, string email) : name(name), email(email) {}
};

// 2. Persistence Service: Handles saving user data
class UserService {
public:
    void saveUser(const User& user) {
        cout << "User " << user.name << " saved to database." << endl;
    }
};

// 3. Notification Service: Handles email logic
class EmailService {
public:
    void sendEmail(const User& user, const string& message) {
        cout << "Email sent to " << user.email << ": " << message << endl;
    }
};

// 4. Reporting Service: Handles report generation
class ReportService {
public:
    void generateReport(const User& user) {
        cout << "Report generated for " << user.name << endl;
    }
};

int main() {
    User user("Alice", "alice@example.com");

    UserService userService;
    EmailService emailService;
    ReportService reportService;

    userService.saveUser(user);
    emailService.sendEmail(user, "Welcome!");
    reportService.generateReport(user);

    return 0;
}