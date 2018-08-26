#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QAction>
#include <QMenu>
#include <QFile>
#include <QPlainTextEdit>
#include <QTextEdit>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void open_file();
    void new_file();
    void save_file();
    void saveas_file();
    void copy();
    void paste();
    void cut();
    void undo();

private:
    Ui::MainWindow *ui;
    QMenu *file_menu ;
    QMenu *edit_menu ;
    QMenu *format_menu ;
    QMenu *view_menu ;
    QMenu *help_menu ;

    QAction *new_action ;
    QAction *open_action ;
    QAction *save_action ;
    QAction *saveas_action ;
    QAction *undo_action ;
    QAction *cut_action ;
    QAction *copy_action ;
    QAction *paste_action ;
    QAction *delete_action ;
    QAction *find_action ;
    QAction *print_action ;
    QAction *exit_action ;
    QAction *about_action ;

    void create_menus();

    QString filename = "";
    QString file ="";

    QTextEdit *editor = new QTextEdit;




};

#endif // MAINWINDOW_H
