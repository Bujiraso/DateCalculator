#include "mainwindow.h"
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

void MainWindow::on_calculateButton_clicked()
{
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
