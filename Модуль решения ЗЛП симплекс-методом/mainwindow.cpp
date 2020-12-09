#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Qt>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    n = 2, m = 1;

    L_cx_s.resize(60);
    L_Condition_x_s.resize(60);
    L_Ax_s.resize(30);
    L_x0_s.resize(20);
    L_xn_asm_s.resize(20);
    T_c_s.resize(20);
    T_A_s.resize(30);
    T_b_s.resize(30);
    T_x0_s.resize(20);
    T_xn_asm_s.resize(20);
    B_sign_s.resize(30);
    signs.resize(30);
    for (int i = 0; i < 20; ++i) {
        QLabel *L_cx, *L_cx2, *L_cx3, *L_Condition_x, *L_Condition_x2, *L_Condition_x3, *L_x0, *L_xn_asm;
        QTextEdit *T_c, *T_x0;
        QLabel *T_xn_asm;

        T_c = new QTextEdit(ui->groupBox);
        T_c_s[i] = T_c;
        T_c_s[i]->setStyleSheet("font-size: 12px");
        T_c_s[i]->setGeometry(i * 85 + 10, 15, 50, 25);
        //T_c_s[i]->setAlignment(Qt::AlignRight);

        L_cx = new QLabel(ui->groupBox);
        L_cx_s[3 * i] = L_cx;
        L_cx_s[3 * i]->setStyleSheet("font-size: 18px");
        L_cx_s[3 * i]->setGeometry(i * 85 + 62, 12, 15, 30);
        L_cx_s[3 * i]->setText("X");

        L_cx2 = new QLabel(ui->groupBox);
        L_cx_s[3 * i + 1] = L_cx2;
        L_cx_s[3 * i + 1]->setStyleSheet("font-size: 12px");
        L_cx_s[3 * i + 1]->setGeometry(i * 85 + 72, 27, 10, 10);
        L_cx_s[3 * i + 1]->setText(QString().number(i + 1));

        L_cx3 = new QLabel(ui->groupBox);
        L_cx_s[3 * i + 2] = L_cx3;
        L_cx_s[3 * i + 2]->setStyleSheet("font-size: 18px");
        L_cx_s[3 * i + 2]->setGeometry(i * 85 + 80, 10, 20, 30);
        L_cx_s[3 * i + 2]->setText("+");

        L_Condition_x = new QLabel(ui->groupBox_13);
        L_Condition_x_s[3 * i] = L_Condition_x;
        L_Condition_x_s[3 * i]->setStyleSheet("font-size: 18px");
        L_Condition_x_s[3 * i]->setGeometry(i * 85 + 10, 10, 15, 30);
        L_Condition_x_s[3 * i]->setText("X");

        L_Condition_x2 = new QLabel(ui->groupBox_13);
        L_Condition_x_s[3 * i + 1] = L_Condition_x2;
        L_Condition_x_s[3 * i + 1]->setStyleSheet("font-size: 12px");
        L_Condition_x_s[3 * i + 1]->setGeometry(i * 85 + 20, 25, 10, 10);
        L_Condition_x_s[3 * i + 1]->setText(QString().number(i + 1));

        L_Condition_x3 = new QLabel(ui->groupBox_13);
        L_Condition_x_s[3 * i + 2] = L_Condition_x3;
        L_Condition_x_s[3 * i + 2]->setStyleSheet("font-size: 18px");
        L_Condition_x_s[3 * i + 2]->setGeometry(i * 85 + 25, 10, 50, 30);
        L_Condition_x_s[3 * i + 2]->setText(">=0;");

        T_x0 = new QTextEdit(ui->groupBox_4);
        T_x0_s[i] = T_x0;
        T_x0_s[i]->setStyleSheet("font-size: 12px");
        T_x0_s[i]->setGeometry(i * 120 + 60, 15, 60, 25);

        L_x0 = new QLabel(ui->groupBox_4);
        L_x0_s[i] = L_x0;
        L_x0_s[i]->setStyleSheet("font-size: 18px");
        L_x0_s[i]->setGeometry(i * 120 + 10, 10, 60, 30);
        L_x0_s[i]->setText("X[" + QString().number(i + 1) + "]=");

        L_xn_asm = new QLabel(ui->groupBox_8);
        L_xn_asm_s[i] = L_xn_asm;
        L_xn_asm_s[i]->setStyleSheet("font-size: 18px");
        L_xn_asm_s[i]->setGeometry(i * 120 + 10, 10, 60, 30);
        L_xn_asm_s[i]->setText("X[" + QString().number(i + 1) + "]=");

        T_xn_asm = new QLabel(ui->groupBox_8);
        T_xn_asm_s[i] = T_xn_asm;
        T_xn_asm_s[i]->setStyleSheet("font-size: 18px");
        T_xn_asm_s[i]->setGeometry(i * 120 + 60, 15, 60, 25);
    }

    ui->label_10->setStyleSheet("font-size: 18px");
    ui->textEdit_3->setStyleSheet("font-size: 12px");

    L_xn_sm = new QLabel(ui->groupBox_6);
    L_xn_sm->setGeometry(10, 10, n * 100 + 15, 30);
    L_xn_sm->setStyleSheet("font-size: 18px");

    for (int i = 0; i < 30; ++i) {
        signs[i] = 0;
        L_Ax_s[i].resize(60);
        T_A_s[i].resize(20);
        for (int j = 0; j < 20; ++j) {
            QTextEdit *T_A;
            QLabel *L_Ax, *L_Ax2, *L_Ax3;
            T_A = new QTextEdit(ui->groupBox_2);
            T_A_s[i][j] = T_A;
            T_A_s[i][j]->setStyleSheet("font-size: 12px");
            T_A_s[i][j]->setGeometry(j * 85 + 10, 40 * i + 15, 50, 25);

            L_Ax = new QLabel(ui->groupBox_2);
            L_Ax_s[i][3 * j] = L_Ax;
            L_Ax_s[i][3 * j]->setStyleSheet("font-size: 18px");
            L_Ax_s[i][3 * j]->setGeometry(j * 85 + 62, 40 * i + 12, 15, 30);
            L_Ax_s[i][3 * j]->setText("X");

            L_Ax2 = new QLabel(ui->groupBox_2);
            L_Ax_s[i][3 * j + 1] = L_Ax2;
            L_Ax_s[i][3 * j + 1]->setStyleSheet("font-size: 12px");
            L_Ax_s[i][3 * j + 1]->setGeometry(j * 85 + 72, 40 * i + 28, 10, 10);
            L_Ax_s[i][3 * j + 1]->setText(QString().number(j + 1));

            L_Ax3 = new QLabel(ui->groupBox_2);
            L_Ax_s[i][3 * j + 2] = L_Ax3;
            L_Ax_s[i][3 * j + 2]->setStyleSheet("font-size: 18px");
            L_Ax_s[i][3 * j + 2]->setGeometry(j * 85 + 80, 40 * i + 10, 20, 30);
            L_Ax_s[i][3 * j + 2]->setText("+");
        }

        QPushButton *B_sign;
        B_sign = new QPushButton(ui->groupBox_9);
        B_sign_s[i] = B_sign;
        B_sign_s[i]->setStyleSheet("font-size: 18px");
        B_sign_s[i]->setGeometry(5, 15 + 40 * i, 30, 25);
        B_sign_s[i]->setText(">=");

        QTextEdit *T_b;
        T_b = new QTextEdit(ui->groupBox_10);
        T_b_s[i] = T_b;
        T_b_s[i]->setGeometry(5, 15 + 40 * i, 50, 25);
        T_b_s[i]->setStyleSheet("font-size: 12px");
    }

    ui->comboBox->setStyleSheet("font-size: 16px");

    ui->label_9->setStyleSheet("font-size: 18px");

    for (int i = 0; i < 30; ++i) {
        connect(B_sign_s[i], SIGNAL(clicked()), this, SLOT(slotSigns()));
    }

    new_table();

    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(slotAction()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(slotAction()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(slotAction()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(slotAction()));
}

void MainWindow::new_table() {
    setGeometry(100, 100, n * 85 + 165, m * 40 + 250);
    setFixedSize(n * 85 + 165, m * 40 + 250);
    ui->groupBox->setGeometry(10, 10, n * 85 - 5, 50);
    ui->groupBox_12->setGeometry(n * 85 + 5, 10, 65, 50);
    ui->groupBox_11->setGeometry(n * 85 + 70, 10, 85, 50);
    ui->groupBox_2->setGeometry(10, 70, n * 85 - 5, m * 40 + 10);
    ui->groupBox_9->setGeometry(n * 85 + 5, 70, 40, m * 40 + 10);
    ui->groupBox_10->setGeometry(n * 85 + 45, 70, 65, m * 40 + 10);
    ui->groupBox_13->setGeometry(10, m * 40 + 90, n * 85 - 10, 45);
    ui->groupBox_5->setGeometry(n * 85 + 10, m * 40 + 90, 60, 45);
    ui->groupBox_6->setGeometry(10, m * 40 + 145, n * 85 + 145, 45);
    ui->groupBox_4->setGeometry(10, m * 40 + 200, n * 85, 50);
    ui->groupBox_7->setGeometry(10, m * 40 + 270, 60, 50);
    ui->groupBox_8->setGeometry(90, m * 40 + 270, n * 85, 50);
    for (int i = 0; i < 20; ++i) {
        T_c_s[i]->setText("");
    }
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 20; ++j) {
            T_A_s[i][j]->setText("");
        }
        T_b_s[i]->setText("");
        B_sign_s[i]->setText(">=");
        signs[i] = 0;
    }
    L_xn_sm->setText("");
    ui->textEdit_3->setText("");
}

void MainWindow::slotAction() {
    if (sender() == ui->actionNew) {
        bool ok = 0, ok_int = 0;
        QString text;
        n = 0, m = 0;

        while (!ok || !ok_int || n < 2 || n > 9) {
            ok = 0;
            ok_int = 0;
            text = QInputDialog::getText(this, tr("Pareto"), tr("Введите число переменных:"), QLineEdit::Normal, "", &ok);
            if (ok && !text.isEmpty()) {
                n = text.toInt(&ok_int);
            }
        }

        ok = 0;
        ok_int = 0;

        while (!ok || !ok_int || m <= 0 || m > 15) {
            ok = 0;
            ok_int = 0;
            text = QInputDialog::getText(this, tr("Pareto"), tr("Введите число ограничений:"), QLineEdit::Normal, "", &ok);
            if (ok && !text.isEmpty()) {
                m = text.toInt(&ok_int);
            }
        }

        new_table();
    }
    if (sender() == ui->actionSave) {
        QString fName = QFileDialog::getSaveFileName(this, tr("Save File"), "./", tr("matr(*.txt)"));
        QString suf = QFileInfo(fName).suffix();
        if (suf.isEmpty()) fName.append(".txt");
        QFile file(fName);
        if (!file.open(QIODevice::WriteOnly)) {
            qDebug()<<"File not open";
        } else {
            QTextStream out(&file);
            out<<n<<" "<<m<<"\n";
            for (int i = 0; i < n; ++i) {
                out<<T_c_s[i]->toPlainText();
                out<<" ";
            }
            out<<ui->textEdit_3->toPlainText().toDouble();
            out<<"\n";
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    out<<T_A_s[i][j]->toPlainText();
                    if (j != n - 1) {
                        out<<" ";
                    }
                }
                out<<"\n";
            }
            for (int i = 0; i < m; ++i) {
                out<<T_b_s[i]->toPlainText();
                if (i != m - 1) {
                    out<<" ";
                }
            }
            out<<"\n";
            for (int i = 0; i < m; ++i) {
                out<<signs[i];
                if (i != m - 1) {
                    out<<" ";
                }
            }
            out<<" ";
            file.close ();
        }
    }
    if (sender() == ui->actionOpen) {
        QString fName = QFileDialog::getOpenFileName(this, tr("Open File"), "./", tr("matr(*.txt)"));
        if (fName != "") {
            QString suf = QFileInfo(fName).suffix();
            if (suf.isEmpty()) fName.append(".txt");
            QFile file(fName);
            if (!file.open(QIODevice::ReadOnly)) {
                qDebug()<<"File not open";
            } else {
                QString s = file.readLine();
                QStringList l = s.split(" ");
                n = l[0].toInt();
                m = l[1].toInt();

                new_table();

                s = file.readLine();
                s.remove(s.length() - 1, 1);
                l = s.split(" ");
                for (int i = 0; i < n; ++i) {
                    T_c_s[i]->setText(l[i]);
                }
                ui->textEdit_3->setText(l[n]);

                for (int i = 0; i < m; ++i) {
                    s = file.readLine();
                    s.remove(s.length() - 1, 1);
                    l = s.split(" ");
                    for (int j = 0; j < n; ++j) {
                        T_A_s[i][j]->setText(l[j]);
                    }
                }

                s = file.readLine();
                s.remove(s.length() - 1, 1);
                l = s.split(" ");
                for (int i = 0; i < m; ++i) {
                    T_b_s[i]->setText(l[i]);
                }

                s = file.readLine();
                s.remove(s.length() - 1, 1);
                l = s.split(" ");
                for (int i = 0; i < m; ++i) {
                    signs[i] = l[i].toInt();
                    if (signs[i] == 1) {
                        B_sign_s[i]->setText("<=");
                    } else if (signs[i] == 2) {
                        B_sign_s[i]->setText("=");
                    } else {
                        B_sign_s[i]->setText(">=");
                    }
                }

                file.close ();
            }
        }
    }
    if (sender() == ui->actionExit) {
        qApp->quit();
    }
}

void MainWindow::on_pushButton_clicked()
{
    Coefficients.resize(m);

    int String_size = n;

    for (int i = 0; i < m; ++i) {
        if (T_b_s[i]->toPlainText().toDouble() >= 0) {
            if (signs[i] == 0) {
                String_size += 2;
            } else {
                String_size += 1;
            }
        } else {
            if (signs[i] == 1) {
                String_size += 2;
            } else {
                String_size += 1;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        Coefficients[i].resize(String_size);
        for (int j = 0; j < n; ++j) {
            Coefficients[i][j] = T_A_s[i][j]->toPlainText().toDouble();
        }
    }

    int next_coef = n, Add_coef = 0;
    F = 0;
    Basic_variables.resize(m);
    c.clear();

    for (int i = 0; i < n; ++i) {
        if (ui->comboBox->currentIndex() == 0) {
            c.push_back(T_c_s[i]->toPlainText().toDouble());
        } else {
            c.push_back(-T_c_s[i]->toPlainText().toDouble());
        }
    }

    QVector <short int> Add_Variable;
    for (int i = 0; i < m; ++i) {
        Add_Variable.push_back(0);
    }

    for (int i = 0; i < m; ++i) {
        if (signs[i] == 0) {
            for (int j = 0; j < m; ++j) {
                Coefficients[j][next_coef] = (i == j) ? -1 : 0;
            }
            Add_Variable[i] = -1;
            ++Add_coef;
            ++next_coef;
        } else if (signs[i] == 1) {
            //F += Basic_variables_values[i];
            for (int j = 0; j < m; ++j) {
                Coefficients[j][next_coef] = (i == j) ? 1 : 0;
                if (i == j) {
                    Basic_variables[i] = next_coef + 1;
                }
            }
            Add_Variable[i] = 1;
            ++Add_coef;
            ++next_coef;
        }
    }

    Basic_variables_values.resize(m);
    for (int i = 0; i < m; ++i) {
        if (T_b_s[i]->toPlainText().toDouble() < 0) {
            Basic_variables_values[i] = -T_b_s[i]->toPlainText().toDouble();
            Add_Variable[i] = -Add_Variable[i];
            for (int j = 0; j < String_size; ++j) {
                Coefficients[i][j] = -Coefficients[i][j];
            }
        } else {
            Basic_variables_values[i] = T_b_s[i]->toPlainText().toDouble();
        }
    }

    F_M = 0;

    M.resize(String_size);
    for (int i = 0; i < String_size; ++i) {
        M[i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        if (Add_Variable[i] != 1) {
            for (int j = 0; j < m; ++j) {
                Coefficients[j][next_coef] = (i == j) ? 1 : 0;
                if (i == j) {
                    Basic_variables[i] = next_coef + 1;
                }
            }
            ++next_coef;
            F_M -= Basic_variables_values[i];
            for (int j = 0; j < n + Add_coef; ++j) {
                M[j] += Coefficients[i][j];
            }
        }
    }

    Indexes.resize(String_size);

    for (int i = 0; i < c.size(); ++i) {
        Indexes[i] = c[i];
    }

    for (int i = c.size(); i < String_size; ++i) {
        Indexes[i] = 0;
    }

    optimal = 0;

    for (int i = 0; i < n + m; ++i) {
        if (Indexes[i] < 0) {
            optimal = 0;
        }
    }

    double max = M[0] * 32000 + Indexes[0];
    int k = 1;

    for (int i = 1; i < String_size; ++i) {
        if (M[i] * 32000 + Indexes[i] > M[k - 1] * 32000 + Indexes[k - 1]) {
            max = M[i] * 32000 + Indexes[i];
            k = i + 1;
        }
    }

    if (max <= 0) {
        optimal = 1;
    }

    no_decision = 1;

    Taus.resize(m);
    int l;
    bool first = 1;
    double min;

    for (int i = 0; i < m; ++i) {
        if (Coefficients[i][k - 1] > 0) {
            Taus[i] = Basic_variables_values[i] / Coefficients[i][k - 1];
            if (!first) {
                if (Taus[i] < min) {
                    l = i + 1;
                    min = Taus[i];
                }
            } else {
                l = i + 1;
                min = Taus[i];
            }
            first = 0;
            no_decision = 0;
        }
    }

    while (!optimal && !no_decision) {
        Basic_variables[l - 1] = k;

        Basic_variables_values[l - 1] /= Coefficients[l - 1][k - 1];

        double coef = Coefficients[l - 1][k - 1];
        for (int i = 0; i < String_size; ++i) {
            Coefficients[l - 1][i] /= coef;
        }

        for (int i = 0; i < m; ++i) {
            if (i != l - 1) {
                coef = Coefficients[i][k - 1];
                Basic_variables_values[i] -= Basic_variables_values[l - 1] * coef;
                for (int j = 0; j < String_size; ++j) {
                    Coefficients[i][j] -= Coefficients[l - 1][j] * coef;
                }
            }
        }

        F = 0;
        F_M = 0;

        for (int i = 0; i < m; ++i) {
            if (Basic_variables[i] > n + Add_coef) {
                F_M -= Basic_variables_values[i];
            } else if (Basic_variables[i] - 1 < n) {
                F += Basic_variables_values[i] * c[Basic_variables[i] - 1];
            }
        }

        for (int i = 0; i < String_size; ++i) {
            Indexes[i] = (i < c.size()) ? c[i] : 0;
            M[i] = (i + 1 > n + Add_coef) ? -1 : 0;
        }

        for (int i = 0; i < m; ++i) {
            if (Basic_variables[i] - 1 < c.size()) {
                for (int j = 0; j < String_size; ++j) {
                    Indexes[j] -= Coefficients[i][j] * c[Basic_variables[i] - 1];
                }
            } else if (Basic_variables[i] > n + Add_coef) {
                for (int j = 0; j < String_size; ++j) {
                    M[j] += Coefficients[i][j];
                }
            }
        }

        optimal = 0;

        max = M[0] * 32000 + Indexes[0];
        k = 1;

        for (int i = 1; i < String_size; ++i) {
            if (M[i] * 32000 + Indexes[i] > M[k - 1] * 32000 + Indexes[k - 1]) {
                max = M[i] * 32000 + Indexes[i];
                k = i + 1;
            }
        }

        if (max <= 0) {
            optimal = 1;
        }

        no_decision = 1;

        Taus.resize(m);
        first = 1;

        for (int i = 0; i < m; ++i) {
            if (Coefficients[i][k - 1] > 0) {
                Taus[i] = Basic_variables_values[i] / Coefficients[i][k - 1];
                if (!first) {
                    if (Taus[i] < min) {
                        l = i + 1;
                        min = Taus[i];
                    }
                } else {
                    l = i + 1;
                    min = Taus[i];
                }
                no_decision = 0;
                first = 0;
            }
        }
    }

    QString s;

    if (F_M != 0) {

        s = "incorrect constraints";

    } else if (optimal) {

        s = "X=(";
        for (int i = 0; i < n; ++i) {
            bool basic = 0;
            for (int j = 0; j < m; ++j) {
                if (Basic_variables[j] == i + 1) {
                    s += QString().setNum(Basic_variables_values[j], 'f', 2) + "; ";
                    basic = 1;
                }
            }
            if (!basic) {
                s += "0; ";
            }
        }

        s.remove(s.length() - 2, 2);
        s+= ") ";

        if (ui->comboBox->currentIndex() == 0) {
            s += "F(x)=" + QString().setNum(F + ui->textEdit_3->toPlainText().toDouble(), 'f', 2);
        } else {
            s += "F(x)=" + QString().setNum(-F + ui->textEdit_3->toPlainText().toDouble(), 'f', 2);
        }

    } else {

        s = "no optimal plan";

    }

    L_xn_sm->setText(s);
}

void MainWindow::on_pushButton_2_clicked()
{
    gamma = 0.66;
    xk.resize(n);
    b.resize(m);
    c.resize(n);
    A.resize(m);
    AT.resize(n);
    dk.resize(n);
    Adk.resize(m);
    AdkAT.resize(m);
    Adkc.resize(m);
    Axk.resize(m);
    uk.resize(m);
    deltaxk.resize(n);
    xk_1.resize(n);

    for (int i = 0; i < n; ++i) {
        AT[i].resize(m);
        xk[i] = T_x0_s[i]->toPlainText().toDouble();
        c[i] = T_c_s[i]->toPlainText().toDouble();
        dk[i] = xk[i] * xk[i];
    }

    for (int i = 0; i < m; ++i) {
        A[i].resize(n);
        Adk[i].resize(n);
        AdkAT[i].resize(m);
        b[i] = T_b_s[i]->toPlainText().toDouble();
        for (int j = 0; j < n; ++j) {
            A[i][j] = T_A_s[i][j]->toPlainText().toDouble();
            AT[j][i] = A[i][j];
        }
    }

    for (int k = 0; k < 100; ++k) {

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            Adk[i][j] = A[i][j] * dk[j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            AdkAT[i][j] = 0;
            for (int l = 0; l < n; ++l) {
                AdkAT[i][j] += Adk[i][l] * AT[l][j];
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        Adkc[i] = 0;
        for (int l = 0; l < n; ++l) {
            Adkc[i] += Adk[i][l] * c[l];
        }
    }

    for (int i = 0; i < m; ++i) {
        Axk[i] = 0;
        for (int l = 0; l < n; ++l) {
            Axk[i] += A[i][l] * xk[l];
        }
    }

    for (int i = 0; i < m; ++i) {
        Adkc[i] += b[i] - Axk[i];
    }

    double coef;
    for (int i = 0; i < m - 1; ++i) {
        for (int j = i + 1; j < m; ++j) {
            coef = AdkAT[j][i] / AdkAT[i][i];
            Adkc[j] -= Adkc[j] * coef;
            for (int l = 0; l < m; ++l) {
                AdkAT[j][l] -= AdkAT[i][l] * coef;
            }
        }
    }

    for (int i = m - 1; i > 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
            coef = AdkAT[j][i] / AdkAT[i][i];
            Adkc[j] -= Adkc[j] * coef;
            for (int l = m - 1; l >= 0; --l) {
                AdkAT[j][l] -= AdkAT[i][l] * coef;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        uk[i] = Adkc[i] / AdkAT[i][i];
    }

    for (int i = 0; i < n; ++i) {
        deltaxk[i] = c[i];
        for (int j = 0; j < m; ++j) {
            deltaxk[i] -= AT[i][j] * uk[j];
        }
        deltaxk[i] *= -dk[i];
    }

    double min = 0, mincoef = 0;
    for (int i = 0; i < n; ++i) {
        if (deltaxk[i] < 0 && deltaxk[i] < min) {
            min = deltaxk[i];
            mincoef = i;
        }
    }

    lambdak = gamma * (-xk[mincoef] / deltaxk[mincoef]);

    for (int i = 0; i < n; ++i) {
        xk_1[i] = xk[i] + lambdak * deltaxk[i];
        xk[i] = xk_1[i];
    }

    }

    for (int i = 0; i < n; ++i) {
        T_xn_asm_s[i]->setText(QString().setNum(xk_1[i], 'f', 3));
    }
}

void MainWindow::slotSigns() {
    for (int i = 0; i < m; ++i) {
        if (sender() == B_sign_s[i]) {
            if (signs[i] == 0) {
                B_sign_s[i]->setText("<=");
                signs[i] = 1;
            } else if (signs[i] == 1) {
                B_sign_s[i]->setText("=");
                signs[i] = 2;
            } else {
                B_sign_s[i]->setText(">=");
                signs[i] = 0;
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
