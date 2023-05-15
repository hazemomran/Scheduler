#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_scheduler.h"

class scheduler : public QMainWindow
{
    Q_OBJECT

public:
    scheduler(QWidget *parent = nullptr);
    ~scheduler();

private:
    Ui::schedulerClass ui;
};
