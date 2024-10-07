#ifndef SHADER_H
#define SHADER_H

#include <iostream>

#include <glad/glad.h>
#include "../../utils/File.h"

class CShader
{
    public:
        GLuint iID;

        int CheckCompileErrors( unsigned int _iID, std::string strType );

        void Create( const std::string strVertexFilePath, const std::string strFragmentFilePath );
        void Delete( );

        void Activate( );
};

#endif /* SHADER_H */