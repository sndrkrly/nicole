#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <glad/glad.h>

class CVertexBuffer
{
    public:
        GLuint iID;

        void Create( GLfloat* aVertices, GLsizeiptr iSize );
        void Delete( );

        void Bind( );
        void UnBind( );
};

#endif /* VERTEX_BUFFER_H */