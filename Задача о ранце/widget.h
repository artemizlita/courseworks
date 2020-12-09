#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <vector>
#include "pack.h"

using namespace std;

class Widget : public QWidget, public pack
{
    Q_OBJECT
    QPushButton *but, *butclear;
    QComboBox *combo, *combov;
    void createWidgets();
    void createConnections();
public:
    QTableWidget *mattab;
    void stepsintable(vector<pair<int,int> > steps, vector<int> cstep);
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void slotButton();
    void slotCombo(int k);
};

#endif // WIDGET_H
