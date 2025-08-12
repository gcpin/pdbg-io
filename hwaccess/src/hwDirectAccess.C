#include "hwDirectAccess.H"
#include "hwTransport.H"

namespace HWACCESS
{
using DirectAccessPath = TARGETING::AttributeTraits<TARGETING::ATTR_DIRECT_ACCESS_DEVICE_PATH>::TypeStdArr;

HwDirectAccess& HwDirectAccess::getInstance()
{
    static HwDirectAccess directAccessInstance;
    return directAccessInstance;
}

int HwDirectAccess::getCfam(TargetPtr_t target, uint32_t addr, uint32_t& val)
{
    if(target == nullptr)
    {
        return -1;
    }

    DirectAccessPath accessPath;
 
    if(target->tryGetAttr<TARGETING::ATTR_DIRECT_ACCESS_DEVICE_PATH>(accessPath))
    {
        std::cout << "HwDirectAccess::getCfam executed" << std::endl;
        return HWTRANSPORT::HwTransportIntf::getCfam(accessPath.data(), addr, val);
    }

    return 0;
}

int HwDirectAccess::putCfam(TargetPtr_t target, uint32_t addr, uint32_t val)
{
    if(target == nullptr)
    {
        return -1;
    }

    DirectAccessPath accessPath;
 
    if(target->tryGetAttr<TARGETING::ATTR_DIRECT_ACCESS_DEVICE_PATH>(accessPath))
    {
        std::cout << "HwDirectAccess::putCfam executed" << std::endl;
        return HWTRANSPORT::HwTransportIntf::putCfam(accessPath.data(), addr, val);
    }

    return 0;
}
} // namespace HWACCESS
