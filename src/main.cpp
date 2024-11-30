
#include "matrix.h"

int main() {
    {
        std::cout << "-----------------" << "\n";
        std::cout << "OUTPUT CASE: " << "\n";
        Matrix test(2, 2);
        test[0][0] = 1;
        test[0][1] = 2;
        test[1][0] = 3;
        test[1][1] = 4;
        std::cout << test << "\n";
    }

    return 0;
}


