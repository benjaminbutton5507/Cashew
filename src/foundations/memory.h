#ifndef __CASHEW_MEMORY_H__
#define __CASHEW_MEMORY_H__

namespace cashew {

    namespace memory {
    
        class Block {

        public:
            Block();
            Block(int size);
            ~Block();

            void AddChar(char c, int index);
            char GetChar(int index);
            const char* GetC_Str();

            int GetSize();
        
        private:
            char* m_Buffer;
            int m_BufferSize;

        };

    }

}

#endif