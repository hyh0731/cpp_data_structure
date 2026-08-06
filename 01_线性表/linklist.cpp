#include <iostream>
using namespace std;

// 定义链表节点
struct ListNode 
{
    int data;           // 存储数据
    ListNode* next;     // 指向下一节点指针
    // 构造函数
    ListNode(int val) : data(val), next(nullptr) {}
};

// 单链表类封装
class LinkList {
private:
    ListNode* head;  // 头结点（不存数据，统一操作逻辑）
public:
    // 1. 构造函数：初始化头结点
    LinkList() 
    {
        head = new ListNode(0);
    }

    // 2. 获取链表长度
    int getLength() 
    {
        int len = 0;
        ListNode* p = head->next;
        while (p != nullptr) 
        {
            len++;
            p = p->next;
        }
        return len;
    }

    // 3. 头插法：头部插入元素
    void insertHead(int val) 
    {
        ListNode* newNode = new ListNode(val);
        newNode->next = head->next;
        head->next = newNode;
    }

    // 4. 尾插法：尾部插入元素
    void insertTail(int val) 
    {
        ListNode* newNode = new ListNode(val);
        ListNode* p = head;
        // 找到最后一个节点
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = newNode;
    }

    // 5. 按位置插入：pos从1开始
    bool insertByPos(int pos, int val) 
    {
        int len = getLength();
        if (pos < 1 || pos > len + 1) 
        {
            cout << "插入位置非法" << endl;
            return false;
        }
        ListNode* p = head;
        // 走到pos前一个节点
        for (int i = 1; i < pos; i++) 
        {
            p = p->next;
        }
        ListNode* newNode = new ListNode(val);
        newNode->next = p->next;
        p->next = newNode;
        return true;
    }

    // 6. 按位置删除节点 pos从1开始
    bool deleteByPos(int pos)
    {
        int len = getLength();
        if (pos < 1 || pos > len) 
        {
            cout << "删除位置非法" << endl;
            return false;
        }
        ListNode* p = head;
        for (int i = 1; i < pos; i++) 
        {
            p = p->next;
        }
        ListNode* del = p->next;
        p->next = del->next;
        delete del;
        return true;
    }

    // 7. 按值删除第一个匹配节点
    bool deleteByVal(int val)
    {
        ListNode* p = head;
        while (p->next != nullptr && p->next->data != val)
        {
            p = p->next;
        }
        if (p->next == nullptr) 
        {
            cout << "未找到值" << val << endl;
            return false;
        }
        ListNode* del = p->next;
        p->next = del->next;
        delete del;
        return true;
    }

    // 8. 查找指定值是否存在
    bool findVal(int val) 
    {
        ListNode* p = head->next;
        while (p != nullptr) 
        {
            if (p->data == val) return true;
            p = p->next;
        }
        return false;
    }

    // 9. 遍历打印全部元素
    void printList() 
    {
        ListNode* p = head->next;
        if (p == nullptr) 
        {
            cout << "链表为空" << endl;
            return;
        }
        cout << "链表元素：";
        while (p != nullptr) 
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // 10. 清空所有数据节点，保留头结点
    void clearList()
    {
        ListNode* p = head->next;
        while (p != nullptr) 
        {
            ListNode* temp = p;
            p = p->next;
            delete temp;
        }
        head->next = nullptr;
    }

    // 11. 析构函数：销毁整个链表，释放内存
    ~LinkList() 
    {
        clearList();
        delete head;
    }
};

// 测试主函数
int main() 
{
    LinkList list;

    // 尾插测试
    list.insertTail(10);
    list.insertTail(20);
    list.insertTail(30);
    list.printList();

    // 头插测试
    list.insertHead(5);
    list.printList();

    // 指定位置插入
    list.insertByPos(3, 15);
    list.printList();

    // 长度
    cout << "链表长度：" << list.getLength() << endl;

    // 按值删除
    list.deleteByVal(20);
    list.printList();

    // 按位置删除
    list.deleteByPos(2);
    list.printList();

    // 查找
    int x = 30;
    if (list.findVal(x)) cout << x << " 存在链表中" << endl;
    else cout << x << " 不存在" << endl;

    // 清空链表
    list.clearList();
    list.printList();

    return 0;
}