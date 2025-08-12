#pragma once

#include <target.H>
#include <attributeenums.H>
#include <attributetraits.H>
#include <hwAccessIntf.H>

namespace HWACCESS
{
class HwBaseAccess 
{
protected:
    HwBaseAccess() = default;
    HwBaseAccess(const HwBaseAccess&) = delete;
    HwBaseAccess& operator=(const HwBaseAccess&) = delete;
    virtual ~HwBaseAccess() = default;

public:
    virtual int getCfam(TargetPtr_t /*target*/, uint32_t /*addr*/, uint32_t& /*val*/){return 0;}
    virtual int putCfam(TargetPtr_t /*target*/, uint32_t /*addr*/, uint32_t /*val*/){return 0;}
};
}  // namespace HWACCESS
