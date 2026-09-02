#include <iostream>
#include <memory>
#include <vector>

// abstraction for shape
class DiscountStrategy
{
public:
    virtual ~DiscountStrategy() = default;
    virtual double applyDiscount(double amountprice) const = 0;
};
// concrete Strategy for percentage discount

class RegularDiscount : public DiscountStrategy
{
public:
    double applyDiscount(double amountprice) const override
    {
        return amountprice * 0.9; // 10% discount
    }
};

class premiumDiscount : public DiscountStrategy
{
public:
    double applyDiscount(double amountprice) const override
    {
        return amountprice * 0.15; // 85% of the original price
    }
};
class vipDiscount : public DiscountStrategy
{
public:
    double applyDiscount(double amountprice) const override
    {
        return amountprice * 0.25; // 75% of the original price
    }
};

class CheckoutService
{
public:
    // this method takes the amount and the discount strategy and returns the final price after applying the discount
    double getFinalPrice(double amount, const DiscountStrategy &strategy)
    {
        return amount - strategy.applyDiscount(amount);
    }
};

int main()
{
    CheckoutService checkoutService;
    double ordertotal = 1000.0;
    RegularDiscount regularDiscount;
    premiumDiscount premiumDiscount;
    vipDiscount vipDiscount;

    std::cout << "regural discount price: " << checkoutService.getFinalPrice(ordertotal, regularDiscount) << std::endl;
    std::cout << "premium discount price: " << checkoutService.getFinalPrice(ordertotal, premiumDiscount) << std::endl;
    std::cout << "vip discount price: " << checkoutService.getFinalPrice(ordertotal, vipDiscount) << std::endl;
}