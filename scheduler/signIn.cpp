#include "signIn.h"
#include "eventsPage.h"
#include "signUp.h"
#include "buttonsPage.h"
signIn::signIn(set<Users>& users, QWidget* parent) : QWidget(parent)
{
    setWindowTitle("Login");
    setFixedSize(900, 550);

    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    titlelayout = new QHBoxLayout();
    title = new QLabel("Welcome!");
    title->setStyleSheet("font: bold 45px; color: #1e2835;");
    title->setAlignment(Qt::AlignCenter);

    titlelayout->addWidget(title);
    titlelayout->setAlignment(Qt::AlignTop);


    mainLayout->addLayout(titlelayout);
    mainLayout->addStretch();

    row1layout = new QHBoxLayout();
    username_label = new QLabel("Username: ");

    username_label->setStyleSheet("font-weight: bold; font-size: 25px; color: #1e2835;");
    username_box = new QLineEdit();
    username_box->setStyleSheet("border: 1px solid #c9c9c9; padding: 5px; font-size: 14px; color: #1e2835;");

    row1layout->addWidget(username_label);
    row1layout->addWidget(username_box);

    mainLayout->addLayout(row1layout);
    mainLayout->addStretch();


    row2layout = new QHBoxLayout();
    row2layout->setSpacing(50);
    password_label = new QLabel("Password: ");
    password_label->setStyleSheet("font-weight: bold; font-size: 25px; color: #1e2835;");

    password_box = new QLineEdit();
    password_box->setEchoMode(QLineEdit::Password);
    password_box->setStyleSheet("border: 1px solid #c9c9c9; padding: 5px; font-size: 14px; color: #1e2835;");

    row2layout->addWidget(password_label);
    row2layout->setSpacing(2);
    row2layout->addWidget(password_box);

    mainLayout->addLayout(row2layout);
    mainLayout->addStretch();

    QCheckBox* showPass = new QCheckBox("Show Password", this);
    showPass->setStyleSheet("color: #1e2835; font-size: 12px;");
    showPass->setFont(QFont("Arial", 12, QFont::Bold));
    rowChecklayout = new QHBoxLayout();
    rowChecklayout->addWidget(showPass);
    mainLayout->addLayout(rowChecklayout);
    showPass->setCheckable(true);
    showPass->setChecked(false); // set initial state
    connect(showPass, &QCheckBox::toggled, [=](bool checked) {
        if (checked) {
            // show password
            password_box->setEchoMode(QLineEdit::Normal);
        }
        else {
            // hide password
            password_box->setEchoMode(QLineEdit::Password);
        }
        });

    row3layout = new QHBoxLayout();
    login = new QPushButton("Login");
    login->setToolTip("Click to log in");

    login->setStyleSheet("background-color: #1e2835; color: white; border: none; padding: 10px 20px; font-size: 14px; font-weight: bold; border-radius: 15px;");



    cancel = new QPushButton("Cancel");
    cancel->setToolTip("Click to cancel");

    cancel->setStyleSheet("background-color: #1e2835; color: white; border: none; padding: 10px 20px; font-size: 14px; font-weight: bold; border-radius: 15px;");

    row3layout->addWidget(login);
    row3layout->addWidget(cancel);


    mainLayout->addLayout(row3layout);
    mainLayout->addStretch();


    connect(login, &QPushButton::clicked, this, [this, &users]() {
        login_pressed(users);
        });

    connect(cancel, &QPushButton::clicked, this, [this, &users]() {
        cancel_pressed(users);
        });

}


void signIn::login_pressed(set<Users>& users)
{
    string username = username_box->text().toStdString();
    string password = password_box->text().toStdString();

    //Search for a user with this username
    auto it = std::find_if(users.begin(), users.end(), [&username](const Users& user)
        {
            return user.name == username;
        });

    //Check if the user exist and the password it correct
    if (it != users.end() && it->pass == password) {
        
        buttonsPage* ep = new buttonsPage(const_cast<Users*>(&(*it)), users);
        ep->show();
        this->close();
    }
    else {
        QMessageBox::information(this, "Login Failed", "Username or password isn't correct."); // user not found
    }

}

void signIn::cancel_pressed(set<Users>& users)
{
    FirstPage* ep = new FirstPage(users);
    ep->show();
    this->close();
}