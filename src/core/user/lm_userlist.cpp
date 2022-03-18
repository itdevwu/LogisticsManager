// Copyright 2022 Zhenglong WU(itdevwu)
#include "../lm_core.hpp"

bool lm::UserList::add_user(const std::string username, const std::string name, const std::string phone, const std::string email, const std::string password, const double balance, const std::string address)
{
    bool res = true;

    if (username.empty() || name.empty() || phone.empty() || email.empty() || password.empty() || balance < 0 || address.empty())
    {
        res = false;
    }
    else
    {
        if (_user_map.find(username) != _user_map.end())
        {
            res = false;
        }
        else
        {
            User user;
            user.set_usertype(USER_TYPE_USER);
            user.set_username(username);
            user.set_name(name);
            user.set_phone(phone);
            user.set_email(email);
            user.set_password(password);
            user.set_balance(balance);
            user.set_address(address);

            _user_list.push_back(username);
            _user_map[username] = user;
        }
    }

    return res;
}

bool lm::UserList::remove_user(const std::string username)
{
    bool res = true;

    if (username.empty())
    {
        res = false;
    }
    else
    {
        if (_user_map.find(username) == _user_map.end())
        {
            res = false;
        }
        else
        {
            _user_list.erase(std::remove(_user_list.begin(), _user_list.end(), username), _user_list.end());
            _user_map.erase(username);
        }
    }

    return res;
}

bool lm::UserList::update_user(const std::string username, const std::string name, const std::string phone, const std::string email, const std::string password, const double balance, const std::string address)
{
    bool res = true;

    if (username.empty() || name.empty() || phone.empty() || email.empty() || password.empty() || balance < 0 || address.empty())
    {
        res = false;
    }
    else
    {
        if (_user_map.find(username) == _user_map.end())
        {
            res = false;
        }
        else
        {
            User user;
            user.set_usertype(USER_TYPE_USER);
            user.set_username(username);
            user.set_name(name);
            user.set_phone(phone);
            user.set_email(email);
            user.set_password(password);
            user.set_balance(balance);
            user.set_address(address);

            _user_map[username] = user;
        }
    }

    return res;
}

lm::User lm::UserList::get_user(const std::string username)
{
    User user;

    if (username.empty())
    {
        return user;
    }
    else
    {
        if (_user_map.find(username) == _user_map.end())
        {
            return user;
        }
        else
        {
            return _user_map[username];
        }
    }
}
