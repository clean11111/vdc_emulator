#include <QtWidgets>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QLabel *serverStateLabel = new QLabel(tr("Server State :"));
    serverState = new QLineEdit;
    serverState->setPlaceholderText(tr("Not Initialized"));
    serverState->setReadOnly(true);

    QLabel *clientStateLabel = new QLabel(tr("Client State :"));
    clientState = new QLineEdit;
    clientState->setPlaceholderText(tr("Not Initialized"));
    clientState->setReadOnly(true);

    QLabel *fileloadStateLabel = new QLabel(tr("FileLoad State :"));
    fileloadState = new QLineEdit;
    fileloadState->setPlaceholderText(tr("Not Initialized"));
    fileloadState->setReadOnly(true);

    QLabel *receivemsgLabel = new QLabel(tr("Receive Message :"));
    receiveText = new QTextEdit;
    receiveText->setReadOnly(true);

    QLabel *sendmsgLabel = new QLabel(tr("Send Message :"));
    sendText = new QTextEdit;

    QVBoxLayout *StartbuttonLayout = new QVBoxLayout;
    startButton = new QPushButton(tr("&Start Server"));
    StartbuttonLayout->addWidget(startButton);

    QVBoxLayout *LoadbuttonLayout = new QVBoxLayout;
    loadButton = new QPushButton(tr("&Load Json"));
    LoadbuttonLayout->addWidget(loadButton);

    QVBoxLayout *ClearbuttonLayout = new QVBoxLayout;
    clearButton = new QPushButton(tr("&Clear"));
    ClearbuttonLayout->addWidget(clearButton);

    QVBoxLayout *HMIbuttonLayout = new QVBoxLayout;
    sendButton = new QPushButton(tr("&Send Message"));
    notifyUpdatesScheduledButton = new QPushButton(tr("&NotifyUpdateScheduled"));
    notifyUpdatesScheduledToInstallButton = new QPushButton(tr("&NotifyUpdatesScheduledToInstall"));
    notifyUpdatesToBeScheduledButton = new QPushButton(tr("&NotifyUpdatesToBeScheduled"));
    notifyUserPresentChangeStatusButton = new QPushButton(tr("&NotifyUserPresentChangeStatus"));
    notifyInstallationResultButton = new QPushButton(tr("&NotifyInstallationResult"));
    notifyUpdatesChangeStatusButton = new QPushButton(tr("&NotifyUpdatesChangeStatus"));
    notifyVehicleLanguageChangeButton = new QPushButton(tr("&NotifyVehicleLanguageChange"));
    getCurrentSOTAInstalledSoftwareButton = new QPushButton(tr("&GetCurrentSOTAInstalledSoftware"));
    getInstallationResultButton = new QPushButton(tr("&GetInstallationResult"));
    getJLRContactDetailsButton = new QPushButton(tr("&GetJLRContactDetails"));
    getPreferencesVehicleButton = new QPushButton(tr("&GetPreferencesVehicle"));
    getSoftwareUpdateInformationButton = new QPushButton(tr("&GetSoftwareUpdateInformation"));
    getTCsResultButton = new QPushButton(tr("&GetTCsResult"));
    getVehicleLanguageButton = new QPushButton(tr("&GetVehicleLanguage"));
    setPreferencesVehicleButton = new QPushButton(tr("&SetPreferencesVehicle"));
    setTCsResultButton = new QPushButton(tr("&SetTCsResult"));
    HMIbuttonLayout->addWidget(sendButton);
    HMIbuttonLayout->addWidget(notifyUpdatesScheduledButton);
    HMIbuttonLayout->addWidget(notifyUpdatesScheduledToInstallButton);
    HMIbuttonLayout->addWidget(notifyUpdatesToBeScheduledButton);
    HMIbuttonLayout->addWidget(notifyUserPresentChangeStatusButton);
    HMIbuttonLayout->addWidget(notifyInstallationResultButton);
    HMIbuttonLayout->addWidget(notifyUpdatesChangeStatusButton);
    HMIbuttonLayout->addWidget(notifyVehicleLanguageChangeButton);
    HMIbuttonLayout->addWidget(getCurrentSOTAInstalledSoftwareButton);
    HMIbuttonLayout->addWidget(getInstallationResultButton);
    HMIbuttonLayout->addWidget(getJLRContactDetailsButton);
    HMIbuttonLayout->addWidget(getPreferencesVehicleButton);
    HMIbuttonLayout->addWidget(getSoftwareUpdateInformationButton);
    HMIbuttonLayout->addWidget(getTCsResultButton);
    HMIbuttonLayout->addWidget(getVehicleLanguageButton);
    HMIbuttonLayout->addWidget(setPreferencesVehicleButton);
    HMIbuttonLayout->addWidget(setTCsResultButton);
    HMIbuttonLayout->addStretch();

    QVBoxLayout *SystembuttonLayout = new QVBoxLayout;
    SoftwareVersionButton = new QPushButton(tr("&SoftwareVersion"));
    StartFileTransferButton = new QPushButton(tr("&StartFileTransfer"));
    FileTransferStatusButton = new QPushButton(tr("&FileTransferStatus"));
    FileTransferCompleteButton = new QPushButton(tr("&FileTransferComplete"));
    StartInstallButton = new QPushButton(tr("&InstallSoftware"));
    InstallStatusButton = new QPushButton(tr("&InstallStatus"));
    InstallCompleteButton = new QPushButton(tr("&InstallComplete"));
    ActivationCompleteButton = new QPushButton(tr("&ActivationComplete"));
    SystembuttonLayout->addWidget(SoftwareVersionButton);
    SystembuttonLayout->addWidget(StartFileTransferButton);
    SystembuttonLayout->addWidget(FileTransferStatusButton);
    SystembuttonLayout->addWidget(FileTransferCompleteButton);
    SystembuttonLayout->addWidget(StartInstallButton);
    SystembuttonLayout->addWidget(InstallStatusButton);
    SystembuttonLayout->addWidget(InstallCompleteButton);
    SystembuttonLayout->addWidget(ActivationCompleteButton);
    SystembuttonLayout->addStretch();

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(serverStateLabel, 0, 0);
    mainLayout->addWidget(serverState, 0, 1);
    mainLayout->addLayout(StartbuttonLayout, 0, 2);
    mainLayout->addWidget(clientStateLabel, 1, 0);
    mainLayout->addWidget(clientState, 1, 1);
    mainLayout->addLayout(LoadbuttonLayout, 1, 2);
    mainLayout->addWidget(fileloadStateLabel, 2, 0);
    mainLayout->addWidget(fileloadState, 2, 1);
    mainLayout->addLayout(ClearbuttonLayout, 2, 2);
    mainLayout->addWidget(receivemsgLabel, 3, 0, Qt::AlignTop);
    mainLayout->addWidget(receiveText, 3, 1);
    mainLayout->addLayout(HMIbuttonLayout, 3, 2);
    mainLayout->addWidget(sendmsgLabel, 4, 0, Qt::AlignTop);
    mainLayout->addWidget(sendText, 4, 1);
    mainLayout->addLayout(SystembuttonLayout, 4, 2);
    setLayout(mainLayout);
    setWindowTitle(tr("VDC Server Tool"));

    connect(startButton, SIGNAL(clicked()), this, SLOT(StartServer()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(SendWSMessage()));
    connect(clearButton, SIGNAL(clicked()), this, SLOT(Clear()));
    connect(loadButton, SIGNAL(clicked()), this, SLOT(loadJSON()));
    connect(notifyUpdatesScheduledButton, SIGNAL(clicked()), this, SLOT(notifyUpdatesScheduled()));
    connect(notifyUpdatesScheduledToInstallButton, SIGNAL(clicked()), this, SLOT(notifyUpdatesScheduledToInstall()));
    connect(notifyUpdatesToBeScheduledButton, SIGNAL(clicked()), this, SLOT(notifyUpdatesToBeScheduled()));
    connect(notifyUserPresentChangeStatusButton, SIGNAL(clicked()), this, SLOT(notifyUserPresentChangeStatus()));
    connect(notifyInstallationResultButton, SIGNAL(clicked()), this, SLOT(notifyInstallationResult()));
    connect(notifyUpdatesChangeStatusButton, SIGNAL(clicked()), this, SLOT(notifyUpdatesChangeStatus()));
    connect(notifyVehicleLanguageChangeButton, SIGNAL(clicked()), this, SLOT(notifyVehicleLanguageChange()));
    connect(getCurrentSOTAInstalledSoftwareButton, SIGNAL(clicked()), this, SLOT(getCurrentSOTAInstalledSoftware()));
    connect(getInstallationResultButton, SIGNAL(clicked()), this, SLOT(getInstallationResult()));
    connect(getJLRContactDetailsButton, SIGNAL(clicked()), this, SLOT(getJLRContactDetails()));
    connect(getPreferencesVehicleButton, SIGNAL(clicked()), this, SLOT(getPreferencesVehicle()));
    connect(getSoftwareUpdateInformationButton, SIGNAL(clicked()), this, SLOT(getSoftwareUpdateInformation()));
    connect(getTCsResultButton, SIGNAL(clicked()), this, SLOT(getTCsResult()));
    connect(getVehicleLanguageButton, SIGNAL(clicked()), this, SLOT(getVehicleLanguage()));
    connect(setPreferencesVehicleButton, SIGNAL(clicked()), this, SLOT(setPreferencesVehicle()));
    connect(setTCsResultButton, SIGNAL(clicked()), this, SLOT(setTCsResult()));
    connect(SoftwareVersionButton, SIGNAL(clicked()), this, SLOT(SoftwareVersion()));
    connect(StartFileTransferButton, SIGNAL(clicked()), this, SLOT(StartFileTransfer()));
    connect(FileTransferStatusButton, SIGNAL(clicked()), this, SLOT(FileTransferStatus()));
    connect(FileTransferCompleteButton, SIGNAL(clicked()), this, SLOT(FileTransferComplete()));
    connect(StartInstallButton, SIGNAL(clicked()), this, SLOT(StartInstall()));
    connect(InstallStatusButton, SIGNAL(clicked()), this, SLOT(InstallStatus()));
    connect(InstallCompleteButton, SIGNAL(clicked()), this, SLOT(InstallComplete()));
    connect(ActivationCompleteButton, SIGNAL(clicked()), this, SLOT(ActivationComplete()));
}

MainWindow::~MainWindow()
{
    qDeleteAll(m_clients.begin(), m_clients.end());
}

//! [onNewConnection]
void MainWindow::onNewConnection()
{
    pSocket = m_pWebSocketServer->nextPendingConnection();
    qDebug() << "Client connected:";
    clientState->setText(tr("Connected"));
    connect(pSocket, &QWebSocket::textMessageReceived, this, &MainWindow::processTextMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &MainWindow::socketDisconnected);
    m_clients << pSocket;
}
//! [onNewConnection]

//! [processTextMessage]
void MainWindow::processTextMessage(QString message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient)
    {
        //pClient->sendTextMessage(message);
        receiveText->clear();
        receiveText->setText(message);

        bool parse_result;
        Json::Reader reader;
        Json::Value root;
        parse_result = reader.parse(message.toStdString(), root);
        if(parse_result == true) {
            ParseEvent(root.getMemberNames().at(0));
        }
    }
}
//! [processTextMessage]

//! [socketDisconnected]
void MainWindow::socketDisconnected()
{
    qDebug() << "Client disconnected";
    clientState->setText(tr("Disconnected"));
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (pClient)
    {
        m_clients.removeAll(pClient);
        pClient->deleteLater();
    }
}
//! [socketDisconnected]

void MainWindow::loadJSON()
{
    QString filename =  QFileDialog::getOpenFileName(
          this,
          "Open Json File",
          QDir::currentPath(),
          tr("Json(*.json)"));

    if(!filename.isNull())
    {
        qDebug() << "selected file path : " << filename.toUtf8();
        bool parsingSuccessful;
        Json::Reader reader;
        Json::Value root;
        std::string data;
        std::string buffer;
        std::ifstream openFile(filename.toStdString());
        parsingSuccessful = reader.parse(openFile, root);
        openFile.close();
        if (parsingSuccessful == false) {
            fileloadState->setText(tr("Invalid Json File"));
        } else {
            fileloadState->setText(tr("Json File Open Success"));
            hmi_info = root;
        }
    }
}

void MainWindow::ParseEvent(std::string key)
{
    qDebug() << QString::fromStdString(key);
    if(key.compare("getCurrentSOTAInstalledSoftwareRequest") == 0) {
        getCurrentSOTAInstalledSoftware();
    } else if(key.compare("getInstallationResultRequest") == 0) {
        getInstallationResult();
    } else if(key.compare("getJLRContactDetailsRequest") == 0) {
        getJLRContactDetails();
    } else if(key.compare("getPreferencesVehicleRequest") == 0) {
        getPreferencesVehicle();
    } else if(key.compare("getSoftwareUpdateInformationRequest") == 0) {
        getSoftwareUpdateInformation();
    } else if(key.compare("getTCsResultRequest") == 0) {
        getTCsResult();
    } else if(key.compare("setPreferencesVehicleRequest") == 0) {
        setPreferencesVehicle();
    } else if(key.compare("setTCsResultRequest") == 0) {
        setTCsResult();
    } else if(key.compare("setUpdateScheduleRequest") == 0) {
        setUpdateSchedule();
    } else if(key.compare("setSoftwareUpdateInstallImmediateRequest") == 0) {
        setSoftwareUpdateInstallImmediate();
    } else if(key.compare("setUnscheduleUpdateRequest") == 0) {
        setUnscheduleUpdate();
    } else if(key.compare("setUpdateAuthorisationRequest") == 0) {
        setUpdateAuthorisation();
    } else if(key.compare("setUpdateNotificationRequest") == 0) {
        setUpdateNotification();
    } else if(key.compare("FileTransferCompleteRequest") == 0) {
        FileTransferComplete();
    } else if(key.compare("notifyVehicleLanguageChangeRequest") == 0) {
        notifyVehicleLanguageChange();
    } else if(key.compare("InstallCompleteRequest") == 0) {
        InstallComplete();
    } else if(key.compare("activationcompleterequest") == 0) {
        ActivationComplete();
    } else {
        return;
    }
    SendWSMessage();
}

void MainWindow::StartServer()
{
    m_pWebSocketServer = new QWebSocketServer(QStringLiteral("VDC Test Server"),
                                              QWebSocketServer::NonSecureMode,
                                              this);

    if (m_pWebSocketServer->listen(QHostAddress::Any, 80))
    {        
        qDebug() << "VDC Test Server listening on port";
        serverState->setText(tr("Listening"));
        connect(m_pWebSocketServer, &QWebSocketServer::newConnection,
                this, &MainWindow::onNewConnection);
    } else {
        //
    }
}

void MainWindow::SendWSMessage()
{
    QString message = QString::fromLocal8Bit(str.c_str());
    qint64 size = pSocket->sendTextMessage(message);
    qDebug() << "size : " << size;
}

void MainWindow::Clear()
{
    sendText->clear();
    receiveText->clear();
}

void MainWindow::notifyUpdatesScheduled()
{
    qDebug() << "Press notifyUpdatesScheduled";
    Json::Value root = hmi_info["notifyUpdatesScheduled"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::notifyUpdatesScheduledToInstall()
{
    qDebug() << "Press notifyUpdatesScheduledToInstall";
    Json::Value root = hmi_info["notifyUpdatesScheduledToInstall"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::notifyUpdatesToBeScheduled()
{
    qDebug() << "Press notifyUpdatesToBeScheduled";
    Json::Value root = hmi_info["notifyUpdatesToBeScheduled"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::notifyUserPresentChangeStatus()
{
    Json::Value root = hmi_info["notifyUserPresentChangeStatus"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::notifyInstallationResult()
{
    Json::Value root = hmi_info["notifyInstallationResult"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::notifyUpdatesChangeStatus()
{
    Json::Value root = hmi_info["notifyUpdatesChangeStatus"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::notifyVehicleLanguageChange()
{
    Json::Value root = hmi_info["notifyVehicleChangeLanguage"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::getCurrentSOTAInstalledSoftware()
{
    Json::Value root = hmi_info["getCurrentSOTAInstalledSoftware"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::getInstallationResult()
{
    Json::Value root = hmi_info["getInstallationResult"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::getJLRContactDetails()
{
    Json::Value root = hmi_info["getJLRContactDetails"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::getPreferencesVehicle()
{
    Json::Value root = hmi_info["getPreferencesVehicle"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::getSoftwareUpdateInformation()
{
    Json::Value root = hmi_info["getSoftwareUpdateInformation"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::getTCsResult()
{
    Json::Value root = hmi_info["getTCsResult"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::getVehicleLanguage()
{
    Json::Value root = hmi_info["getVehicleLanguage"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::setPreferencesVehicle()
{
    Json::Value root = hmi_info["setPreferencesVehicle"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::setTCsResult()
{
    Json::Value root = hmi_info["setTCsResult"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::setUpdateSchedule()
{
    Json::Value root = hmi_info["setUpdateSchedule"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::setSoftwareUpdateInstallImmediate()
{
    Json::Value root = hmi_info["setSoftwareUpdateInstallImmediate"];
    qDebug() << QString::fromStdString(root["setSoftwareUpdateInstallImmediateResponse"]["messageData"]["errorGeneralErrorResponse"].asString());
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::setUnscheduleUpdate()
{
    Json::Value root = hmi_info["setUnscheduleUpdate"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::setUpdateAuthorisation()
{
    Json::Value root = hmi_info["setUpdateAuthorisation"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::setUpdateNotification()
{
    Json::Value root = hmi_info["setUpdateNotification"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::SoftwareVersion()
{
    Json::Value root = hmi_info["SoftwareVersion"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::StartFileTransfer()
{
    Json::Value root = hmi_info["StartFileTransfer"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::FileTransferStatus()
{
    Json::Value root = hmi_info["FileTransferStatus"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::FileTransferComplete()
{
    Json::Value root = hmi_info["FileTransferComplete"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::StartInstall()
{
    Json::Value root = hmi_info["InstallSoftware"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::InstallStatus()
{
    Json::Value root = hmi_info["InstallStatus"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::InstallComplete()
{
    Json::Value root = hmi_info["InstallComplete"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}

void MainWindow::ActivationComplete()
{
    Json::Value root = hmi_info["ActivationComplete"];
    str = styledWriter.write(root);
    sendText->clear();
    sendText->setText(QString::fromStdString(str));
}
