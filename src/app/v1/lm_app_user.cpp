#include "lm_app_user.hpp"
#include "ui_lm_app_user.h"

User::User(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::User)
{
    ui->setupUi(this);
}

User::~User()
{
    delete ui;
}

