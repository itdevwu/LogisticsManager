// Copyright 2022 Zhenglong WU(itdevwu)
#ifndef _LM_USERLIST_HPP_
#define _LM_USERLIST_HPP_

#include "../lm_core.hpp"

namespace lm
{
    class UserList
    {
        private:
            std::vector<std::string> _user_list;
            std::map<std::string, lm::User> _user_map;

        public:
            bool add_user(const std::string username, const std::string name, const std::string phone, const std::string email, const std::string password, const double balance, const std::string address);
            bool remove_user(const std::string username);
            bool update_user(const std::string username, const std::string name, const std::string phone, const std::string email, const std::string password, const double balance, const std::string address);
            lm::User get_user(const std::string username);
    };
}

#endif // _LM_USERLIST_HPP_