#include <iostream>
#include <string>
using namespace std;

/**
 * @brief 辅助函数，防止清屏
 */
void pause()
{
    cout << "(按任意键继续)...";
    cin.get();
    cin.get();
}

#define Capacity 1000  // 通讯录最大容量

/**
 * @brief 联系人结构体定义
 */
struct Contact
{
    string m_Name;
    int m_Gender;
    int m_Age;
    string m_Phone;
    string m_Addr;
};

/**
 * @brief 通讯录结构体定义
 */
struct Contacts
{
    struct Contact contacts[Capacity];
    size_t m_Count = 0;
};

/**
 * @brief 显示联系人信息
 *
 * @param contact 联系人
 */
void showContact(struct Contact *contact)
{
    cout << contact->m_Name << "\t";
    cout << contact->m_Phone << "\t";
    cout << (contact->m_Gender == 1 ? "男\t" : "女\t");
    cout << contact->m_Addr << "\t";
    cout << "年龄:" << contact->m_Age << endl;
}

/**
 * @brief 添加联系人
 *
 * @param contacts 指向struct Contacts类型的指针
 */
void addContact(struct Contacts *contacts)
{
    if (contacts->m_Count == Capacity)
    {
        cout << "通讯录已满!\n";
        return;
    }
    struct Contact contact;

    cout << "请输入姓名: ";
    cin >> contact.m_Name;
    cout << "请输入性别(1-男, 0-女): ";
    cin >> contact.m_Gender;
    cout << "请输入年龄(0-140): ";
    cin >> contact.m_Age;
    cout << "请输入电话: ";
    cin >> contact.m_Phone;
    cout << "请输入地址: ";
    cin >> contact.m_Addr;
    contacts->contacts[contacts->m_Count] = contact;
    contacts->m_Count++;
    cout << "添加成功!\n";
    pause();
}

/**
 * @brief 显示联系人
 *
 * @param contacts 所有联系人
 */
void showContacts(struct Contacts *contacts)
{
    if (contacts->m_Count == 0)
    {
        cout << "通讯录中无联系人!\n";
        pause();
        return;
    }
    for (size_t i = 0; i < contacts->m_Count; i++)
    {
        showContact(&(contacts->contacts[i]));
    }
    pause();
}

/**
 * @brief 删除联系人
 *
 * @param contacts 所有联系人
 */
void deleteContact(struct Contacts *contacts)
{
    string name;
    size_t i = 0;

    cout << "请输入姓名: ";
    cin >> name;

    // 查找联系人
    while (i < contacts->m_Count)
    {
        if (name == contacts->contacts[i].m_Name)
            break;
        contacts->m_Count++;
    }

    // 未找到
    if (i == contacts->m_Count)
    {
        cout << "未找到联系人: " << name << endl;
        pause();
        return;
    }

    // 找到了并删除
    while (i < contacts->m_Count - 1)
    {
        contacts->contacts[i].m_Name = contacts->contacts[i + 1].m_Name;
        contacts->contacts[i].m_Age = contacts->contacts[i + 1].m_Age;
        contacts->contacts[i].m_Addr = contacts->contacts[i + 1].m_Addr;
        contacts->contacts[i].m_Phone = contacts->contacts[i + 1].m_Phone;
        contacts->contacts[i].m_Gender = contacts->contacts[i + 1].m_Gender;
    }
    contacts->m_Count--;
    cout << "已删除联系人: " << name << endl;
    pause();
}

// 查找联系人
void findContact(struct Contacts *contacts)
{
    string name;
    bool found = false;

    cout << "请输入要查找的姓名: ";
    cin >> name;

    // 查找联系人
    for (size_t i = 0; i < contacts->m_Count; i++)
    {
        if (name == contacts->contacts[i].m_Name)
        {
            found = true;
            showContact(&(contacts->contacts[i]));
        }
    }

    // 未找到
    if (!found) cout << "未找到联系人: " << name << endl;
    pause();
}

// 修改联系人
void editContact(struct Contacts *contacts)
{
    string name;
    bool found = false;
    struct Contact *ptr_contact;

    cout << "请输入要修改的联系人姓名: ";
    cin >> name;

    // 查找联系人
    for (size_t i = 0; i < contacts->m_Count; i++)
    {
        if (name == contacts->contacts[i].m_Name)
        {
            found = true;
            ptr_contact = &contacts->contacts[i];
            showContact(ptr_contact);
            break;
        }
    }

    // 未找到
    if (!found)
    {
        cout << "未找到联系人: " << name << endl;
    }
    else
    {
        cout << "修改联系人: " << ptr_contact->m_Name << endl;
        cout << "请输入姓名: ";
        cin >> ptr_contact->m_Name;
        cout << "请输入性别(1-男, 0-女): ";
        cin >> ptr_contact->m_Gender;
        cout << "请输入年龄(0-140): ";
        cin >> ptr_contact->m_Age;
        cout << "请输入电话: ";
        cin >> ptr_contact->m_Phone;
        cout << "请输入地址: ";
        cin >> ptr_contact->m_Addr;
    }
    pause();
}

// 清空联系人
void deleteAllContacts(struct Contacts *contacts)
{
    contacts->m_Count = 0;
    cout << "已清空联系人列表\n";
    pause();
}

/**
 * @brief 显示菜单
 */
void showMenu()
{
    cout << "*************************" << endl;
    cout << "***** 1、添加联系人 *****" << endl;
    cout << "***** 2、显示联系人 *****" << endl;
    cout << "***** 3、删除联系人 *****" << endl;
    cout << "***** 4、查找联系人 *****" << endl;
    cout << "***** 5、修改联系人 *****" << endl;
    cout << "***** 6、清空联系人 *****" << endl;
    cout << "***** 0、退出通讯录 *****" << endl;
    cout << "*************************" << endl;
    cout << "请输入选项: ";
}

int main(int argc, char const *argv[])
{
    int select = 0;
    struct Contacts contacts;

    while (true)
    {
        system("clear");
        showMenu();
        cin >> select;
        switch (select)
        {
        case 1:  // 1、添加联系人
            addContact(&contacts);
            break;
        case 2:  // 2、显示联系人
            showContacts(&contacts);
            break;
        case 3:  // 3、删除联系人
            deleteContact(&contacts);
            break;
        case 4:  // 4、查找联系人
            findContact(&contacts);
            break;
        case 5:  // 5、修改联系人
            editContact(&contacts);
            break;
        case 6:  // 6、清空联系人
            deleteAllContacts(&contacts);
            break;
        default:  // 0、退出通讯录
            cout << "再见!\n";
            return 0;
            break;
        }
    }

    return 0;
}
