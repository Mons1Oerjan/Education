#ifndef DATABASE_H
#define DATABASE_H
#include "User.h"
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>

class Database {
    private:
        User* manager;
        map<int, User*> users;
        unordered_map<string, vector<int>> firstNameMap;
        unordered_map<string, vector<int>> lastNameMap;
        unordered_map<string, vector<int>> cityMap;
        unordered_map<string, vector<int>> postalCodeMap;
        unordered_map<string, vector<int>> countryMap;
    public:
        Database();
        ~Database();
        User* login(string username, string password);
        User* getManager();
        void addUser(User* u);
        void removeUser(User* u);
        void removeUserById(int id);
        User* findUserByUsername(string username);
        User* findUserById(int id);
        User* findRichest();
        User* findPoorest();
        vector<User*> findUsersByFirstName(string name);
        vector<User*> findUsersByLastName(string name);
        vector<User*> findUsersByCity(string input);
        vector<User*> findUsersByPostalCode(string input);
        vector<User*> findUsersByCountry(string input);
        map<int, User*> findAllUsers();
        void printAllCustomers();
        void printAllUsers();
        void updateFirstNameMap(bool reset);
        void updateLastNameMap(bool reset);
        void updateCityMap(bool reset);
        void updatePostalCodeMap(bool reset);
        void updateCountryMap(bool reset);
        void seed();
};

#endif
