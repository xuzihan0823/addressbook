#include "Contact.h"
#include <iostream>

// 默认构造函数
Contact::Contact() : name(""), phone(""), email(""), address("") {}

// 带参数的构造函数
Contact::Contact(const std::string& name, const std::string& phone, 
                 const std::string& email, const std::string& address)
    : name(name), phone(phone), email(email), address(address) {}

// Getter 方法实现
std::string Contact::getName() const {
    return name;
}

std::string Contact::getPhone() const {
    return phone;
}

std::string Contact::getEmail() const {
    return email;
}

std::string Contact::getAddress() const {
    return address;
}

// Setter 方法实现
void Contact::setName(const std::string& name) {
    this->name = name;
}

void Contact::setPhone(const std::string& phone) {
    this->phone = phone;
}

void Contact::setEmail(const std::string& email) {
    this->email = email;
}

void Contact::setAddress(const std::string& address) {
    this->address = address;
}

// 显示联系人信息
void Contact::display() const {
    std::cout << "================================" << std::endl;
    std::cout << "姓名: " << name << std::endl;
    std::cout << "电话: " << phone << std::endl;
    if (!email.empty()) {
        std::cout << "邮箱: " << email << std::endl;
    }
    if (!address.empty()) {
        std::cout << "地址: " << address << std::endl;
    }
    std::cout << "================================" << std::endl;
}
