#include "../lm_core.hpp"

bool lm::User::_username_valid()
{
    bool ans = true;

    auto len = _username.length();
    for (auto i = 0; i < len; ++i)
    {
        if ((_username[i] >= 'a' && _username[i] <= 'z') ||
            (_username[i] >= 'A' && _username[i] <= 'Z') ||
            (_username[i] >= '0' && _username[i] <= '9'))
            continue;
        ans = false;
        break;
    }

    return ans;
}

bool lm::User::_name_valid()
{
    bool ans = true;

    return ans;
}

bool lm::User::_phone_valid()
{
    bool ans = true;

    auto len = _phone.length();

    if (len != 11)
        ans = false;
    if (len >= 3)
    {
        ans = true;
        for (auto i = 0; i < len; ++i)
        {
            if (i == 0 && _phone[i] != '+')
            {
                ans = false;
                break;
            }
            if (i > 0 && (_phone[i] < '0' || _phone[i] > '9'))
            {
                ans = false;
                break;
            }
        }
    }

    return ans;
}

// Returns true if _email is a valid email address.
bool lm::User::_email_valid()
{
    bool ans = true;

    auto len = _email.length();
    if (len < 5)
        ans = false;
    if (len >= 5)
    {
        ans = true;
        for (auto i = 0; i < len; ++i)
        {
            if (i == 0 && _email[i] != '@')
            {
                ans = false;
                break;
            }
            if (i > 0 && (_email[i] < 'a' || _email[i] > 'z') &&
                (_email[i] < 'A' || _email[i] > 'Z') &&
                (_email[i] < '0' || _email[i] > '9') &&
                _email[i] != '.' && _email[i] != '_' && _email[i] != '-')
            {
                ans = false;
                break;
            }
        }
    }

    return ans;
}

bool lm::User::_password_valid()
{
    bool ans = true;

    auto len = _password.length();
    if (len < 8)
        ans = false;
    else if (len > 32)
        ans = false;
    else
    {
        auto num_count = 0;
        auto upper_count = 0;
        auto lower_count = 0;
        auto special_count = 0;
        for (auto i = 0; i < len; ++i)
        {
            if (_password[i] >= '0' && _password[i] <= '9')
                ++num_count;
            else if (_password[i] >= 'A' && _password[i] <= 'Z')
                ++upper_count;
            else if (_password[i] >= 'a' && _password[i] <= 'z')
                ++lower_count;
            else
                ++special_count;
        }

        if (num_count < 1)
            ans = false;
        else if (upper_count < 1)
            ans = false;
        else if (lower_count < 1)
            ans = false;
        else if (special_count < 1)
            ans = false;
    }

    return ans;
}

bool lm::User::_balance_valid()
{
    bool ans = true;

    return ans;
}

bool lm::User::_address_valid()
{
    bool ans = true;

    auto len = _address.length();
    for (auto i = 0; i < len; ++i)
    {
        if ((_address[i] >= 'a' && _address[i] <= 'z') ||
            (_address[i] >= 'A' && _address[i] <= 'Z') ||
            (_address[i] >= '0' && _address[i] <= '9') ||
            (_address[i] == ' ' && _address[i] == '.' && _address[i] == ','))
            continue;
        ans = false;
        break;
    }

    return ans;
}

bool lm::User::set_usertype(const unsigned short user_type)
{
    bool ans = true;

    if (user_type != USER_TYPE_ADMIN && user_type != USER_TYPE_USER)
        ans = false;
    else
        _user_type = user_type;

    return ans;
}

bool lm::User::set_username(const std::string username)
{
    bool ans = true;

    _username = username;
    if (!_username_valid())
        ans = false;

    return ans;
}

bool lm::User::set_name(const std::string name)
{
    bool ans = true;

    _name = name;
    if (!_name_valid())
        ans = false;

    return ans;
}

bool lm::User::set_phone(const std::string phone)
{
    bool ans = true;

    _phone = phone;
    if (!_phone_valid())
        ans = false;

    return ans;
}

bool lm::User::set_email(const std::string email)
{
    bool ans = true;

    _email = email;
    if (!_email_valid())
        ans = false;

    return ans;
}

bool lm::User::set_password(const std::string password)
{
    bool ans = true;

    _password = password;
    if (!_password_valid())
        ans = false;

    return ans;
}

bool lm::User::set_balance(const double balance)
{
    bool ans = true;

    _balance = balance;
    if (!_balance_valid())
        ans = false;

    return ans;
}

bool lm::User::set_address(const std::string address)
{
    bool ans = true;

    _address = address;
    if (!_address_valid())
        ans = false;

    return ans;
}

unsigned short lm::User::get_usertype() const
{
    return _user_type;
}

std::string lm::User::get_username() const
{
    return _username;
}

std::string lm::User::get_name() const
{
    return _name;
}

std::string lm::User::get_phone() const
{
    return _phone;
}

std::string lm::User::get_email() const
{
    return _email;
}

std::string lm::User::get_password() const
{
    return _password;
}

double lm::User::get_balance() const
{
    return _balance;
}

std::string lm::User::get_address() const
{
    return _address;
}
