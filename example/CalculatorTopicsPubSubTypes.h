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
 * @file CalculatorTopicsPubSubTypes.h
 * This header file contains the declaration of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#ifndef _FAST_DDS_GENERATED_CALCULATORTOPICS_PUBSUBTYPES_H_
#define _FAST_DDS_GENERATED_CALCULATORTOPICS_PUBSUBTYPES_H_

#include <fastdds/dds/topic/TopicDataType.hpp>
#include <fastrtps/utils/md5.h>

#include "CalculatorTopics.h"

#if !defined(GEN_API_VER) || (GEN_API_VER != 1)
#error \
    Generated CalculatorTopics is not compatible with current installed Fast DDS. Please, regenerate it with fastddsgen.
#endif  // GEN_API_VER

/*
 * @brief This class represents the TopicDataType of the type Calculator_addition_In defined by the user in the IDL file.
 * @ingroup CALCULATORTOPICS
 */
class Calculator_addition_InPubSubType : public eprosima::fastdds::dds::TopicDataType
{
public:

    typedef Calculator_addition_In type;

    eProsima_user_DllExport Calculator_addition_InPubSubType();

    eProsima_user_DllExport virtual ~Calculator_addition_InPubSubType();

    eProsima_user_DllExport virtual bool serialize(
            void* data,
            eprosima::fastrtps::rtps::SerializedPayload_t* payload) override;

    eProsima_user_DllExport virtual bool deserialize(
            eprosima::fastrtps::rtps::SerializedPayload_t* payload,
            void* data) override;

    eProsima_user_DllExport virtual std::function<uint32_t()> getSerializedSizeProvider(
            void* data) override;

    eProsima_user_DllExport virtual bool getKey(
            void* data,
            eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
            bool force_md5 = false) override;

    eProsima_user_DllExport virtual void* createData() override;

    eProsima_user_DllExport virtual void deleteData(
            void* data) override;

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
    eProsima_user_DllExport inline bool is_bounded() const override
    {
        return true;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
    eProsima_user_DllExport inline bool is_plain() const override
    {
        return true;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

#ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
    eProsima_user_DllExport inline bool construct_sample(
            void* memory) const override
    {
        new (memory) Calculator_addition_In();
        return true;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*
 * @brief This class represents the TopicDataType of the type Calculator_subtraction_In defined by the user in the IDL file.
 * @ingroup CALCULATORTOPICS
 */
class Calculator_subtraction_InPubSubType : public eprosima::fastdds::dds::TopicDataType
{
public:

    typedef Calculator_subtraction_In type;

    eProsima_user_DllExport Calculator_subtraction_InPubSubType();

    eProsima_user_DllExport virtual ~Calculator_subtraction_InPubSubType();

    eProsima_user_DllExport virtual bool serialize(
            void* data,
            eprosima::fastrtps::rtps::SerializedPayload_t* payload) override;

    eProsima_user_DllExport virtual bool deserialize(
            eprosima::fastrtps::rtps::SerializedPayload_t* payload,
            void* data) override;

    eProsima_user_DllExport virtual std::function<uint32_t()> getSerializedSizeProvider(
            void* data) override;

    eProsima_user_DllExport virtual bool getKey(
            void* data,
            eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
            bool force_md5 = false) override;

    eProsima_user_DllExport virtual void* createData() override;

    eProsima_user_DllExport virtual void deleteData(
            void* data) override;

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
    eProsima_user_DllExport inline bool is_bounded() const override
    {
        return true;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
    eProsima_user_DllExport inline bool is_plain() const override
    {
        return true;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

#ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
    eProsima_user_DllExport inline bool construct_sample(
            void* memory) const override
    {
        new (memory) Calculator_subtraction_In();
        return true;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*
 * @brief This class represents the TopicDataType of the type Calculator_addition_Out defined by the user in the IDL file.
 * @ingroup CALCULATORTOPICS
 */
class Calculator_addition_OutPubSubType : public eprosima::fastdds::dds::TopicDataType
{
public:

    typedef Calculator_addition_Out type;

    eProsima_user_DllExport Calculator_addition_OutPubSubType();

    eProsima_user_DllExport virtual ~Calculator_addition_OutPubSubType();

    eProsima_user_DllExport virtual bool serialize(
            void* data,
            eprosima::fastrtps::rtps::SerializedPayload_t* payload) override;

    eProsima_user_DllExport virtual bool deserialize(
            eprosima::fastrtps::rtps::SerializedPayload_t* payload,
            void* data) override;

    eProsima_user_DllExport virtual std::function<uint32_t()> getSerializedSizeProvider(
            void* data) override;

    eProsima_user_DllExport virtual bool getKey(
            void* data,
            eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
            bool force_md5 = false) override;

    eProsima_user_DllExport virtual void* createData() override;

    eProsima_user_DllExport virtual void deleteData(
            void* data) override;

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
    eProsima_user_DllExport inline bool is_bounded() const override
    {
        return true;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
    eProsima_user_DllExport inline bool is_plain() const override
    {
        return true;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

#ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
    eProsima_user_DllExport inline bool construct_sample(
            void* memory) const override
    {
        new (memory) Calculator_addition_Out();
        return true;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

    MD5 m_md5;
    unsigned char* m_keyBuffer;
};
/*
 * @brief This class represents the TopicDataType of the type Calculator_subtraction_Out defined by the user in the IDL file.
 * @ingroup CALCULATORTOPICS
 */
class Calculator_subtraction_OutPubSubType : public eprosima::fastdds::dds::TopicDataType
{
public:

    typedef Calculator_subtraction_Out type;

    eProsima_user_DllExport Calculator_subtraction_OutPubSubType();

    eProsima_user_DllExport virtual ~Calculator_subtraction_OutPubSubType();

    eProsima_user_DllExport virtual bool serialize(
            void* data,
            eprosima::fastrtps::rtps::SerializedPayload_t* payload) override;

    eProsima_user_DllExport virtual bool deserialize(
            eprosima::fastrtps::rtps::SerializedPayload_t* payload,
            void* data) override;

    eProsima_user_DllExport virtual std::function<uint32_t()> getSerializedSizeProvider(
            void* data) override;

    eProsima_user_DllExport virtual bool getKey(
            void* data,
            eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
            bool force_md5 = false) override;

    eProsima_user_DllExport virtual void* createData() override;

    eProsima_user_DllExport virtual void deleteData(
            void* data) override;

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
    eProsima_user_DllExport inline bool is_bounded() const override
    {
        return true;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
    eProsima_user_DllExport inline bool is_plain() const override
    {
        return true;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

#ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
    eProsima_user_DllExport inline bool construct_sample(
            void* memory) const override
    {
        new (memory) Calculator_subtraction_Out();
        return true;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

    MD5 m_md5;
    unsigned char* m_keyBuffer;
};



/*
 * @brief This class represents the TopicDataType of the type Calculator_Request defined by the user in the IDL file.
 * @ingroup CALCULATORTOPICS
 */
class Calculator_RequestPubSubType : public eprosima::fastdds::dds::TopicDataType
{
public:

    typedef Calculator_Request type;

    eProsima_user_DllExport Calculator_RequestPubSubType();

    eProsima_user_DllExport virtual ~Calculator_RequestPubSubType();

    eProsima_user_DllExport virtual bool serialize(
            void* data,
            eprosima::fastrtps::rtps::SerializedPayload_t* payload) override;

    eProsima_user_DllExport virtual bool deserialize(
            eprosima::fastrtps::rtps::SerializedPayload_t* payload,
            void* data) override;

    eProsima_user_DllExport virtual std::function<uint32_t()> getSerializedSizeProvider(
            void* data) override;

    eProsima_user_DllExport virtual bool getKey(
            void* data,
            eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
            bool force_md5 = false) override;

    eProsima_user_DllExport virtual void* createData() override;

    eProsima_user_DllExport void copyData(void *dst, void *src);

    eProsima_user_DllExport virtual void deleteData(
            void* data) override;

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
    eProsima_user_DllExport inline bool is_bounded() const override
    {
        return true;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
    eProsima_user_DllExport inline bool is_plain() const override
    {
        return false;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

#ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
    eProsima_user_DllExport inline bool construct_sample(
            void* memory) const override
    {
        (void)memory;
        return false;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

    MD5 m_md5;
    unsigned char* m_keyBuffer;
};

/*
 * @brief This class represents the TopicDataType of the type Calculator_Reply defined by the user in the IDL file.
 * @ingroup CALCULATORTOPICS
 */
class Calculator_ReplyPubSubType : public eprosima::fastdds::dds::TopicDataType
{
public:

    typedef Calculator_Reply type;

    eProsima_user_DllExport Calculator_ReplyPubSubType();

    eProsima_user_DllExport virtual ~Calculator_ReplyPubSubType();

    eProsima_user_DllExport virtual bool serialize(
            void* data,
            eprosima::fastrtps::rtps::SerializedPayload_t* payload) override;

    eProsima_user_DllExport virtual bool deserialize(
            eprosima::fastrtps::rtps::SerializedPayload_t* payload,
            void* data) override;

    eProsima_user_DllExport virtual std::function<uint32_t()> getSerializedSizeProvider(
            void* data) override;

    eProsima_user_DllExport virtual bool getKey(
            void* data,
            eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
            bool force_md5 = false) override;

    eProsima_user_DllExport virtual void* createData() override;

    eProsima_user_DllExport void copyData(void *dst, void *src);

    eProsima_user_DllExport virtual void deleteData(
            void* data) override;

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
    eProsima_user_DllExport inline bool is_bounded() const override
    {
        return false;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
    eProsima_user_DllExport inline bool is_plain() const override
    {
        return false;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

#ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
    eProsima_user_DllExport inline bool construct_sample(
            void* memory) const override
    {
        (void)memory;
        return false;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

    MD5 m_md5;
    unsigned char* m_keyBuffer;
};

#endif // _FAST_DDS_GENERATED_CALCULATORTOPICS_PUBSUBTYPES_H_