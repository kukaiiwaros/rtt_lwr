#include <rtt/RTT.hpp>
#include <rtt/Property.hpp>
#include <rtt/plugin/ServicePlugin.hpp>


using namespace RTT;
using namespace std;

class LwrHelper: public RTT::Service
{
public:
    LwrHelper(TaskContext* owner) :
    Service("lwr_helper", owner)
    {
        this->addOperation("connectHw", &LwrHelper::connectHw, this);
        this->addOperation("connectSim", &LwrHelper::connectSim, this);
        this->addOperation("connectPeers", &LwrHelper::connectPeers, this);
    }
    bool connectHw(const std::string& name)
    {
    }
    bool connectSim(const std::string& name)
    {
    }
    bool connectPeers(const std::string& interface_name,const std::string& peer_name)
    {
        if(this->getOwner()->hasPeer(interface_name) == false){return false;}
        if(this->getOwner()->getPeer(interface_name)->hasPeer(peer_name) == false) { return false;}
        //return this->getOwner()->addPeer(this->getOwner()->getPeer(interface_name)->getPeer(peer_name),peer_name);
        return this->getOwner()->connectPeers(this->getOwner()->getPeer(interface_name)->getPeer(peer_name));
    }
};

ORO_SERVICE_NAMED_PLUGIN(LwrHelper, "lwr_helper")
