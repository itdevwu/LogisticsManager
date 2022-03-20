// Copyright 2022 Zhenglong WU(itdevwu)

#include "../lm_core.hpp"

lm::Database::Database(const std::string &name)
{
    this->_name = name;
}

lm::Database::~Database()
{
    this->close();
}

bool lm::Database::open()
{
    if (this->is_open())
    {
        return true;
    }

    if (sqlite3_open(this->_name.c_str(), &this->_db) != SQLITE_OK)
    {
        return false;
    }

    return true;
}

bool lm::Database::close()
{
    if (!this->is_open())
    {
        return true;
    }

    if (sqlite3_close(this->_db) != SQLITE_OK)
    {
        return false;
    }

    return true;
}

bool lm::Database::is_open() const
{
    return this->_db != nullptr;
}

std::string lm::Database::get_name() const
{
    return this->_name;
}

std::string lm::Database::get_error_message() const
{
    return std::string(sqlite3_errmsg(this->_db));
}

int lm::Database::get_error_code() const
{
    return sqlite3_errcode(this->_db);
}

bool lm::Database::execute(const std::string &query)
{
    if (!this->is_open())
    {
        return false;
    }

    char *errmsg = nullptr;
    if (sqlite3_exec(this->_db, query.c_str(), nullptr, nullptr, &errmsg) != SQLITE_OK)
    {
        return false;
    }

    return true;
}

bool lm::Database::is_table_exist(const std::string &table)
{
    if (!this->is_open())
    {
        return false;
    }

    std::string query = "SELECT name FROM sqlite_master WHERE type='table' AND name='" + table + "'";
    char *errmsg = nullptr;
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(this->_db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        return false;
    }

    if (sqlite3_step(stmt) != SQLITE_ROW)
    {
        return false;
    }

    return true;
}

int lm::Database::get_table_row_count(const std::string &table)
{
    if (!this->is_open())
    {
        return 0;
    }

    std::string query = "SELECT COUNT(*) FROM " + table;
    char *errmsg = nullptr;
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(this->_db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        return 0;
    }

    if (sqlite3_step(stmt) != SQLITE_ROW)
    {
        return 0;
    }

    return sqlite3_column_int(stmt, 0);
}

int lm::Database::get_table_column_count(const std::string &table)
{
    if (!this->is_open())
    {
        return 0;
    }

    std::string query = "SELECT COUNT(*) FROM " + table + " LIMIT 0";
    char *errmsg = nullptr;
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(this->_db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        return 0;
    }

    if (sqlite3_step(stmt) != SQLITE_ROW)
    {
        return 0;
    }

    return sqlite3_column_int(stmt, 0);
}

std::string lm::Database::get_table_column_type(const std::string &table, const std::string &column)
{
    if (!this->is_open())
    {
        return "";
    }

    std::string query = "SELECT " + column + " FROM " + table + " LIMIT 0";
    char *errmsg = nullptr;
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(this->_db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        return "";
    }

    if (sqlite3_step(stmt) != SQLITE_ROW)
    {
        return "";
    }

    return std::string(sqlite3_column_decltype(stmt, 0));
}

std::string lm::Database::get_table_column_name(const std::string &table, int column)
{
    if (!this->is_open())
    {
        return "";
    }

    std::string query = "SELECT * FROM " + table + " LIMIT 0";
    char *errmsg = nullptr;
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(this->_db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        return "";
    }

    if (sqlite3_step(stmt) != SQLITE_ROW)
    {
        return "";
    }

    return std::string(sqlite3_column_name(stmt, column));
}

std::string lm::Database::get_table_column_name(const std::string &table, const std::string &column)
{
    if (!this->is_open())
    {
        return "";
    }

    std::string query = "SELECT " + column + " FROM " + table + " LIMIT 0";
    char *errmsg = nullptr;
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(this->_db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        return "";
    }

    if (sqlite3_step(stmt) != SQLITE_ROW)
    {
        return "";
    }

    return std::string(sqlite3_column_name(stmt, 0));
}

std::vector<std::string> lm::Database::get_table_column_names(const std::string &table)
{
    if (!this->is_open())
    {
        return std::vector<std::string>();
    }

    std::string query = "SELECT * FROM " + table + " LIMIT 0";
    char *errmsg = nullptr;
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(this->_db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        return std::vector<std::string>();
    }

    if (sqlite3_step(stmt) != SQLITE_ROW)
    {
        return std::vector<std::string>();
    }

    int column_count = sqlite3_column_count(stmt);
    std::vector<std::string> column_names;
    for (int i = 0; i < column_count; i++)
    {
        column_names.push_back(std::string(sqlite3_column_name(stmt, i)));
    }

    return column_names;
}

std::vector<std::string> lm::Database::get_table_column_names(const std::string &table, const std::string &column)
{
    if (!this->is_open())
    {
        return std::vector<std::string>();
    }

    std::string query = "SELECT " + column + " FROM " + table + " LIMIT 0";
    char *errmsg = nullptr;
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(this->_db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        return std::vector<std::string>();
    }

    if (sqlite3_step(stmt) != SQLITE_ROW)
    {
        return std::vector<std::string>();
    }

    int column_count = sqlite3_column_count(stmt);
    std::vector<std::string> column_names;
    for (int i = 0; i < column_count; i++)
    {
        column_names.push_back(std::string(sqlite3_column_name(stmt, i)));
    }

    return column_names;
}

std::vector<std::vector<std::string>> lm::Database::get_table_rows(const std::string &table)
{
    if (!this->is_open())
    {
        return std::vector<std::vector<std::string>>();
    }

    std::string query = "SELECT * FROM " + table;
    char *errmsg = nullptr;
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(this->_db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        return std::vector<std::vector<std::string>>();
    }

    std::vector<std::vector<std::string>> rows;
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::vector<std::string> row;
        int column_count = sqlite3_column_count(stmt);
        for (int i = 0; i < column_count; i++)
        {
            row.push_back(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, i))));
        }

        rows.push_back(row);
    }

    return rows;
}

std::vector<std::vector<std::string>> lm::Database::get_table_rows(const std::string &table, const std::string &column)
{
    if (!this->is_open())
    {
        return std::vector<std::vector<std::string>>();
    }

    std::string query = "SELECT " + column + " FROM " + table;
    char *errmsg = nullptr;
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(this->_db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        return std::vector<std::vector<std::string>>();
    }

    std::vector<std::vector<std::string>> rows;
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::vector<std::string> row;
        int column_count = sqlite3_column_count(stmt);
        for (int i = 0; i < column_count; i++)
        {
            row.push_back(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, i))));
        }

        rows.push_back(row);
    }

    return rows;
}

std::vector<std::vector<std::string>> lm::Database::get_table_rows(const std::string &table, const std::vector<std::string> &columns)
{
    if (!this->is_open())
    {
        return std::vector<std::vector<std::string>>();
    }

    std::string query = "SELECT ";
    for (auto &column : columns)
    {
        query += column + ", ";
    }

    query.pop_back();
    query.pop_back();
    query += " FROM " + table;
    char *errmsg = nullptr;
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(this->_db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        return std::vector<std::vector<std::string>>();
    }

    std::vector<std::vector<std::string>> rows;
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::vector<std::string> row;
        int column_count = sqlite3_column_count(stmt);
        for (int i = 0; i < column_count; i++)
        {
            row.push_back(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, i))));
        }

        rows.push_back(row);
    }

    return rows;
}

std::vector<std::vector<std::string>> lm::Database::get_table_rows(const std::string &table, const std::string &column, const std::string &value)
{
    if (!this->is_open())
    {
        return std::vector<std::vector<std::string>>();
    }

    std::string query = "SELECT " + column + " FROM " + table + " WHERE " + column + " = '" + value + "'";
    char *errmsg = nullptr;
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(this->_db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        return std::vector<std::vector<std::string>>();
    }

    std::vector<std::vector<std::string>> rows;
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::vector<std::string> row;
        int column_count = sqlite3_column_count(stmt);
        for (int i = 0; i < column_count; i++)
        {
            row.push_back(std::string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, i))));
        }

        rows.push_back(row);
    }

    return rows;
}
