#ifndef ELEMENT_BUFFER_H
#define ELEMENT_BUFFER_H

#include <glad/glad.h>

class CElementBuffer
{
    public:
        GLuint iID;

        void Create( GLuint* aIndices, GLsizeiptr iSize );
        void Delete( );

        void Bind( );
        void UnBind( );
};

#endif /* !ELEMENT_BUFFER_H */
