#include "AddressBook.h"
#include <iostream>
#include <limits>

// 显示菜单
void showMenu() {
    std::cout << "\n==============================" << std::endl;
    std::cout << "       通 讯 录 管 理 系 统      " << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "  1. 添加联系人" << std::endl;
    std::cout << "  2. 显示所有联系人" << std::endl;
    std::cout << "  3. 查找联系人" << std::endl;
    std::cout << "  4. 修改联系人" << std::endl;
    std::cout << "  5. 删除联系人" << std::endl;
    std::cout << "  6. 保存数据" << std::endl;
    std::cout << "  7. 清空通讯录" << std::endl;
    std::cout << "  0. 退出程序" << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "请选择操作 (0-7): ";
}

// 清除输入缓冲区
void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// 添加联系人
void addContact(AddressBook& book) {
    std::string name, phone, email, address;
    
    std::cout << "\n--- 添加新联系人 ---" << std::endl;
    
    std::cout << "请输入姓名: ";
    std::getline(std::cin, name);
    
    std::cout << "请输入电话: ";
    std::getline(std::cin, phone);
    
    std::cout << "请输入邮箱 (可选，回车跳过): ";
    std::getline(std::cin, email);
    
    std::cout << "请输入地址 (可选，回车跳过): ";
    std::getline(std::cin, address);
    
    Contact contact(name, phone, email, address);
    book.addContact(contact);
}

// 查找联系人
void findContact(AddressBook& book) {
    std::cout << "\n--- 查找联系人 ---" << std::endl;
    std::cout << "1. 按姓名查找" << std::endl;
    std::cout << "2. 按电话查找" << std::endl;
    std::cout << "请选择: ";
    
    int choice;
    std::cin >> choice;
    clearInput();
    
    std::string keyword;
    Contact* result = nullptr;
    
    if (choice == 1) {
        std::cout << "请输入姓名: ";
        std::getline(std::cin, keyword);
        result = book.findContactByName(keyword);
    } else if (choice == 2) {
        std::cout << "请输入电话: ";
        std::getline(std::cin, keyword);
        result = book.findContactByPhone(keyword);
    } else {
        std::cout << "无效选择！" << std::endl;
        return;
    }
    
    if (result != nullptr) {
        std::cout << "\n找到联系人：" << std::endl;
        result->display();
    } else {
        std::cout << "未找到该联系人！" << std::endl;
    }
}

// 修改联系人
void updateContact(AddressBook& book) {
    std::cout << "\n--- 修改联系人 ---" << std::endl;
    std::cout << "请输入要修改的联系人姓名: ";
    
    std::string name;
    std::getline(std::cin, name);
    
    Contact* contact = book.findContactByName(name);
    if (contact == nullptr) {
        std::cout << "未找到该联系人！" << std::endl;
        return;
    }
    
    std::cout << "当前信息：" << std::endl;
    contact->display();
    
    std::cout << "\n请输入新信息 (回车保持原值):" << std::endl;
    
    std::string newName, phone, email, address;
    
    std::cout << "新姓名 [" << contact->getName() << "]: ";
    std::getline(std::cin, newName);
    if (newName.empty()) newName = contact->getName();
    
    std::cout << "新电话 [" << contact->getPhone() << "]: ";
    std::getline(std::cin, phone);
    if (phone.empty()) phone = contact->getPhone();
    
    std::cout << "新邮箱 [" << contact->getEmail() << "]: ";
    std::getline(std::cin, email);
    if (email.empty()) email = contact->getEmail();
    
    std::cout << "新地址 [" << contact->getAddress() << "]: ";
    std::getline(std::cin, address);
    if (address.empty()) address = contact->getAddress();
    
    Contact newContact(newName, phone, email, address);
    book.updateContact(name, newContact);
}

// 删除联系人
void deleteContact(AddressBook& book) {
    std::cout << "\n--- 删除联系人 ---" << std::endl;
    std::cout << "请输入要删除的联系人姓名: ";
    
    std::string name;
    std::getline(std::cin, name);
    
    book.removeContact(name);
}

// 清空通讯录
void clearAddressBook(AddressBook& book) {
    std::cout << "\n确定要清空通讯录吗？(y/n): ";
    char confirm;
    std::cin >> confirm;
    clearInput();
    
    if (confirm == 'y' || confirm == 'Y') {
        book.clear();
    } else {
        std::cout << "操作已取消。" << std::endl;
    }
}

int main() {
    AddressBook book;
    int choice;
    
    std::cout << "欢迎使用通讯录管理系统！" << std::endl;
    
    while (true) {
        showMenu();
        std::cin >> choice;
        clearInput();
        
        switch (choice) {
            case 1:
                addContact(book);
                break;
            case 2:
                book.displayAll();
                break;
            case 3:
                findContact(book);
                break;
            case 4:
                updateContact(book);
                break;
            case 5:
                deleteContact(book);
                break;
            case 6:
                book.saveToFile();
                break;
            case 7:
                clearAddressBook(book);
                break;
            case 0:
                book.saveToFile();
                std::cout << "\n感谢使用，再见！" << std::endl;
                return 0;
            default:
                std::cout << "无效选择，请重新输入！" << std::endl;
        }
    }
    
    return 0;
}
