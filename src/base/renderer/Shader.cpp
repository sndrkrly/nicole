#include "Shader.h"

#ifdef __APPLE__
    #define GL_SILENCE_DEPRECATION
#endif

int CShader::CheckCompileErrors( unsigned int _iID, std::string strType )
{
    int bSuccess;
    char szInfoLog[ 1024 ];

    if ( strType != "PROGRAM" )
	{
        glGetShaderiv( _iID, GL_COMPILE_STATUS, &bSuccess );

        if ( !bSuccess )
		{
            glGetShaderInfoLog( _iID, 1024, NULL, szInfoLog );
            std::cout << "FATAL ERROR: Shader compilation error of type: " << strType << "\n" << szInfoLog << "\n -- --------------------------------------------------- -- \n";
        }
    } else
	{
        glGetProgramiv( _iID, GL_LINK_STATUS, &bSuccess );

        if ( !bSuccess ) 
		{
            glGetProgramInfoLog( _iID, 1024, NULL, szInfoLog );
            std::cout << "FATAL ERROR: Program linking error of type: " << strType << "\n" << szInfoLog << "\n -- --------------------------------------------------- -- \n";
        }
    }

    return bSuccess;
}

void CShader::Create( const std::string strVertexFilePath, const std::string strFragmentFilePath )
{
    const std::string pVertexString = ReadFileFromPath( strVertexFilePath );
    const std::string pFragmentString = ReadFileFromPath( strFragmentFilePath );

    const char* charVertexSource = pVertexString.c_str( );
    const char* charFragmentSource = pFragmentString.c_str( );

    GLuint pVertexShader = glCreateShader( GL_VERTEX_SHADER );
	glShaderSource( pVertexShader, 1, &charVertexSource, NULL );
	glCompileShader( pVertexShader);

	CheckCompileErrors( pVertexShader, "VERTEX" );

	GLuint pFragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
	glShaderSource( pFragmentShader, 1, &charFragmentSource, NULL );
	glCompileShader( pFragmentShader );

	CheckCompileErrors( pFragmentShader, "FRAGMENT" );

    iID = glCreateProgram( );

	glAttachShader( iID, pVertexShader );
	glAttachShader( iID, pFragmentShader );

	glLinkProgram( iID );

 	if ( CheckCompileErrors( iID, "PROGRAM" ) )
	{
        if ( iID != -1 ) 
		{
            glDeleteProgram( iID );
        }
    } else 
	{
        std::cout << "Shader failed to compile " << strVertexFilePath << " " << strFragmentFilePath << "\n";
        return;
    }

	glDeleteShader( pVertexShader );
	glDeleteShader( pFragmentShader );
}

void CShader::Activate( )
{
    glUseProgram( iID );
}

void CShader::Delete( )
{
    glDeleteProgram( iID );
}