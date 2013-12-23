#ifndef BASENETWORKACCESSMANAGER_H
#define BASENETWORKACCESSMANAGER_H

#include <QNetworkAccessManager>


// This is base class for all network access managers.
class BaseNetworkAccessManager : public QNetworkAccessManager {
    Q_OBJECT

  public:
    // Constructors and desctructors.
    explicit BaseNetworkAccessManager(QObject *parent = 0);
    virtual ~BaseNetworkAccessManager();

  public slots:
    // Loads network settings for this instance.
    // NOTE: This sets up proxy settings.
    virtual void loadSettings();

  protected:

    QNetworkReply *createRequest(Operation op,
                                 const QNetworkRequest &request,
                                 QIODevice *outgoingData);
};

#endif // BASENETWORKACCESSMANAGER_H
