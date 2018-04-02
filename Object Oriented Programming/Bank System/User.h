#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>

using namespace std;

class User {
    private:
        int id;
        string userName;
        string password;
        string firstName;
        string lastName;
        string address;
        string city;
        string postalCode;
        string country;
        long phoneNumber;
        long balance;
        string passportNumber;
        string photoId;
        int medicalNumber;
        bool manager;
    public:
        User(string userName, string password, int id, bool manager);
        User(string userName, string password, int id);
        ~User();
        int getId();
        string getUserName();
        string getPassword();
        string getFirstName();
        string getLastName();
        string getAddress();
        string getCity();
        string getPostalCode();
        string getCountry();
        long getPhoneNumber();
        long getBalance();
        string getPassportNumber();
        string getPhotoId();
        int getMedicalNumber();
        bool isManager();
        void setId(int id);
        void setUserName(string userName);
        void setPassword(string password);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setAddress(string address);
        void setCity(string city);
        void setPostalCode(string postalCode);
        void setCountry(string country);
        void setPhoneNumber(long phoneNumber);
        void setBalance(long balance);
        void setPassportNumber(string passportNumber);
        void setPhotoId(string photoId);
        void setMedicalNumber(int medicalNumber);
        void setManager(bool manager);
        void print();
};

#endif
