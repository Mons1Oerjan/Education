#include "Database.h"

/*
 * Constructor that initializes the DB and creates a manager
 */
Database::Database() {
    this->manager = new User("manager", "iamtheboss", 1, true);
    this->manager->setFirstName("manager");
    this->manager->setLastName("manager");
    Database::addUser(this->manager);
}

/*
 * Destructor
 */
Database::~Database() {

}

/*
 * Logs in the user if the username and password match a user in the DB
 */
User* Database::login(string username, string password) {
    User* u = Database::findUserByUsername(username);

    if (u != nullptr) {
        if (u->getPassword() == password) {
            cout << "Login successful." << endl;
            return u;
        }
    }

    cout << "Login failed." << endl;
    return nullptr;
}

/*
 * Retrieve a pointer to the manager
 */
User* Database::getManager() {
    return this->manager;
}

/*
 * Add a user to the DB and update all unordered maps
 */
void Database::addUser(User* u) {
    bool shouldResetMap = false;
    int id = u->getId();

    if (this->users.find(id) != this->users.end()) {
        cout << "Error: Can't add user. User already exist in the DB." << endl;
    } else {
        this->users[id] = u;
        Database::updateFirstNameMap(shouldResetMap);
        Database::updateLastNameMap(shouldResetMap);
        Database::updateCityMap(shouldResetMap);
        Database::updatePostalCodeMap(shouldResetMap);
        Database::updateCountryMap(shouldResetMap);
    }
}

/*
 * Remove a specific user and update all unordered maps
 */
void Database::removeUser(User* u) {
    bool shouldResetMap = true;
    this->users.erase(u->getId());
    Database::updateFirstNameMap(shouldResetMap);
    Database::updateLastNameMap(shouldResetMap);
    Database::updateCityMap(shouldResetMap);
    Database::updatePostalCodeMap(shouldResetMap);
    Database::updateCountryMap(shouldResetMap);
}

/*
 * Remove a specific user by the user ID and update all unordered maps
 */
void Database::removeUserById(int id) {
    bool shouldResetMap = true;

    if (this->users.find(id) == this->users.end()) {
        cout << "Error: Can't remove user. User does not exist in the DB." << endl;
    } else {
        this->users.erase(id);
        Database::updateFirstNameMap(shouldResetMap);
        Database::updateLastNameMap(shouldResetMap);
    }
}

/*
 * Find a single user by the user ID
 */
User* Database::findUserById(int id) {
    if (this->users.find(id) == this->users.end()) {
        return nullptr;
    }

    return this->users[id];
}

/*
 * Find a single user by the UserName
 */
User* Database::findUserByUsername(string username) {
    for (map<int, User*>::iterator it = this->users.begin(); it != this->users.end(); ++it) {
        User* u = (*it).second;

        if (u->getUserName() == username) {
            return u;
        }
    }

    return nullptr;
}

/**
 * Returns the user with the largest balance
 */
User* Database::findRichest() {
    User* richest = (*this->users.begin()).second;

    if (richest->isManager()) {
        richest = (*(++this->users.begin())).second;
    }

    for (map<int, User*>::iterator it = this->users.begin(); it != this->users.end(); ++it) {
        User* u = (*it).second;

        if (u->isManager()) {
            continue;
        }

        if (u->getBalance() > richest->getBalance()) {
            richest = u;
        }
    }

    return richest;
}

/**
 * Returns the user with the smallest balance
 */
User* Database::findPoorest() {
    User* poorest = (*this->users.begin()).second;

    if (poorest->isManager()) {
        poorest = (*(++this->users.begin())).second;
    }

    for (map<int, User*>::iterator it = this->users.begin(); it != this->users.end(); ++it) {
        User* u = (*it).second;

        if (u->isManager()) {
            continue;
        }

        if (u->getBalance() < poorest->getBalance()) {
            poorest = u;
        }
    }

    return poorest;
}

/*
 * Find all users by a given first name in O(1) time
 */
vector<User*> Database::findUsersByFirstName(string name) {
    vector<User*> usersFound;

    if (this->firstNameMap.find(name) != this->firstNameMap.end()) {
        vector<int> ids = this->firstNameMap[name];

        for (vector<int>::iterator it = ids.begin(); it != ids.end(); ++it) {
            usersFound.push_back(Database::findUserById((*it)));
        }
    }

    return usersFound;
}

/*
 * Find all users by a given last name in O(1) time
 */
vector<User*> Database::findUsersByLastName(string name) {
    vector<User*> usersFound;

    if (this->lastNameMap.find(name) != this->lastNameMap.end()) {
        vector<int> ids = this->lastNameMap[name];

        for (vector<int>::iterator it = ids.begin(); it != ids.end(); ++it) {
            usersFound.push_back(Database::findUserById((*it)));
        }
    }

    return usersFound;
}

/*
 * Find all users by a given city in O(1) time
 */
vector<User*> Database::findUsersByCity(string input) {
    vector<User*> usersFound;

    if (this->cityMap.find(input) != this->cityMap.end()) {
        vector<int> ids = this->cityMap[input];

        for (vector<int>::iterator it = ids.begin(); it != ids.end(); ++it) {
            usersFound.push_back(Database::findUserById((*it)));
        }
    }

    return usersFound;
}

/*
 * Find all users by a given postalCode in O(1) time
 */
vector<User*> Database::findUsersByPostalCode(string input) {
    vector<User*> usersFound;

    if (this->postalCodeMap.find(input) != this->postalCodeMap.end()) {
        vector<int> ids = this->postalCodeMap[input];

        for (vector<int>::iterator it = ids.begin(); it != ids.end(); ++it) {
            usersFound.push_back(Database::findUserById((*it)));
        }
    }

    return usersFound;
}

/*
 * Find all users by a given postalCode in O(1) time
 */
vector<User*> Database::findUsersByCountry(string input) {
    vector<User*> usersFound;

    if (this->countryMap.find(input) != this->countryMap.end()) {
        vector<int> ids = this->countryMap[input];

        for (vector<int>::iterator it = ids.begin(); it != ids.end(); ++it) {
            usersFound.push_back(Database::findUserById((*it)));
        }
    }

    return usersFound;
}

/*
 * Returns a map of all users where the key is the userId
 */
map<int, User*> Database::findAllUsers() {
    return this->users;
}

/*
 * Function that prints all users, excluding the manager, in the database
 */
void Database::printAllCustomers() {
    for (map<int, User*>::iterator it = this->users.begin(); it != this->users.end(); ++it) {
        User* u = (*it).second;
        if (u->isManager() == false) {
            u->print();
        }
    }
}

/*
 * Function that prints all users, including the manager, in the database
 */
void Database::printAllUsers() {
    for (map<int, User*>::iterator it = this->users.begin(); it != this->users.end(); ++it) {
        User* u = (*it).second;
        u->print();
    }
}

/*
 * Update an unordered map to hash user's first names for O(1) lookup time
 */
void Database::updateFirstNameMap(bool reset) {
    if (reset == true) {
        // reset the map if a user was removed from the DB
        this->firstNameMap.clear();
    }

    for (map<int, User*>::iterator it = this->users.begin(); it != this->users.end(); ++it) {
        User* u = (*it).second;
        string firstname = u->getFirstName();
        int id = u->getId();

        if (this->firstNameMap.find(firstname) == this->firstNameMap.end()) {
            // firstname not found in the map. create a new entry:
            vector<int> ids;
            ids.push_back(id);
            this->firstNameMap.insert(make_pair(firstname, ids));
        } else {
            // firstname exists in the map. Add to the existing entry:
            vector<int> lastNameIds = this->firstNameMap[firstname];

            if (find(lastNameIds.begin(), lastNameIds.end(), id) != lastNameIds.end()) {
                // id not found in the vector. Add the id:
                this->firstNameMap[firstname].push_back(id);
            }
        }
    }
}

/*
 * Update an unordered map to hash user's last names for O(1) lookup time
 */
void Database::updateLastNameMap(bool reset) {
    if (reset == true) {
        // reset the map if a user was removed from the DB
        this->lastNameMap.clear();
    }

    for (map<int, User*>::iterator it = this->users.begin(); it != this->users.end(); ++it) {
        User* u = (*it).second;
        string lastname = u->getLastName();
        int id = u->getId();

        if (this->lastNameMap.find(lastname) == this->lastNameMap.end()) {
            // lastname not found in the map. create a new entry:
            vector<int> ids;
            ids.push_back(id);
            this->lastNameMap[lastname] = ids;
        } else {
            // lastname exists in the map. Add to the existing entry:
            vector<int> lastNameIds = this->lastNameMap[lastname];

            if (find(lastNameIds.begin(), lastNameIds.end(), id) == lastNameIds.end()) {
                // id not found in the vector. Add the id:
                this->lastNameMap[lastname].push_back(id);
            }
        }
    }
}

/*
 * Update an unordered map to hash user's cities for O(1) lookup time
 */
void Database::updateCityMap(bool reset) {
    if (reset == true) {
        // reset the map if a user was removed from the DB
        this->cityMap.clear();
    }

    for (map<int, User*>::iterator it = this->users.begin(); it != this->users.end(); ++it) {
        User* u = (*it).second;
        string city = u->getCity();
        int id = u->getId();

        if (this->cityMap.find(city) == this->cityMap.end()) {
            // city not found in the map. create a new entry:
            vector<int> ids;
            ids.push_back(id);
            this->cityMap[city] = ids;
        } else {
            // city exists in the map. Add to the existing entry:
            vector<int> ids = this->cityMap[city];

            if (find(ids.begin(), ids.end(), id) == ids.end()) {
                // id not found in the vector. Add the id:
                this->cityMap[city].push_back(id);
            }
        }
    }
}

/*
 * Update an unordered map to hash user's postalCode for O(1) lookup time
 */
void Database::updatePostalCodeMap(bool reset) {
    if (reset == true) {
        // reset the map if a user was removed from the DB
        this->postalCodeMap.clear();
    }

    for (map<int, User*>::iterator it = this->users.begin(); it != this->users.end(); ++it) {
        User* u = (*it).second;
        string postalCode = u->getPostalCode();
        int id = u->getId();

        if (this->postalCodeMap.find(postalCode) == this->postalCodeMap.end()) {
            // postalCode not found in the map. create a new entry:
            vector<int> ids;
            ids.push_back(id);
            this->postalCodeMap[postalCode] = ids;
        } else {
            // postalCode exists in the map. Add to the existing entry:
            vector<int> ids = this->postalCodeMap[postalCode];

            if (find(ids.begin(), ids.end(), id) == ids.end()) {
                // id not found in the vector. Add the id:
                this->postalCodeMap[postalCode].push_back(id);
            }
        }
    }
}

/*
 * Update an unordered map to hash user's country for O(1) lookup time
 */
void Database::updateCountryMap(bool reset) {
    if (reset == true) {
        // reset the map if a user was removed from the DB
        this->countryMap.clear();
    }

    for (map<int, User*>::iterator it = this->users.begin(); it != this->users.end(); ++it) {
        User* u = (*it).second;
        string country = u->getCountry();
        int id = u->getId();

        if (this->countryMap.find(country) == this->countryMap.end()) {
            // country not found in the map. create a new entry:
            vector<int> ids;
            ids.push_back(id);
            this->countryMap[country] = ids;
        } else {
            // country exists in the map. Add to the existing entry:
            vector<int> ids = this->countryMap[country];

            if (find(ids.begin(), ids.end(), id) == ids.end()) {
                // id not found in the vector. Add the id:
                this->countryMap[country].push_back(id);
            }
        }
    }
}

void Database::seed() {
    cout << "----------- Seeding the Database with 10 users: -----------" << endl;

    User* u1 = new User("James", "password", 2);
    User* u2 = new User("Joe", "password", 3);
    User* u3 = new User("John", "password", 4);
    User* u4 = new User("Alex", "password", 5);
    User* u5 = new User("Mackenzie", "password", 6);
    User* u6 = new User("Sam", "password", 7);
    User* u7 = new User("Jane", "password", 8);
    User* u8 = new User("Sage", "password", 9);
    User* u9 = new User("Paige", "password", 10);
    User* u10 = new User("Marie", "password", 11);

    u1->setFirstName("James");
    u1->setLastName("Dunn");
    u1->setAddress("7654 Random Street");
    u1->setCity("Halifax");
    u1->setPostalCode("B3H3S4");
    u1->setCountry("Canada");
    u1->setBalance(1000);
    u1->setPhoneNumber(9029894568);
    u1->setPassportNumber("Pass123Num456");

    u2->setFirstName("Joe");
    u2->setLastName("Dunn");
    u2->setAddress("4532 Harvey Street");
    u2->setCity("Halifax");
    u2->setPostalCode("B5F3S8");
    u2->setCountry("Canada");
    u2->setBalance(2000);
    u2->setPhoneNumber(1231231234);
    u2->setPassportNumber("Pass123Foo456");

    u3->setFirstName("John");
    u3->setLastName("Smith");
    u3->setAddress("4321 Bird Street");
    u3->setCity("Halifax");
    u3->setPostalCode("B8V5C3");
    u3->setCountry("Canada");
    u3->setBalance(1500);
    u3->setPhoneNumber(1234123123);
    u3->setPassportNumber("Pass456Foo456");

    u4->setFirstName("Alex");
    u4->setLastName("Smith");
    u4->setAddress("2222 Water Street");
    u4->setCity("Halifax");
    u4->setPostalCode("B6B5S2");
    u4->setCountry("Canada");
    u4->setBalance(5000);
    u4->setPhoneNumber(8767656543);
    u4->setPassportNumber("Pas456Foo654");

    u5->setFirstName("Mackenzie");
    u5->setLastName("Rogers");
    u5->setAddress("3232 Rock Street");
    u5->setCity("Halifax");
    u5->setPostalCode("B6B5S2");
    u5->setCountry("Canada");
    u5->setBalance(10345);
    u5->setPhoneNumber(7897897897);
    u5->setPassportNumber("Pas987Foo890");

    u6->setFirstName("Sam");
    u6->setLastName("Thorsen");
    u6->setAddress("789 Nice Street");
    u6->setCity("Reykjavik");
    u6->setPostalCode("J8K3F5");
    u6->setCountry("Iceland");
    u6->setBalance(14);
    u6->setPhoneNumber(5435675980);
    u6->setPassportNumber("Pass555Foo876");

    u7->setFirstName("Jane");
    u7->setLastName("Doe");
    u7->setAddress("1342 Main Street");
    u7->setCity("New York");
    u7->setPostalCode("G5F4D3");
    u7->setCountry("America");
    u7->setBalance(7654);
    u7->setPhoneNumber(5435675980);
    u7->setPassportNumber("Pass333Foo333");

    u8->setFirstName("Sage");
    u8->setLastName("West");
    u8->setAddress("5467 Main Street");
    u8->setCity("New York");
    u8->setPostalCode("S3S2S1");
    u8->setCountry("America");
    u8->setBalance(20500);
    u8->setPhoneNumber(4443332216);
    u8->setPassportNumber("Pass999Foo321");

    u9->setFirstName("Paige");
    u9->setLastName("South");
    u9->setAddress("4444 North Street");
    u9->setCity("Quebec");
    u9->setPostalCode("S3S4S5");
    u9->setCountry("Canada");
    u9->setBalance(20000);
    u9->setPhoneNumber(3454565677);
    u9->setPassportNumber("Pass888Foo763");

    u10->setFirstName("Marie");
    u10->setLastName("Hansen");
    u10->setAddress("4444 North Street");
    u10->setCity("Toronto");
    u10->setPostalCode("F5G0H1");
    u10->setCountry("Canada");
    u10->setBalance(6420);
    u10->setPhoneNumber(5550005500);
    u10->setPassportNumber("Pass123Foo000");

    u1->print();
    u2->print();
    u3->print();
    u4->print();
    u5->print();
    u6->print();
    u7->print();
    u8->print();
    u9->print();
    u10->print();

    Database::addUser(u1);
    Database::addUser(u2);
    Database::addUser(u3);
    Database::addUser(u4);
    Database::addUser(u5);
    Database::addUser(u6);
    Database::addUser(u7);
    Database::addUser(u8);
    Database::addUser(u9);
    Database::addUser(u10);

    cout << "----------- Seed script has finished. -----------" << endl << endl;
}
