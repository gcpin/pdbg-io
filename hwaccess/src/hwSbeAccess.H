#pragma once

#include "hwBaseAccess.H"

namespace HWACCESS
{
class HwSbeAccess : public HwBaseAccess
{
private:
    HwSbeAccess(){};
public:
    HwSbeAccess(const HwSbeAccess&) = delete;
    HwSbeAccess& operator=(const HwSbeAccess&) = delete;
    static HwSbeAccess& getInstance();
    
};
} // namespace HWACCESS
