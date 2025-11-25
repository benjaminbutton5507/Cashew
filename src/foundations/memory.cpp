#include "memory.h"
#include "../debugging/logger.h"
#include <stdlib.h>
cashew::memory::Block::Block() : m_Buffer(nullptr), m_BufferSize(0) {}

cashew::memory::Block::Block(int size) : m_Buffer(nullptr), m_BufferSize(size) {
    m_Buffer = (char*) malloc(size);

    if (m_Buffer) {
        cashew::debug::Logger::Log("Memory Allocation Success.", debug::INFO);
    } else {
        cashew::debug::Logger::Log("Memory Allocation Failed.", debug::ERROR);
    }
}

cashew::memory::Block::~Block() {
    if (m_Buffer) free(m_Buffer);
}

void cashew::memory::Block::AddChar(char c, int index)
{
    if (!m_Buffer) {
        cashew::debug::Logger::Log("Memory Was Not Allocated Correctly.", cashew::debug::LogLevel::ERROR);
        return;
    }

    if (index < 0 || index > m_BufferSize) {
        cashew::debug::Logger::Log("Index Is Out Of Range.", cashew::debug::LogLevel::ERROR);
        return;
    }

    *(m_Buffer + index) = c;
}

char cashew::memory::Block::GetChar(int index)
{
    if (!m_Buffer) {
        cashew::debug::Logger::Log("Memory Was Not Allocated Correctly.", cashew::debug::LogLevel::ERROR);
        return 0;
    }

    if (index < 0 || index > m_BufferSize) {
        cashew::debug::Logger::Log("Index Is Out Of Range.", cashew::debug::LogLevel::ERROR);
        return 0;
    }

    return *(m_Buffer + index);
}

const char *cashew::memory::Block::GetC_Str()
{
    return m_Buffer;
}

int cashew::memory::Block::GetSize()
{
    return m_BufferSize;
}
