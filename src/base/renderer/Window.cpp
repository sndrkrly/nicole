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

const char* strVertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char* strFragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
    "}\n\0";

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

    GLuint pVertexShader = glCreateShader( GL_VERTEX_SHADER );
    glShaderSource( pVertexShader, 1, &strVertexShaderSource, NULL );
    glCompileShader( pVertexShader );

    GLuint pFragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
    glShaderSource( pFragmentShader, 1, &strFragmentShaderSource, NULL );
    glCompileShader( pFragmentShader );

    GLuint pShaderProgram = glCreateProgram( );
    glAttachShader( pShaderProgram, pVertexShader );
    glAttachShader( pShaderProgram, pFragmentShader );

    glLinkProgram( pShaderProgram );

    glDeleteShader( pVertexShader );
    glDeleteShader( pFragmentShader );

    GLfloat aVertices[ ] =
	{
		-0.5f, -0.5f * float( sqrt( 3 ) ) / 3, 0.0f, // lower left corner
		0.5f, -0.5f * float( sqrt( 3 ) ) / 3, 0.0f, // lower right corner
		0.0f, 0.5f * float( sqrt( 3 ) ) * 2 / 3, 0.0f // upper corner
	};

    GLuint VAO, VBO;
    
	glGenVertexArrays( 1, &VAO );
	glGenBuffers( 1, &VBO );

	glBindVertexArray( VAO );

	glBindBuffer( GL_ARRAY_BUFFER, VBO );
	glBufferData( GL_ARRAY_BUFFER, sizeof( aVertices ), aVertices, GL_STATIC_DRAW );

	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0 );
	glEnableVertexAttribArray( 0 );
        
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
	glBindVertexArray( 0 );

    while ( !glfwWindowShouldClose( m_pWindow ) )
    {
        glClearColor( 0.07f, 0.13f, 0.17f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT );

        glUseProgram( pShaderProgram );
        glBindVertexArray( VAO );

        glDrawArrays( GL_TRIANGLES, 0, 3 );
        
        glfwPollEvents( );
        glfwSwapBuffers( m_pWindow );
    }

    glDeleteVertexArrays( 1, &VAO );  
    glDeleteBuffers( 1, &VBO );
    glDeleteProgram( pShaderProgram );

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
