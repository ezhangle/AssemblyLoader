#ifndef __APPDOMAIN_HXX__
#define __APPDOMAIN_HXX__

#include <cstdint>
#include <vector>
#include <map>
#include <memory>
#include <string>

#include "AssemblyData.hxx"
#include "ExecutionThread.hxx"
#include "crossguid/guid.hxx"

struct AppDomain {
    std::map<Guid, std::shared_ptr<const AssemblyData> > assemblies;
    std::vector<std::shared_ptr<ExecutionThread> > threads;

    const Guid& loadAssembly(const AssemblyData* assembly);
    const AssemblyData* AppDomain::getAssembly(const Guid& guid) const;
    const AssemblyData* AppDomain::getAssembly(const std::u16string& name, const std::vector<uint16_t>& version) const;
    ExecutionThread* AppDomain::createThread();

    template<typename T>
    const Guid& loadAssembly(const T& assembly) {
        const auto* assemblyData = new AssemblyData(assembly);
        return loadAssembly(assemblyData);
    }

};

#endif
