#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <glad/glad.h>
#include "VertexBuffer.h"

class CVertexArray
{
    public:
        GLuint iID;

        void Create( );
        void Delete( );

        void LinkAttrib( CVertexBuffer& pVertexBuffer, GLuint iLayout, GLuint iNumComponents, GLenum eType, GLsizeiptr iStride, void* iOffset );

        void Bind( );
        void UnBind( );
};

#endif /* VERTEX_ARRAY_H */