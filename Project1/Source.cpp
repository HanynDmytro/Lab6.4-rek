#include <iostream>
#include <cstdlib> // ��� rand() � srand()
#include <ctime>   // ��� time()
#include <cmath>   // ��� abs()
#include<windows.h>

using namespace std;

void InitArray(int* arr, const int size, int i) {
    if (i < size) {
        arr[i] = rand() % 21 - 10;
        InitArray(arr, size, i + 1);
    }
}

// ���������� ������� ��� ��������� ������
void printArray(const int* arr, int size, int index = 0) {
    if (index == size) {
        cout << endl;
        return;
    }
    cout << arr[index] << " ";
    printArray(arr, size, index + 1);
}

// ���������� ������� ��� ���������� ���� �������� � ��������� ���������
int sumOddIndexElements(const int* arr, int size, int index = 1) {
    if (index >= size) return 0;
    return arr[index] + sumOddIndexElements(arr, size, index + 2);
}

// ���������� ������� ��� ������ ������� ��'������ ��������
int findFirstNegative(const int* arr, int size, int index = 0) {
    if (index >= size) return -1;
    if (arr[index] < 0) return index;
    return findFirstNegative(arr, size, index + 1);
}

// ���������� ������� ��� ������ ���������� ��'������ ��������
int findLastNegative(const int* arr, int index) {
    if (index < 0) return -1;
    if (arr[index] < 0) return index;
    return findLastNegative(arr, index - 1);
}

// ���������� ������� ��� ���������� ���� �� ������ �� ������� ��'������ ����������
int sumBetweenNegatives(const int* arr, int start, int end) {
    if (start >= end) return 0;
    return arr[start] + sumBetweenNegatives(arr, start + 1, end);
}

// ���������� ������� ��� ��������� ������ (��������� ��������, ������ ���� <= 1)
void compressArray(int* arr, int size, int index = 0, int newIndex = 0) {
    if (index == size) {
        for (int i = newIndex; i < size; i++) {
            arr[i] = 0; // ���������� ����� ������
        }
        return;
    }

    if ((abs(arr[index]) > 1)) {
        arr[newIndex] = arr[index];
        compressArray(arr, size, index + 1, newIndex + 1);
    }
    else {
        compressArray(arr, size, index + 1, newIndex);
    }
}

int main() {
    // ���������� ��������� ���������� �����
    srand(time(0));


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "������ ������� �������� ������: ";
    cin >> n;

    // �������� �������� ���'�� ��� ������
    int* arr = new int[n];
    InitArray(arr, n ,0);

    cout << "���������� �����: ";
    printArray(arr, n);

    // 1.1. ���� �������� � ��������� ���������
    int sumOdd = sumOddIndexElements(arr, n);
    cout << "���� �������� � ��������� ���������: " << sumOdd << endl;

    // 1.2. ���� �� ������ �� ������� ��'������ ����������
    int firstNeg = findFirstNegative(arr, n);
    int lastNeg = findLastNegative(arr, n - 1);

    if (firstNeg != -1 && lastNeg != -1 && firstNeg < lastNeg) {
        int sumBetween = sumBetweenNegatives(arr, firstNeg + 1, lastNeg);
        cout << "���� �������� �� ������ � ������� ��'������: " << sumBetween << endl;
    }
    else {
        cout << "�� �������� ���� ��'����� �������� ��� ���������� ����." << endl;
    }

    // 2. ��������� ������
    compressArray(arr, n);
    cout << "����� ���� ���������: ";
    printArray(arr, n);

    // ��������� �������� ���'��
    delete[] arr;

    return 0;
}
