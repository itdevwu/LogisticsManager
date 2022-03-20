#ifndef _LM_IO_ORM_HPP_
#define _LM_IO_ORM_HPP_

#include "../lm_core.hpp"

namespace lm
{
    // sqlite database
    class Database
    {
        private:
            std::string _name;
            sqlite3 *_db;

        public:
            // constructor
            Database(const std::string &name);
            // destructor
            ~Database();

            // open database
            bool open();
            // close database
            bool close();
            // is database open
            bool is_open() const;

            // get database name
            std::string get_name() const;

            // get sqlite error message
            std::string get_error_message() const;

            // get sqlite error code
            int get_error_code() const;

            // execute sqlite query
            bool execute(const std::string &query);

            // is table exist
            bool is_table_exist(const std::string &table);

            // get table row count
            int get_table_row_count(const std::string &table);

            // get table column count
            int get_table_column_count(const std::string &table);

            // get table column type
            std::string get_table_column_type(const std::string &table, const std::string &column);

            // get table column name
            std::string get_table_column_name(const std::string &table, int column);

            // get table column name
            std::string get_table_column_name(const std::string &table, const std::string &column);

            // get table column names
            std::vector<std::string> get_table_column_names(const std::string &table);

            // get table column names
            std::vector<std::string> get_table_column_names(const std::string &table, const std::string &column);

            // get table rows
            std::vector<std::vector<std::string>> get_table_rows(const std::string &table);

            // get table rows
            std::vector<std::vector<std::string>> get_table_rows(const std::string &table, const std::string &column);

            // get table rows
            std::vector<std::vector<std::string>> get_table_rows(const std::string &table, const std::vector<std::string> &columns);

            // get table rows
            std::vector<std::vector<std::string>> get_table_rows(const std::string &table, const std::string &column, const std::string &value);
    };
}

#endif // _LM_IO_ORM_HPP_