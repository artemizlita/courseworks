#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QVector <QLabel *> L_cx_s, L_Condition_x_s, L_x0_s, L_xn_asm_s;
    QVector <QVector <QLabel *> > L_Ax_s;
    QVector <QTextEdit *> T_c_s, T_b_s, T_x0_s;
    QVector <QLabel *> T_xn_asm_s;
    QVector <QVector <QTextEdit *> > T_A_s;
    QVector <short int> signs;
    QVector <QPushButton *> B_sign_s;
    QLabel *L_xn_sm;

    double gamma, lambdak;
    QVector <double> xk, xk_1, dk, c, b, uk, deltaxk, Adkc, Axk;
    QVector <QVector <double> > A, AT, Adk, AdkAT;

    QVector <QVector <double> > Coefficients;
    QVector <double> Basic_variables_values, Indexes, Taus, M;
    QVector <int> Basic_variables;
    double F, F_M;
    bool optimal, no_decision;

    int n, m;
    void new_table();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void slotSigns();

    void on_pushButton_clicked();

    void slotAction();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
