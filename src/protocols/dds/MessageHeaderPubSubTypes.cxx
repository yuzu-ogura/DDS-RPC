// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*
 * @file MessageHeaderPubSubTypes.cpp
 * This header file contains the implementation of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#include <fastcdr/FastBuffer.h>
#include <fastcdr/Cdr.h>

#include "protocols/dds/MessageHeaderPubSubTypes.h"

using SerializedPayload_t = eprosima::fastrtps::rtps::SerializedPayload_t;
using InstanceHandle_t = eprosima::fastrtps::rtps::InstanceHandle_t;

namespace eprosima {
    namespace rpc {
        namespace protocol {

            EntityId_tPubSubType::EntityId_tPubSubType()
            {
                setName("eprosima::rpc::protocol::EntityId_t");
                auto type_size = EntityId_t::getMaxCdrSerializedSize();
                type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
                m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
                m_isGetKeyDefined = EntityId_t::isKeyDefined();
                size_t keyLength = EntityId_t::getKeyMaxCdrSerializedSize() > 16 ?
                        EntityId_t::getKeyMaxCdrSerializedSize() : 16;
                m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
                memset(m_keyBuffer, 0, keyLength);
            }

            EntityId_tPubSubType::~EntityId_tPubSubType()
            {
                if (m_keyBuffer != nullptr)
                {
                    free(m_keyBuffer);
                }
            }

            bool EntityId_tPubSubType::serialize(
                    void* data,
                    SerializedPayload_t* payload)
            {
                EntityId_t* p_type = static_cast<EntityId_t*>(data);

                // Object that manages the raw buffer.
                eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
                // Object that serializes the data.
                eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
                payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
                // Serialize encapsulation
                ser.serialize_encapsulation();

                try
                {
                    // Serialize the object.
                    p_type->serialize(ser);
                }
                catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
                {
                    return false;
                }

                // Get the serialized length
                payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
                return true;
            }

            bool EntityId_tPubSubType::deserialize(
                    SerializedPayload_t* payload,
                    void* data)
            {
                try
                {
                    //Convert DATA to pointer of your type
                    EntityId_t* p_type = static_cast<EntityId_t*>(data);

                    // Object that manages the raw buffer.
                    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

                    // Object that deserializes the data.
                    eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);

                    // Deserialize encapsulation.
                    deser.read_encapsulation();
                    payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

                    // Deserialize the object.
                    p_type->deserialize(deser);
                }
                catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
                {
                    return false;
                }

                return true;
            }

            std::function<uint32_t()> EntityId_tPubSubType::getSerializedSizeProvider(
                    void* data)
            {
                return [data]() -> uint32_t
                       {
                           return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<EntityId_t*>(data))) +
                                  4u /*encapsulation*/;
                       };
            }

            void* EntityId_tPubSubType::createData()
            {
                return reinterpret_cast<void*>(new EntityId_t());
            }

            void EntityId_tPubSubType::deleteData(
                    void* data)
            {
                delete(reinterpret_cast<EntityId_t*>(data));
            }

            bool EntityId_tPubSubType::getKey(
                    void* data,
                    InstanceHandle_t* handle,
                    bool force_md5)
            {
                if (!m_isGetKeyDefined)
                {
                    return false;
                }

                EntityId_t* p_type = static_cast<EntityId_t*>(data);

                // Object that manages the raw buffer.
                eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
                        EntityId_t::getKeyMaxCdrSerializedSize());

                // Object that serializes the data.
                eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
                p_type->serializeKey(ser);
                if (force_md5 || EntityId_t::getKeyMaxCdrSerializedSize() > 16)
                {
                    m_md5.init();
                    m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
                    m_md5.finalize();
                    for (uint8_t i = 0; i < 16; ++i)
                    {
                        handle->value[i] = m_md5.digest[i];
                    }
                }
                else
                {
                    for (uint8_t i = 0; i < 16; ++i)
                    {
                        handle->value[i] = m_keyBuffer[i];
                    }
                }
                return true;
            }

            GUID_tPubSubType::GUID_tPubSubType()
            {
                setName("eprosima::rpc::protocol::GUID_t");
                auto type_size = GUID_t::getMaxCdrSerializedSize();
                type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
                m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
                m_isGetKeyDefined = GUID_t::isKeyDefined();
                size_t keyLength = GUID_t::getKeyMaxCdrSerializedSize() > 16 ?
                        GUID_t::getKeyMaxCdrSerializedSize() : 16;
                m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
                memset(m_keyBuffer, 0, keyLength);
            }

            GUID_tPubSubType::~GUID_tPubSubType()
            {
                if (m_keyBuffer != nullptr)
                {
                    free(m_keyBuffer);
                }
            }

            bool GUID_tPubSubType::serialize(
                    void* data,
                    SerializedPayload_t* payload)
            {
                GUID_t* p_type = static_cast<GUID_t*>(data);

                // Object that manages the raw buffer.
                eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
                // Object that serializes the data.
                eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
                payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
                // Serialize encapsulation
                ser.serialize_encapsulation();

                try
                {
                    // Serialize the object.
                    p_type->serialize(ser);
                }
                catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
                {
                    return false;
                }

                // Get the serialized length
                payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
                return true;
            }

            bool GUID_tPubSubType::deserialize(
                    SerializedPayload_t* payload,
                    void* data)
            {
                try
                {
                    //Convert DATA to pointer of your type
                    GUID_t* p_type = static_cast<GUID_t*>(data);

                    // Object that manages the raw buffer.
                    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

                    // Object that deserializes the data.
                    eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);

                    // Deserialize encapsulation.
                    deser.read_encapsulation();
                    payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

                    // Deserialize the object.
                    p_type->deserialize(deser);
                }
                catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
                {
                    return false;
                }

                return true;
            }

            std::function<uint32_t()> GUID_tPubSubType::getSerializedSizeProvider(
                    void* data)
            {
                return [data]() -> uint32_t
                       {
                           return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<GUID_t*>(data))) +
                                  4u /*encapsulation*/;
                       };
            }

            void* GUID_tPubSubType::createData()
            {
                return reinterpret_cast<void*>(new GUID_t());
            }

            void GUID_tPubSubType::deleteData(
                    void* data)
            {
                delete(reinterpret_cast<GUID_t*>(data));
            }

            bool GUID_tPubSubType::getKey(
                    void* data,
                    InstanceHandle_t* handle,
                    bool force_md5)
            {
                if (!m_isGetKeyDefined)
                {
                    return false;
                }

                GUID_t* p_type = static_cast<GUID_t*>(data);

                // Object that manages the raw buffer.
                eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
                        GUID_t::getKeyMaxCdrSerializedSize());

                // Object that serializes the data.
                eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
                p_type->serializeKey(ser);
                if (force_md5 || GUID_t::getKeyMaxCdrSerializedSize() > 16)
                {
                    m_md5.init();
                    m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
                    m_md5.finalize();
                    for (uint8_t i = 0; i < 16; ++i)
                    {
                        handle->value[i] = m_md5.digest[i];
                    }
                }
                else
                {
                    for (uint8_t i = 0; i < 16; ++i)
                    {
                        handle->value[i] = m_keyBuffer[i];
                    }
                }
                return true;
            }

            SequenceNumber_tPubSubType::SequenceNumber_tPubSubType()
            {
                setName("eprosima::rpc::protocol::SequenceNumber_t");
                auto type_size = SequenceNumber_t::getMaxCdrSerializedSize();
                type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
                m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
                m_isGetKeyDefined = SequenceNumber_t::isKeyDefined();
                size_t keyLength = SequenceNumber_t::getKeyMaxCdrSerializedSize() > 16 ?
                        SequenceNumber_t::getKeyMaxCdrSerializedSize() : 16;
                m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
                memset(m_keyBuffer, 0, keyLength);
            }

            SequenceNumber_tPubSubType::~SequenceNumber_tPubSubType()
            {
                if (m_keyBuffer != nullptr)
                {
                    free(m_keyBuffer);
                }
            }

            bool SequenceNumber_tPubSubType::serialize(
                    void* data,
                    SerializedPayload_t* payload)
            {
                SequenceNumber_t* p_type = static_cast<SequenceNumber_t*>(data);

                // Object that manages the raw buffer.
                eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
                // Object that serializes the data.
                eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
                payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
                // Serialize encapsulation
                ser.serialize_encapsulation();

                try
                {
                    // Serialize the object.
                    p_type->serialize(ser);
                }
                catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
                {
                    return false;
                }

                // Get the serialized length
                payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
                return true;
            }

            bool SequenceNumber_tPubSubType::deserialize(
                    SerializedPayload_t* payload,
                    void* data)
            {
                try
                {
                    //Convert DATA to pointer of your type
                    SequenceNumber_t* p_type = static_cast<SequenceNumber_t*>(data);

                    // Object that manages the raw buffer.
                    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

                    // Object that deserializes the data.
                    eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);

                    // Deserialize encapsulation.
                    deser.read_encapsulation();
                    payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

                    // Deserialize the object.
                    p_type->deserialize(deser);
                }
                catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
                {
                    return false;
                }

                return true;
            }

            std::function<uint32_t()> SequenceNumber_tPubSubType::getSerializedSizeProvider(
                    void* data)
            {
                return [data]() -> uint32_t
                       {
                           return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<SequenceNumber_t*>(data))) +
                                  4u /*encapsulation*/;
                       };
            }

            void* SequenceNumber_tPubSubType::createData()
            {
                return reinterpret_cast<void*>(new SequenceNumber_t());
            }

            void SequenceNumber_tPubSubType::deleteData(
                    void* data)
            {
                delete(reinterpret_cast<SequenceNumber_t*>(data));
            }

            bool SequenceNumber_tPubSubType::getKey(
                    void* data,
                    InstanceHandle_t* handle,
                    bool force_md5)
            {
                if (!m_isGetKeyDefined)
                {
                    return false;
                }

                SequenceNumber_t* p_type = static_cast<SequenceNumber_t*>(data);

                // Object that manages the raw buffer.
                eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
                        SequenceNumber_t::getKeyMaxCdrSerializedSize());

                // Object that serializes the data.
                eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
                p_type->serializeKey(ser);
                if (force_md5 || SequenceNumber_t::getKeyMaxCdrSerializedSize() > 16)
                {
                    m_md5.init();
                    m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
                    m_md5.finalize();
                    for (uint8_t i = 0; i < 16; ++i)
                    {
                        handle->value[i] = m_md5.digest[i];
                    }
                }
                else
                {
                    for (uint8_t i = 0; i < 16; ++i)
                    {
                        handle->value[i] = m_keyBuffer[i];
                    }
                }
                return true;
            }

            SampleIdentity_tPubSubType::SampleIdentity_tPubSubType()
            {
                setName("eprosima::rpc::protocol::SampleIdentity_t");
                auto type_size = SampleIdentity_t::getMaxCdrSerializedSize();
                type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
                m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
                m_isGetKeyDefined = SampleIdentity_t::isKeyDefined();
                size_t keyLength = SampleIdentity_t::getKeyMaxCdrSerializedSize() > 16 ?
                        SampleIdentity_t::getKeyMaxCdrSerializedSize() : 16;
                m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
                memset(m_keyBuffer, 0, keyLength);
            }

            SampleIdentity_tPubSubType::~SampleIdentity_tPubSubType()
            {
                if (m_keyBuffer != nullptr)
                {
                    free(m_keyBuffer);
                }
            }

            bool SampleIdentity_tPubSubType::serialize(
                    void* data,
                    SerializedPayload_t* payload)
            {
                SampleIdentity_t* p_type = static_cast<SampleIdentity_t*>(data);

                // Object that manages the raw buffer.
                eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
                // Object that serializes the data.
                eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
                payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
                // Serialize encapsulation
                ser.serialize_encapsulation();

                try
                {
                    // Serialize the object.
                    p_type->serialize(ser);
                }
                catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
                {
                    return false;
                }

                // Get the serialized length
                payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
                return true;
            }

            bool SampleIdentity_tPubSubType::deserialize(
                    SerializedPayload_t* payload,
                    void* data)
            {
                try
                {
                    //Convert DATA to pointer of your type
                    SampleIdentity_t* p_type = static_cast<SampleIdentity_t*>(data);

                    // Object that manages the raw buffer.
                    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

                    // Object that deserializes the data.
                    eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);

                    // Deserialize encapsulation.
                    deser.read_encapsulation();
                    payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

                    // Deserialize the object.
                    p_type->deserialize(deser);
                }
                catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
                {
                    return false;
                }

                return true;
            }

            std::function<uint32_t()> SampleIdentity_tPubSubType::getSerializedSizeProvider(
                    void* data)
            {
                return [data]() -> uint32_t
                       {
                           return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<SampleIdentity_t*>(data))) +
                                  4u /*encapsulation*/;
                       };
            }

            void* SampleIdentity_tPubSubType::createData()
            {
                return reinterpret_cast<void*>(new SampleIdentity_t());
            }

            void SampleIdentity_tPubSubType::deleteData(
                    void* data)
            {
                delete(reinterpret_cast<SampleIdentity_t*>(data));
            }

            bool SampleIdentity_tPubSubType::getKey(
                    void* data,
                    InstanceHandle_t* handle,
                    bool force_md5)
            {
                if (!m_isGetKeyDefined)
                {
                    return false;
                }

                SampleIdentity_t* p_type = static_cast<SampleIdentity_t*>(data);

                // Object that manages the raw buffer.
                eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
                        SampleIdentity_t::getKeyMaxCdrSerializedSize());

                // Object that serializes the data.
                eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
                p_type->serializeKey(ser);
                if (force_md5 || SampleIdentity_t::getKeyMaxCdrSerializedSize() > 16)
                {
                    m_md5.init();
                    m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
                    m_md5.finalize();
                    for (uint8_t i = 0; i < 16; ++i)
                    {
                        handle->value[i] = m_md5.digest[i];
                    }
                }
                else
                {
                    for (uint8_t i = 0; i < 16; ++i)
                    {
                        handle->value[i] = m_keyBuffer[i];
                    }
                }
                return true;
            }






            RequestHeaderPubSubType::RequestHeaderPubSubType()
            {
                setName("eprosima::rpc::protocol::RequestHeader");
                auto type_size = RequestHeader::getMaxCdrSerializedSize();
                type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
                m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
                m_isGetKeyDefined = RequestHeader::isKeyDefined();
                size_t keyLength = RequestHeader::getKeyMaxCdrSerializedSize() > 16 ?
                        RequestHeader::getKeyMaxCdrSerializedSize() : 16;
                m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
                memset(m_keyBuffer, 0, keyLength);
            }

            RequestHeaderPubSubType::~RequestHeaderPubSubType()
            {
                if (m_keyBuffer != nullptr)
                {
                    free(m_keyBuffer);
                }
            }

            bool RequestHeaderPubSubType::serialize(
                    void* data,
                    SerializedPayload_t* payload)
            {
                RequestHeader* p_type = static_cast<RequestHeader*>(data);

                // Object that manages the raw buffer.
                eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
                // Object that serializes the data.
                eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
                payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
                // Serialize encapsulation
                ser.serialize_encapsulation();

                try
                {
                    // Serialize the object.
                    p_type->serialize(ser);
                }
                catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
                {
                    return false;
                }

                // Get the serialized length
                payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
                return true;
            }

            bool RequestHeaderPubSubType::deserialize(
                    SerializedPayload_t* payload,
                    void* data)
            {
                try
                {
                    //Convert DATA to pointer of your type
                    RequestHeader* p_type = static_cast<RequestHeader*>(data);

                    // Object that manages the raw buffer.
                    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

                    // Object that deserializes the data.
                    eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);

                    // Deserialize encapsulation.
                    deser.read_encapsulation();
                    payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

                    // Deserialize the object.
                    p_type->deserialize(deser);
                }
                catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
                {
                    return false;
                }

                return true;
            }

            std::function<uint32_t()> RequestHeaderPubSubType::getSerializedSizeProvider(
                    void* data)
            {
                return [data]() -> uint32_t
                       {
                           return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<RequestHeader*>(data))) +
                                  4u /*encapsulation*/;
                       };
            }

            void* RequestHeaderPubSubType::createData()
            {
                return reinterpret_cast<void*>(new RequestHeader());
            }

            void RequestHeaderPubSubType::deleteData(
                    void* data)
            {
                delete(reinterpret_cast<RequestHeader*>(data));
            }

            bool RequestHeaderPubSubType::getKey(
                    void* data,
                    InstanceHandle_t* handle,
                    bool force_md5)
            {
                if (!m_isGetKeyDefined)
                {
                    return false;
                }

                RequestHeader* p_type = static_cast<RequestHeader*>(data);

                // Object that manages the raw buffer.
                eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
                        RequestHeader::getKeyMaxCdrSerializedSize());

                // Object that serializes the data.
                eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
                p_type->serializeKey(ser);
                if (force_md5 || RequestHeader::getKeyMaxCdrSerializedSize() > 16)
                {
                    m_md5.init();
                    m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
                    m_md5.finalize();
                    for (uint8_t i = 0; i < 16; ++i)
                    {
                        handle->value[i] = m_md5.digest[i];
                    }
                }
                else
                {
                    for (uint8_t i = 0; i < 16; ++i)
                    {
                        handle->value[i] = m_keyBuffer[i];
                    }
                }
                return true;
            }

            ReplyHeaderPubSubType::ReplyHeaderPubSubType()
            {
                setName("eprosima::rpc::protocol::ReplyHeader");
                auto type_size = ReplyHeader::getMaxCdrSerializedSize();
                type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
                m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
                m_isGetKeyDefined = ReplyHeader::isKeyDefined();
                size_t keyLength = ReplyHeader::getKeyMaxCdrSerializedSize() > 16 ?
                        ReplyHeader::getKeyMaxCdrSerializedSize() : 16;
                m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
                memset(m_keyBuffer, 0, keyLength);
            }

            ReplyHeaderPubSubType::~ReplyHeaderPubSubType()
            {
                if (m_keyBuffer != nullptr)
                {
                    free(m_keyBuffer);
                }
            }

            bool ReplyHeaderPubSubType::serialize(
                    void* data,
                    SerializedPayload_t* payload)
            {
                ReplyHeader* p_type = static_cast<ReplyHeader*>(data);

                // Object that manages the raw buffer.
                eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
                // Object that serializes the data.
                eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
                payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
                // Serialize encapsulation
                ser.serialize_encapsulation();

                try
                {
                    // Serialize the object.
                    p_type->serialize(ser);
                }
                catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
                {
                    return false;
                }

                // Get the serialized length
                payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
                return true;
            }

            bool ReplyHeaderPubSubType::deserialize(
                    SerializedPayload_t* payload,
                    void* data)
            {
                try
                {
                    //Convert DATA to pointer of your type
                    ReplyHeader* p_type = static_cast<ReplyHeader*>(data);

                    // Object that manages the raw buffer.
                    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

                    // Object that deserializes the data.
                    eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);

                    // Deserialize encapsulation.
                    deser.read_encapsulation();
                    payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

                    // Deserialize the object.
                    p_type->deserialize(deser);
                }
                catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
                {
                    return false;
                }

                return true;
            }

            std::function<uint32_t()> ReplyHeaderPubSubType::getSerializedSizeProvider(
                    void* data)
            {
                return [data]() -> uint32_t
                       {
                           return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<ReplyHeader*>(data))) +
                                  4u /*encapsulation*/;
                       };
            }

            void* ReplyHeaderPubSubType::createData()
            {
                return reinterpret_cast<void*>(new ReplyHeader());
            }

            void ReplyHeaderPubSubType::deleteData(
                    void* data)
            {
                delete(reinterpret_cast<ReplyHeader*>(data));
            }

            bool ReplyHeaderPubSubType::getKey(
                    void* data,
                    InstanceHandle_t* handle,
                    bool force_md5)
            {
                if (!m_isGetKeyDefined)
                {
                    return false;
                }

                ReplyHeader* p_type = static_cast<ReplyHeader*>(data);

                // Object that manages the raw buffer.
                eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
                        ReplyHeader::getKeyMaxCdrSerializedSize());

                // Object that serializes the data.
                eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
                p_type->serializeKey(ser);
                if (force_md5 || ReplyHeader::getKeyMaxCdrSerializedSize() > 16)
                {
                    m_md5.init();
                    m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
                    m_md5.finalize();
                    for (uint8_t i = 0; i < 16; ++i)
                    {
                        handle->value[i] = m_md5.digest[i];
                    }
                }
                else
                {
                    for (uint8_t i = 0; i < 16; ++i)
                    {
                        handle->value[i] = m_keyBuffer[i];
                    }
                }
                return true;
            }


        } //End of namespace protocol

    } //End of namespace rpc

} //End of namespace eprosima
