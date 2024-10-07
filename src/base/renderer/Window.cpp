/* @author: skif */

#include "Window.h"

#ifdef __APPLE__
    #define GL_SILENCE_DEPRECATION
    #define GLFW_INCLUDE_GLCOREARB
#endif

void error_callback( int, const char* strErrorDescription )
{
    std::cout << "GLFW Error: " << strErrorDescription << std::endl;
    return;
}

void keyboard_callback( GLFWwindow* m_pWindow, int iKey, int iScancode, int iAction, int _iMods )
{
    if ( iKey == GLFW_KEY_ESCAPE && iAction == GLFW_PRESS )
    {
        glfwSetWindowShouldClose( m_pWindow, GLFW_TRUE );
    }
}

void CWindow::Create( const char *strTitle, int iWidth, int iHeight )
{
    glfwInit( );
    glfwSetErrorCallback( error_callback );

    #if __APPLE__
        /* GL 4.1 + GLSL 410 */
        glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
        glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 1 );
        
        glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE ); /* 3.2+ only */
        glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );           /* Required on Mac */
    #endif

    m_pWindow = glfwCreateWindow( iWidth, iHeight, strTitle, NULL, NULL );
    if ( !m_pWindow )
    {
        std::cout << "FATAL ERROR: Couldn't create GLFW window!" << std::endl;

        glfwTerminate( );
        return;
    }

    glfwSetKeyCallback( m_pWindow, keyboard_callback );

    glfwMakeContextCurrent( m_pWindow );
    glfwSetWindowUserPointer( m_pWindow, this );

    gladLoadGL( );
    if ( !gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ) )
    {
        std::cout << "FATAL ERROR: Couldn't load OpenGL!" << std::endl;

        glfwTerminate( );
        exit( 0 );
    }

    const GLubyte* strRenderer = glGetString( GL_RENDERER );
    const GLubyte* strVersion = glGetString( GL_VERSION );

    std::cout << "Renderer: " << strRenderer << std::endl;
    std::cout << "OpenGL version supported: " << strVersion << std::endl;

    std::cout << "\n=====================" << std::endl;

    glfwSwapInterval( 1 ); /* VSync */
    glViewport( 0, 0, iWidth, iHeight );

    while ( !glfwWindowShouldClose( m_pWindow ) )
    {
        glClearColor( 0.07f, 0.13f, 0.17f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT );

        float fDeltaTime = 1.0f / FRAMERATE;

        glDrawElements( GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0 );
        
        glfwPollEvents( );
        glfwSwapBuffers( m_pWindow );
    }

    glfwDestroyWindow( m_pWindow );
    glfwTerminate( );

    return;
}

void CWindow::Shutdown( )
{
    if ( m_pWindow )
    {
        glfwDestroyWindow( m_pWindow );
        glfwTerminate( );

        return;
    }
}
