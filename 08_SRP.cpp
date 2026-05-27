#include <iostream>
#include <vector>
using namespace std;

//------------ Product class representing a item in eCommerce -------------

class Product
{
public:
    string name;
    double price;
    int quantity;

    Product(string name, double price, int quantity)
    {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }
};

// 1. ShoppingCart: Only ressponsible for Cart related bussiness logic

class ShoppingCart
{
private:
    vector<Product *> products; // store products in cart/ store heap allocated products

public:
    // setters and getters for products
    void addProduct(Product *product)
    {
        products.push_back(product);
    }

    const vector<Product *> &getProducts() const
    {
        return products;
    }

    double calculateTotalPrice()
    {
        double totalPrice = 0.0;
        for (const auto &product : products)
        {
            totalPrice += product->price * product->quantity;
        }
        return totalPrice;
    }
};

// 2. ShoppingCartPrinter: Only ressponsible for printing the cart details 
class ShoppingCartPrinter
{
    private :
    ShoppingCart *cart; // reference to shopping cart

    public :
    ShoppingCartPrinter(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    void printCartDetails()
    {
        cout << "Cart Details:" << endl;
        for (const auto &product : cart->getProducts())
        {
            cout << "Product: " << product->name << ", Price: " << product->price << ", Quantity: " << product->quantity << endl;
        }
        cout << "Total Price: " << cart->calculateTotalPrice() << endl; 
    }
};

int main()
{
    // Create some products
    Product *product1 = new Product("Laptop", 1000.0, 1);
    Product *product2 = new Product("Phone", 500.0, 10);

    // Create a shopping cart and add products to it
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(product1);
    cart->addProduct(product2);

    // Create a printer for the shopping cart and print details
    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printCartDetails();

    // Clean up memory
    delete product1;
    delete product2;
    delete cart;
    delete printer;

    return 0;
};