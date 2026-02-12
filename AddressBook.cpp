#include "AddressBook.h"
#include <iostream>
#include <fstream>
#include <algorithm>

// 构造函数
AddressBook::AddressBook(const std::string& filename) : filename(filename) {
    loadFromFile();  // 启动时自动加载数据
}

// 添加联系人
void AddressBook::addContact(const Contact& contact) {
    contacts.push_back(contact);
    std::cout << "联系人 \"" << contact.getName() << "\" 添加成功！" << std::endl;
}

// 删除联系人
bool AddressBook::removeContact(const std::string& name) {
    auto it = std::find_if(contacts.begin(), contacts.end(),
        [&name](const Contact& c) { return c.getName() == name; });
    
    if (it != contacts.end()) {
        contacts.erase(it);
        std::cout << "联系人 \"" << name << "\" 删除成功！" << std::endl;
        return true;
    }
    std::cout << "未找到联系人 \"" << name << "\"" << std::endl;
    return false;
}

// 按姓名查找联系人
Contact* AddressBook::findContactByName(const std::string& name) {
    auto it = std::find_if(contacts.begin(), contacts.end(),
        [&name](const Contact& c) { return c.getName() == name; });
    
    if (it != contacts.end()) {
        return &(*it);
    }
    return nullptr;
}

// 按电话查找联系人
Contact* AddressBook::findContactByPhone(const std::string& phone) {
    auto it = std::find_if(contacts.begin(), contacts.end(),
        [&phone](const Contact& c) { return c.getPhone() == phone; });
    
    if (it != contacts.end()) {
        return &(*it);
    }
    return nullptr;
}

// 修改联系人
bool AddressBook::updateContact(const std::string& name, const Contact& newContact) {
    Contact* contact = findContactByName(name);
    if (contact != nullptr) {
        *contact = newContact;
        std::cout << "联系人信息更新成功！" << std::endl;
        return true;
    }
    std::cout << "未找到联系人 \"" << name << "\"" << std::endl;
    return false;
}

// 显示所有联系人
void AddressBook::displayAll() const {
    if (contacts.empty()) {
        std::cout << "通讯录为空！" << std::endl;
        return;
    }
    
    std::cout << "\n========== 通讯录列表 ==========" << std::endl;
    std::cout << "共有 " << contacts.size() << " 位联系人：\n" << std::endl;
    
    for (size_t i = 0; i < contacts.size(); ++i) {
        std::cout << "[" << (i + 1) << "] ";
        contacts[i].display();
        std::cout << std::endl;
    }
}

// 获取联系人数量
size_t AddressBook::getCount() const {
    return contacts.size();
}

// 保存到文件
bool AddressBook::saveToFile() const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "无法打开文件进行保存！" << std::endl;
        return false;
    }
    
    for (const auto& contact : contacts) {
        file << contact.getName() << "\n"
             << contact.getPhone() << "\n"
             << contact.getEmail() << "\n"
             << contact.getAddress() << "\n"
             << "---\n";  // 分隔符
    }
    
    file.close();
    std::cout << "数据已保存到文件！" << std::endl;
    return true;
}

// 从文件加载
bool AddressBook::loadFromFile() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;  // 文件不存在时静默返回
    }
    
    contacts.clear();
    std::string name, phone, email, address, separator;
    
    while (std::getline(file, name)) {
        if (name.empty()) continue;
        
        std::getline(file, phone);
        std::getline(file, email);
        std::getline(file, address);
        std::getline(file, separator);  // 读取分隔符
        
        contacts.emplace_back(name, phone, email, address);
    }
    
    file.close();
    return true;
}

// 清空通讯录
void AddressBook::clear() {
    contacts.clear();
    std::cout << "通讯录已清空！" << std::endl;
}
