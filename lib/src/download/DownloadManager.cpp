//
//

#include "DownloadManager.hpp"
#include "DownloadItem.hpp"


DownloadManager::DownloadManager(std::shared_ptr<Configuration> configuration) {
    _configuration = configuration;
}


void DownloadManager::enqueueDownloadItem(const DownloadItem &downloadItem)
{
}

void DownloadManager::pauseItem(const DownloadItem &downloadItem)
{
}

void DownloadManager::start(const TaskScheduler &taskScheduler)
{
}

void DownloadManager::stop()
{
}