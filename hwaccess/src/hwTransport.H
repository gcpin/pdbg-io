#pragma once

#include <target.H>

namespace HWTRANSPORT
{
class HwTransportIntf
{
public:
        static int getCfam(const char* path, uint32_t addr, uint32_t& val); 
        static int putCfam(const char* path, uint32_t addr, uint32_t val);
};
} // namespace HWTRANSPORT
