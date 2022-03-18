#ifndef _LM_USER_HPP_
#define _LM_USER_HPP_

#include "../lm_core.hpp"

namespace lm 
{
    enum UserType
    {
        USER_TYPE_ADMIN = 0,
        USER_TYPE_USER = 1
    };

    class User
    {
        private:
            unsigned short _user_type;
            std::string _username;
            std::string _name;
            std::string _phone;
            std::string _email;
            std::string _password;
            double _balance;
            std::string _address;

            bool _username_valid();
            bool _name_valid();
            bool _phone_valid();
            bool _email_valid();
            bool _password_valid();
            bool _balance_valid();
            bool _address_valid();

        public:
            bool set_usertype(const unsigned short user_type);
            bool set_username(const std::string);
            bool set_name(const std::string);
            bool set_phone(const std::string);
            bool set_email(const std::string);
            bool set_password(const std::string);
            bool set_balance(const double);
            bool set_address(const std::string);

            unsigned short get_usertype() const;
            std::string get_username() const;
            std::string get_name() const;
            std::string get_phone() const;
            std::string get_email() const;
            std::string get_password() const;
            double get_balance() const;
            std::string get_address() const;
    };

    class Admin : public User
    {
        private:

        public:

    };
}

#endif // _LM_USER_HPP_