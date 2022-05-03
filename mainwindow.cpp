#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    doctorModel = new QSqlTableModel();
    doctorModel->setTable("doctor");
    doctorModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    doctorModel->setHeaderData(0, Qt::Horizontal, "ID");
    doctorModel->setHeaderData(1,Qt::Horizontal,"ФИО");
    doctorModel->setHeaderData(2,Qt::Horizontal,"Специальность");
    doctorModel->select();

    time_tableModel = new QSqlTableModel();
    time_tableModel->setTable("time_table");
    time_tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    time_tableModel->setHeaderData(0, Qt::Horizontal, "ID");
    time_tableModel->setHeaderData(1, Qt::Horizontal, "ID врача");
    time_tableModel->setHeaderData(2, Qt::Horizontal, "Кабинет");
    time_tableModel->setHeaderData(3, Qt::Horizontal, "Дни работы");
    time_tableModel->setHeaderData(4, Qt::Horizontal, "Время начала");
    time_tableModel->setHeaderData(5, Qt::Horizontal, "Время конца");
    time_tableModel->select();

    patientModel = new QSqlTableModel();
    patientModel->setTable("patient");
    patientModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    patientModel->setHeaderData(0, Qt::Horizontal, "ID");
    patientModel->setHeaderData(1, Qt::Horizontal, "ФИО");
    patientModel->select();

    medical_cardModel = new QSqlTableModel();
    medical_cardModel->setTable("medical_card");
    medical_cardModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    medical_cardModel->setHeaderData(0, Qt::Horizontal, "ID");
    medical_cardModel->setHeaderData(1, Qt::Horizontal, "ID пациента");
    medical_cardModel->setHeaderData(2, Qt::Horizontal, "Номер");
    medical_cardModel->select();

    visitingModel = new QSqlTableModel();
    visitingModel->setTable("visiting");
    visitingModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    visitingModel->setHeaderData(0, Qt::Horizontal, "ID");
    visitingModel->setHeaderData(1, Qt::Horizontal, "ID мед. карты");
    visitingModel->setHeaderData(2, Qt::Horizontal, "ID врача");
    visitingModel->setHeaderData(3, Qt::Horizontal, "Диагноз");
    visitingModel->setHeaderData(4, Qt::Horizontal, "Отметка о приеме");
    visitingModel->setHeaderData(5, Qt::Horizontal, "Начало посещения");
    visitingModel->setHeaderData(6, Qt::Horizontal, "Конец посещения");
    visitingModel->select();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete patientModel;
    delete time_tableModel;
    delete doctorModel;
    delete medical_cardModel;
    delete visitingModel;
    delete  queryModel;
}


void MainWindow::on_doctorPushButton_clicked()
{
    ui->tableView->setModel(doctorModel);
    ui->tableView->setColumnHidden(0,false);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->setWindowTitle("Врач");
}

void MainWindow::on_time_tablePushButton_clicked()
{
    ui->tableView->setModel(time_tableModel);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->setWindowTitle("Расписание");
}

void MainWindow::on_patientPushButton_clicked()
{
    ui->tableView->setModel(patientModel);
    ui->tableView->setColumnHidden(0, false);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->setWindowTitle("Пациент");
}

void MainWindow::on_medical_cardPushButton_clicked()
{
    ui->tableView->setModel(medical_cardModel);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->setWindowTitle("Мед.карта");
}

void MainWindow::on_visitingPushButton_clicked()
{
    ui->tableView->setModel(visitingModel);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->setWindowTitle("Прием");
}

void MainWindow::on_addPushButton_clicked()
{
    if(ui->tableView->model() == doctorModel) {
        if(!doctorModel->insertRow(doctorModel->rowCount())) {
                QMessageBox::critical(this, "Ошибка при добавлении!",
                    QString("Ошибка: %1").arg(doctorModel->lastError().text()),
                    QMessageBox::Cancel);
            }

            ui->tableView->selectRow(doctorModel->rowCount() - 1);

     } else if(ui->tableView->model() == time_tableModel) {
        if(!time_tableModel->insertRow(time_tableModel->rowCount())) {
                QMessageBox::critical(this, "Ошибка при добавлении!",
                    QString("Ошибка: %1").arg(time_tableModel->lastError().text()),
                    QMessageBox::Cancel);
            }

            ui->tableView->selectRow(time_tableModel->rowCount() - 1);

    } else if(ui->tableView->model() == patientModel) {
        if(!patientModel->insertRow(patientModel->rowCount())) {
                QMessageBox::critical(this, "Ошибка при добавлении!",
                    QString("Ошибка: %1").arg(patientModel->lastError().text()),
                    QMessageBox::Cancel);
            }

            ui->tableView->selectRow(patientModel->rowCount() - 1);

    } else if(ui->tableView->model() == medical_cardModel) {
        if(!medical_cardModel->insertRow(medical_cardModel->rowCount())) {
                QMessageBox::critical(this, "Ошибка при добавлении!",
                    QString("Ошибка: %1").arg(medical_cardModel->lastError().text()),
                    QMessageBox::Cancel);
            }

            ui->tableView->selectRow(medical_cardModel->rowCount() - 1);

    } else if(ui->tableView->model() == visitingModel) {
        if(!visitingModel->insertRow(visitingModel->rowCount())) {
                QMessageBox::critical(this, "Ошибка при добавлении!",
                    QString("Ошибка: %1").arg(visitingModel->lastError().text()),
                    QMessageBox::Cancel);
            }

            ui->tableView->selectRow(visitingModel->rowCount() - 1);
    }
}

void MainWindow::on_removePushButton_clicked()
{
    if(ui->tableView->model() == doctorModel) {
        int row = ui->tableView->selectionModel()->currentIndex().row();
        if (row == -1)
            return;
        if (!doctorModel->removeRow(row))
        {
            QMessageBox::critical(this, "Ошибка при удалении!",
                QString("Ошибка: %1").arg(doctorModel->lastError().text()),
                QMessageBox::Cancel);
            return;
        }
    } else if(ui->tableView->model() == time_tableModel) {
        int row = ui->tableView->selectionModel()->currentIndex().row();
        if (row == -1)
            return;
        if (!time_tableModel->removeRow(row))
        {
            QMessageBox::critical(this, "Ошибка при удалении!",
                QString("Ошибка: %1").arg(time_tableModel->lastError().text()),
                QMessageBox::Cancel);
            return;
        }
    } else if(ui->tableView->model() == patientModel) {
        int row = ui->tableView->selectionModel()->currentIndex().row();
        if (row == -1)
            return;
        if (!patientModel->removeRow(row))
        {
            QMessageBox::critical(this, "Ошибка при удалении!",
                QString("Ошибка: %1").arg(patientModel->lastError().text()),
                QMessageBox::Cancel);
            return;
        }
    } else if(ui->tableView->model() == medical_cardModel) {
        int row = ui->tableView->selectionModel()->currentIndex().row();
        if (row == -1)
            return;
        if (!medical_cardModel->removeRow(row))
        {
            QMessageBox::critical(this, "Ошибка при удалении!",
                QString("Ошибка: %1").arg(medical_cardModel->lastError().text()),
                QMessageBox::Cancel);
            return;
        }
    } else if(ui->tableView->model() == visitingModel) {
        int row = ui->tableView->selectionModel()->currentIndex().row();
        if (row == -1)
            return;
        if (!visitingModel->removeRow(row))
        {
            QMessageBox::critical(this, "Ошибка при удалении!",
                QString("Ошибка: %1").arg(visitingModel->lastError().text()),
                QMessageBox::Cancel);
            return;
        }
    }
}

void MainWindow::on_acceptPushButton_clicked()
{
    if(ui->tableView->model() == doctorModel) {
        if(!doctorModel->submitAll()) {
            QMessageBox::critical(this, "Ошибка подтверждения!",
                QString("Ошибка: %1").arg(doctorModel->lastError().text()),
                QMessageBox::Cancel);
        }
    } else if(ui->tableView->model() == time_tableModel) {
        if(!time_tableModel->submitAll()) {
            QMessageBox::critical(this, "Ошибка подтверждения!",
                QString("Ошибка: %1").arg(time_tableModel->lastError().text()),
                QMessageBox::Cancel);
        }
    } else if(ui->tableView->model() == patientModel) {
        if(!patientModel->submitAll()) {
            QMessageBox::critical(this, "Ошибка подтверждения!",
                QString("Ошибка: %1").arg(patientModel->lastError().text()),
                QMessageBox::Cancel);
        }
    } else if(ui->tableView->model() == medical_cardModel) {
        if(!medical_cardModel->submitAll()) {
            QMessageBox::critical(this, "Ошибка подтверждения!",
                QString("Ошибка: %1").arg(medical_cardModel->lastError().text()),
                QMessageBox::Cancel);
        }
    } else if(ui->tableView->model() == visitingModel) {
        if(!visitingModel->submitAll()) {
            QMessageBox::critical(this, "Ошибка подтверждения!",
                QString("Ошибка: %1").arg(visitingModel->lastError().text()),
                QMessageBox::Cancel);
        }
    }
}

void MainWindow::on_cancelPushButton_clicked()
{
    if(ui->tableView->model() == doctorModel) {
        doctorModel->revertAll();
    } else if(ui->tableView->model() == time_tableModel) {
        time_tableModel->revertAll();
    } else if(ui->tableView->model() == patientModel) {
        patientModel->revertAll();
    } else if(ui->tableView->model() == medical_cardModel) {
        medical_cardModel->revertAll();
    } else if(ui->tableView->model() == visitingModel) {
        visitingModel->revertAll();
    }
}

void MainWindow::on_searchPushButton_clicked()
{
    queryModel = new QSqlQueryModel;
    queryModel->setQuery(ui->queryTextEdit->toPlainText());
    ui->tableView->setModel(queryModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->setWindowTitle("Запрос на языке SQL");
}

void MainWindow::on_fullTime_tablePushButton_clicked()
{
    queryModel = new QSqlQueryModel();
    queryModel->setQuery("SELECT d.ID AS id , name AS ФИО, speciality AS 'Специальность', tt.cabinet AS '№ кабинета',tt.days AS 'Дни работы',tt.start_time AS 'Время начала',tt.end_time AS 'Время конца' FROM doctor d INNER JOIN time_table tt on d.ID = tt.doctor_id;");
    ui->tableView->setModel(queryModel);
    ui->tableView->setColumnHidden(0,false);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->setWindowTitle("Полное расписание врачей");
}

void MainWindow::on_registryPushButton_clicked()
{
    queryModel = new QSqlQueryModel();
    queryModel->setQuery("SELECT tt.cabinet AS Кабинет,mc.number AS '№ мед.карты' FROM visiting v INNER JOIN medical_card mc on v.medical_card_id = mc.ID INNER JOIN doctor d on v.doctor_id = d.ID INNER JOIN time_table tt on d.ID = tt.doctor_id WHERE '" + ui->registrydateEdit->date().toString("yyyy.MM.dd") + " 00:00:00' < v.visit_begin AND '" + ui->registrydateEdit->date().toString("yyyy.MM.dd") + " 23:59:59' > v.visit_end ORDER BY tt.cabinet;");
    ui->tableView->setModel(queryModel);
    ui->tableView->setColumnHidden(0,false);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->setWindowTitle("Ведомость для регистратуры");
}

void MainWindow::on_doctorPushButton_2_clicked()
{
    queryModel = new QSqlQueryModel();
    queryModel->setQuery("SELECT d.id AS 'id врача',d.name AS 'ФИО врача',p.name AS 'ФИО пациента',v.diagnosis AS 'Диагноз', DATE(v.visit_begin) AS 'Дата приема' FROM visiting v RIGHT JOIN doctor d on v.doctor_id = d.ID RIGHT JOIN medical_card mc on v.medical_card_id = mc.ID RIGHT JOIN patient p on mc.patient_id = p.ID WHERE v.mark_of_visit = 'Был' AND DATE(v.visit_begin) BETWEEN '" + ui->doctorWithDateEdit->date().toString("yyyy.MM.dd") + "' AND '" + ui->doctorToDateEdit->date().toString("yyyy.MM.dd") + "';");
    ui->tableView->setModel(queryModel);
    ui->tableView->setColumnHidden(0,false);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->setWindowTitle("Ведомость для врача");
}

void MainWindow::on_frequentPatientPushButton_clicked()
{
    queryModel = new QSqlQueryModel();
    queryModel->setQuery("SELECT p.id AS 'id пациента', COUNT(v.id) AS 'Количество посещений', \
p.name AS 'ФИО пациента' FROM visiting v RIGHT JOIN medical_card mc on v.medical_card_id = mc.ID RIGHT JOIN patient p ON mc.patient_id = p.ID WHERE v.mark_of_visit = 'Был' GROUP BY p.id ORDER BY COUNT(v.id) DESC LIMIT 1;");
    ui->tableView->setModel(queryModel);
    ui->tableView->setColumnHidden(0,false);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->setWindowTitle("Самый частый пациент");
}
