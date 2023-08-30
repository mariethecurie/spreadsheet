#ifndef SPREADSHEET_CELL_H
#define SPREADSHEET_CELL_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

class SpreadsheetCell {
public:
    SpreadsheetCell();
    SpreadsheetCell(const SpreadsheetCell& other);
    explicit SpreadsheetCell(std::string&& value);
    void setStringValue(const std::string& value);
    std::string getStringValue() const;
    int getIntValue() const;
    double getDoubleValue() const;
private:
    std::string m_value;
};

#endif
