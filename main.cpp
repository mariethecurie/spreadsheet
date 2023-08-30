#include "spreadsheet.h"

int main() {
    Spreadsheet spreadsheet(3, 4);

    spreadsheet.setCell(0, 0, "Hello");
    spreadsheet.setCell(1, 1, "World");
    spreadsheet.setCell(2, 2, "123");

    std::cout << "Initial Spreadsheet:" << std::endl;
    spreadsheet.print();

    SpreadsheetCell* cell = spreadsheet.getCell(0, 0);
    if (cell) {
        std::cout << "Value at (0, 0): " << cell->getStringValue() << std::endl;
        cell->setStringValue("Updated");
        spreadsheet.removeRow(1);
        spreadsheet.addColumn(1);
    }

    std::cout << "Updated Spreadsheet:" << std::endl;
    spreadsheet.print();

    return 0;
}
