//
//

#ifndef AMKY_DAEMON_DOWNLOADMANAGER_H
#define AMKY_DAEMON_DOWNLOADMANAGER_H

class DownloadItem;
class TaskScheduler;

class DownloadManager
{

public:
    void enqueueDownloadItem(const DownloadItem &downloadItem);
    void pauseItem(const DownloadItem &downloadItem);

    void start(const TaskScheduler &taskScheduler);

    void stop();
};

#endif //AMKY_DAEMON_DOWNLOADMANAGER_H
