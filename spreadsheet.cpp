#include "spreadsheet.h"

Spreadsheet::Spreadsheet()
    : m_rows {0}
    , m_columns {0}
    , m_cells {nullptr} {
}

Spreadsheet::Spreadsheet(int rows, int cols) {
    if (rows <= 0 || cols <=0) {
        throw std::invalid_argument("Invalid number of rows or columns.");
    }

    m_rows = rows;
    m_columns = cols;
    m_cells = new SpreadsheetCell*[m_rows];
    for (int i = 0; i < m_rows; ++i) {
        m_cells[i] = new SpreadsheetCell[m_columns];
        for (int j = 0; j < m_columns; ++j) {
            m_cells[i][j] = SpreadsheetCell{};
        }
    }
}

Spreadsheet::~Spreadsheet() {
    if (m_cells) {
        for (int i = 0; i < m_rows; ++i) {
            for (int j = 0; j < m_columns; ++j) {
                //delete[] m_cells[i];
            }
        }
        delete[] m_cells;
    }
}

void Spreadsheet::addRow(int index) {
    if (index < 0 || index > m_rows) {
        throw std::invalid_argument("Invalid index for row.");
    }

    if (m_cells) {
        SpreadsheetCell** newCells = new SpreadsheetCell*[m_rows + 1];

        for (int i = 0; i < index; ++i) {
            newCells[i] = m_cells[i];
        }

        newCells[index] = new SpreadsheetCell[m_columns];

        for (int i = index; i < m_rows; ++i) {
            newCells[i + 1] = m_cells[i];
        }

        delete[] m_cells;
        m_cells = newCells;
    } else {
        m_cells[0] = new SpreadsheetCell;
    }
    ++m_rows;
}

void Spreadsheet::addColumn(int index) {
    if (index < 0 || index > m_columns || !m_cells) {
        throw std::invalid_argument("Invalid index for column.");
    }

    for (int i = 0; i < m_rows; ++i) {
        SpreadsheetCell* newRow = new SpreadsheetCell[m_columns + 1];

        for (int j = 0; j < index; ++j) {
            newRow[j] = m_cells[i][j];
        }

        newRow[index] = SpreadsheetCell{};

        for (int j = index; j < m_columns; ++j) {
            newRow[j + 1] = m_cells[i][j];
        }

        delete[] m_cells[i];
        m_cells[i] = newRow;
    }
    ++m_columns;
}

void Spreadsheet::removeRow(int index) {
    if (index < 0 || index > m_rows || !m_cells) {
        throw std::invalid_argument("Invalid index for row.");
    }

    if (m_cells) {
        SpreadsheetCell** newCells = new SpreadsheetCell*[m_rows - 1];

        for (int i = 0; i < index; ++i) {
            newCells[i] = m_cells[i];
        }

        for (int i = index; i < m_rows; ++i) {
            newCells[i] = m_cells[i + 1];
        }

        delete[] m_cells;
        m_cells = newCells;
    }
    --m_rows;
}

void Spreadsheet::removeColumn(int index) {
    if (index < 0 || index > m_columns || !m_cells) {
        throw std::invalid_argument("Invalid index for column.");
    }

    for (int i = 0; i < m_rows; ++i) {
        SpreadsheetCell* newRow = new SpreadsheetCell[m_columns - 1];

        for (int j = 0; j < index; ++j) {
            newRow[j] = m_cells[i][j];
        }

        for (int j = index; j < m_columns; ++j) {
            newRow[j] = m_cells[i][j + 1];
        }

        delete[] m_cells[i];
        m_cells[i] = newRow;
    }
    --m_columns;
}

SpreadsheetCell* Spreadsheet::getCell(int row, int col) const {
    if (row < 0 || col < 0 || row >= m_rows || col >= m_columns || !m_cells) {
        throw std::invalid_argument("Invalid index for rows or columns.");
    }
    return &m_cells[row][col];
}

void Spreadsheet::setCell(int row, int col, std::string&& value) {
    if (row < 0 || col < 0 || row >= m_rows || col >= m_columns) {
        throw std::invalid_argument("Invalid index for rows or columns.");
    }
    if (m_cells) {
        m_cells[row][col].setStringValue(value);
    }
}

void Spreadsheet::setCell(int row, int col, SpreadsheetCell&& cell) {
    if (row < 0 || col < 0 || row >= m_rows || col >= m_columns) {
        throw std::invalid_argument("Invalid index for rows or columns.");
    }
    if (m_cells) {
        m_cells[row][col] = cell;
    }
}

void Spreadsheet::print() const {
    const int cellWidth = 10;

    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_columns; ++j) {
            std::cout << " " << std::left << std::setw(cellWidth) << m_cells[i][j].getStringValue();
            if (j < m_columns - 1) {
                std::cout << "  |";
            }
        }
        std::cout << " " << std::endl;

        if (i < m_rows - 1) {
            for (int j = 0; j < m_columns; ++j) {
                std::cout << " " << std::string(cellWidth + 1, '-');
                if (j < m_columns - 1) {
                    std::cout << " +";
                }
            }
            std::cout << " " << std::endl;
        }
    }
}









