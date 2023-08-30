#include "spreadsheet_cell.h"

SpreadsheetCell::SpreadsheetCell()
    : m_value {" "} {
}
SpreadsheetCell::SpreadsheetCell(std::string&& value)
    : m_value {std::move(value)} {
}

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& other) {
    m_value = other.m_value;
}

void SpreadsheetCell::setStringValue(const std::string& value) {
    m_value = value;
}

std::string SpreadsheetCell::getStringValue() const {
    return m_value;
}

int SpreadsheetCell::getIntValue() const {
    std::stringstream ss(m_value);
    int intValue;
    if(!(ss >> intValue)) {
        throw std::runtime_error("Invalid format to convert to int.");
    }

    return intValue;
}

double SpreadsheetCell::getDoubleValue() const {
    std::stringstream ss(m_value);
    double doubleValue;
    if(!(ss >> doubleValue)) {
        throw std::runtime_error("Invalid format to convert to double.");
    }

    return doubleValue;
}
