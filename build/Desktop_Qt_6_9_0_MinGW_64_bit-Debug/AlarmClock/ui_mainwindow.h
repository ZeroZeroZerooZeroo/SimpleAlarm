/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTimeEdit *timeEdit;
    QPushButton *setTimeButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QCheckBox *activeCheckBox;
    QLabel *statusLabel;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *selectMusicButton;
    QPushButton *stopButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(438, 256);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 10, 421, 64));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        timeEdit = new QTimeEdit(layoutWidget);
        timeEdit->setObjectName("timeEdit");

        verticalLayout->addWidget(timeEdit);

        setTimeButton = new QPushButton(layoutWidget);
        setTimeButton->setObjectName("setTimeButton");

        verticalLayout->addWidget(setTimeButton);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 80, 421, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        activeCheckBox = new QCheckBox(layoutWidget1);
        activeCheckBox->setObjectName("activeCheckBox");

        horizontalLayout->addWidget(activeCheckBox);

        statusLabel = new QLabel(layoutWidget1);
        statusLabel->setObjectName("statusLabel");

        horizontalLayout->addWidget(statusLabel);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(0, 120, 421, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        selectMusicButton = new QPushButton(layoutWidget2);
        selectMusicButton->setObjectName("selectMusicButton");

        verticalLayout_2->addWidget(selectMusicButton);

        stopButton = new QPushButton(layoutWidget2);
        stopButton->setObjectName("stopButton");

        verticalLayout_2->addWidget(stopButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 438, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        setTimeButton->setText(QCoreApplication::translate("MainWindow", "Set time", nullptr));
        activeCheckBox->setText(QCoreApplication::translate("MainWindow", "Active", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        selectMusicButton->setText(QCoreApplication::translate("MainWindow", "Choose a melody", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
