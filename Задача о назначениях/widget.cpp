#include "widget.h"
#include "W_and_P.h"
#include <Qt>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    createWidgets();
    createConnections();
}

void Widget::createWidgets () {
    mattab = new QTableWidget(2, 2, this);
    mattab->setGeometry(25, 75, 257, 265);
    mattab->setColumnWidth(0, 30);
    mattab->setColumnWidth(1, 30);
    but = new QPushButton("start", this);
    but->setGeometry(25, 25, 50, 25);
    butclear = new QPushButton("clear", this);
    butclear->setGeometry(25, 25, 50, 25);
    butclear->setVisible(0);
    combo = new QComboBox(this);
    QStringList counts (QStringList()<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8");
    combo->addItems (counts);
    combo->setGeometry(100, 25, 50, 25);
}

void Widget::createConnections () {
    connect(but, SIGNAL(clicked()), this, SLOT(slotButton()));
    connect(butclear, SIGNAL(clicked()), this, SLOT(slotButton()));
    connect(combo, SIGNAL(activated(int)), this, SLOT(slotCombo(int)));
}

void Widget::tableinmatrix() {
    QString r;
    matrix.resize(n);
    for(int i = 0; i < n; ++i) {
        matrix[i].resize(n);
        for(int j = 0; j < n; ++j) {
            r = mattab->item(i, j)->text();
            matrix[i][j] = r.toInt();
        }
    }
}

void Widget::slotButton() {
    if (sender() == but) {
        tableinmatrix();
        find_change();
        for (int i = 0; i < n; ++i) {
            QTableWidgetItem *item = new QTableWidgetItem;
            QString s;
            s = mattab->item(places[i], i)->text();
            item->setBackground(QBrush("green"));
            item->setText(s);
            mattab->setItem(places[i], i, item);
        }
        combo->setVisible(0);
        but->setVisible(0);
        butclear->setVisible(1);
        mattab->setEditTriggers(QAbstractItemView::EditTriggers(0));
    }
    if (sender() == butclear) {
        n = 2;
        places.clear();
        mattab->clear();
        mattab->setColumnCount (2);
        mattab->setRowCount (2);
        combo->setCurrentIndex(0);
        combo->setVisible(1);
        but->setVisible(1);
        butclear->setVisible(0);
        mattab->setEditTriggers(QAbstractItemView::EditTriggers(1));
    }
}

void Widget::slotCombo(int k)
{
    if (sender() == combo) {
        n = k + 2;
        mattab->setRowCount(k + 2);
        mattab->setColumnCount(k + 2);
        for (int i = 0; i < k + 2; ++i) {
            mattab->setColumnWidth(i, 30);
        }
    }
}

Widget::~Widget()
{

}
