#include "User.h"

User::User(string userName, string password, int id) {
    this->userName = userName;
    this->password = password;
    this->id = id;
    this->manager = false;
}

User::User(string userName, string password, int id, bool manager) {
    this->userName = userName;
    this->password = password;
    this->id = id;
    this->manager = manager;
}

User::~User() {

}

int User::getId() {
    return this->id;
}

string User::getUserName() {
    return this->userName;
}

string User::getPassword() {
    return this->password;
}

string User::getFirstName() {
    return this->firstName;
}

string User::getLastName() {
    return this->lastName;
}

string User::getAddress() {
    return this->address;
}

string User::getCity() {
    return this->city;
}

string User::getPostalCode() {
    return this->postalCode;
}

string User::getCountry() {
    return this->country;
}

long User::getPhoneNumber() {
    return this->phoneNumber;
}

long User::getBalance() {
    return this->balance;
}

string User::getPassportNumber() {
    return this->passportNumber;
}

string User::getPhotoId() {
    return this->photoId;
}

int User::getMedicalNumber() {
    return this->medicalNumber;
}

bool User::isManager() {
    return this->manager;
}

void User::setId(int id) {
    this->id = id;
}

void User::setUserName(string userName) {
    this->userName = userName;
}

void User::setPassword(string password) {
    this->password = password;
}

void User::setFirstName(string firstName) {
    if (firstName.find_first_of("0123456789") != string::npos) {
        cout << "A user's firstName can't contain numbers." << endl;
    } else {
        this->firstName = firstName;
    }
}

void User::setLastName(string lastName) {
    if (lastName.find_first_of("0123456789") != string::npos) {
        cout << "A user's firstName can't contain numbers." << endl;
    } else {
        this->lastName = lastName;
    }
}

void User::setAddress(string address) {
    this->address = address;
}

void User::setCity(string city) {
    this->city = city;
}

void User::setPostalCode(string postalCode) {
    this->postalCode = postalCode;
}

void User::setCountry(string country) {
    this->country = country;
}

void User::setPhoneNumber(long phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void User::setBalance(long balance) {
    this->balance = balance;
}

void User::setPassportNumber(string passportNumber) {
    if (passportNumber.find_first_of("0123456789") == string::npos) {
        cout << "A user's passportNumber must contain letters and numbers." << endl;
    } else {
        this->passportNumber = passportNumber;
    }
}

void User::setPhotoId(string photoId) {
    this->photoId = photoId;
}

void User::setMedicalNumber(int medicalNumber) {
    this->medicalNumber = medicalNumber;
}

void User::setManager(bool manager) {
    this->manager = manager;
}

void User::print() {
    cout << endl;
    cout << "User #" << this->id << ":" << endl;
    cout << "\t- username: " << this->userName << endl;
    cout << "\t- first name: " << this->firstName << endl;
    cout << "\t- last name: " << this->lastName << endl;
    cout << "\t- address: " << this->address << endl;
    cout << "\t- phone number: " << this->phoneNumber << endl;
    cout << "\t- balance: " << this->balance << endl;
    cout << "\t- passport number: " << this->passportNumber << endl;
    cout << "\t- photo ID: " << this->photoId << endl;
    cout << "\t- medical number: " << this->medicalNumber << endl;
    cout << "\t- is manager: " << this->manager << endl;
    cout << endl;
}
