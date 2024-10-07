#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../base/api/GLRenderer.h"

#include "../base/renderer/Window.h"
#include "../base/renderer/Shader.h"

#include "../config.h"

class CGame
{
    public:
        CGLRenderer* m_pGLRenderer = new CGLRenderer( );

        void PreLoop( );
        void Loop( );

        void UpdateLoop( int fDeltaTime );
        void StopLoop( );
};

#endif /* GAME_H */
