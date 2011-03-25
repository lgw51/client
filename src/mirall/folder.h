#ifndef MIRALL_FOLDER_H
#define MIRALL_FOLDER_H

#include <QObject>
#include <QString>
#include <QStringList>

class QAction;

namespace Mirall {

class FolderWatcher;

class Folder : public QObject
{
    Q_OBJECT

public:
    Folder(const QString &path, QObject *parent = 0L);
    virtual ~Folder();

    /**
     * local folder path
     */
    QString path() const;

    QAction *openAction() const;

    /**
     * starts a sync operation
     * requests are serialized
     */
    virtual void startSync(const QStringList &pathList) = 0;

    virtual bool isSyncing() const = 0;

signals:
    void syncStarted();
    void syncFinished();

protected:

private:
    QString _path;
    FolderWatcher *_watcher;
    QAction *_openAction;
private slots:
    void slotChanged(const QStringList &pathList);
    void slotOpenFolder();

    void slotSyncStarted();
    void slotSyncFinished();
};

}

#endif
