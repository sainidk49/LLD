#include <iostream>
using namespace std;

/*
    ISP (Interface Segregation Principle)

    Definition:
    Many small, specific interfaces are better than
    one large, general-purpose interface.

    A class should not be forced to implement methods
    it does not need.
*/

// Interface 1
class Workable {
public:
    virtual void work() = 0;
    virtual ~Workable() {}
};

// Interface 2
class Eatable {
public:
    virtual void eat() = 0;
    virtual ~Eatable() {}
};

// Interface 3
class Codable {
public:
    virtual void code() = 0;
    virtual ~Codable() {}
};

// Developer needs all three capabilities
class Developer : public Workable,
                  public Eatable,
                  public Codable {
public:
    void work() override {
        cout << "Developer is working" << endl;
    }

    void eat() override {
        cout << "Developer is eating" << endl;
    }

    void code() override {
        cout << "Developer is coding" << endl;
    }
};

// Robot only needs Workable and Codable
class Robot : public Workable,
              public Codable {
public:
    void work() override {
        cout << "Robot is working" << endl;
    }

    void code() override {
        cout << "Robot is coding" << endl;
    }
};

int main() {

    cout << "===== Developer =====" << endl;

    Developer dev;
    dev.work();
    dev.eat();
    dev.code();

    cout << endl;

    cout << "===== Robot =====" << endl;

    Robot robot;
    robot.work();
    robot.code();

    return 0;
}