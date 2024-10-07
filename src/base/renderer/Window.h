#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <stdio.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../../config.h"

class CWindow 
{
    public:
        GLFWwindow* m_pWindow;

        void Create( const char *strTitle, int iWidth, int iHeight );
        void Destroy( );
};

#endif /* !WINDOW_H */
