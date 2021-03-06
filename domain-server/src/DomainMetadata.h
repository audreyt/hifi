//
//  DomainMetadata.h
//  domain-server/src
//
//  Created by Zach Pomerantz on 5/25/2016.
//  Copyright 2016 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html

#ifndef hifi_DomainMetadata_h
#define hifi_DomainMetadata_h

#include <stdint.h>

#include <QVariantMap>
#include <QJsonObject>

class DomainMetadata : public QObject {
Q_OBJECT

    static const QString USERS;
    static const QString USERS_NUM_TOTAL;
    static const QString USERS_NUM_ANON;
    static const QString USERS_HOSTNAMES;

    static const QString DESCRIPTORS;
    static const QString DESCRIPTORS_DESCRIPTION;
    static const QString DESCRIPTORS_CAPACITY;
    static const QString DESCRIPTORS_HOURS;
    static const QString DESCRIPTORS_RESTRICTION;
    static const QString DESCRIPTORS_MATURITY;
    static const QString DESCRIPTORS_HOSTS;
    static const QString DESCRIPTORS_TAGS;
    static const QString DESCRIPTORS_IMG;
    static const QString DESCRIPTORS_IMG_SRC;
    static const QString DESCRIPTORS_IMG_TYPE;
    static const QString DESCRIPTORS_IMG_SIZE;
    static const QString DESCRIPTORS_IMG_UPDATED_AT;

public:
    DomainMetadata();

    // Returns the last set metadata
    // If connected users have changed, metadata may need to be updated
    // this should be checked by storing tic = getTic() between calls
    // and testing it for equality before the next get (tic == getTic())
    QJsonObject get() { return QJsonObject::fromVariantMap(_metadata); }
    QJsonObject getUsers() { return QJsonObject::fromVariantMap(_metadata[USERS].toMap()); }
    QJsonObject getDescriptors() { return QJsonObject::fromVariantMap(_metadata[DESCRIPTORS].toMap()); }

    uint32_t getTic() { return _tic; }

    void setDescriptors(QVariantMap& settings);
    void updateUsers();

public slots:
    void usersChanged();

protected:
    QVariantMap _metadata;
    uint32_t _tic{ 0 };
};

#endif // hifi_DomainMetadata_h
