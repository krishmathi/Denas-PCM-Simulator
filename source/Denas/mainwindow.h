#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTime>
#include "device.h"
#include "programs.h"
#include "homemenu.h"
#include "recording.h"
#include "frequency.h"
#include "settings.h"
#include <vector>
#include <QString>
#include <math.h>
#include <QDateTime>
#include <QTimer>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void fillHomeMenu();
    void fillPrograms();
    void fillFrequency();
    void fillSettings();
    void waitInterval(int);



private:
    Ui::MainWindow *ui;
    Device device;
    Programs programs;
    Frequency frequency;
    HomeMenu homeMenu;
    Settings settings;
    vector<Recording> recordingCollection;
    void disableButtons();
    void homeScreen();
    QTime time;
    QTimer *timer;

private slots:
    void powerClicked();
    void navUp();
    void navDown();
    void programsClicked();
    void programMessage();
    void frequencyClicked();
    void recordingsClicked();
    void settingsClicked();
    void okClicked();
    void homeClicked();
    void returnButton();
    void decreaseBattery();
    void powerLevel(int);
    void updateTimer();
    void recordTherapy();
    void changeFreq(int);
};

#endif // MAINWINDOW_H
