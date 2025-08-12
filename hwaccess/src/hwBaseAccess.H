#pragma once

#include <targeting/target.H>
#include <targeting/xmltohb/attributeenums.H>
#include <targeting/xmltohb/attributetraits.H>

namespace HWACCESS
{
class HwBaseAccess //Abstract class for HwAccess
{
public:
    HwBaseAccess(){}
    HwBaseAccess(const HwBaseAccess&) = delete;
    HwBaseAccess& operator=(const HwBaseAccess&) = delete;
    virtual ~HwBaseAccess() = default;

    virtual int getCfam(TargetPtr_t target, uint32_t addr, uint32_t& val) = 0;
    virtual int putCfam(TargetPtr_t target, uint32_t addr, uint32_t val) = 0;
};
}  // namespace HWACCESS
