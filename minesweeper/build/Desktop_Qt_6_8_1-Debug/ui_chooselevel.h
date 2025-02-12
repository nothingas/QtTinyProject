/********************************************************************************
** Form generated from reading UI file 'chooselevel.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSELEVEL_H
#define UI_CHOOSELEVEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChooseLevel
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *ChooseLevel)
    {
        if (ChooseLevel->objectName().isEmpty())
            ChooseLevel->setObjectName("ChooseLevel");
        ChooseLevel->resize(311, 222);
        horizontalLayout = new QHBoxLayout(ChooseLevel);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(ChooseLevel);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        groupBox = new QGroupBox(ChooseLevel);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout->addWidget(pushButton_4);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(ChooseLevel);

        QMetaObject::connectSlotsByName(ChooseLevel);
    } // setupUi

    void retranslateUi(QDialog *ChooseLevel)
    {
        ChooseLevel->setWindowTitle(QCoreApplication::translate("ChooseLevel", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ChooseLevel", "Choose Level:", nullptr));
        groupBox->setTitle(QString());
        pushButton->setText(QCoreApplication::translate("ChooseLevel", "\347\256\200\345\215\225", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ChooseLevel", "\344\270\255\347\255\211", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ChooseLevel", "\345\233\260\351\232\276", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ChooseLevel", "\345\234\260\347\213\261", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseLevel: public Ui_ChooseLevel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSELEVEL_H
