#include <iostream>
#include <chrono>

// Dinh nghia hàm inline
inline int square(int x) {
    return x * x;
}

int main() {
    // Ghi nhan thoi diem bat dau
    auto start = std::chrono::steady_clock::now();

    long long result = 0;
    // Goi ham inline nhieu lan de thay ro thoi gian thuc thi
    for (int i = 0; i < 100000000; i++) {
        result += square(i);
    }

    // Ghi nhan thoi diem ket thuc
    auto end = std::chrono::steady_clock::now();

    // Tinh thoi gian chenh lech (don vi: mili-giay hoac nano-giay)
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Ket qua: " << result << std::endl;
    std::cout << "Thoi gian thuc hien: " << duration.count() << " ms" << std::endl;

    return 0;
}

