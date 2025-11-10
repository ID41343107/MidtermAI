#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    // Connect button signals to slots
    connect(ui->submitButton, &QPushButton::clicked, this, &Widget::onSubmitClicked);
    connect(ui->clearButton, &QPushButton::clicked, this, &Widget::onClearClicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onSubmitClicked()
{
    QString name = ui->nameLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString message = ui->messageTextEdit->toPlainText();
    
    if (name.isEmpty() || email.isEmpty() || message.isEmpty()) {
        ui->statusLabel->setText("錯誤：請填寫所有欄位");
        ui->statusLabel->setStyleSheet("QLabel { color: #e74c3c; font-size: 12px; font-weight: normal; }");
        return;
    }
    
    ui->statusLabel->setText("成功：資料已提交");
    ui->statusLabel->setStyleSheet("QLabel { color: #27ae60; font-size: 12px; font-weight: normal; }");
    
    QMessageBox::information(this, "提交成功", 
        QString("姓名：%1\n電郵：%2\n訊息：%3").arg(name).arg(email).arg(message));
}

void Widget::onClearClicked()
{
    ui->nameLineEdit->clear();
    ui->emailLineEdit->clear();
    ui->messageTextEdit->clear();
    ui->statusLabel->setText("就緒");
    ui->statusLabel->setStyleSheet("QLabel { color: #27ae60; font-size: 12px; font-weight: normal; }");
}
