#pragma once

#include "common.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

using ID = std::string;
using string = std::string;
using time_point = std::chrono::system_clock::time_point;
using buffer_data = std::vector<uint8_t>;
using packed_data = buffer_data;
using unpacked_data = buffer_data;

class IEntity
{
public:
    IEntity() = default;
    virtual ~IEntity() = default;
    virtual ID GetID() const = 0;
};

template <typename EntityType>
class EntityContainer final
{
public:
    EntityContainer() = default;
    ~EntityContainer() = default;
    void AddEntity(std::unique_ptr<EntityType> &entity);
    void RemoveEntity(ID id);
    EntityType *GetEntity(ID id);
    const EntityType *GetEntity(ID id) const;

private:
    std::unordered_map<ID, std::unique_ptr<EntityType>> m_entities;
};

template <typename EntityType>
inline void EntityContainer<EntityType>::AddEntity(std::unique_ptr<EntityType> &entity)
{
}

template <typename EntityType>
inline void EntityContainer<EntityType>::RemoveEntity(ID id)
{
}

template <typename EntityType>
inline EntityType *EntityContainer<EntityType>::GetEntity(ID id)
{
    return nullptr;
}

template <typename EntityType>
inline const EntityType *EntityContainer<EntityType>::GetEntity(ID id) const
{
    return nullptr;
}
