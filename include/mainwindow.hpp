#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionFromToday_triggered();
    void on_actionFromTextChanged_triggered();
    void on_actionToToday_triggered();
    void on_actionToTextChanged_triggered();
    void on_actionQuit_triggered();
    void on_actionUpdateAnswer_triggered();

    void on_fromLineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
