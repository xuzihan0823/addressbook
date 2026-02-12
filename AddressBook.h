#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "Contact.h"
#include <vector>
#include <string>

// 通讯录管理类
class AddressBook {
private:
    std::vector<Contact> contacts;  // 联系人列表
    std::string filename;           // 数据文件名

public:
    // 构造函数
    AddressBook(const std::string& filename = "contacts.dat");

    // 添加联系人
    void addContact(const Contact& contact);

    // 删除联系人（按姓名）
    bool removeContact(const std::string& name);

    // 查找联系人（按姓名）
    Contact* findContactByName(const std::string& name);

    // 查找联系人（按电话）
    Contact* findContactByPhone(const std::string& phone);

    // 修改联系人
    bool updateContact(const std::string& name, const Contact& newContact);

    // 显示所有联系人
    void displayAll() const;

    // 获取联系人数量
    size_t getCount() const;

    // 保存到文件
    bool saveToFile() const;

    // 从文件加载
    bool loadFromFile();

    // 清空通讯录
    void clear();
};

#endif // ADDRESSBOOK_H
