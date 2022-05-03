#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QString>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_doctorPushButton_clicked();

    void on_time_tablePushButton_clicked();

    void on_patientPushButton_clicked();

    void on_medical_cardPushButton_clicked();

    void on_visitingPushButton_clicked();

    void on_addPushButton_clicked();

    void on_removePushButton_clicked();

    void on_acceptPushButton_clicked();

    void on_cancelPushButton_clicked();

    void on_searchPushButton_clicked();

    void on_fullTime_tablePushButton_clicked();

    void on_registryPushButton_clicked();

    void on_doctorPushButton_2_clicked();

    void on_frequentPatientPushButton_clicked();

private:
    Ui::MainWindow *ui;

    QSqlTableModel *doctorModel;
    QSqlTableModel *patientModel;
    QSqlTableModel *medical_cardModel;
    QSqlTableModel *visitingModel;
    QSqlTableModel *time_tableModel;
    QSqlQueryModel *queryModel;

};
#endif // MAINWINDOW_H
