#include <iostream>

class TinhTong {
private:
    int so_a;
    int so_b;

public:
    TinhTong(int a, int b) {
        so_a = a;
        so_b = b;
    }

    int tinhTong() {
        return so_a + so_b;
    }
};

int main() {
    int so_a, so_b;
    std::cout << "";
    std::cin >> so_a;
    std::cout << "";
    std::cin >> so_b;

    TinhTong tong_hai_so(so_a, so_b);

    int ket_qua = tong_hai_so.tinhTong();
    std::cout << ket_qua << std::endl;

    return 0;
}
