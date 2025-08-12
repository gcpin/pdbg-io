#include "hwSbeAccess.H"

namespace HWACCESS
{
HwSbeAccess& HwSbeAccess::getInstance()
{
    static HwSbeAccess sbeAccessInstance;
    return sbeAccessInstance;
}

int HwSbeAccess::getCfam(TargetPtr_t target, uint32_t addr, uint32_t& val) override
{
    std::cerr << "getCfam executed via SbeAccess path" << std::endl;
    return 0;
}

int HwSbeAccess::putCfam(TargetPtr_t target, uint32_t addr, uint32_t val) override
{
    std::cout << "putCfam executed via SbeAccess path" << std::endl;
    return 0;
}
} //namespace HWACCESS
