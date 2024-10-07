#include "ElementBuffer.h"

#ifdef __APPLE__
    #define GL_SILENCE_DEPRECATION
#endif

void CElementBuffer::Create( GLuint* aIndices, GLsizeiptr iSize )
{
    glGenBuffers( 1, &iID );

    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, iID );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, iSize * sizeof( unsigned int ), aIndices, GL_STATIC_DRAW );
}

void CElementBuffer::Bind( )
{
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, iID );
}

void CElementBuffer::UnBind( )
{
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );
}

void CElementBuffer::Delete( )
{
    glDeleteBuffers( 1, &iID );
}
