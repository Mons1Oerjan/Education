#include "User.h"
#include "Database.h"
#include <iostream>
#include <string>

bool isLoggedIn = false;
Database* db = new Database();

void testDatabase() {
    cout << "-------- Starting Database tests --------" << endl;

    // create a database with a manager:
    Database* db_test = new Database();

    // create a new user
    User* u = new User("test", "secret", 2);
    User* u2 = new User("test2", "secret", 3);

    // test input validation:
    cout << "Testing input validation:" << endl;
    u->setFirstName("ExampleFirstName123");
    u->setLastName("123ExampleLastName");
    u->setPassportNumber("ExamplePassport");
    u->print();

    // set attributes
    u->setFirstName("ExampleFirstName");
    u->setLastName("ExampleLastName");
    u->setAddress("1650 Walnut Street");
    u->setCity("Halifax");
    u->setPostalCode("B3H3S4");
    u->setCountry("Canada");
    u->setBalance(4598);
    u->setPhoneNumber(9029894568);
    u->setPassportNumber("Pass123Num456");
    u->print();

    u2->setFirstName("foo");
    u2->setLastName("bar");
    u2->setAddress("1234 Foobar Street");
    u2->setCity("Halifax");
    u2->setPostalCode("B3J8F5");
    u2->setCountry("Canada");
    u2->setBalance(1234);
    u2->setPhoneNumber(1234567890);
    u2->setPassportNumber("Foo123Bar456");
    u2->print();

    // test add and print functions
    db_test->addUser(u);
    db_test->addUser(u2);
    cout << "Printing all users:" << endl;
    db_test->printAllUsers();
    cout << "Printing all customers:" << endl;
    db_test->printAllCustomers();

    // test seed script:
    db_test->seed();

    cout << "Printing all customers:" << endl;
    db_test->printAllCustomers();

    // test hashing of last names:
    vector<User*> usersLastName = db_test->findUsersByLastName("ExampleLastName");
    cout << "Found users with last name ExampleLastName: " << usersLastName.size() << endl;
    usersLastName[0]->print();

    // test hashing of first names:
    vector<User*> usersFirstName = db_test->findUsersByFirstName("ExampleFirstName");
    cout << "Found users with first name ExampleFirstName: " << usersFirstName.size() << endl;
    usersFirstName[0]->print();

    // test find by username:
    cout << "Finding test user by username:" << endl;
    User* user_by_username = db_test->findUserByUsername("test");
    user_by_username->print();

    // test findRichest:
    cout << "Finding the richest customer:" << endl;
    db_test->findRichest()->print();

    // test findPoorest:
    cout << "Finding the poorest customer:" << endl;
    db_test->findPoorest()->print();

    // test login:
    cout << "Logging in with wrong credentials:" << endl;
    db_test->login("test", "wrong_password");
    cout << "Logging in with correct credentials:" << endl;
    db_test->login("test", "secret");

    // test removal of user:
    cout << "Removing test user from the DB" << endl;
    db_test->removeUser(u);
    db_test->printAllUsers();

    // free memory:
    usersLastName.clear();
    usersFirstName.clear();
    delete db_test;
    delete u;

    cout << "-------- Database tests complete --------" << endl << endl;
}

User* login() {
    string username;
    string password;
    User* loggedInUser;

    cout << "Please log in:" << endl;

    while (!isLoggedIn) {
        cout << "username: ";
        cin >> username;
        cout << "password: ";
        cin >> password;

        loggedInUser = db->login(username, password);

        if (loggedInUser != nullptr) {
            isLoggedIn = true;
            cout << "You successfully logged in as:" << endl;
            loggedInUser->print();

            return loggedInUser;
        }

        cout << "Invalid credentials. Please try again." << endl;
    }

    return nullptr;
}

void runUserCommands(User* loggedInUser) {
    if (isLoggedIn) {
        if (loggedInUser->isManager() == true) {
            // display manager options:
            while (isLoggedIn) {
                string command;

                cout << "What do you want to do? These are your commands:" << endl;
                cout << "\t- create_customer: Create a new bank customer." << endl;
                cout << "\t- update_user: Update an existing user's information by ID." << endl;
                cout << "\t- delete_user: Delete a user by ID." << endl;
                cout << "\t- check_customer_balance: Check a customer's balance by ID." << endl;
                cout << "\t- search_users: Search for specific user information, e.g. firstName, lastName, or Address." << endl;
                cout << "\t- show_all_users: Show all users sorted in alphabetic order by lastName." << endl;
                cout << "\t- find_richest: Find the richest customer in the bank." << endl;
                cout << "\t- find_poorest: Find the poorest customer in the bank." << endl;
                cout << "\t- logout: log out from your account." << endl;
                cout << "Enter command: ";
                cin >> command;

                if (command == "create_customer") {
                    string new_username;
                    string new_password;
                    string new_first_name;
                    string new_last_name;
                    string add_more_attributes;
                    int new_id;

                    cout << "Enter a username: ";
                    cin >> new_username;
                    cout << "Enter a password: ";
                    cin >> new_password;
                    cout << "Enter an integer ID: ";
                    cin >> new_id;

                    User* new_user = new User(new_username, new_password, new_id);

                    cout << "Add first name: ";
                    cin >> new_first_name;
                    new_user->setFirstName(new_first_name);

                    cout << "Add last name: ";
                    cin >> new_last_name;
                    new_user->setLastName(new_last_name);

                    cout << "Add more information about this user (yes, no)? ";
                    cin >> add_more_attributes;

                    if (add_more_attributes == "yes") {
                        string input;
                        long num_input;
                        int int_input;

                        cout << "Add phone number: ";
                        cin >> input;
                        num_input = stol(input);
                        new_user->setPhoneNumber(num_input);

                        cout << "Add address: ";
                        cin >> input;
                        new_user->setAddress(input);

                        cout << "Add passport number: ";
                        cin >> input;
                        new_user->setPassportNumber(input);

                        cout << "Add photo ID: ";
                        cin >> input;
                        new_user->setPhotoId(input);

                        cout << "Add medical number: ";
                        cin >> input;
                        int_input = stoi(input);
                        new_user->setMedicalNumber(int_input);
                    }

                    cout << "Attempting to add this user to the database:" << endl;
                    new_user->print();

                    db->addUser(new_user);
                }
                else if (command == "update_user") {
                    int update_id;
                    int int_input;
                    long num_input;
                    string input;

                    cout << "Enter the ID of the user you want to update:" << endl;
                    cin >> update_id;

                    User* update_user = db->findUserById(update_id);

                    if (update_user != nullptr) {
                        cout << "Update first name: ";
                        cin >> input;
                        update_user->setFirstName(input);

                        cout << "Update last name: ";
                        cin >> input;
                        update_user->setLastName(input);

                        cout << "Update username: ";
                        cin >> input;
                        update_user->setUserName(input);

                        cout << "Update password: ";
                        cin >> input;
                        update_user->setPassword(input);

                        cout << "Update phone number: ";
                        cin >> input;
                        num_input = stol(input);
                        update_user->setPhoneNumber(num_input);

                        cout << "Update address: ";
                        cin >> input;
                        update_user->setAddress(input);

                        cout << "Update passport number: ";
                        cin >> input;
                        update_user->setPassportNumber(input);

                        cout << "Update photo ID: ";
                        cin >> input;
                        update_user->setPhotoId(input);

                        cout << "Update medical number: ";
                        cin >> input;
                        int_input = stoi(input);
                        update_user->setMedicalNumber(int_input);

                        cout << "The user info has been updated. The new user info is:" << endl;
                        update_user->print();
                    }
                }
                else if (command == "delete_user") {
                    int delete_id;
                    string should_delete;

                    cout << "Enter the ID of the user you want to delete:" << endl;
                    cin >> delete_id;

                    User* user_to_be_deleted = db->findUserById(delete_id);

                    cout << "You have requested to delete this user:" << endl;
                    user_to_be_deleted->print();

                    cout << "Are you sure you wish to delete this user (yes, no)? ";
                    cin >> should_delete;

                    if (should_delete == "yes") {
                        db->removeUserById(delete_id);
                    }
                }
                else if (command == "check_customer_balance") {
                    int customer_id;
                    cout << "Enter the ID of the user: ";
                    cin >> customer_id;

                    User* customer = db->findUserById(customer_id);

                    cout << "This user's balance is: $" << customer->getBalance() << "." << endl;
                }
                else if (command == "search_users") {
                    string search_attribute;
                    string search_value;
                    cout << "Which user info do you want to search by?" << endl;
                    cout << "Select between firstName, lastName, city, postal_code, or country: ";
                    cin >> search_attribute;

                    if (search_attribute == "firstName") {
                        cout << "Enter firstName to search for: ";
                        cin >> search_value;

                        vector<User*> users = db->findUsersByFirstName(search_value);

                        cout << "Search results:" << endl;
                        for (vector<User*>::iterator it = users.begin(); it != users.end(); ++it) {
                            (*it)->print();
                        }
                    }
                    else if (search_attribute == "lastName") {
                        cout << "Enter lastName to search for: ";
                        cin >> search_value;

                        vector<User*> users = db->findUsersByLastName(search_value);

                        cout << "Search results:" << endl;
                        for (vector<User*>::iterator it = users.begin(); it != users.end(); ++it) {
                            (*it)->print();
                        }
                    }
                    else if (search_attribute == "city") {
                        cout << "Enter city to search for: ";
                        cin >> search_value;

                        vector<User*> users = db->findUsersByCity(search_value);

                        cout << "Search results:" << endl;
                        for (vector<User*>::iterator it = users.begin(); it != users.end(); ++it) {
                            (*it)->print();
                        }
                    }
                    else if (search_attribute == "postal_code") {
                        cout << "Enter postalCode to search for: ";
                        cin >> search_value;

                        vector<User*> users = db->findUsersByPostalCode(search_value);

                        cout << "Search results:" << endl;
                        for (vector<User*>::iterator it = users.begin(); it != users.end(); ++it) {
                            (*it)->print();
                        }
                    }
                    else if (search_attribute == "country") {
                        cout << "Enter country to search for: ";
                        cin >> search_value;

                        vector<User*> users = db->findUsersByCountry(search_value);

                        cout << "Search results:" << endl;
                        for (vector<User*>::iterator it = users.begin(); it != users.end(); ++it) {
                            (*it)->print();
                        }
                    }
                    else {
                        cout << "Wrong input. Please try again." << endl;
                    }
                }
                else if (command == "show_all_users") {
                    cout << "Printing all users:" << endl;

                    db->printAllUsers();
                }
                else if (command == "find_richest") {
                    cout << "The richest customer is:" << endl;
                    db->findRichest()->print();
                }
                else if (command == "find_poorest") {
                    cout << "The poorest customer is:" << endl;
                    db->findPoorest()->print();
                }
                else if (command == "logout") {
                    cout << "Logging out of your account..." << endl << endl;
                    isLoggedIn = false;
                }
                else {
                    cout << "The command you entered is not supported. Please try again." << endl;
                }
            }
        } else {
            // display customer options:
            while (isLoggedIn) {
                string command;

                cout << "What do you want to do? These are your commands:" << endl;
                cout << "\t- update_info: Update your user info." << endl;
                cout << "\t- check_balance: Check your account balance." << endl;
                cout << "\t- withdraw: Withdraw money from your account." << endl;
                cout << "\t- deposit: Deposit money to your account." << endl;
                cout << "\t- logout: log out from your account." << endl;
                cout << "Enter command: ";
                cin >> command;

                if (command == "update_info") {
                    string input;
                    long num_input;
                    int int_input;

                    cout << "Update first name: ";
                    cin >> input;
                    loggedInUser->setFirstName(input);

                    cout << "Update last name: ";
                    cin >> input;
                    loggedInUser->setLastName(input);

                    cout << "Update username: ";
                    cin >> input;
                    loggedInUser->setUserName(input);

                    cout << "Update password: ";
                    cin >> input;
                    loggedInUser->setPassword(input);

                    cout << "Update phone number: ";
                    cin >> input;
                    num_input = stol(input);
                    loggedInUser->setPhoneNumber(num_input);

                    cout << "Update address: ";
                    cin >> input;
                    loggedInUser->setAddress(input);

                    cout << "Update passport number: ";
                    cin >> input;
                    loggedInUser->setPassportNumber(input);

                    cout << "Update photo ID: ";
                    cin >> input;
                    loggedInUser->setPhotoId(input);

                    cout << "Update medical number: ";
                    cin >> input;
                    int_input = stoi(input);
                    loggedInUser->setMedicalNumber(int_input);

                    cout << "Your user info has been updated. Your info is:" << endl;
                    loggedInUser->print();
                }
                else if (command == "check_balance") {
                    cout << "Your current balance is: $" << loggedInUser->getBalance() << endl;
                }
                else if (command == "withdraw") {
                    long balance = loggedInUser->getBalance();
                    long amountToWithdraw;
                    cout << "Your current balance is: $" << balance << endl;
                    cout << "Enter the amount to withdraw: $";
                    cin >> command;
                    amountToWithdraw = stol(command);

                    if (amountToWithdraw > balance) {
                        cout << "Insufficient funds." << endl;
                    } else {
                        loggedInUser->setBalance(balance - amountToWithdraw);
                        cout << "You successfully withdrawed $" << amountToWithdraw << "." << endl;
                        cout << "Your new balance is: $" << loggedInUser->getBalance() << endl;
                    }
                }
                else if (command == "deposit") {
                    long balance = loggedInUser->getBalance();
                    long amountToDeposit;
                    cout << "Your current balance is: $" << balance << endl;
                    cout << "Enter the amount to deposit: $";
                    cin >> command;
                    amountToDeposit = stol(command);
                    loggedInUser->setBalance(balance + amountToDeposit);
                    cout << "You successfully deposited $" << amountToDeposit << "." << endl;
                    cout << "Your new balance is: $" << loggedInUser->getBalance() << endl;
                }
                else if (command == "logout") {
                    cout << "Logging out of your account..." << endl << endl;
                    isLoggedIn = false;
                }
                else {
                    cout << "The command you entered is not supported. Please try again." << endl;
                }
            }
        }
    }

    loggedInUser = login();
    runUserCommands(loggedInUser);
}

int main(void) {
    // test the database class
    testDatabase();

    // seed the DB with 10 users:
    db->seed();

    cout << "Welcome to the Console Bank." << endl << endl;

    User* loggedInUser = login();
    runUserCommands(loggedInUser);

    delete loggedInUser;
    return 0;
}
