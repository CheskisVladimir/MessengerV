#pragma once

#include "common.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

using GUID = boost::uuids::uuid;

class IEntity
{
public:
    IEntity() = default;
    virtual ~IEntity() = default;
    virtual GUID GetID() const = 0;
};

template <typename EntityType>
class EntityContainer final
{
public:
    EntityContainer() = default;
    ~EntityContainer() = default;
    void AddEntity(std::unique_ptr<EntityType> &entity);
    void RemoveEntity(GUID id);
    EntityType *GetEntity(GUID id);
    const EntityType *GetEntity(GUID id) const;

private:
    std::unordered_map<GUID, std::unique_ptr<EntityType>> m_entities;
};

template <typename EntityType>
inline void EntityContainer<EntityType>::AddEntity(std::unique_ptr<EntityType> &entity)
{
}

template <typename EntityType>
inline void EntityContainer<EntityType>::RemoveEntity(GUID id)
{
}

template <typename EntityType>
inline EntityType *EntityContainer<EntityType>::GetEntity(GUID id)
{
    return nullptr;
}

template <typename EntityType>
inline const EntityType *EntityContainer<EntityType>::GetEntity(GUID id) const
{
    return nullptr;
}
