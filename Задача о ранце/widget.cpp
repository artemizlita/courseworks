#include "widget.h"
#include "pack.h"
#include <algorithm>
#include <vector>

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    createWidgets();
    createConnections();
}

void Widget::createWidgets () {
    this->setWindowTitle("BackPack v 1.0");
    mattab = new QTableWidget(1, 2, this);
    mattab->setGeometry(25, 75, 557, 295);
    but = new QPushButton("start", this);
    but->setGeometry(25, 25, 50, 25);
    butclear = new QPushButton("clear", this);
    butclear->setGeometry(25, 25, 50, 25);
    butclear->setVisible(0);
    QTableWidgetItem *item = new QTableWidgetItem;
    item->setText("v(i)");
    mattab->setHorizontalHeaderItem(0, item);
    mattab->setColumnWidth(0, 30);
    item = new QTableWidgetItem;
    item->setText("c(i)");
    mattab->setHorizontalHeaderItem(1, item);
    mattab->setColumnWidth(1, 30);
    combo = new QComboBox(this);
    QStringList counts (QStringList()<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9");
    combo->addItems (counts);
    combo->setGeometry(100, 25, 50, 25);
    combov = new QComboBox(this);
    QStringList countsv (QStringList()<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"10"<<"11"<<"12"<<"13"<<"14"<<"15"<<"16");
    combov->addItems (countsv);
    combov->setGeometry(175, 25, 50, 25);
}

void Widget::createConnections () {
    connect(but, SIGNAL(clicked()), this, SLOT(slotButton()));
    connect(butclear, SIGNAL(clicked()), this, SLOT(slotButton()));
    connect(combo, SIGNAL(activated(int)), this, SLOT(slotCombo(int)));
    connect(combov, SIGNAL(activated(int)), this, SLOT(slotCombo(int)));
}

void Widget::stepsintable(vector<pair<int, int> > steps, vector<int> cstep) {
    for (int i = 0; i < cstep.size(); ++i) {
        QString s;
        QTableWidgetItem *item = new QTableWidgetItem;
        s.setNum(cstep[i]);
        item->setText(s);
        if (i == cstep.size() - 1) {
            item->setBackground(QBrush("orange"));
        }
        mattab->setItem(steps[i].first, steps[i].second, item);
    }
}

void Widget::slotButton() {
    if (sender()==but) {
        QString r;
        mattab->setColumnCount (BacV + 2);
        for (int i = 0; i < BacV; ++i) {
            QTableWidgetItem *item = new QTableWidgetItem;
            r.setNum(i + 1);
            item->setText(r);
            mattab->setHorizontalHeaderItem(i + 2, item);
            mattab->setColumnWidth(i + 2, 30);
        };
        v.resize(mattab->rowCount());
        c.resize(mattab->rowCount());
        for (int i = 0; i < mattab->rowCount(); ++i) {
            r = mattab->item(i,0)->text();
            v[i] = r.toInt();
            r = mattab->item(i,1)->text();
            c[i] = r.toInt();
        }
        Recurtion(mattab->rowCount() - 1, BacV);
        stepsintable (steps, cstep);
        combo->setVisible(0);
        combov->setVisible(0);
        but->setVisible(0);
        butclear->setVisible(1);
        mattab->setEditTriggers(QAbstractItemView::EditTriggers(0));
    }
    if (sender()==butclear) {
        v.resize(0);
        c.resize(0);
        steps.resize(0);
        cstep.resize(0);
        BacV = 1;
        mattab->clear();
        mattab->setColumnCount (2);
        mattab->setRowCount (1);
        combo->setCurrentIndex(0);
        combov->setCurrentIndex(0);
        combo->setVisible(1);
        combov->setVisible(1);
        but->setVisible(1);
        butclear->setVisible(0);
        mattab->setEditTriggers(QAbstractItemView::EditTriggers(1));
    }
}

void Widget::slotCombo(int k)
{
    if (sender() == combo) {
        mattab->setRowCount(k + 1);
    }
    if (sender() == combov) {
        BacV = k + 1;
    }
}

Widget::~Widget()
{

}
