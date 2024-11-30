
#include "matrix.h"
#include "square_matrix.h"

void testMatrix() {
    {
        std::cout << "-----------------" << "\n";
        std::cout << "OUTPUT CASE: " << "\n";
        Matrix test(2, 2);
        test[0][0] = 1;
        test[0][1] = 2;
        test[1][0] = 3;
        test[1][1] = 4;
        std::cout << test;
    }

    {
        std::cout << "-----------------" << "\n";
        std::cout << "+ CASE: " << "\n";
        Matrix test1(2, 2);
        test1[0][0] = 1;
        test1[0][1] = 2;
        test1[1][0] = 3;
        test1[1][1] = 4;

        Matrix test2(2, 2);
        test2[0][0] = 4;
        test2[0][1] = 3;
        test2[1][0] = 2;
        test2[1][1] = 1;

        std::cout << test1 + test2;
    }

    {
        std::cout << "-----------------" << "\n";
        std::cout << "- CASE: " << "\n";
        Matrix test1(2, 2);
        test1[0][0] = 1;
        test1[0][1] = 2;
        test1[1][0] = 3;
        test1[1][1] = 4;

        Matrix test2(2, 2);
        test2[0][0] = 4;
        test2[0][1] = 3;
        test2[1][0] = 2;
        test2[1][1] = 1;

        std::cout << test1 - test2;
    }

    {
        std::cout << "-----------------" << "\n";
        std::cout << "* CASE: " << "\n";
        Matrix test1(2, 2);
        test1[0][0] = 1;
        test1[0][1] = 2;
        test1[1][0] = 3;
        test1[1][1] = 4;

        Matrix test2(2, 2);
        test2[0][0] = 4;
        test2[0][1] = 3;
        test2[1][0] = 2;
        test2[1][1] = 1;

        std::cout << test1 * test2;
    }

    {
        std::cout << "-----------------" << "\n";
        std::cout << "= CASE: " << "\n";
        Matrix test1(2, 2);
        test1[0][0] = 1;
        test1[0][1] = 2;
        test1[1][0] = 3;
        test1[1][1] = 4;

        Matrix test2(2, 2);
        test2[0][0] = 4;
        test2[0][1] = 3;
        test2[1][0] = 2;
        test2[1][1] = 1;

        std::cout << "test1 before = test2 : " << "\n" << test1;
        test1 = test2;
        std::cout << "test1 aftr = test2 : " << "\n" << test1;
    }

    {
        std::cout << "-----------------" << "\n";
        std::cout << "== CASE: " << "\n";
        Matrix test1(2, 2);
        test1[0][0] = 1;
        test1[0][1] = 2;
        test1[1][0] = 3;
        test1[1][1] = 4;

        Matrix test2(2, 2);
        test2[0][0] = 4;
        test2[0][1] = 3;
        test2[1][0] = 2;
        test2[1][1] = 1;

        std::cout << "test1 : " << "\n" << test1 << "\n";
        std::cout << "test2 : " << "\n" << test2 << "\n";
        std::cout << "test1 == test2 : " << "\n" << std::boolalpha << (test1 == test2) << "\n";
    }

    {
        std::cout << "-----------------" << "\n";
        std::cout << "!= CASE: " << "\n";
        Matrix test1(2, 2);
        test1[0][0] = 1;
        test1[0][1] = 2;
        test1[1][0] = 3;
        test1[1][1] = 4;

        Matrix test2(2, 2);
        test2[0][0] = 4;
        test2[0][1] = 3;
        test2[1][0] = 2;
        test2[1][1] = 1;

        std::cout << "test1 : " << "\n" << test1 << "\n";
        std::cout << "test2 : " << "\n" << test2 << "\n";
        std::cout << "test1 != test2 : " << "\n" << std::boolalpha << (test1 != test2) << "\n";
    }

    {
        std::cout << "-----------------" << "\n";
        std::cout << "TRANSPONSE CASE: " << "\n";
        Matrix test1(2, 2);
        test1[0][0] = 1;
        test1[0][1] = 2;
        test1[1][0] = 3;
        test1[1][1] = 4;

        std::cout << "test1 before transponse : " << "\n" << test1 << "\n";
        test1.transponse();
        std::cout << "test1 after transponse : " << "\n" << test1 << "\n";
    }

    {
        std::cout << "-----------------" << "\n";
        std::cout << "PRINT CASE: " << "\n";
        Matrix test1(2, 2);
        test1[0][0] = 1;
        test1[0][1] = 2;
        test1[1][0] = 3;
        test1[1][1] = 4;

        test1.print();
    }

    {
        std::cout << "-----------------" << "\n";
        std::cout << "INPUT CASE: " << "\n";
        Matrix test;
        std::cin >> test;
        test.print();
    }
}

void testSquareMatrix() {
    {
        std::cout << "-----------------" << "\n";
        std::cout << "DETERMINANT CASE(SquareMatrix): " << "\n";
        SquareMatrix test(2);
        test[0][0] = 1;
        test[0][1] = 2;
        test[1][0] = 3;
        test[1][1] = 4;
        test.print();
        std::cout << "\nDeterminant: " << test.determinantGauss() << "\n";
    }

    {
        std::cout << "-----------------" << "\n";
        std::cout << "TRANSPONSE CASE(SquareMatrix): " << "\n";
        SquareMatrix test(2);
        test[0][0] = 1;
        test[0][1] = 2;
        test[1][0] = 3;
        test[1][1] = 4;
        std::cout << "\nBefore transponse: \n" << test << "\n";
        test.transponse();
        std::cout << "\nAfter transponse: \n" << test << "\n";
    }

    {
        std::cout << "-----------------" << "\n";
        std::cout << "POWER CASE(SquareMatrix): " << "\n";
        SquareMatrix test(2);
        test[0][0] = 1;
        test[0][1] = 2;
        test[1][0] = 3;
        test[1][1] = 4;
        std::cout << "\nBefore power: \n" << test << "\n";
        test.matrixPower(0);
        std::cout << "\nAfter power: \n" << test << "\n";
    }

    {
        std::cout << "-----------------" << "\n";
        std::cout << "FIRST NORM CASE(SquareMatrix): " << "\n";
        SquareMatrix test(2);
        test[0][0] = 1;
        test[0][1] = 2;
        test[1][0] = 3;
        test[1][1] = 4;
        std::cout << "\nMatrix: \n" << test << "\nFirst Norm: " << test.firstNorm() << "\n";
    }
}
int main() {
    testMatrix();
    testSquareMatrix();
    return 0;
}


