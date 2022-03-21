#ifndef _LM_APP_USER_HPP_
#define _LM_APP_USER_HPP_

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class User; }
QT_END_NAMESPACE

class User : public QWidget
{
    Q_OBJECT

public:
    User(QWidget *parent = nullptr);
    ~User();

private:
    Ui::User *ui;
};
#endif // _LM_APP_USER_HPP_
