#include "VertexArray.h"

#ifdef __APPLE__
    #define GL_SILENCE_DEPRECATION
#endif

void CVertexArray::Create( )
{
    glGenVertexArrays( 1, &iID );
}

void CVertexArray::LinkAttrib( CVertexBuffer& pVertexBuffer, GLuint iLayout, GLuint iNumComponents, GLenum eType, GLsizeiptr iStride, void* iOffset )
{
    pVertexBuffer.Bind( );

    glVertexAttribPointer( iLayout, iNumComponents, GL_FLOAT, GL_FALSE, iStride, ( void* ) iOffset );
    glEnableVertexAttribArray( iLayout );

    pVertexBuffer.UnBind( );
}

void CVertexArray::Bind( )
{
    glBindVertexArray( iID );
}

void CVertexArray::UnBind( )
{
    glBindVertexArray( 0 );
}

void CVertexArray::Delete( )
{
    glDeleteVertexArrays( 1, &iID );
}