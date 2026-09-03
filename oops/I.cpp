// I- stands for interface segregated

#include <iostream>

// Role specific interfaces
class IPrinter // Fixed capitalization to match modern naming conventions
{
public:
    virtual ~IPrinter() = default;
    virtual void print() = 0;
};

class IScanner
{
public:
    virtual ~IScanner() = default;
    virtual void scan() = 0;
};

class IFax // Renamed from Ifix to fit the office machine context (Faxing)
{
public:
    virtual ~IFax() = default;
    virtual void fax() = 0;
};

// SimplePrinter only implements what it needs
class SimplePrinter : public IPrinter // Fixed typo "lass" to "class"
{
public:
    void print() override {
        std::cout << "Printing document safely...\n";
    }
};

// Concrete class implementing multiple specific interfaces
class SuperJobMachine : public IPrinter, public IScanner, public IFax // Renamed to match main()
{
public:
    void print() override { std::cout << "Printing from super job machine\n"; }
    void scan() override { std::cout << "Scanning from super job machine\n"; }
    void fax() override { std::cout << "Faxing from super job machine\n"; }
};

int main()
{
    SimplePrinter budgetPrinter;
    budgetPrinter.print();
    // budgetPrinter.scan(); // Safe: This line won't even compile now!

    SuperJobMachine officeHeavyweight;
    officeHeavyweight.print();
    officeHeavyweight.scan();
    officeHeavyweight.fax();
    return 0;
}
