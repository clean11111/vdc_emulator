#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QByteArray>
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkInterface>
#include <QWidget>
#include "QtWebSockets/QWebSocket"
#include "QtWebSockets/QWebSocketServer"

#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>
#include "json.h"

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QLineEdit;
class QTextEdit;
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void ParseEvent(const Json::Value &request);

public slots:
    void StartServer();
    void SendWSMessage();
    void Clear();
    void loadJSON();
    void notifyUpdatesScheduled();
    void notifyUpdatesScheduledToInstall();
    void notifyUpdatesToBeScheduled();
    void notifyUserPresentChangeStatus();
    void notifyInstallationResult();
    void notifyUpdatesChangeStatus();
    void notifyVehicleLanguageChange();
    void getCurrentSOTAInstalledSoftware();
    void getInstallationResult();
    void getPreferencesVehicle();
    void getSoftwareUpdateInformation();
    void getTCsResult();
    void getVehicleLanguage();
    void setPreferencesVehicle(const Json::Value &request);
    void setTCsResult(const Json::Value &request);
    void setUpdateSchedule(const Json::Value &request);
    void setSoftwareUpdateInstallImmediate();
    void setUnscheduleUpdate();
    void setUpdateAuthorisation();
    void setUpdateNotification();
    void StartFileTransfer();
    void FileTransferStatus();
    void FileTransferComplete();
    void StartInstall();
    void InstallStatus();
    void InstallComplete();
    void ActivationComplete();
    void Test();

private Q_SLOTS:
    void onNewConnection();
    void processTextMessage(QString message);
    void socketDisconnected();

private:
    Json::Value hmi_info;
    Json::StyledWriter styledWriter;
    std::string str;
    std::string pivi_transactionId;
    int vdc_transactionId;

    QJsonObject jsonObj;
    QLineEdit *serverState;
    QLineEdit *clientState;
    QLineEdit *fileloadState;
    QTextEdit *receiveText;
    QTextEdit *sendText;
    QPushButton *startButton;
    QPushButton *loadButton;
    QPushButton *sendButton;
    QPushButton *clearButton;
    QPushButton *notifyUpdatesScheduledButton;
    QPushButton *notifyUpdatesScheduledToInstallButton;
    QPushButton *notifyUpdatesToBeScheduledButton;
    QPushButton *notifyUserPresentChangeStatusButton;
    QPushButton *notifyInstallationResultButton;
    QPushButton *notifyUpdatesChangeStatusButton;
    QPushButton *notifyVehicleLanguageChangeButton;
    QPushButton *getCurrentSOTAInstalledSoftwareButton;
    QPushButton *getInstallationResultButton;
    QPushButton *getPreferencesVehicleButton;
    QPushButton *getSoftwareUpdateInformationButton;
    QPushButton *getTCsResultButton;
    QPushButton *getVehicleLanguageButton;
    QPushButton *setPreferencesVehicleButton;
    QPushButton *setTCsResultButton;
    QPushButton *StartFileTransferButton;
    QPushButton *FileTransferStatusButton;
    QPushButton *FileTransferCompleteButton;
    QPushButton *StartInstallButton;
    QPushButton *InstallStatusButton;
    QPushButton *InstallCompleteButton;
    QPushButton *ActivationCompleteButton;
    QPushButton *TestButton;
    QWebSocketServer *m_pWebSocketServer;
    QWebSocket *pSocket;
    QList<QWebSocket *> m_clients;
};

#endif // MAINWINDOW_H
