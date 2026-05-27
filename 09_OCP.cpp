#include <iostream>
#include <vector>

using namespace std;

// Product class representing any item in eCommerce.

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

//1. ShoppingCart: Only responsible for Cart related business logic.
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

// 2. ShoppingCartPrinter: Only responsible for printing invoices
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

//Abstract class
class PersistenceDb {
private:
    ShoppingCart* cart;

public:
    virtual void save(ShoppingCart* cart) = 0; // Pure virtual function
};

class SQLPersistence : public PersistenceDb {
public:
    void save(ShoppingCart* cart) override {
        cout << "Saving shopping cart to SQL DB..." << endl;
    }
};

class MongoPersistence : public PersistenceDb {
public:
    void save(ShoppingCart* cart) override {
        cout << "Saving shopping cart to MongoDB..." << endl;
    }
};

class FilePersistence : public  PersistenceDb {
public:
    void save(ShoppingCart* cart) override {
        cout << "Saving shopping cart to a file..." << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 50000, 1));
    cart->addProduct(new Product("Mouse", 2000, 2));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printCartDetails();

    PersistenceDb* db = new SQLPersistence();
    PersistenceDb* mongo = new MongoPersistence();
    PersistenceDb* file = new FilePersistence();

    db->save(cart);   // Save to SQL database
    mongo->save(cart); // Save to MongoDB
    file->save(cart);  // Save to File

    return 0;
}