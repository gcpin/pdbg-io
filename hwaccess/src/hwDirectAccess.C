#include "hwDirectAccess.H"

namespace HWACCESS
{
HwDirectAccess& HwDirectAccess::getInstance()
{
    static HwDirectAccess directAccessInstance;
    return directAccessInstance;
}

int HwDirectAccess::getCfam(TargetPtr_t target, uint32_t addr, uint32_t& val)
{
    //fetch device path etc from Targeting trygetattr and
    // call to plat hw transport method
    // assert if the target is non-proc
    std::cout << "HwDirectAccess::getCfam executed" << std::endl;
    return 0;
}

int HwDirectAccess::putCfam(TargetPtr_t target, uint32_t addr, uint32_t val)
{
    //fetch device path etc from Targeting trygetattr and
    // call to plat hw transport method
    // assert if the target is non-proc
    std::cout << "HwDirectAccess::putCfam executed" << std::endl;
    return 0;
}
} // namespace HWACCESS
