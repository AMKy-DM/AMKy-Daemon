#ifndef AMKY_DAEMON_DOWNLOADMANAGER_HPP
#define AMKY_DAEMON_DOWNLOADMANAGER_HPP

#include <memory>
#include <config/Configuration.hpp>

class DownloadItem;
class TaskScheduler;

class DownloadManager
{
private:
    std::shared_ptr<Configuration> _configuration;

public:
    DownloadManager(std::shared_ptr<Configuration> configuration);

    void enqueueDownloadItem(const DownloadItem &downloadItem);
    void pauseItem(const DownloadItem &downloadItem);

    void start(const TaskScheduler &taskScheduler);

    void stop();
};

#endif //AMKY_DAEMON_DOWNLOADMANAGER_HPP
