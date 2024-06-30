#include "mycase.h"
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QPen>
#include <QBrush>
#include <QDebug>

MyCase::MyCase()=default;

MyCase::MyCase(const QDateTime& start_date, const QDateTime& end_date, const QString& description)
    : start_date(start_date), end_date(end_date), description(description) {}

QDate MyCase::getStartDate() const {
    return start_date.date();
}

QDate MyCase::getEndDate() const {
    return end_date.date();
}

QString MyCase::getDescription() const {
    return description;
}

QString MyCase::toString() const {
    return QString("%1,%2,%3")
        .arg(start_date.toString(Qt::ISODate))
        .arg(end_date.toString(Qt::ISODate))
        .arg(description);
}

MyCase* MyCase::fromString(const QString &str) {
    QStringList parts = str.split(",");
    if (parts.size() < 3) {
        qDebug() << "Length error";
        return new MyCase();
    }

    QDateTime startDate = QDateTime::fromString(parts[0], Qt::ISODate);
    QDateTime endDate = QDateTime::fromString(parts[1], Qt::ISODate);
    QString description = parts[2];

    return new MyCase(startDate, endDate, description);
}

void MyCase::writeCasesToFile(const QVector<MyCase>& cases, const QString& fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing:" << fileName;
        return;
    }

    QTextStream out(&file);
    for (const MyCase& myCase : cases) {
        out << myCase.toString() << "\n";
    }

    file.close();
}

QVector<MyCase*> MyCase::readCasesFromFile(const QString& fileName) {
    QVector<MyCase*> cases;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading:" << fileName;
        return cases;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        MyCase *myCase = MyCase::fromString(line);
        cases.append(myCase);
    }

    file.close();
    return cases;
}

QDateTime MyCase::getStartDateTime() const
{
    return start_date;
}
QDateTime MyCase::getEndDateTime() const
{
    return end_date;
}

void MyCase::setStartDate(QDateTime date) {
    start_date = date;
}

void MyCase::setEndDate(QDateTime date) {
    end_date = date;
}

void MyCase::setDescription(QString str) {
    description = str;
}

