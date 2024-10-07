#include "VertexBuffer.h"

#ifdef __APPLE__
    #define GL_SILENCE_DEPRECATION
#endif

void CVertexBuffer::Create( GLfloat* aVertices, GLsizeiptr iSize )
{
    glGenBuffers( 1, &iID );

    glBindBuffer( GL_ARRAY_BUFFER, iID );
    glBufferData( GL_ARRAY_BUFFER, iSize, aVertices, GL_STATIC_DRAW );
}

void CVertexBuffer::Bind( )
{
    glBindBuffer( GL_ARRAY_BUFFER, iID );
}

void CVertexBuffer::UnBind( )
{
    glBindBuffer( GL_ARRAY_BUFFER, 0 );
}

void CVertexBuffer::Delete( )
{
    glDeleteBuffers( 1, &iID );
}