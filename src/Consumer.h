#include <Common/Configuration.h>


#include <Common/DataBlock.h>
#include <Common/DataBlockContainer.h>
#include <Common/DataSet.h>

#include <memory>


#include <InfoLogger/InfoLogger.hxx>
using namespace AliceO2::InfoLogger;


class Consumer {
  public:
  Consumer(ConfigFile &, std::string) {
  };
  virtual ~Consumer() {
  };
  virtual int pushData(DataBlockContainerReference &b)=0;
  
  virtual int starting() {return 0;}; // function called when starting data taking. Data will soon start to flow in.
  virtual int stopping() {return 0;}; // function called when stopping data taking. Data will soon stop to flow in (but pushData will still be called while fifo not empty).
  
  protected:
    InfoLogger theLog;
};


std::unique_ptr<Consumer> getUniqueConsumerStats(ConfigFile &cfg, std::string cfgEntryPoint);
std::unique_ptr<Consumer> getUniqueConsumerFMQ(ConfigFile &cfg, std::string cfgEntryPoint);
std::unique_ptr<Consumer> getUniqueConsumerFileRecorder(ConfigFile &cfg, std::string cfgEntryPoint);
std::unique_ptr<Consumer> getUniqueConsumerDataChecker(ConfigFile &cfg, std::string cfgEntryPoint);
std::unique_ptr<Consumer> getUniqueConsumerDataSampling(ConfigFile &cfg, std::string cfgEntryPoint);


