#include "GLRenderer.h"

void CGLRenderer::HotloadTestShader( )
{
    GLfloat aVertices[ ] =
    { 	
        //               COORDINATES                       COLORS           //
        -0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower left corner
        0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower right corner

        0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,     1.0f, 0.6f,  0.32f, // Upper corner

        -0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner left
        0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner right

        0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f  // Inner down
    };

    GLuint aIndices[ ] =
    {
        0, 3, 5, // lower left triangle
        3, 2, 4, // lower right triangle
        5, 4, 1 // upper triangle
    };

    m_pShader->Create( "res/shaders/default_vert", "res/shaders/default_frag" );
	
    m_pVertex->Create( );
    m_pVertex->Bind( );

	m_pVertexBuffer->Create( aVertices, sizeof( aVertices ) );
	m_pElementBuffer->Create( aIndices, sizeof( aIndices ) );

	m_pVertex->LinkAttrib( *m_pVertexBuffer, 0, 3, GL_FLOAT, 6 * sizeof( float ), ( void* ) 0 );
	m_pVertex->LinkAttrib( *m_pVertexBuffer, 1, 3, GL_FLOAT, 6 * sizeof( float ), ( void* )( 3 * sizeof( float ) ) );

	m_pVertex->UnBind( );
	m_pVertexBuffer->UnBind( );
	m_pElementBuffer->UnBind( );

    m_iUniID = glGetUniformLocation( m_pShader->iID, "scale" );
}

void CGLRenderer::DrawTestShader( )
{
    m_pShader->Activate( );
    glUniform1f( m_iUniID, 0.5f );
	m_pVertex->Bind( );
}

void CGLRenderer::HotdestroyTestShader( )
{
    m_pVertex->Delete( );
	m_pVertexBuffer->Delete( );
	m_pElementBuffer->Delete( );

	m_pShader->Delete( );
}