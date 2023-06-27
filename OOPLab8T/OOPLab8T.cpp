#include <iostream>
#include <cstring>
using namespace std;

// Завдання 1: Функція-шаблон для знаходження максимального значення в масиві та їх кількості
template <typename T>
void findMax(T array[], int size, T& maxValue, int& count) {
    maxValue = array[0];
    count = 1;

    for (int i = 1; i < size; ++i) {
        if (array[i] > maxValue) {
            maxValue = array[i];
            count = 1;
        }
        else if (array[i] == maxValue) {
            count++;
        }
    }
}

// Спеціалізація функції-шаблону для типу char*
template <>
void findMax<const char*>(const char* array[], int size, const char*& maxValue, int& count) {
    maxValue = array[0];
    count = 1;

    for (int i = 1; i < size; ++i) {
        if (strcmp(array[i], maxValue) > 0) {
            maxValue = array[i];
            count = 1;
        }
        else if (strcmp(array[i], maxValue) == 0) {
            count++;
        }
    }
}

// Завдання 2: Функція-шаблон для сортування методом Шелла
template <typename T>
void shellSort(T array[], int size) {
    int gap = size / 2;

    while (gap > 0) {
        for (int i = gap; i < size; ++i) {
            T temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
        gap /= 2;
    }
}

// Завдання 3: Параметризований клас двозв'язного списку
template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(const T& value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        size++;
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    // Завдання 1: Знаходження максимального значення в масиві та їх кількості
    int intArray[] = { 3, 2, 5, 2, 5, 5 };
    int intMaxValue;
    int intCount;
    findMax(intArray, 6, intMaxValue, intCount);
    cout << "Max value in intArray: " << intMaxValue << ", Count: " << intCount << endl;

    double doubleArray[] = { 2.5, 1.2, 3.7, 2.5, 3.7, 3.7 };
    double doubleMaxValue;
    int doubleCount;
    findMax(doubleArray, 6, doubleMaxValue, doubleCount);
    cout << "Max value in doubleArray: " << doubleMaxValue << ", Count: " << doubleCount << endl;

    const char* charArray[] = { "apple", "banana", "orange", "banana", "orange" };
    const char* charMaxValue;
    int charCount;
    findMax(charArray, 5, charMaxValue, charCount);
    cout << "Max value in charArray: " << charMaxValue << ", Count: " << charCount << endl;

    // Завдання 2: Сортування методом Шелла
    int shellIntArray[] = { 9, 2, 5, 7, 1 };
    int shellIntSize = sizeof(shellIntArray) / sizeof(shellIntArray[0]);
    shellSort(shellIntArray, shellIntSize);
    cout << "Sorted intArray: ";
    for (int i = 0; i < shellIntSize; ++i) {
        cout << shellIntArray[i] << " ";
    }
    cout << endl;

    double shellDoubleArray[] = { 3.5, 1.2, 4.8, 2.1, 0.5 };
    int shellDoubleSize = sizeof(shellDoubleArray) / sizeof(shellDoubleArray[0]);
    shellSort(shellDoubleArray, shellDoubleSize);
    cout << "Sorted doubleArray: ";
    for (int i = 0; i < shellDoubleSize; ++i) {
        cout << shellDoubleArray[i] << " ";
    }
    cout << endl;

    const char* shellStringArray[] = { "apple", "banana", "orange", "kiwi", "melon" };
    int shellStringSize = sizeof(shellStringArray) / sizeof(shellStringArray[0]);
    shellSort(shellStringArray, shellStringSize);
    cout << "Sorted stringArray: ";
    for (int i = 0; i < shellStringSize; ++i) {
        cout << shellStringArray[i] << " ";
    }
    cout << endl;

    // Завдання 3: Параметризований клас двозв'язного списку
    DoublyLinkedList<int> intList;
    intList.insert(5);
    intList.insert(10);
    intList.insert(3);
    cout << "DoublyLinkedList of ints: ";
    intList.display();

    DoublyLinkedList<char> charList;
    charList.insert('a');
    charList.insert('b');
    charList.insert('c');
    cout << "DoublyLinkedList of chars: ";
    charList.display();

    return 0;
}

