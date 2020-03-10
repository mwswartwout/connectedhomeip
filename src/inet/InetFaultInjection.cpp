/*
 *
 *    <COPYRIGHT>
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *      Implementation of the fault-injection utilities for Inet.
 */

#include <nlassert.h>
#include "InetFaultInjection.h"

#if INET_CONFIG_TEST


namespace Inet {
namespace FaultInjection {

static FaultInjection::Record sFaultRecordArray[kFault_NumItems];
static class FaultInjection::Manager sInetFaultInMgr;
static const FaultInjection::Name sManagerName = "Inet";
static const FaultInjection::Name sFaultNames[] = {
    "DNSResolverNew",
    "Send",
    "SendNonCritical",
};


/**
 * Get the singleton FaultInjection::Manager for Inet faults
 */
FaultInjection::Manager &GetManager(void)
{
    if (0 == sInetFaultInMgr.GetNumFaults())
    {
        sInetFaultInMgr.Init(kFault_NumItems,
                             sFaultRecordArray,
                             sManagerName,
                             sFaultNames);
    }
    return sInetFaultInMgr;
}

} // namespace FaultInjection
} // namespace Inet

#endif // INET_CONFIG_TEST
