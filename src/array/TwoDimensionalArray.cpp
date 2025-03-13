#include <iostream>

int main()
{
    constexpr int numRows{9};
    constexpr int numCols{9};

    // Declare a 9x9 array
    int product[numRows][numCols]{};

    // Calculate a multiplication table
    for (int row{0}; row < numRows; ++row)
    {
        for (int col{0}; col < numCols; ++col)
        {
            product[row][col] = (row + 1) * (col + 1);
        }
    }

    // Print the table
    for (int row{0}; row < numRows; ++row)
    {
        for (int col{0}; col < numCols; ++col)
        {
            std::cout << product[row][col] << '\t';
        }

        std::cout << '\n';
    }

    return 0;
}