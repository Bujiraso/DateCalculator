#include "include/mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QDate>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    exit(0);
}

void MainWindow::on_actionFromTextChanged_triggered()
{
    if (ui->fromLineEdit->inputMask() == ""){
            ui->fromLineEdit->setInputMask("99\\/99\\/9999");
            ui->fromLineEdit->setCursorPosition(1);
    }
}

void MainWindow::on_actionFromToday_triggered() {
    QDate cd = QDate::currentDate();
    ui->fromLineEdit->setText(cd.toString("dd/MM/yyyy"));
    ui->fromLineEdit->setInputMask("99\\/99\\/9999");
    ui->fromLineEdit->setCursorPosition(10);
    ui->toLineEdit->setFocus();
}

void MainWindow::on_fromLineEdit_cursorPositionChanged(int oldP, int newP) {
    if (oldP == 9 && newP == 10) {
        ui->toLineEdit->setFocus();
    }
}


void MainWindow::on_actionToTextChanged_triggered()
{
    if (ui->toLineEdit->inputMask() == ""){
            ui->toLineEdit->setInputMask("99\\/99\\/9999");
            ui->toLineEdit->setCursorPosition(1);
    }
}

void MainWindow::on_actionToToday_triggered() {
    QDate cd = QDate::currentDate();
    ui->toLineEdit->setText(cd.toString("dd/MM/yyyy"));
    ui->toLineEdit->setInputMask("99\\/99\\/9999");
    ui->toLineEdit->setCursorPosition(10);
}

void MainWindow::on_actionUpdateAnswer_triggered()
{
    //Check field lengths (inputs are already masked)
    if (ui->fromLineEdit->text().length() < 10 || ui->toLineEdit->text().length() < 10) {
        ui->answerLabel->setText("Invalid input");
        return;
    }
    //Compute from date
    int fDay = ui->fromLineEdit->text().left(2).toInt();
    int fMo = ui->fromLineEdit->text().mid(3,2).toInt();
    int fYr = ui->fromLineEdit->text().right(4).toInt();
    QDate frDate(fYr, fMo, fDay);

    //Computer to date
    int tDay = ui->toLineEdit->text().left(2).toInt();
    int tMo = ui->toLineEdit->text().mid(3,2).toInt();
    int tYr = ui->toLineEdit->text().right(4).toInt();
    QDate toDate(tYr, tMo, tDay);

    QString answer("There are " + QString::number(frDate.daysTo(toDate)) + " days between these dates.");
    ui->answerLabel->setText(answer);
}
