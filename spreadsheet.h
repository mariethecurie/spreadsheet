#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include "spreadsheet_cell.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>

class Spreadsheet {
public:
    Spreadsheet();
    Spreadsheet(int rows, int cols);
    ~Spreadsheet();
    void addRow(int index);
    void addColumn(int index);
    void removeRow(int index);
    void removeColumn(int index);
    SpreadsheetCell* getCell(int row, int col) const;
    void setCell(int row, int col, std::string&& value);
    void setCell(int row, int col, SpreadsheetCell&& cell);
    void print() const;

private:
    int m_rows;
    int m_columns;
    SpreadsheetCell** m_cells;
};

#endif
