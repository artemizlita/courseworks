#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>
#include "road_matrix.h"

class Widget : public QWidget, public road_matrix
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
