#ifndef GL_RENDERER_H
#define GL_RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../renderer/Shader.h"
#include "../renderer/ElementBuffer.h"

#include "../renderer/VertexArray.h"
#include "../renderer/VertexBuffer.h"

class CGLRenderer
{
    GLuint m_iUniID;

    CShader* m_pShader = new CShader( );
	CVertexArray* m_pVertex = new CVertexArray( );

	CVertexBuffer* m_pVertexBuffer = new CVertexBuffer( );
	CElementBuffer* m_pElementBuffer = new CElementBuffer( );

    public:
        void HotloadTestShader( );
        void DrawTestShader( );
        void HotdestroyTestShader( );
};

#endif /* GL_RENDERER_H */