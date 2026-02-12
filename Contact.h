#ifndef CONTACT_H
#define CONTACT_H

#include <string>

// 联系人类
class Contact {
private:
    std::string name;      // 姓名
    std::string phone;     // 电话号码
    std::string email;     // 电子邮箱
    std::string address;   // 地址

public:
    // 构造函数
    Contact();
    Contact(const std::string& name, const std::string& phone, 
            const std::string& email = "", const std::string& address = "");

    // Getter 方法
    std::string getName() const;
    std::string getPhone() const;
    std::string getEmail() const;
    std::string getAddress() const;

    // Setter 方法
    void setName(const std::string& name);
    void setPhone(const std::string& phone);
    void setEmail(const std::string& email);
    void setAddress(const std::string& address);

    // 显示联系人信息
    void display() const;
};

#endif // CONTACT_H
