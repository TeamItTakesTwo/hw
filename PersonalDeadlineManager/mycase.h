#ifndef MYCASE_H
#define MYCASE_H

#include <QDateTime>
#include <QString>
#include <QFile>
#include <QVector>

class MyCase
{
public:
    MyCase();
    MyCase(const QDateTime& start_date, const QDateTime& end_date, const QString& description);
    QDate getStartDate() const;
    QDateTime getStartDateTime() const;
    QDate getEndDate() const;
    QDateTime getEndDateTime() const;
    QString getDescription() const;

    void setStartDate(QDateTime date);
    void setEndDate(QDateTime date);
    void setDescription(QString str);

    QString toString() const;
    static MyCase* fromString(const QString &str);
    static void writeCasesToFile(const QVector<MyCase>& cases, const QString& fileName);
    static QVector<MyCase*> readCasesFromFile(const QString& fileName);
private:
    QDateTime start_date;
    QDateTime end_date;
    QString description;
};


#endif // MYCASE_H
