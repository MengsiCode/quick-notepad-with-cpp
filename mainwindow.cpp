#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Mengsi Pad");
//    setWindowIcon(QIcon(":/images/main.png"));
    setWindowIcon(QIcon("main.png"));
    create_menus();
    // new_file();
    setCentralWidget(editor);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create_menus(){
    file_menu = menuBar()->addMenu("File");
    new_action = new QAction("New",this);
    new_action->setShortcut(QKeySequence("Ctrl+N"));
    connect(new_action,SIGNAL(triggered()), this, SLOT(new_file()));

    open_action = new QAction("Open...",this);
    open_action->setShortcut(QKeySequence("Ctrl+O"));
    connect(open_action,SIGNAL(triggered()), this, SLOT(open_file()));

    save_action = new QAction("Save",this);
    save_action->setShortcut(QKeySequence("Ctrl+S"));

    saveas_action = new QAction("Save As",this);
    connect(saveas_action,SIGNAL(triggered()), this, SLOT(saveas_file()));
    print_action = new QAction("Print",this);
    print_action->setShortcut(QKeySequence("Ctrl+P"));

    exit_action = new QAction("Exit",this);
    exit_action->setShortcut(QKeySequence("Alt+F4"));
    file_menu->addAction(new_action);
    file_menu->addAction(open_action);
    file_menu->addAction(save_action);
    file_menu->addAction(saveas_action);
    file_menu->addSeparator();
    file_menu->addAction(print_action);
    file_menu->addSeparator();
    file_menu->addAction(exit_action);


    edit_menu = menuBar()->addMenu("Edit");
    undo_action = new QAction("Undo", this);
    undo_action->setShortcut(QKeySequence("Ctrl+Z"));
    connect(undo_action,SIGNAL(triggered()), this, SLOT(undo()));
    cut_action = new QAction("Cut", this);
    cut_action->setShortcut(QKeySequence("Ctrl+X"));
    connect(cut_action,SIGNAL(triggered()), this, SLOT(cut()));
    copy_action = new QAction("Copy", this);
    copy_action->setShortcut(QKeySequence("Ctrl+C"));
    connect(copy_action,SIGNAL(triggered()), this, SLOT(copy()));

    paste_action = new QAction("Paste", this);
    paste_action->setShortcut(QKeySequence("Ctrl+V"));
    connect(paste_action,SIGNAL(triggered()), this, SLOT(paste()));

    edit_menu->addAction(undo_action);
    edit_menu->addSeparator();
    edit_menu->addAction(cut_action);
    edit_menu->addAction(copy_action);
    edit_menu->addAction(paste_action);

    format_menu = menuBar()->addMenu("Format");

    view_menu = menuBar()->addMenu("View");
    help_menu = menuBar()->addMenu("Help");



}

void MainWindow::open_file(){
    filename = QFileDialog::getOpenFileName(this, "choose file");
    QFile current_file(filename);
    if(!current_file.open(QIODevice::ReadWrite | QFile::Text)){
        qDebug()<<"nope";
    }
    setWindowTitle(filename);
    QTextStream input(&current_file);
    QString this_text = input.readAll();
    editor->setPlainText(this_text);
    current_file.close();

}

void MainWindow::new_file(){
    editor->setText("");

}
void MainWindow::save_file(){

}
void MainWindow::saveas_file(){
    filename = QFileDialog::getSaveFileName(this,"Save as");
    QFile current_file(filename);
    if(!current_file.open(QIODevice::WriteOnly | QFile::Text)){
        qDebug()<<"nope";
    }
    setWindowTitle(filename);
    QTextStream output(&current_file);
    QString this_text = editor->toPlainText();
    output << this_text;
    current_file.close();
}
void MainWindow::cut(){
    editor->cut();
}
void MainWindow::copy(){
    editor->copy();
}
void MainWindow::paste(){
    editor->paste();
}
void MainWindow::undo(){
    editor->undo();
}
