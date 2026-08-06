#include <iostream>
using namespace std;

// 手写动态数组Vector（顺序表）
class MyVector {
private:
    int* arr;         // 底层存储数组
    int size;         // 当前有效元素个数
    int capacity;     // 总容量（最大可存数量）

    // 私有扩容函数：容量不足时自动扩容2倍
    void expand() {
        if (capacity == 0) {
            capacity = 4; // 初始容量4
        }
        else {
            capacity *= 2; // 两倍扩容
        }
        // 开辟新内存
        int* newArr = new int[capacity];
        // 拷贝旧数据
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        // 释放旧内存
        delete[] arr;
        arr = newArr;
    }

public:
    // 构造函数：初始化空数组
    MyVector() {
        arr = nullptr;
        size = 0;
        capacity = 0;
    }

    // 1. 获取当前元素个数
    int getSize() {
        return size;
    }

    // 2. 获取总容量
    int getCapacity() {
        return capacity;
    }

    // 3. 判断是否为空
    bool isEmpty() {
        return size == 0;
    }

    // 4. 尾插元素（末尾添加）
    void pushBack(int val) {
        if (size >= capacity) {
            expand(); // 容量不够自动扩容
        }
        arr[size] = val;
        size++;
    }

    // 5. 头插元素（头部添加）
    void pushFront(int val) {
        if (size >= capacity) {
            expand();
        }
        // 所有元素后移一位
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = val;
        size++;
    }

    // 6. 指定下标插入元素（下标从0开始）
    bool insert(int index, int val) {
        if (index < 0 || index > size) {
            cout << "插入下标非法！" << endl;
            return false;
        }
        if (size >= capacity) {
            expand();
        }
        // 后移元素
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = val;
        size++;
        return true;
    }

    // 7. 根据下标获取元素
    int get(int index) {
        if (index < 0 || index >= size) {
            cout << "下标越界！" << endl;
            return -9999;
        }
        return arr[index];
    }

    // 8. 根据下标修改元素
    void set(int index, int val) {
        if (index < 0 || index >= size) {
            cout << "下标越界！" << endl;
            return;
        }
        arr[index] = val;
    }

    // 9. 删除末尾元素
    void popBack() {
        if (isEmpty()) {
            cout << "数组为空，无法删除！" << endl;
            return;
        }
        size--;
    }

    // 10. 删除头部元素
    void popFront() {
        if (isEmpty()) {
            cout << "数组为空，无法删除！" << endl;
            return;
        }
        // 所有元素前移覆盖
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // 11. 删除指定下标元素
    bool erase(int index) {
        if (index < 0 || index >= size) {
            cout << "删除下标非法！" << endl;
            return false;
        }
        // 元素前移覆盖被删位置
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        return true;
    }

    // 12. 遍历打印全部元素
    void print() {
        if (isEmpty()) {
            cout << "Vector为空" << endl;
            return;
        }
        cout << "Vector元素：";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // 13. 清空所有元素（保留容量内存）
    void clear() {
        size = 0;
    }

    // 析构函数：释放底层数组内存，防止内存泄漏
    ~MyVector() {
        delete[] arr;
    }
};

// 测试主函数
int main() {
    MyVector vec;

    // 尾插测试
    vec.pushBack(10);
    vec.pushBack(20);
    vec.pushBack(30);
    vec.print();
    cout << "元素数量：" << vec.getSize() << "，总容量：" << vec.getCapacity() << endl;

    // 头插
    vec.pushFront(5);
    vec.print();

    // 下标插入
    vec.insert(2, 15);
    vec.print();

    // 修改下标值
    vec.set(0, 1);
    vec.print();

    // 获取下标值
    cout << "下标3的值：" << vec.get(3) << endl;

    // 删除尾部
    vec.popBack();
    vec.print();

    // 删除头部
    vec.popFront();
    vec.print();

    // 删除指定下标
    vec.erase(1);
    vec.print();

    // 清空
    vec.clear();
    vec.print();

    return 0;
}