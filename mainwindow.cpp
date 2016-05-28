#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "delegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_stuModel = new QSqlTableModel;
    m_stuModel->setTable("stu");
    m_stuModel->select();

    ui->tableView->setModel(m_stuModel);
    ui->tableView->setItemDelegate(new ItemDelegate());
}

MainWindow::~MainWindow()
{
    delete ui;
}
