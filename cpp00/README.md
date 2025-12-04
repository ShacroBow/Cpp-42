# CPP Module 00 - Study Guide & Evaluation Prep

## Overview
This module introduces C++ basics: namespaces, classes, member functions, stdio streams, initialization lists, static, const, and more.

---

# C++ Fundamentals & OOP Concepts

This section explains C++ and Object-Oriented Programming for someone who knows programming but not C++.

## C++ vs C: The Key Differences

| Feature | C | C++ |
|---------|---|-----|
| Paradigm | Procedural | Multi-paradigm (procedural + OOP) |
| I/O | `printf`, `scanf` | `std::cout`, `std::cin` (streams) |
| Memory | `malloc`/`free` | `new`/`delete` (+ constructors/destructors) |
| Strings | `char[]`, `char*` | `std::string` class |
| Data grouping | `struct` (data only) | `class` (data + methods + access control) |
| Function overloading | ❌ No | ✅ Yes |
| References | ❌ No (only pointers) | ✅ Yes (`int &ref`) |
| Namespaces | ❌ No | ✅ Yes (`std::`) |

## What is OOP?

**Object-Oriented Programming** organizes code around "objects" that combine:
- **Data** (attributes/members)
- **Behavior** (methods/functions)

### The 4 Pillars of OOP

#### 1. Encapsulation
**Hide internal details, expose only what's needed.**

```cpp
class BankAccount {
private:
    int _balance;  // Hidden - can't be modified directly

public:
    void deposit(int amount) {
        if (amount > 0)          // Validation!
            _balance += amount;
    }
    int getBalance() { return _balance; }
};

// Usage:
BankAccount acc;
acc._balance = -1000;      // ❌ Compile error! Private.
acc.deposit(100);          // ✅ Goes through validation
```

**Why?** Prevents invalid states. You can't set balance to -1000 directly.

#### 2. Abstraction
**Show only essential features, hide complexity.**

```cpp
// User doesn't need to know HOW timestamp is calculated
void Account::_displayTimestamp(void)  // Private helper
{
    // Complex time formatting logic hidden here
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();  // Just call it, don't care how it works
    // ...
}
```

#### 3. Inheritance (covered in later modules)
**Create new classes based on existing ones.**

```cpp
class Animal {
public:
    void eat() { std::cout << "Eating" << std::endl; }
};

class Dog : public Animal {  // Dog "is-a" Animal
public:
    void bark() { std::cout << "Woof!" << std::endl; }
};

Dog d;
d.eat();   // Inherited from Animal
d.bark();  // Dog's own method
```

#### 4. Polymorphism (covered in later modules)
**Same interface, different behavior.**

```cpp
class Shape {
public:
    virtual double area() = 0;  // Pure virtual - must be implemented
};

class Circle : public Shape {
    double _radius;
public:
    double area() { return 3.14159 * _radius * _radius; }
};

class Square : public Shape {
    double _side;
public:
    double area() { return _side * _side; }
};

// Same function call, different behavior
Shape* s1 = new Circle();
Shape* s2 = new Square();
s1->area();  // Calls Circle::area()
s2->area();  // Calls Square::area()
```

---

## C++ Class Anatomy

```cpp
class MyClass {
private:                    // Access specifier
    int _data;              // Member variable (attribute)
    void _helper();         // Private method

public:
    MyClass();              // Constructor (same name as class)
    MyClass(int val);       // Overloaded constructor
    ~MyClass();             // Destructor (~ + class name)

    void doSomething();     // Member function (method)
    int getData() const;    // Const method (won't modify object)

    static int count;       // Static member (shared by all instances)
    static int getCount();  // Static method (no 'this' pointer)
};
```

### Access Specifiers

| Specifier | Accessible From |
|-----------|-----------------|
| `private` | Only inside the class |
| `public` | Anywhere |
| `protected` | Inside class + derived classes |

**Default:** `class` = private, `struct` = public

---

## Constructors & Destructors

### Constructor
**Called automatically when object is created.**

```cpp
class Contact {
private:
    std::string _name;
    int _age;

public:
    // Default constructor (no parameters)
    Contact() {
        _name = "";
        _age = 0;
    }

    // Parameterized constructor
    Contact(std::string name, int age) {
        _name = name;
        _age = age;
    }

    // Initialization list (preferred, more efficient)
    Contact(std::string name, int age) : _name(name), _age(age) {}
};

// Usage:
Contact c1;                    // Calls default constructor
Contact c2("John", 25);        // Calls parameterized constructor
Contact c3 = Contact("Jane", 30);  // Same as c2
```

### Destructor
**Called automatically when object is destroyed (goes out of scope or deleted).**

```cpp
class FileHandler {
private:
    FILE* _file;

public:
    FileHandler(const char* path) {
        _file = fopen(path, "r");  // Open file
    }

    ~FileHandler() {
        if (_file)
            fclose(_file);  // Cleanup! Close file automatically
    }
};

void process() {
    FileHandler fh("data.txt");  // Constructor opens file
    // ... use file ...
}  // Destructor called here, file closed automatically
```

**This is RAII (Resource Acquisition Is Initialization)** - C++ idiom where resources are tied to object lifetime.

---

## Static Members

### Static Variables
**Shared by ALL instances of the class. Only one copy exists.**

```cpp
class Account {
private:
    static int _nbAccounts;    // Declaration
    int _accountIndex;

public:
    Account() {
        _accountIndex = _nbAccounts;  // Each account gets unique index
        _nbAccounts++;                 // Increment shared counter
    }
};

// MUST initialize outside class (in .cpp file)
int Account::_nbAccounts = 0;

// Usage:
Account a1;  // _accountIndex = 0, _nbAccounts becomes 1
Account a2;  // _accountIndex = 1, _nbAccounts becomes 2
Account a3;  // _accountIndex = 2, _nbAccounts becomes 3
```

### Static Methods
**Can be called without an object. No `this` pointer.**

```cpp
class Account {
    static int _nbAccounts;
public:
    static int getNbAccounts() {
        return _nbAccounts;  // Can only access static members
    }
};

// Call without object:
int count = Account::getNbAccounts();
```

---

## The `this` Pointer

**Implicit pointer to the current object.**

```cpp
class Person {
    std::string _name;

public:
    void setName(std::string name) {
        this->_name = name;  // 'this' refers to current object
        // Same as: _name = name;
    }

    Person& setAge(int age) {
        this->_age = age;
        return *this;  // Return reference to self (for chaining)
    }
};

// Method chaining:
Person p;
p.setName("John").setAge(25);  // Works because setAge returns *this
```

---

## `const` Correctness

### Const Member Functions
**Promise not to modify the object.**

```cpp
class Contact {
    std::string _name;

public:
    // Non-const: CAN modify
    void setName(std::string n) { _name = n; }

    // Const: CANNOT modify (note 'const' after parentheses)
    std::string getName() const { return _name; }
};

void printContact(const Contact& c) {
    std::cout << c.getName();  // ✅ OK - getName is const
    c.setName("X");            // ❌ Error! Can't call non-const on const object
}
```

**Rule:** If a method doesn't modify the object, mark it `const`.

---

## References vs Pointers

| Feature | Pointer | Reference |
|---------|---------|-----------|
| Syntax | `int* p` | `int& r` |
| Can be null | Yes | No |
| Can be reassigned | Yes | No |
| Indirection | `*p` to access | Direct access |
| Address-of | `&var` to get pointer | N/A |

```cpp
int x = 10;

// Pointer
int* ptr = &x;
*ptr = 20;       // x is now 20

// Reference
int& ref = x;
ref = 30;        // x is now 30 (no * needed)

// Reference MUST be initialized
int& bad;        // ❌ Compile error!
```

### Pass by Reference (avoid copying)
```cpp
// Bad: copies entire string
void print(std::string s) { std::cout << s; }

// Good: no copy, just reference
void print(const std::string& s) { std::cout << s; }
```

---

## Namespaces

**Prevent name collisions.**

```cpp
namespace MyLib {
    void print() { std::cout << "MyLib print" << std::endl; }
}

namespace OtherLib {
    void print() { std::cout << "OtherLib print" << std::endl; }
}

int main() {
    MyLib::print();      // Calls MyLib version
    OtherLib::print();   // Calls OtherLib version
}
```

### The `std` Namespace
All standard library components are in `std`:
```cpp
std::cout    // Output stream
std::cin     // Input stream
std::string  // String class
std::endl    // Newline + flush
std::setw    // Set width (from <iomanip>)
```

**Avoid `using namespace std;`** - pollutes global namespace, can cause conflicts.

---

## C++ I/O Streams

### Output: `std::cout`
```cpp
#include <iostream>

std::cout << "Hello";              // Print string
std::cout << 42;                   // Print int
std::cout << 3.14;                 // Print double
std::cout << "A" << "B" << "C";    // Chain multiple outputs
std::cout << std::endl;            // Newline + flush buffer
std::cout << "\n";                 // Just newline (faster)
```

### Input: `std::cin`
```cpp
int num;
std::cin >> num;          // Read int (stops at whitespace)

std::string word;
std::cin >> word;         // Reads ONE word

std::string line;
std::getline(std::cin, line);  // Reads ENTIRE line
```

### Formatting with `<iomanip>`
```cpp
#include <iomanip>

std::cout << std::setw(10) << "Hi";       // "        Hi" (right-aligned)
std::cout << std::setfill('0') << std::setw(4) << 42;  // "0042"
std::cout << std::left << std::setw(10) << "Hi";       // "Hi        "
```

---

## Memory: Stack vs Heap

### Stack (automatic)
```cpp
void func() {
    int x = 10;        // Stack - automatic cleanup
    Contact c;         // Stack - destructor called at }
}  // x and c destroyed here
```

### Heap (manual)
```cpp
void func() {
    int* p = new int(10);     // Heap allocation
    Contact* c = new Contact; // Heap allocation

    // MUST manually free:
    delete p;
    delete c;
}
// If you forget delete → memory leak!
```

**42 Rule:** Many exercises forbid `new`/`delete` to teach stack-based RAII.

---

## Common Evaluation Questions About OOP

**Q: What's the difference between a class and an object?**
A: Class is a blueprint (like `Contact`). Object is an instance of that blueprint (like `Contact c1, c2, c3;`).

**Q: What's encapsulation?**
A: Bundling data with methods that operate on it, and restricting direct access (private members + public getters/setters).

**Q: Why use getters/setters instead of public variables?**
A: Validation, computed values, debugging hooks, future-proofing (can change internal representation without breaking API).

**Q: What happens if you don't write a constructor?**
A: Compiler generates a default one that does nothing (members uninitialized for basic types).

**Q: When is a destructor called?**
A: When object goes out of scope (stack), or when `delete` is called (heap).

**Q: What's the difference between `struct` and `class` in C++?**
A: Only default access: `struct` = public, `class` = private. Otherwise identical.

---

# ex01 - PhoneBook

## What It Does
A simple phonebook that stores up to **8 contacts** in memory. No dynamic allocation allowed.

## Key Concepts You Must Understand

### 1. Classes vs Structs
```cpp
class Contact {
private:          // Only accessible inside the class
    std::string _firstName;
public:           // Accessible from anywhere
    void setFirstName(std::string str);
};
```
**Evaluator might ask:** "Why use private members?"
**Answer:** Encapsulation - hide internal data, control access through getters/setters, prevent invalid states.

### 2. The Circular Buffer (Oldest Replacement)
```cpp
_contacts[_oldest] = newContact;  // Store at oldest position
_oldest = (_oldest + 1) % 8;      // Move to next slot (wraps 7→0)
if (_count < 8) _count++;         // Only increment until full
```
**Evaluator might ask:** "What happens when you add a 9th contact?"
**Answer:** It replaces the 1st (oldest) contact. Index 0 now contains the 9th contact, indices 1-7 contain contacts 2-8.

### 3. std::setw() for Column Formatting
```cpp
#include <iomanip>
std::cout << std::setw(10) << "text";  // Right-aligns in 10-char width
```
**Evaluator might ask:** "Why use setw?"
**Answer:** Subject requires columns of exactly 10 characters, right-aligned.

### 4. Truncation Logic
```cpp
if (str.length() > 10)
    return (str.substr(0, 9) + ".");  // 9 chars + dot = 10 chars
return (str);
```
**Evaluator might ask:** "How do you handle long names?"
**Answer:** Truncate to 9 characters and add a dot, so it fits in 10-char column.

### 5. std::getline() vs std::cin >>
```cpp
std::getline(std::cin, str);  // Reads entire line including spaces
std::cin >> str;              // Stops at whitespace
```
**Evaluator might ask:** "Why use getline?"
**Answer:** Names can have spaces. `cin >>` would only read "John" from "John Doe".

### 6. Empty Field Validation
```cpp
if (!std::getline(std::cin, in) || in.empty())
```
- `!std::getline()` catches EOF (Ctrl+D)
- `in.empty()` catches user pressing Enter without typing

## Files Structure
| File | Purpose |
|------|---------|
| `Contact.hpp` | Contact class declaration (5 private fields, getters/setters) |
| `Contact.cpp` | Contact class implementation |
| `phonebook.cpp` | PhoneBook class + main() |

## Commands
| Command | What It Does |
|---------|--------------|
| `ADD` | Prompt for 5 fields, store contact |
| `SEARCH` | Display table, prompt for index, show details |
| `EXIT` | Quit program |

## Common Evaluation Questions

**Q: Why not use `new` or `malloc`?**
A: Subject forbids dynamic allocation. Fixed array of 8 contacts.

**Q: What if user enters "add" lowercase?**
A: It won't work - we compare `cmd == "ADD"` exactly. Subject doesn't require case-insensitive.

**Q: What's `const` after a function?**
A: `void searchContacts(void) const` - promises not to modify member variables.

---

# ex02 - Account

## What It Does
Implement `Account.cpp` to match the provided `Account.hpp` header. Your output must match the log file format exactly.

## Key Concepts You Must Understand

### 1. Static Members
```cpp
// Declaration in header
static int _nbAccounts;
static int _totalAmount;

// MUST initialize in .cpp file (only once!)
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
```
**Evaluator might ask:** "What are static members?"
**Answer:** Shared across ALL instances of the class. There's only one `_nbAccounts` for all Account objects, not one per object.

**Evaluator might ask:** "Why initialize in .cpp?"
**Answer:** Static members need storage allocated once. Header could be included multiple times → multiple definitions → linker error.

### 2. Static vs Non-Static Functions
```cpp
static int getNbAccounts(void);     // Can be called without object: Account::getNbAccounts()
int checkAmount(void) const;        // Needs object: myAccount.checkAmount()
```
**Evaluator might ask:** "Why is displayAccountsInfos static?"
**Answer:** It displays info about ALL accounts (using static counters), not a specific account.

### 3. Constructor Order
When you create an Account:
```cpp
Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;   // 1. Get current count as index (0, 1, 2...)
    _nbAccounts++;                  // 2. Increment total count
    _amount = initial_deposit;      // 3. Set initial balance
    _nbDeposits = 0;                // 4. Zero deposits/withdrawals
    _nbWithdrawals = 0;
    _totalAmount += initial_deposit; // 5. Add to global total
    // 6. Print creation message
}
```

### 4. Timestamp Format
```cpp
void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);      // Get current time
    std::tm *t = std::localtime(&now);       // Convert to local time struct

    std::cout << "[" << std::setfill('0')    // Pad with zeros
              << std::setw(4) << t->tm_year + 1900  // Year (1900-based)
              << std::setw(2) << t->tm_mon + 1      // Month (0-based, so +1)
              << std::setw(2) << t->tm_mday         // Day
              << "_"
              << std::setw(2) << t->tm_hour
              << std::setw(2) << t->tm_min
              << std::setw(2) << t->tm_sec
              << "]";
}
```
Output: `[20251204_153045]`

**Evaluator might ask:** "Why +1900 for year?"
**Answer:** `tm_year` is years since 1900, so 2025 is stored as 125.

### 5. Withdrawal Logic
```cpp
bool Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > _amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);  // Can't withdraw more than balance
    }
    // ... do withdrawal ...
    return (true);
}
```
**Evaluator might ask:** "What happens if withdrawal > balance?"
**Answer:** Print "refused", return false, don't change any values.

### 6. Output Format (MUST MATCH EXACTLY)
```
[TIMESTAMP] index:0;amount:42;created
[TIMESTAMP] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
[TIMESTAMP] index:0;p_amount:47;withdrawal:refused
[TIMESTAMP] index:0;amount:47;closed
```
- Space after `]`
- Semicolons between fields
- No spaces around `:` or `;`

## The tests.cpp Flow
```cpp
// 1. Create 8 accounts with initial deposits
accounts_t accounts(amounts, amounts + amounts_size);

// 2. Display all accounts info
Account::displayAccountsInfos();

// 3. Display each account's status
std::for_each(acc_begin, acc_end, &Account::displayStatus);

// 4. Make deposits
(*(it.first)).makeDeposit(*(it.second));

// 5. Make withdrawals (some will be refused)
(*(it.first)).makeWithdrawal(*(it.second));

// 6. Destructor called for each account when vector goes out of scope
```

## Common Evaluation Questions

**Q: What's the difference between `_amount` and `_totalAmount`?**
A: `_amount` is THIS account's balance. `_totalAmount` is sum of ALL accounts' balances (static).

**Q: Why is `_displayTimestamp` private?**
A: It's a helper function only used internally by other member functions.

**Q: How do you verify your output is correct?**
A: Compare against the provided log file (ignoring timestamps):
```bash
./accounts | sed 's/\[[0-9_]*\]/[TS]/g' > my_out.txt
sed 's/\[[0-9_]*\]/[TS]/g' ../19920104_091532.log > expected.txt
diff expected.txt my_out.txt  # Should show nothing
```

---

# Quick Reference: C++ Concepts

| Concept | Example | Meaning |
|---------|---------|---------|
| `private:` | `std::string _name;` | Only class can access |
| `public:` | `void setName(std::string);` | Anyone can call |
| `static` member | `static int _count;` | Shared by all objects |
| `static` function | `static int getCount();` | No `this`, call via `Class::func()` |
| `const` function | `int getValue() const;` | Won't modify object |
| `std::setw(n)` | `std::setw(10)` | Next output padded to n chars |
| `std::setfill(c)` | `std::setfill('0')` | Pad with character c |

---

# Build & Test Commands

```bash
# ex01
cd ex01 && make re && ./phonebook

# ex02
cd ex02 && make re && ./accounts

# Validate ex02 output
./accounts 2>&1 | sed 's/\[[0-9_]*\]/[TS]/g' > /tmp/my.txt
sed 's/\[[0-9_]*\]/[TS]/g' ../19920104_091532.log > /tmp/exp.txt
diff /tmp/exp.txt /tmp/my.txt && echo "PASS"
```

---

# Checklist Before Evaluation

## ex01
- [ ] Compiles with `-Wall -Wextra -Werror -std=c++98`
- [ ] ADD prompts for all 5 fields
- [ ] Empty field shows error, doesn't save contact
- [ ] SEARCH shows formatted table (10-char columns)
- [ ] Long names truncated with dot
- [ ] Invalid index shows error
- [ ] 9th contact replaces 1st (oldest)
- [ ] EXIT and Ctrl+D exit cleanly

## ex02
- [ ] Compiles with `-Wall -Wextra -Werror -std=c++98`
- [ ] Static members initialized in .cpp
- [ ] Output matches log file exactly
- [ ] Withdrawal refused when amount > balance
- [ ] Timestamp format correct `[YYYYMMDD_HHMMSS]`
