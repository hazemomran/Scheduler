#include "signUp.h"
#include "signIn.h"
#include "Users.h"
#include "eventsPage.h"
#include <QStackedWidget>
#include <set>
#include <QSignalMapper>
signUp::signUp(set<Users>& users, QWidget* parent) : QWidget(parent)
{

    setWindowTitle("Sign Up");
    setFixedSize(900, 550);

    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    titlelayout = new QHBoxLayout();
    title = new QLabel("Create your account!");
    title->setStyleSheet("font: bold 45px; color: #1e2835;");
    title->setAlignment(Qt::AlignCenter);

    titlelayout->addWidget(title);
    titlelayout->setAlignment(Qt::AlignTop);



    mainLayout->addLayout(titlelayout);
    mainLayout->addStretch();


    row1layout = new QHBoxLayout();
    username_label = new QLabel("Username: ");
    username_label->setStyleSheet("font-weight: bold; font-size: 22px; color: #1e2835;");
    username_box = new QLineEdit();
    
    //username_box->setFixedWidth(300);
    username_box->setFixedHeight(30);
    //username_box->move(200, 300);
    //row1layout->addStretch();
    //row1layout->setAlignment(Qt::AlignCenter);
    //username_label->setAlignment(Qt::AlignLeft);
    //username_box->setAlignment(Qt::AlignLeft);

    extra_label = new QLabel("                                                 ");
    extra_label->setStyleSheet("font-weight: bold; font-size: 14px; color: #1e2835;");

    //row1layout->setSpacing(50);
    row1layout->addWidget(extra_label);
    row1layout->addWidget(username_label);
    //row1layout->setSpacing(50);
    row1layout->addWidget(username_box);
    //row1layout->setSpacing(100);
    row1layout->addWidget(extra_label);

    mainLayout->addLayout(row1layout);
    mainLayout->addStretch();
    mainLayout->setAlignment(Qt::AlignCenter);


    row4layout = new QHBoxLayout();
    // row4layout->setSpacing(50);
    email_label = new QLabel("Email: ");
    email_label->setStyleSheet("font-weight: bold; font-size: 22px; color: #1e2835;");
    email_box = new QLineEdit();
    email_box->setFixedHeight(30);
    extra_label1 = new QLabel("                                                 ");
    extra_label1->setStyleSheet("font-weight: bold; font-size: 14px; color: #1e2835;");

    row4layout->addWidget(extra_label1);
    row4layout->addWidget(email_label);
    row4layout->addWidget(email_box);
    row4layout->addWidget(extra_label1);

    mainLayout->addLayout(row4layout);
    mainLayout->addStretch();




    row2layout = new QHBoxLayout();
    // row2layout->setSpacing(50);
    password_label = new QLabel("Password: ");
    password_label->setStyleSheet("font-weight: bold; font-size: 22px; color: #1e2835;");
    password_box = new QLineEdit();
    password_box->setFixedHeight(30);
    password_box->setEchoMode(QLineEdit::Password);
    extra_label2 = new QLabel("                                                 ");
    extra_label2->setStyleSheet("font-weight: bold; font-size: 14px; color: #1e2835;");

    row2layout->addWidget(extra_label2);
    row2layout->addWidget(password_label);
    row2layout->addWidget(password_box);
    row2layout->addWidget(extra_label2);


    mainLayout->addLayout(row2layout);
    mainLayout->addStretch();




    row5layout = new QHBoxLayout();
    //  row5layout->setSpacing(50);
    confirm_label = new QLabel("Confirm password: ");
    confirm_label->setStyleSheet("font-weight: bold; font-size: 22px; color: #1e2835;");
    confirm_box = new QLineEdit();
    confirm_box->setFixedHeight(30);
    confirm_box->setEchoMode(QLineEdit::Password);
    extra_label3 = new QLabel("                                                 ");
    extra_label3->setStyleSheet("font-weight: bold; font-size: 14px; color: #1e2835;");

    row5layout->addWidget(extra_label3);
    row5layout->addWidget(confirm_label);
    row5layout->addWidget(confirm_box);
    row5layout->addWidget(extra_label3);

    mainLayout->addLayout(row5layout);
    mainLayout->addStretch();

    QCheckBox* showPass = new QCheckBox("Show Password", this);
    showPass->setStyleSheet("color: #1e2835; font-size: 12px;");
    showPass->setFont(QFont("Arial", 12, QFont::Bold));
    rowChecklayout = new QHBoxLayout();
    extra_label4 = new QLabel("");
    extra_label4->setStyleSheet("font-weight: bold; font-size: 14px; color: #1e2835;");

    //rowChecklayout->addWidget(extra_label4);
    rowChecklayout->addWidget(showPass);
    //rowChecklayout->addWidget(extra_label4);

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
    back = new QPushButton("Back");
    back->setStyleSheet("background-color: #1e2835; color: white; border: none; padding: 10px 20px; font-size: 14px; font-weight: bold; border-radius: 15px;");
    sign = new QPushButton("Sign up");
    sign->setStyleSheet("background-color: #1e2835; color: white; border: none; padding: 10px 20px; font-size: 14px; font-weight: bold; border-radius: 15px;");
    row3layout->addWidget(sign);
    row3layout->addWidget(back);
    //row3layout->addStretch();

    mainLayout->addLayout(row3layout);
    mainLayout->addStretch();
    //setWindowTitle("Sign Up");
    //setFixedSize(900, 550);

    //mainLayout = new QVBoxLayout();
    //setLayout(mainLayout);

    //titlelayout = new QHBoxLayout();
    //title = new QLabel("Create your account!");
    //title->setStyleSheet("font: bold 45px; color: #1e2835;");
    //title->setAlignment(Qt::AlignCenter);

    //titlelayout->addWidget(title);
    //titlelayout->setAlignment(Qt::AlignTop);



    //mainLayout->addLayout(titlelayout);
    //mainLayout->addStretch();


    //row1layout = new QHBoxLayout();
    //username_label = new QLabel("Username: ");
    //username_label->setStyleSheet("font-weight: bold; font-size: 14px; color: #1e2835;");
    //username_box = new QLineEdit();

    //row1layout->addWidget(username_label);
    //row1layout->addWidget(username_box);

    //mainLayout->addLayout(row1layout);

    //row4layout = new QHBoxLayout();
    // row4layout->setSpacing(50);
    //email_label = new QLabel("Email: ");
    //email_label->setStyleSheet("font-weight: bold; font-size: 14px; color: #1e2835;");
    //email_box = new QLineEdit();
    //row4layout->addWidget(email_label);
    //row4layout->addWidget(email_box);

    //mainLayout->addLayout(row4layout);



    //row2layout = new QHBoxLayout();
    // row2layout->setSpacing(50);
    //password_label = new QLabel("Password: ");
    //password_label->setStyleSheet("font-weight: bold; font-size: 14px; color: #1e2835;");
    //password_box = new QLineEdit();
    //password_box->setEchoMode(QLineEdit::Password);

    //row2layout->addWidget(password_label);
    //row2layout->addWidget(password_box);


    //mainLayout->addLayout(row2layout);



    //row5layout = new QHBoxLayout();
    //  row5layout->setSpacing(50);
    //confirm_label = new QLabel("Confirm password: ");
    //confirm_label->setStyleSheet("font-weight: bold; font-size: 14px; color: #1e2835;");
    //confirm_box = new QLineEdit();
    //confirm_box->setEchoMode(QLineEdit::Password);

    //row5layout->addWidget(confirm_label);
    //row5layout->addWidget(confirm_box);

    //mainLayout->addLayout(row5layout);
    //QCheckBox* showPass = new QCheckBox("Show Password", this);
    //showPass->setStyleSheet("color: #1e2835; font-size: 12px;");
    //showPass->setFont(QFont("Arial", 12, QFont::Bold));
    //rowChecklayout = new QHBoxLayout();
    //rowChecklayout->addWidget(showPass);

    //mainLayout->addLayout(rowChecklayout);
    //showPass->setCheckable(true);
    //showPass->setChecked(false); // set initial state
    //connect(showPass, &QCheckBox::toggled, [=](bool checked) {
    //    if (checked) {
    //         show password
    //        password_box->setEchoMode(QLineEdit::Normal);
    //    }
    //    else {
    //         hide password
    //        password_box->setEchoMode(QLineEdit::Password);
    //    }
    //    });




    //row3layout = new QHBoxLayout();
    //back = new QPushButton("Back");
    //back->setStyleSheet("background-color: #1e2835; color: white; border: none; padding: 10px 20px; font-size: 14px; font-weight: bold; border-radius: 25px;");
    //sign = new QPushButton("Sign up");
    //sign->setStyleSheet("background-color: #1e2835; color: white; border: none; padding: 10px 20px; font-size: 14px; font-weight: bold; border-radius: 25px;");
    //row3layout->addWidget(sign);
    //row3layout->addWidget(back);
    //row3layout->addStretch();

    //mainLayout->addLayout(row3layout);


    //connect(back, &QPushButton::clicked, this, &signUp::back_pressed);
    //connect(sign, &QPushButton::clicked, this, &signUp::sign_pressed);
    connect(back, &QPushButton::clicked, this, [this, &users]() {
        back_pressed(users);
        });
    connect(sign, &QPushButton::clicked, this, [this, &users]() {
        sign_pressed(users);
        });



}
void signUp::back_pressed(set<Users>& users)
{
    // Modify the users set here
    FirstPage* first = new FirstPage(users);
    first->show();
    this->close();
}


void signUp::sign_pressed(set<Users>& users)
{
    string name = username_box->text().toStdString();
    string email = email_box->text().toStdString();
    string password = password_box->text().toStdString();
    string confirm_password = confirm_box->text().toStdString();

    auto it = std::find_if(users.begin(), users.end(), [&email](const Users& users)
        {
            return users.email == email;
        });

    if (validate_signup(users, name, email, password, confirm_password)) {
        if (it != users.end())
        {
            QMessageBox::information(this, "User exists", "User already exist!");
        }
        else
        {
            Users user(name, email, password);
            users.insert(user);
            signIn* e = new signIn(users);
            e->show();
            this->close();
        }
    }

}



bool signUp::validate_signup(const set<Users>& users,
    const string& username,
    const string& email,
    const string& password,
    const string& confirm_password) {

    // Check username and password length
    if (username.length() < 8) {
        QMessageBox::information(this, "Check Username", "Your username should be more than 8 characters.");
        return false;
    }

    // Check email format
    size_t at_pos = email.find('@');
    size_t dot_pos = email.find(".com");
    if (at_pos == string::npos ||
        dot_pos == string::npos ||
        dot_pos <= at_pos + 1) {
        QMessageBox::information(this, "Check Email", "Please write your email in a right format!");
        return false;
    }

    // Check email uniqueness
    for (const auto& user : users) {
        if (user.email == email) {
            QMessageBox::information(this, "Check Email", "This email already exist!");
            return false;
        }
    }



    if (password.length() < 8) {
        QMessageBox::information(this, "Check Password", "Your password should be more than 8 characters.");
        return false;
    }

    // Check password confirmation
    if (password != confirm_password) {
        QMessageBox::information(this, "Check Password", "Passwords don't match!");
        return false;
    }

    // Passed all checks
    return true;
}