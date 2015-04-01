#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>
#include <QApplication>
#include "settings.h"

class Settings : public QObject
{
    Q_OBJECT
public:
    static Settings* getInstance();
    QSettings s;
    static void validate();
private:
    explicit Settings(QObject *parent = 0);

signals:
    void settingsChanged();

public slots:
    void sendChangeNotification();

};

extern Settings *globalSettings;

#endif // SETTINGS_H