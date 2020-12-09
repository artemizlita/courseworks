#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>
#include "W_and_P.h"

class Widget : public QWidget, public W_and_P
{
    Q_OBJECT
    QPushButton *but, *butclear;
    QComboBox *combo;
    void createWidgets();
    void createConnections();
public:
    QTableWidget *mattab;
    void tableinmatrix();
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void slotButton();
    void slotCombo(int k);
};

#endif // WIDGET_H
